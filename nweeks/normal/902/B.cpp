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

const int	MAXN = 1e4;

vi			G[MAXN];
int			color[MAXN];

int		DFS(int u, int prev_c)
{
	if (prev_c == color[u])
	{
		int		summ = 0;
		for (auto v : G[u])
			summ += DFS(v, prev_c);
		return summ;
	}
	int summ = 1;
	for (auto v : G[u])
		summ += DFS(v, color[u]);
	return summ;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);

	int	N;
	std::cin >> N;
	FOR(i,1,N)
	{
		int	u; std::cin >> u;
		--u;
		G[u].pb(i);
	}

	FOR(i,0,N)
		std::cin >> color[i];

	pnl(DFS(0, -1));
}