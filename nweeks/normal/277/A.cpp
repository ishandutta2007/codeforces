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

const int	MAX = 100;

vi			G[MAX];
bool		languages[MAX][MAX]= {};
bool		visited[MAX] = {};

void	DFS(int u)
{
	visited[u] = true;
	for (auto v : G[u])
		if (!visited[v]) DFS(v);
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n, m;
	std::cin >> n >> m;

	bool	all_0 = true;
	FOR(i,0,n)
	{
		int	l;std::cin >> l;
		if (l) all_0 = false;
		FOR(k,0,l)
		{
			int	a; std::cin >> a; --a;
			languages[i][a] = true;
		}
	}
	FOR(i,0,n) FOR(j,i+1,n) FOR(k,0,m)
		if (languages[i][k] and languages[j][k])
			G[i].pb(j), G[j].pb(i);

	int	ans(0);
	FOR(i,0,n) if (!visited[i]) DFS(i), ans++;
	pnl(ans-(all_0 ? 0 : 1));

}