#include <bits/stdc++.h>

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::set<int>	set;
	int		N;
	std::cin >> N;
	while (N--)
	{
		int		a;
		std::cin >> a;
		set.insert(a);
		if (set.size() > 3)
		{
			std::cout << "NO\n";
			return 0;
		}
	}

	if (set.size() < 3)
		std::cout << "YES\n";
	else
	{
		int		values[3];
		int		cur(0);
		for (auto val : set)
			values[cur++] = val;
		std::sort(values, values + 3);
		if (values[1] - values[0] == values[2] - values[1])
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}