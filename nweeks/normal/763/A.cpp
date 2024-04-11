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
int			color[MAX];
bool		visited[MAX] = {};
int		N;


bool	ok(int u, int c)
{
	//std::cout << u << " " << color[u] << " " << c << "\n";
	visited[u] = true;
	if (color[u] != c) return false;
	for (auto v : G[u])
		if (!visited[v] and !ok(v, c))
			return false;
	return true;
}

bool	works(int node)
{
	for (int i(0); i < N; ++i) visited[i] = false;
	visited[node] = true;
	for (auto v : G[node])
		if (!ok(v, color[v]))
			return false;
	return true;
}

void	check(int a, int b)
{
	if (works(a))
	{
		pnl("YES"); pnl(a+1);
	}
	else	if (works(b))
	{
		pnl("YES"); pnl(b+1);
	}
	else pnl("NO");
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;

	vii	edges(N-1);

	for (auto&v : edges) {std::cin >> v.first >> v.second, --v.first, --v.second; G[v.first].pb(v.second), G[v.second].pb(v.first);}

	FOR(i,0,N) std::cin >> color[i];

	for (auto v : edges)
	{
		if (color[v.first] != color[v.second])
		{
			check(v.first, v.second);
			return 0;
		}
	}
	pnl("YES");
	pnl(1);
}