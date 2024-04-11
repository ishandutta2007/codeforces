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
const int MAXK = 100;

vi G[MAXN];
int val[MAXN];
int visited[MAXN];
int closest[MAXN][MAXK];;
vector<int> cities[MAXK];
int N, m, k, s;

void calc(int type)
{
	queue<ii> Q;
	for (auto e : cities[type])
	{
		Q.push({e, 0});
		visited[e] = type;
		closest[e][type] = 0;
	}
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (auto v : G[cur.F])
			if (visited[v] != type)
			{
				visited[v] = type;
				closest[v][type] = cur.S + 1;
				Q.push({v, cur.S + 1});
			}
	}
}

int		solve(int start)
{
	sort(closest[start], closest[start] + k);
	int ans(0);
	for (int i(0); i < s; ++i)
		ans += closest[start][i];
	return ans;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fill(visited, visited + MAXN, -1);
	read4(N, m, k, s);
	FOR(i,0,N)
	{
		read(val[i]);
		--val[i];
		cities[val[i]].pb(i);
	}
	FOR(i,0,m)
	{
		int u, v;
		read2(u, v);
		--u, --v;
		G[u].pb(v);
		G[v].pb(u);
	}
	FOR(i,0,k)
		calc(i);
	
	FOR(i,0,N)
		pns(solve(i));
}