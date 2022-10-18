#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll N = 100100, M = 20;

vl operator+(const vl &a, const vl &b) {
	vl res;
	set_union(all(a),all(b),back_inserter(res));
	if (sz(res) > 10) res.resize(10);
	return res;
}

ll h[N];
vl adj[N];
ll p[M][N];
vl dp[M][N];

void dfs(ll i) {
	for (ll j: adj[i]) if (j != p[0][i]) {
		p[0][j] = i, h[j] = h[i] + 1;
		dfs(j);
	}
}

ll lca(ll i, ll j) {
	if (h[i] < h[j]) swap(i,j);
	ll d = h[i]-h[j];
	FOR(m,0,M) if (d & (1 << m)) i = p[m][i];
	if (i == j) return i;
	FORD(m,0,M) if (p[m][i] != p[m][j]) {
		i = p[m][i], j = p[m][j];
	}
	return p[0][i];
}

vl query(ll i, ll j) {
	ll d = h[i]-h[j]+1;
	vl res;
	FOR(m,0,M) if (d & (1 << m)) {
		res = res + dp[m][i];
		i = p[m][i];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, q; cin >> n >> m >> q;
	
	FOR(i,1,n) {
		ll u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}
	
	p[0][0] = -1, h[0] = 0;
	dfs(0);
	FOR(j,1,M) FOR(i,0,n) {
		if (p[j-1][i] >= 0) 
			p[j][i] = p[j-1][p[j-1][i]];
		else
			p[j][i] = -1;
	}

	//FOR(i,0,n) FOR(j,0,n) cout << i << " " << j << " " << lca(i,j) << endl;	

	FOR(i,0,m) {
		ll c; cin >> c;
		c--;
		if (sz(dp[0][c]) < 10) dp[0][c].pb(i+1);
	}
	FOR(j,1,M) FOR(i,0,n) {
		if (p[j-1][i] >= 0)
			dp[j][i] = dp[j-1][i] + dp[j-1][p[j-1][i]];
		else
			dp[j][i] = dp[j-1][i];
	}
	
	while (q--) {
		ll u, v, a; cin >> u >> v >> a;
		u--, v--;
		ll w = lca(u,v);
		vl res = query(u,w) + query(v,w);
		ll k = min(sz(res),a);
		cout << k;
		FOR(i,0,k) cout << " " << res[i];
		cout << endl;
	}

}