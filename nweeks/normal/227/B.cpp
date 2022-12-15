#include <bits/stdc++.h>

int		main(void)
{
	int		N;
	std::cin >> N;

	std::vector<int>	index(N + 1);

	for (int i(1); i <= N; ++i)
	{
		int		val;
		std::cin >> val;
		index[val] = i;
	}

	int		Q;
	std::cin >> Q;

	long long a(0), b(0);

	while (Q--)
	{
		int		val;
		std::cin >> val;
		a += index[val];
		b += N - index[val] + 1;
	}
	std::cout << a << " " << b << std::endl;
}