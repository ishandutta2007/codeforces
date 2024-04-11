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
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

const ll N = 1e5 + 10, K = 18;
ll par[N][K], dep[N];
vl adj[N];

void dfs(ll i) {
	FOR(k,1,K) par[i][k] = par[ par[i][k-1] ][k-1];

	for (ll j: adj[i]) if (dep[j] == -1) {
		dep[j] = dep[i] + 1;
		par[j][0] = i;
		dfs(j);
	}
}

ll lca(ll i, ll j) {
	if (dep[i] < dep[j]) swap(i,j);
	ll dh = dep[i]-dep[j];

	FOR(k,0,K) if (dh & (1 << k)) i = par[i][k];

	if (i == j) return i;
	FORD(k,0,K) if (par[i][k] != par[j][k]) {
		i = par[i][k], j = par[j][k];
	}
	return par[i][0];
}

ll dist(ll i, ll j) {
	ll k = lca(i,j);
	return dep[i] + dep[j] - 2*dep[k];
}

bool query() {
	ll x, y, a, b, k;
	cin >> x >> y >> a >> b >> k;

	ll dab = dist(a,b);
	ll dp = dist(a,x) + 1 + dist(y,b);
	ll dq = dist(a,y) + 1 + dist(x,b);

	vl dmin = {oo,oo};
	for (ll d: {dab,dp,dq}) {
		dmin[d%2] = min(dmin[d%2], d);
	}
	
	return dmin[k%2] <= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	FOR(i,1,n) {
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(dep,-1,sizeof dep);
	dep[1] = 0;
	dfs(1);
	
	ll q; cin >> q;
	while (q--) {
		cout << (query() ? "YES" : "NO") << "\n";
	}
}