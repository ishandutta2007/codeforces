#include <bits/stdc++.h>

int		main(void)
{
	std::ios_base::sync_with_stdio(false);

	std::map<int, int> cnt;

	int		N;
	std::cin >> N;

	for (int i(0); i < N; ++i)
	{
		int	a;
		std::cin >> a;
		cnt[a] += 1;
	}

	std::cin >> N;

	int		max_a(0), max_b(0), index(0);

	std::vector<std::pair<int,int> > movies(N);

	for (auto& val : movies)
		std::cin >> val.first;
	for (auto& val : movies)
		std::cin >> val.second;

	for (int i(0); i < N; ++i)
	{
		std::pair<int, int> cur = {cnt[movies[i].first], cnt[movies[i].second]};
		if (cur.first == max_a and cur.second > max_b)
			max_b = cur.second, index = i;
		else if (cur.first > max_a)
			max_a = cur.first, max_b = cur.second, index = i;
	}
	std::cout << index + 1 << std::endl;
}