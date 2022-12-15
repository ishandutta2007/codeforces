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

vi		G[100];

bool	visited[100] = {};

void	DFS(int u)
{
	visited[u] = true;
	for (auto v : G[u])
		if (!visited[v])
			DFS(v);
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n;
	std::cin >> n;

	vii	a(n);
	for (auto&v : a) std::cin >> v.first >> v.second;

	for (int i(0); i < n; ++i)
		for (int j(i+1); j < n; ++j)
			if (a[i].first == a[j].first or a[i].second == a[j].second)
				G[i].pb(j), G[j].pb(i);

	int	cnt(0);
	for (int i(0); i < n; ++i)
		if (!visited[i]) DFS(i), ++cnt;
	pnl(cnt-1);
}