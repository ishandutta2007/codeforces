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

struct Server
{
	ll c, i;

	bool operator<(Server other) const
	{
		return c < other.c;
	}

};

const int MAX = 3e5;

list<int> one, two;
vector<Server> servers;
ll n, x1, x2;

ll segments[MAX+1];

pair<ll, ll> min_covered[MAX+1], cpy[MAX+1];

inline void calc_segment(ll k)
{
	int i = lower_bound(all(servers), (Server){(ll)ceil(x1/(double)k), 0}) - servers.begin();
	if (i + k-1 < n and min_covered[i].F > k)
		min_covered[i] = {k, k};
}

void test(int k)
{
	int i = lower_bound(all(servers), (Server){(ll)ceil(x2/(double)k), 0}) - servers.begin();
	if (i + min_covered[i].F + k -1>= n) return ;

	pnl("Yes");
	ll good = min_covered[i].S;
	int j = lower_bound(all(servers), (Server){(ll)ceil(x1/(double)good), 0}) - servers.begin();

	cout << good << ' ' << k << endl;
	for (int l(0); l < good; ++l)
		cout << servers[l+j].i + 1 << ' ';
	cout << endl;
	
	int cur(i);
	for (int l(0); l < k; ++l)
	{
		while (cur >= j and cur < j + good)
			++cur;
		cout << servers[cur].i + 1 << ' ';
		++cur;
	}
	cout << endl;
	exit(0);
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	read3(n, x1, x2);
	servers.resize(n);
	fill(min_covered, min_covered + n+1, (pair<ll,ll>){(ll)1e9, -1LL});
	FOR(i,0,n)
	{
		cin >> servers[i].c;
		servers[i].i = i;
	}
	
	sort(all(servers));
	for (int i(1); i <= n; ++i)
		calc_segment(i);

	multiset<pair<ll,ll>> best;

	for (int i(0); i < n; ++i)
		best.insert(min_covered[i]);
	
	ll prev = 1e9;
	ll prev_i = 1e9;
	for (int i(0); i < n; ++i)
	{
		best.erase(best.find(min_covered[i]));
		if (prev - 1 < min_covered[i].F)
			min_covered[i] = {max(0LL, prev-1), prev_i};
		prev = min_covered[i].F;
		prev_i = min_covered[i].S;
		if (!best.empty() and best.begin()->F < min_covered[i].F)
			min_covered[i] = *best.begin();
	}


	for (int i(1); i <= n; ++i)
		test(i);
	pnl("No");
}