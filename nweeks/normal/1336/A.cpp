#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

typedef	vector<int>	vi;
typedef vector<long long>	vl;
typedef	long long ll;

const int MAXN = 2e5;

vector<int> G[MAXN];
int nb_sommets, nb_usines;
ll prof[MAXN];
ll sz[MAXN];
int par[MAXN];
vector<int> at[MAXN];
int cur_val[MAXN];
int taken_under[MAXN];

void dfs(int u, int p, int d)
{
	prof[u]=d;
	par[u]=p;
	at[prof[u]].pb(u);
	sz[u]=1;
	for (auto v : G[u])
		if (v != p)
		{
			dfs(v,u,d+1);
			sz[u]+=sz[v];
		}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k;
	cin >> nb_sommets >> k;
	FOR(i,1,nb_sommets)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(0,0,0);
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(nb_sommets, 0));

	FOR(i,0,nb_sommets-k)
	{
		auto [_, u] = pq.top(); pq.pop();
		FORR(v, G[u])
			if (v != par[u])
				pq.push(make_pair(sz[v]-prof[v], v));
	}
	
	ll ans(0);
	while (!pq.empty())
	{
		auto [cnt,u] = pq.top(); pq.pop();
		ans += sz[u] * prof[u];
	}
	cout<<ans<<endl;
}