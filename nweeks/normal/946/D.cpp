#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << '\n'
#define pns(x) std::cout << x << ' '
#define read(x) std::cin >> x
#define read2(x,y) std::cin >> x >> y
#define read3(x, y, z) std::cin >> x >> y >> z
#define read4(a, b, c, d) std::cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<Arrete>	vg;
typedef std::vector<long long>	vl;
typedef	long long ll;

const int	MAXN = 500;
const int	MAXM = 500;
const int	MAXK = 501;

vi	timetable[MAXN];
int	n, m, k;

int	dp[MAXN][MAXK];
int	best[MAXN][MAXK];

void	compute(int index)
{
	for (int i(0); i <= k; ++i)
	{
		if (i >= timetable[index].size())
		{
			best[index][i] = 0;
			continue ;
		}
		int	min(1e9);
		for (int j(0); j < timetable[index].size(); ++j)
		{
			int	r = timetable[index].size() - i + j - 1;
			if (r >= timetable[index].size())
				break ;
			min = std::min(min, timetable[index][r] - timetable[index][j] + 1);
		}
		best[index][i] = min;
	}
}

void	read_input(void)
{
	read3(n,m,k);

	FOR(i,0,n)
		FOR(j,0,m)
		{
			char c; read(c);
			if (c == '1')
				timetable[i].pb(j);
		}
}

int		solve(int index, int allowed)
{
	if (index == n) return 0;
	if (dp[index][allowed] != -1)
		return dp[index][allowed];

	int	min (1e9);
	for (int i(0); i <= allowed; ++i)
	{
		if (best[index][i] == 1e9) continue ;
		min = std::min(min, best[index][i] + solve(index + 1, allowed - i));
	}
	return dp[index][allowed] = min;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	read_input();

	FOR(i,0,n)
		compute(i);

	FOR(i,0,n) FOR(j,0,k+1)
		dp[i][j] = -1;
	
	pnl(solve(0, k));
}