#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << "\n"

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<long long>	vl;
typedef	long long ll;

const int	MAX = 31;

ll			pascal[MAX][MAX] = {};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n, m, t; std::cin >> n >> m >> t;

	FOR(i,0,MAX) pascal[i][i] = 1, pascal[i][0] = 1;

	for (int i(1); i < MAX; ++i)
		for (int j(1); j < i; ++j)
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
	
/*	for (int i(0); i <= n; ++i)
	{
		for (int j(0); j <= i; ++j)
			std::cout << pascal[i][j] << " ";
		std::cout << std::endl;
	}*/


	ll	ans(0);

	for (int i(0); i <= t - 5; ++i)
	{
		if (4 + i > n or 1 + t - 5 - i > m) continue;
		ans += pascal[n][4+i] * pascal[m][1+(t-5-i)];
	}
	pnl(ans);
}