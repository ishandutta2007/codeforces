#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define dbg(x) cerr<<#x<<" = " << (x) << endl
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	vector<int>	vi;
typedef pair<int,int>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<Arrete>	vg;
typedef vector<long long>	vl;
typedef	long long ll;

const int DIM = 10;

double dp[DIM][DIM];

int ladder[DIM][DIM];

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	FOR(i,0,DIM)
		FOR(j,0,DIM)
			read(ladder[i][j]);

	dp[0][0] = 0;

	for (int i(1); i < 6; ++i)
	{
		dp[0][i] = 6;
		for (int j(0); j < i; ++j) dp[0][i] += dp[0][j];
		dp[0][i] /= i;
	}
	for (int i(6); i < DIM; ++i)
	{
		for (int dice(1); dice <= 6; ++dice) dp[0][i] += 1+dp[0][i-dice];
		dp[0][i] /= 6;
	}

	for (int line(1); line < DIM; ++line)
	{
		// If ->
		if (line % 2)
		{
			for (int j(DIM-1); j >= 0 ; --j)
			{
				for (int dice(1); dice <= 6; ++dice)
				{
					int line_land, col_land;
					if (j + dice >= DIM)
						line_land = line - 1, col_land = DIM - (dice - (DIM - 1 - j)) ;
					else
						line_land = line, col_land = j + dice;
					dp[line][j] += 1+min(dp[line_land][col_land], dp[line_land - ladder[line_land][col_land]][col_land]);
				}
				dp[line][j] /= 6;
			}
		}
		// If <-
		else
		{
			for (int j(0); j < DIM; ++j)
			{
				for (int dice(1); dice <= 6; ++dice)
				{
					int line_land, col_land;
					if (j - dice >= 0)
						line_land = line, col_land = j - dice;
					else
						line_land = line-1, col_land = dice - j - 1;
					dp[line][j] += 1+min(dp[line_land][col_land], dp[line_land - ladder[line_land][col_land]][col_land]);
				}
				dp[line][j] /= 6;
			}
		}
	}
	cout << setprecision(12) << fixed << dp[DIM-1][0] << endl;
}