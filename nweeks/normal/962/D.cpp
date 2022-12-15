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

struct Event
{
	ll x, ind;

	bool operator<(Event other) const
	{
		return x > other.x or (x == other.x and ind > other.ind);
	}
};

bool comp(Event a, Event b)
{
	return a.ind < b.ind;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	read(N);

	priority_queue<Event> Q;
	
	FOR(i,0,N)
	{
		ll x; read(x);
		Q.push({x, i});
	}
	
	vector<Event> restant;
	while (!Q.empty())
	{
		auto a = Q.top(); Q.pop();
		if (Q.empty() or Q.top().x != a.x)
		{
			restant.pb(a);
			continue;
		}
		auto b = Q.top(); Q.pop();
		Q.push({2*b.x, b.ind});
	}
	sort(all(restant), comp);
	cout << restant.size() << endl;
	for (auto v : restant)
		cout << v.x << ' ';
	cout << endl;
}