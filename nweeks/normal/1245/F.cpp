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

typedef	long long ll;
typedef	vector<int>	vi;
typedef pair<ll,ll>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<Arrete>	vg;
typedef vector<long long>	vl;

const int NB_DIG = 30;

ll dp[NB_DIG][2][2][2][2];

ll l, r;

ll calc(int digit, bool l1, bool r1, bool l2, bool r2)
{
	if (digit == -1)
		return 1;
	ll &val = dp[digit][l1][r1][l2][r2];
	if (val != -1)
		return val;
	val = 0;
	
	bool a =  !!(l & (1 << digit));
	bool b = !!(r & (1 << digit));

	// 0 0
	if ( (l1 or !a) and (l2 or !a)  )
		val += calc(digit - 1, l1, r1 | b , l2, r2 | b);
	// 1 0
	if ( (r1 or b) and (l2 or !a))
		val += calc(digit-1, l1 | (!a), r1, l2, r2 | b);
	// 0 1
	if ( (l1 or !a) and (r2 or b))
		val += calc(digit - 1, l1, r1 | b, l2 | (!a), r2);
	return val;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	read(t);
	while (t--)
	{
		FOR(i,0, NB_DIG) FOR(j,0,2) FOR(k,0,2) FOR(l,0,2) FOR(m,0,2)
			dp[i][j][k][l][m] = -1;
		read2(l,r);
		pnl(calc(NB_DIG - 1, 0,0,0,0));
	}
}