#include <bits/stdc++.h>

int		main(void)
{
	int		N;

	std::cin >> N;

	int		count(0);
	int		before(0);
	int		cur(0);
	int		max(0);

	while (N--)
	{
		std::cin >> cur;
		count += cur - before;
		max = std::max(count, max);
		before = cur;
	}
	std::cout << std::max(0, max) << std::endl;
}