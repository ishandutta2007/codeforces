#include <bits/stdc++.h>

int		main(void)
{
	int		N, F;
	std::cin >> N >> F;
	std::vector<int>	a(N);
	std::vector<int>	b(N);

	for (int i(0); i < N; ++i)
		std::cin >> a[i] >> b[i];
	
	long long ans(0);

	for (int i(0); i < N; i++)
	{
		ans += std::min(a[i], b[i]);
		a[i] = std::min(2 * a[i], b[i]) - std::min(a[i], b[i]);
	}

	std::sort(a.begin(), a.end());
	for (int i(N - 1); i >= N - F; --i)
		ans += a[i];
	std::cout << ans << std::endl;
}