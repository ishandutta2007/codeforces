#include <bits/stdc++.h>

const int		MAX_DIGITS = 100;

int				digits[MAX_DIGITS];
int				nb_chiffres;

bool found = false;

void			compute(int index, int n)
{
	if (index == nb_chiffres)
	{
		if (n != 0)
			return ;
		for (int i(0); i < nb_chiffres; ++i)
			std::cout << digits[i];
		std::cout << " ";
			
		found = true;

		return ;
	}

	for (int i(std::max((int)!index, n - 9 * (nb_chiffres - index - 1))); i  <= 9; ++i)
	{
		if (found)
			return ;
		digits[index] = i;
		compute(index + 1, n - i);
	}
}

void			compute_other(int index, int n)
{
	if (n < 0)
		return ;
	if (index == nb_chiffres)
	{
		if (n)
			return ;
		for (int i(0); i < nb_chiffres; ++i)
			std::cout << digits[i];
		std::cout << std::endl;
		exit(0);
	}
	
	int		lower_bound = std::max((int)!index, n - 9 * (nb_chiffres - index - 1));
	

	for (int i(9); i >= lower_bound; --i)
	{
		digits[index] = i;
		compute_other(index + 1, n - i);
	}
}

int				main(void)
{
	int		target;
	std::cin >> nb_chiffres >> target;

	std::cout.tie(NULL);
	std::cin.tie(NULL);

	if (nb_chiffres == 1 and target == 0)
	{
		std::cout << "0 0\n";
		return 0;
	}

	if (target == 0)
	{
		std::cout << "-1 -1" << std::endl;
		return 0;
	}

	compute(0, target);
	
	if (not found)
		std::cout << "-1 -1\n";
	else
		compute_other(0, target);
}