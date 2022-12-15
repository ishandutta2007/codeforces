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

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

const int MAXN = 1e6+1;
ll dp[4][MAXN];
/*
	0 : ""
	1: "w"
	2: "ow"
	3: "wow"
*/


int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s;
	read(s);
	int n = s.size();
	
	string t = "";
	for (int i(0); i < n; ++i)
	{
		if (s[i] == 'o') t += 'o';
		else if (i < n-1 && s[i+1] == 'v') t += 'w';
	}

	n = t.size();
	dp[0][n] = 1;
	for (int i(n-1); i >= 0; --i)
	{
		for (int k(0); k < 4; ++k) dp[k][i] = dp[k][i+1];
		if (t[i] == 'o') 
			dp[2][i] += dp[1][i+1];
		else
		{
			dp[1][i] += dp[0][i+1];
			dp[3][i] += dp[2][i+1];
		}
	}
	cout << dp[3][0] << endl;
}