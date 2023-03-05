/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:32:34 by ygurma            #+#    #+#             */
/*   Updated: 2023/02/06 19:56:03 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "libft.h"

static int	ft_nbrlen(int i)
{
	if (i < 0)
	{
		if (-i < 0)
			return (ft_nbrlen(-(i / 10)) + 2);
		else
			return (ft_nbrlen(-i) + 1);
	}
	else if (i > 9)
		return (ft_nbrlen(i / 10) + 1);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		sign;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	length = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length] = '\0';
	sign = (n < 0);
	if (sign)
	{
		str[0] = '-';
		n = -n;
	}
	while (length > sign)
	{
		str[length - 1] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (str);
}
