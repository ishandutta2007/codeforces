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

const int MAXN = 201;

int n, k;

vi G[MAXN];

int weight[MAXN];

ll dp[MAXN][MAXN];


void dfs(int u, int p)
{
	FORR(v, G[u])
		if (v != p)
			dfs(v, u);
	dp[u][0] = weight[u];

	FORR(v, G[u])
		if (v != p)
			dp[u][0] +=dp[v][k];

	FOR(d,1, n)
	{
		ll sum = 0;
		FORR(v, G[u])
			if (v != p)
				sum += dp[v][max(d-1, k-d)];
		dp[u][d] = 0;
		FORR(v, G[u])
			if (v != p)
			{
				dp[u][d] = max(dp[u][d], sum - dp[v][max(d-1, k-d)] + dp[v][d-1]);
			}
	}
	
	for (int d(n-1); d > 0; --d)
		dp[u][d-1] = max(dp[u][d-1], dp[u][d]);

	
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	read2(n,k);
	
	FOR(i,0,n)
		read(weight[i]);

	FOR(i,1,n)
	{
		int u, v;
		read2(u,v);
		--u, --v;
		G[u].pb(v);
		G[v].pb(u);
	}

	dfs(0,-1);
	cout << dp[0][0] << endl;

}