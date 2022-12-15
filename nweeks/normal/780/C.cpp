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


const int	MAX = 2 * 1e5;

vi	G[MAX];
bool	visited[MAX] = {};
int		color[MAX] = {};
int	N;
int	max = 0;

void	DFS(int node, int	banned)
{
	int		banned2 = color[node];
	int		c = 0;
	visited[node] = true;
	for (auto v : G[node])
	{
		if (visited[v])
			continue ;
		while (c == banned2 or c == banned)
			++c;
		color[v] = c;
		++c;
		DFS(v, color[node]);
	}
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin>>N;

	FOR(i, 1, N)
	{
		int	a,b;
		std::cin >> a >> b;
		--a,--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	FOR(i, 0, N)
		max = std::max(max, (int)G[i].size() + 1);
	color[0] = 0;
	DFS(0, -1);
	pnl(max);
	FOR(i, 0, N)
		std::cout << color[i] + 1 << " ";
	std::cout<<"\n";
}