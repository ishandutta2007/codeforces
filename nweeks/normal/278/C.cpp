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

bool		lang[MAX][MAX] = {};
vi			G[MAX];
bool		visited[MAX] = {};

void		DFS(int u)
{
	if (visited[u]) return ;
	visited[u] = true;
	for (auto v : G[u])
		DFS(v);
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n, m;
	std::cin >> n >> m;
	bool	at_least_one = false;
	FOR(i,0,n)
	{
		int	l; std::cin >> l;
		if (l) at_least_one = true;
		while (l--)
		{
			int	a; std::cin >> a; --a;
			lang[i][a] = true;
		}
	}

	FOR(i,0,n) FOR(j,i+1,n) FOR(k,0,m)
		if (lang[i][k] and lang[j][k])
			G[i].pb(j), G[j].pb(i);
	
	int	ans(0);
	FOR(i,0,n) if (!visited[i]) ++ans, DFS(i);

	if (at_least_one) --ans;
	pnl(ans);
}