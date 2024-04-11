#include <bits/stdc++.h>

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		N, M;
	std::cin >> N >> M;

	std::set<int>	set;

	while (N--)
	{
		int		left(0), right(0);
		for (int i(0); i < M; ++i)
		{
			char c;
			std::cin >> c;
			if (c == 'G')
				left = i;
			else if (c == 'S')
				right = i;
		}
			if (left > right)
			{
				std::cout << -1 << std::endl;
				return 0;
			}
		set.insert(right - left);
	}
	std::cout << set.size() << std::endl;
}