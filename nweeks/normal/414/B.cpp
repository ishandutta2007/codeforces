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

const int	MAX = 2e3+1;
const int	MOD = 1e9+7;

ll		dp[MAX][MAX] = {};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		n,k;
	std::cin>>n>>k;

	for (int i(1); i <=n;++i)
		dp[1][i] = 1;

	for (int i(1); i < k; ++i)
		for (int j(1); j <= n; ++j)
			for (int l(j); l <= n; l += j)
				dp[i + 1][l] = (dp[i + 1][l] + dp[i][j]) % MOD;
	ll	ans(0);
	for (int i(1); i <= n; ++i)
		ans = (ans + dp[k][i]) % MOD;
	pnl(ans);
}