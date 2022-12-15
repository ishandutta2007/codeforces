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

const int MAX = 2000;
const ll MOD = 1e9 + 7;

ll dp[MAX][MAX][2];

string up;
int nb_dig;
int req;
ll m;

ll calc(int digit, int mod, bool smal)
{
	if (digit == -1)
		return !mod;
	if (dp[digit][mod][smal] != -1)
		return dp[digit][mod][smal];

	if ((up.size() - digit) %2 == 0)
	{
		if (smal || req <= up[digit] -'0')
			return (dp[digit][mod][smal] = calc(digit - 1, (10 * mod + req)%m, smal || (req < up[digit] -'0')));
		else
			return (dp[digit][mod][smal] = 0);
	}
	else
	{
		dp[digit][mod][smal] = 0;
		for (int d(0); d < 10; ++d)
		{
			if (!d and digit == up.size() -1) continue;
			if (d == req) continue;
			if (smal || (d <= up[digit] - '0'))
				dp[digit][mod][smal] += calc(digit - 1, (10 *mod +d)%m, smal || (d < up[digit] - '0'));
			dp[digit][mod][smal] %= MOD;
		}
		return dp[digit][mod][smal];
	}
}

bool is_magic(string s)
{
	int mod = 0;
	for (int i(s.size()-1); i >= 0;--i)
	{
		mod = (10 * mod + s[i] - '0')%m;
		if ((s.size() - i)%2==0 && s[i]-'0' != req)
			return false;
		if ((s.size() - i)%2 && s[i]-'0' == req)
			return false;
	}
	return !mod;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	read2(m,req);
	string a, b;
	read(a);
	read(b);
	reverse(all(a));
	reverse(all(b));
	
	up = b;
	FOR(i,0, MAX) FOR(j,0, MAX) FOR(k,0,2)
		dp[i][j][k] = -1;
	ll u = calc(up.size() - 1, 0, false);
	FOR(i,0, MAX) FOR(j,0, MAX) FOR(k,0,2)
		dp[i][j][k] = -1;
	up  = a;
	ll l = calc(up.size() - 1, 0, false) - is_magic(a);
	cout << (MOD + u - l)%MOD << endl;

}