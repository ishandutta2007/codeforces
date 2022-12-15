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

const int MAXP = 2e5;
const int MOD = 998244353;

ll power[MAXP];

void compute_power(void)
{
	ll cur(1);
	power[0] = cur;
	for (int i(1); i < MAXP; ++i)
	{
		cur *= 2;
		cur %= MOD;
		power[i] = cur;
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	compute_power();
	int n, m;
	read2(n, m);
	string a, b;
	read2(a, b);
	for (int i(0); i < n-1-i; ++i)
		swap(a[i], a[n-1-i]);
	for (int i(0); i < m-i; ++i)
		swap(b[i], b[m-1-i]);

	ll ans(0);
	ll before(0);
	for (int i(0); i < m; ++i)
	{
		if (i < n and a[i] == '1')
			before = (before + power[i])%MOD;
		if (b[i] == '1')
			ans = (ans + before)%MOD;
	}
	cout << ans << endl;
}