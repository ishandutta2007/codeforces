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

const int MAXN = 2e5;

vector<int> G[MAXN];
bool visited[MAXN];

bool dfs(int u)
{
	bool good = true;
	if (visited[u])
		return true;
	if (G[u].size()!=2)
		good = false;
	visited[u] = true;
	for (auto v : G[u])
		if (!dfs(v))
			good = false;
	return good;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n,m;
	read2(n, m);

	FOR(i,0,m)
	{
		int u, v;
		read2(u, v);
		G[u].pb(v);
		G[v].pb(u);
	}

	ll ans(0);
	FOR(i,0,n)
		if (!visited[i])
			ans += dfs(i);
	pnl(ans);
}