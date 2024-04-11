#include <bits/stdc++.h>

const int	MOD = 1e9 + 7;

int		main(void)
{
	int		n, m;
	std::cin >> n >> m;

	std::vector<int>	cnt(m, 0);
	bool	used[m][26] = {};
	for (int i(0); i < m; ++i)
		for (int j(0); j < 26; ++j)
			used[i][j] = false;

	for (int i(0); i < n; ++i)
	{
		std::string s;
		std::cin >> s;
		for (int k(0); k < m; ++k)
		{
			if (!used[k][s[k] - 'A'])
				cnt[k]++;
			used[k][s[k] - 'A'] = true;
		}
	}

	long long result = 1;
	
	for (auto val : cnt)
		result = (result * val) % MOD;
	std::cout << result << std::endl;
}