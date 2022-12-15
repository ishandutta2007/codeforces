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

const int MAXN = 2001;
const int MOD = 998244353;
const int FLIP = 3;
ll dp[2][MAXN][4];



int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, K;
	read2(n, K);

	dp[0][1][0] = dp[0][1][3] = dp[0][2][1] = dp[0][2][2] = 1;
	for (int i(0); i < n; ++i)
	{
		int p = i&1;
		if (i)
		for (int j(1); j <= K; ++j)
		{
			ll total = 0;
			// 00
			dp[p][j][0] = (dp[!p][j][0] + dp[!p][j][1] + dp[!p][j][2] +dp[!p][j-1][3])%MOD;
			// 01
			dp[p][j][1] = (dp[!p][j-1][0] + dp[!p][j][1] + (j!=1 ? dp[!p][j-2][2]:0) + dp[!p][j-1][3])%MOD;
			// 10
			dp[p][j][2] = (dp[!p][j-1][0] + (j != 1 ? dp[!p][j-2][1]:0) + dp[!p][j][2] + dp[!p][j-1][3])%MOD;
			// 11
			dp[p][j][3] = (dp[!p][j-1][0] + dp[!p][j][1] + dp[!p][j][2] + dp[!p][j][3])%MOD;
		}
		/*cout << i << "----------\n";
		FOR(k,0,4)
		{
			cout << k << ":\n";
			FOR(j,1,K+1)
				cout<< j<<" " << dp[p][j][k] << endl;
		}*/
	}
	ll ans(0);
	FOR(k,0,4) ans = (ans + dp[!(n&1)][K][k])%MOD;
	pnl(ans);
}