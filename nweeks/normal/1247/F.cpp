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

const int MAXN = 1e5;

vi kids[MAXN];
int sz[MAXN];
int n;
vi order;
vi ops[MAXN];;
vi ans;
int who[MAXN];

void dfs(int u)
{
	sz[u] = 1;
	FORR(v, kids[u])
	{
		dfs(v);
		sz[u] = max(sz[u], 1+sz[v]);
	}
}

bool compare(int u, int v)
{
	return sz[u] < sz[v];
}

void solve(int u)
{
	who[u] = order.size();
	order.pb(u);

	int nb_enfants = kids[u].size();
	FOR(i,0, nb_enfants)
		solve(kids[u][i]);
}

void solve_ops(int u)
{
	int nb_enfants = kids[u].size();
	for (int i(0); i < nb_enfants; ++i)
	{
		if (i)
		{
			FOR(j, 0, sz[kids[u][i-1]])
				ans.pb(kids[u][i]);
		}
		solve_ops(kids[u][i]);
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	read(n);

	FOR(i, 1, n)
	{
		int p;
		read(p);
		kids[p].pb(i);
	}

	dfs(0);

	FOR(i,0, n)
		sort(all(kids[i]), compare);

	solve(0);
	FORR(v, order)
		cout << v << ' ';
	cout << endl;
	
	solve_ops(0);
	cout << ans.size() << endl;
	FORR(v, ans)
		cout << v << ' ';
	cout << endl;

}