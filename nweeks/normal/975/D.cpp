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

map<ll, ll> cnt;
map<pair<pair<ll, ll> ,ll>, ll> same_all;

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, a, b;
	read3(n, a, b);

	FOR(i,0,n)
	{
		ll x, vx, vy;
		read3(x, vx, vy);
		cnt[a*vx-vy]++;
		ll det = a*vx - vy;
		same_all[{{vx, vy}, det}]++;
	}

	ll ans(0);
	for (auto v : cnt)
		ans += (v.second-1) * v.second;
	for (auto v: same_all)
		ans -= (v.second-1) * v.second;
		
	pnl(ans);
}