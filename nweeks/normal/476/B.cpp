#include <bits/stdc++.h>

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

std::string s1, s2;
int			target(0);
int			cnt(0);

void	compute(int index, int prev)
{
	if (index == s2.size())
	{
		if (prev == target)
			++cnt;
		return ;
	}
	else if (s2[index] == '+')
		compute(index + 1, prev + 1);
	else if (s2[index] == '-')
		compute(index + 1, prev - 1);
	else
		compute(index + 1, prev + 1), compute(index + 1, prev - 1);
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> s1 >> s2;

	for (auto c : s1)
		target = (c == '+') ? target + 1 : target - 1;
	compute(0, 0);
	int		paths = 1;
	for (auto c : s2)
		if (c == '?')
			paths *= 2;
	std::cout.precision(9);
	std::cout << std::fixed << cnt / (paths * 1.0) << std::endl;
}