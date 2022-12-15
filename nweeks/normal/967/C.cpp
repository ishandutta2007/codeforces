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

const int MAXN = 1e6;

set<ll> stairs, elevators;

int S, E, v;

ll cost_elev(Point a, Point b)
{
	if (a.y == b.y)
		return abs(a.x - b.x);
	if (elevators.empty()) return 1e9;
	
	

	auto it = elevators.lower_bound(a.x);
	if (it == elevators.end())
		it--;
	ll cost = abs(a.x - *it) + (ll)ceil(abs(a.y-b.y) / (double)v)+ abs(b.x - *it);
	if (it != elevators.begin())
	{
		--it;
		ll cost2 = abs(a.x - *it) + (ll)ceil(abs(a.y-b.y) / (double)v)+ abs(b.x - *it);
		if (cost2 < cost) cost = cost2;
	}
	return cost;

}

ll cost_stairs(Point a, Point b)
{
	if (a.y == b.y)
		return abs(a.x - b.x);
	if (stairs.empty())
		return 1e9;

	auto it = stairs.lower_bound(a.x);
	if (it == stairs.end())
		it--;
	
	ll cost = abs(a.x - *it) + abs(a.y-b.y) + abs(b.x-*it);
	
	if (it != stairs.begin())
	{
		--it;
		ll cost2 = abs(a.x - *it) + abs(a.y-b.y) + abs(b.x-*it);
		if (cost2 < cost)
			cost = cost2;
	}

	return cost;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, m;
	cin >> n >> m >> S >> E >> v;
	FOR(i,0,S)
	{
		ll a; read(a);
		stairs.insert(a);
	}
	FOR(i,0,E)
	{
		ll a; read(a);
		elevators.insert(a);
	}

	ll Q;
	read(Q);

	while (Q--)
	{
		Point a, b;
		read4(a.y, a.x, b.y, b.x);
		pnl(min(cost_elev(a, b), cost_stairs(a, b)));
	}
}