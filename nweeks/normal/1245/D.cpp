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

struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	vector<int>	vi;
typedef pair<int,int>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<long long>	vl;
typedef	long long ll;
struct Arrete { 
	ll u, v, c;

	bool operator<(Arrete other) const
	{
		return c < other.c or (c== other.c and ( u < other.u or (u == other.u and v < other.v)));
	}
};


const int MAXN = 1e5;

int id[MAXN];

int find(int u)
{
	if (id[u] < 0) return u;
	id[u] = find(id[u]);
	return id[u];
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a==b) return;
	if (-id[a] < -id[b]) swap(a, b);
	id[a] += id[b];
	id[b] = a;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	read(n);
	vi x(n);
	vi y(n);
	vl k(n);
	vl c(n);

	vector<Arrete> aretes;

	FOR(i,0,n)
		read2(x[i], y[i]);
	FOR(i,0,n)
		read(c[i]);
	FOR(i,0,n)
		read(k[i]);

	FOR(i,0,MAXN)
		id[i] = -1;

	FOR(i,0,n)
	{
		Arrete a;
		a.u = 0;
		a.v = i+1;
		a.c = c[i];
		aretes.pb(a);
	}
	FOR(i,0,n)
		FOR(j,i+1, n)
		{
			ll dis = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			ll cost = (k[i] + k[j])*dis;
			aretes.pb({i+1, j+1, cost});
		}
	sort(all(aretes));

	ll cost(0);
	vl used;
	vii p;

	FORR(e, aretes)
	{
		int a = e.u;
		int b = e.v;
		if (find(a) == find(b)) continue;

		merge(a,b);
		cost += e.c;
		if (a)
			p.pb({a,b});
		else
			used.pb(b);	
	}
	cout << cost << endl;
	cout << used.size() << endl;
	FORR(v, used)
		cout << v << ' ';
	cout << endl;
	cout << p.size() << endl;
	FORR(v, p)
		cout << v.F << ' ' << v.S << endl;
}