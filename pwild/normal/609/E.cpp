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

struct edge {
	ll a, b, c, i;
	
	bool operator<(const edge &e) const {
		return c < e.c;
	}
};

vl ufp;

ll Find(ll x) {
	if (x == ufp[x]) return x;
	return ufp[x] = Find(ufp[x]);
}

bool Union(ll x, ll y) {
	x = Find(x), y = Find(y);
	if (x == y) return false;
	if (rand() & 1) swap(x,y);
	ufp[x] = y;
	return true;
}

vvl adj;
vl h;
vvl p, dp;

void dfs(ll i) {
	for (ll j: adj[i]) if (j != p[0][i]) {
		p[0][j] = i; h[j] = h[i] + 1;
		dfs(j);
	}
}

ll query_up(ll i, ll steps) {
	ll res = -oo;
	FOR(k,0,18) if (steps & (1 << k)) {
		res = max(res,dp[k][i]);
		i = p[k][i];
		if (i == -1) break;
	}
	return res;
}

void move_up(ll &i, ll steps) {
	FOR(k,0,18) if (steps & (1 << k)) i = p[k][i];
}

ll lca(ll i, ll j) {
	if (h[i] < h[j]) move_up(j,h[j]-h[i]);
	else move_up(i,h[i]-h[j]);
	if (i == j) return i;
	assert (h[i] == h[j]);
	FORD(k,0,18) {
		if (p[k][i] != p[k][j]) i = p[k][i], j = p[k][j];
	}
	assert (p[0][i] == p[0][j]);
	return p[0][i];
}

ll query(ll i, ll j) {
	ll k = lca(i,j);
	return max(query_up(i,h[i]-h[k]),query_up(j,h[j]-h[k]));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	vector<edge> e(m);
	FOR(i,0,m) {
		cin >> e[i].a >> e[i].b >> e[i].c;
		e[i].a--, e[i].b--;
		e[i].i = i;
	}
	
	sort(all(e));
	
	vl res(m,oo);
	adj.resize(n);
	
	ll base = 0;
	
	ufp.resize(n);
	FOR(i,0,n) ufp[i] = i;

	for (const edge &p: e) if (Union(p.a,p.b)) {
		base += p.c, res[p.i] = 0;
		adj[p.a].pb(p.b), adj[p.b].pb(p.a);
	}
	FOR(i,0,m) if (res[i] != oo) res[i] = base;
	
	p = vvl(18, vl(n,-1));
	h.resize(n);
	dfs(0);
	FOR(i,1,18) FOR(j,0,n) if (p[i-1][j] != -1) p[i][j] = p[i-1][p[i-1][j]];

	dp = vvl(18,vl(n,-oo));

	for (const edge &q: e) if (res[q.i] != oo) {
		ll i = q.a, j = q.b;
		if (p[0][j] == i) swap(i,j);
		dp[0][i] = q.c;
	}
	FOR(i,1,18) FOR(j,0,n) {
		dp[i][j] = dp[i-1][j];
		if (p[i-1][j] != -1) dp[i][j] = max(dp[i][j], dp[i-1][p[i-1][j]]);
	}
	
	for (const edge &q: e) if (res[q.i] == oo) {
		res[q.i] = base - query(q.a,q.b) + q.c;
	}
	FOR(i,0,m) cout << res[i] << "\n";


}