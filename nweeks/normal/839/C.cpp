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

const int	MAX = 1e5;

vi			G[MAX];
bool		visited[MAX] = {};

double	DFS(int u, double p, int d)
{
	int	cnt(0);
	double	summ = 0.0;
	visited[u] = true;
	for (auto v : G[u])
		cnt += !visited[v];
	
	if (!cnt)
		return d * p;

	for (auto v : G[u])
	{
		if (visited[v]) continue;
		summ += DFS(v, p * (1.0/cnt), d+1);
	}
	return summ;
}


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	N;
	std::cin >> N;
	FOR(i,0,N-1)
	{
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		G[u].pb(v);
		G[v].pb(u);
	}
	
	std::cout.precision(10);
	std::cout << std::fixed << DFS(0, 1.0, 0) << std::endl;
}