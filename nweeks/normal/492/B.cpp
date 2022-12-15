#include <bits/stdc++.h>

int		main(void)
{
	int	N, L;
	std::cin >> N >> L;

	std::vector<int>	a(N);

	for (auto &val : a)
		std::cin >> val;
	std::sort(a.begin(), a.end());

	int		max = std::max(2 * (a.front() - 0), 2 * (L - a.back()));
	for (int i(0); i < N - 1; ++i)
		max = std::max(max, a[i + 1] - a[i]);
	printf("%.9lf\n", max / 2.0);
}