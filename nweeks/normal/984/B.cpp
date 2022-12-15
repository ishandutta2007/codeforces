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

const int	NB_D = 8;
const int	DY[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int	DX[] = {0, 0, -1, 1, -1, 1, -1, 1};



int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	read2(n, m);

	const int MAX = 100;
	char map[MAX][MAX];
	FOR(i,0,n) FOR(j,0,m)
		read(map[i][j]);

	FOR(i,0,n) FOR(j,0,m)
	{
		if (map[i][j] == '*') continue;
		if (map[i][j] == '.')
		{
			FOR(d, 0, NB_D)
				if (i + DY[d] >= 0 and i + DY[d] < n and j + DX[d] >= 0 and j + DX[d] < m)
					if (map[i+DY[d]][j+DX[d]] == '*')
					{
						cout << "NO" << endl;
						return 0;
					}
		}
		else
		{
			int cnt = '0';
			FOR(d, 0, NB_D)
				if (i + DY[d] >= 0 and i + DY[d] < n and j + DX[d] >= 0 and j + DX[d] < m)
					cnt += map[i+DY[d]][j+DX[d]] == '*';
			if (cnt != map[i][j])
			{
				pnl("NO");
				return 0;
			}
		}

	}
	pnl("YES");
}