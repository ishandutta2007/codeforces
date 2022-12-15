#include <bits/stdc++.h>

int		main(void)
{
	int		N;
	std::cin >> N;

	std::vector<int>	tab(N);
	for (auto& val : tab)
		std::cin >> val;

	std::vector<int>	cpy(N);
	for (int i(0); i < N; ++i)
		cpy[i] = tab[i];

	std::sort(tab.begin(), tab.end());

	bool	reversed = false;
	int		i(1), j(1);
	int		cur(0);
	
	while (cur < N)
	{
		if (tab[cur] != cpy[cur])
		{
			if (reversed)
			{
				std::cout << "no" << std::endl;
				return 0;
			}
			reversed = true;
			int	right(cur + 1);
			while (tab[cur] != cpy[right] and right < N)
				++right;
			if (right == N)
			{
				--right;
			}
			int		left(cur);
			i = left + 1, j = right + 1;
			cur = right;
			while (left <= cur and tab[left] == cpy[right])
				++left, --right;
			if (left <= cur)
			{
				std::cout << "no\n";
				return 0;
			}
		}
		++cur;
	}
	std::cout << "yes\n";
	std::cout << i << " " << j << std::endl;

}