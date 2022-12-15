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

const int MAXN = 100;

ll arr[MAXN];

ll val2(ll n)
{
	ll b(0);
	while (n%2==0)
		b++, n/=2;
	return b;
}

ll val3(ll n)
{
	ll b(0);
	while (n%3==0)
		b++, n/=3;
	return b;
}

bool comp(ll a, ll b)
{
	ll a3 = val3(a), b3 = val3(b), a2 = val2(a), b2 = val2(b);
	if (a3 == b3)
		return a2 < b2;
	return a3 > b3;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n;
	read(n);
	FOR(i,0,n)
		read(arr[i]);
	sort(arr, arr + n, comp);
	FOR(i,0,n)
		cout << arr[i] << ' ';
	cout << endl;
}