#include <bits/stdc++.h>

const int	MAX = 1e5 + 1;

long long	dp[MAX] = {};
long long	arr[MAX] = {};
long long	summ[MAX] = {};

long long	get_summ(int right, int left)
{
	return summ[right] - summ[left];
}


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::multiset<int>	set;

	int	N, c;
	std::cin >> N >> c;

	for (int i(1); i <= N; ++i)
	{
		std::cin >> arr[i];
		summ[i] = summ[i-1] + arr[i];
	}

	for (int i(1); i <= N; ++i)
	{
		if (i > c)
			set.erase(set.find(arr[i-c]));
		dp[i] = dp[i-1] + arr[i];
		set.insert(arr[i]);
		if (i >= c)
			dp[i] = std::min(dp[i], dp[i-c] + get_summ(i, i-c) - *set.begin());
	}
	std::cout << dp[N] << std::endl;
}