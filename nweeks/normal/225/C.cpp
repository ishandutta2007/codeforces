#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << '\n'
#define pns(x) std::cout << x << ' '
#define read(x) std::cin >> x
#define read2(x,y) std::cin >> x >> y
#define read3(x, y, z) std::cin >> x >> y >> z
#define read4(a, b, c, d) std::cin >> a >> b >> c >> d

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<long long>	vl;
typedef	long long ll;

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

const int	WHITE = 0;
const int	BLACK = 1;

const int	MAX = 1e3;

int		map[MAX][MAX];
int		cost[2][MAX] = {};
int		dp[2][MAX] = {};

int		N, M, x , y;

void	read_input(void)
{
	read4(N, M, x, y);

	FOR(i,0,N) FOR(j,0,M)
	{
		char c;
		read(c);
		map[i][j] = (c == '.' ? WHITE : BLACK);
	}
}

void	compute_cost_col(void)
{
	FOR(k, 0, 2) FOR(i, 0, N) FOR(j,0,M)
		cost[k][j] += map[i][j]!=k;

	FOR(k,0,2) FOR(i,0,M-1)
		cost[k][i+1] += cost[k][i];
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	read_input();
	compute_cost_col();

	for (int k(0); k < 2; ++k)
		for (int i(0); i < x-1; ++i)
			dp[k][i] = 1e9;

	for (int i(x-1); i < M; ++i)
	{
		for (int k(0); k < 2; ++k)
		{
			dp[k][i] = 1e9;
			for (int j(x); i-j>=-1  and j<= y; ++j)
				dp[k][i] = std::min(dp[k][i], (i-j==-1?0:dp[!k][i-j]) + cost[k][i]-(i-j==-1?0:cost[k][i-j]));
		}
	}

	pnl(std::min(dp[0][M-1], dp[1][M-1]));
}