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

ll	cost[33];

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	
	ll	N, L;
	std::cin >> N >> L;

	FOR(i,0,N) std::cin >> cost[i];

	for (int i(1); i < N; ++i)
		cost[i] = std::min(2*cost[i-1], cost[i]);
	for (int i(N); i < 33; ++i)
		cost[i] = 2*cost[i-1];

	ll	ans = 0;

	for (int bit(0); bit < 32; ++bit)
	{
		if ((1<<bit)&L)
			ans += cost[bit];
		ans = std::min(ans, cost[bit+1]);
	}
	pnl(ans);
}