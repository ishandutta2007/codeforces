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

const int MAX = 1e5;
vi G[MAX];

int d[MAX];
int id[MAX];
int par[MAX];

struct Situation
{
	int node;

	bool operator<(Situation other) const
	{
		return d[node] < d[other.node];
	}
};

void DFS(int u, int p, int depth)
{
	par[u] = p;
	d[u] = depth;
	for (auto v : G[u])
		if (v != p)
			DFS(v, u, depth + 1);
}

int find(int i)
{
	return id[i] < 0 ? i : id[i] = find(id[i]);
}

void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return ;
	if (d[a] > d[b]) swap(a, b);
	id[a] += id[b];
	id[b] = a;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	read(n);
	fill(id, id + n, -1);

	if (n&1)
	{
		pnl(-1);
		return 0;
	}
	FOR(i,1,n)
	{
		int u, v;
		read2(u, v);
		G[u-1].pb(v-1);
		G[v-1].pb(u-1);
	}

	DFS(0, 0, 0);
	par[0] = -1;

	priority_queue<Situation> Q;
	FOR(i,0,n)
		Q.push({i});
	int ans(n);
	FOR(i,0,n)
	{
		auto cur = Q.top(); Q.pop();
		if ((-id[find(cur.node)])%2 ==0)
			continue ;
		merge(cur.node, par[cur.node]);
		ans--;
	}
		cout << ans - 1<< endl;
}