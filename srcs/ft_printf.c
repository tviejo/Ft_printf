/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:36:32 by tviejo            #+#    #+#             */
/*   Updated: 2024/04/06 23:30:29 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		ft_putvoid(va_arg(args, void *));
	else if (c == 'd')
		ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_puthexalow(va_arg(args, unsigned int));
	else if (c == 'X')
		ft_puthexahigh(va_arg(args, unsigned int));
	else if (c == '%')
		ft_putchar('%');
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		converted;

	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			return (-1);
		i++;
		converted = ft_convert(str[i], args);
		if (converted == 0)
			return (0);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int     main(void)
{
        void    *ptr;

        ptr = "a";
        
//        ft_printf("%s%c%p%d%i%u%x%X%%","qwerty",'a',ptr,-51,-99,-666,15,-15);

	printf("\n\nteststr:\n");
        ft_printf("%s","qwerty");
        printf("\n%s","qwerty");

	printf("\n\ntestc:\n");
        ft_printf("%c",'a');
        printf("\n%c",'a');

	printf("\n\ntestptr:\n");
        ft_printf("%p",ptr);
        printf("\n%p",ptr);
	printf("\n");
        ft_printf("%p",NULL);
        printf("\n%p",NULL);

	printf("\n\ntestd:\n");
        ft_printf("%d",0);
        printf("\n%d",0);
	printf("\n");
        ft_printf("%d",2147483647);
        printf("\n%d",2147483647);
	printf("\n");
        ft_printf("%d",-2147483647);
        printf("\n%d",-2147483647);

	printf("\n\ntesti:\n");
        ft_printf("%i",0);
        printf("\n%i",0);
	printf("\n");
        ft_printf("%i",2147483647);
        printf("\n%i",2147483647);
	printf("\n");
        ft_printf("%i",-2147483647);
        printf("\n%i",-2147483647);
}
*/
