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

vl a;
vl sum;
vvl adj;

ll dfs(ll i, ll p) {
	sum[i] = a[i];
	for (ll j: adj[i]) if (j != p) sum[i] += dfs(j,i);
	return sum[i];
}

pll dfs2(ll i, ll p) {
	ll r1 = sum[i], r2 = -oo;
	ll b1[2] = {-oo,-oo};
	for (ll j: adj[i]) if (j != p) {
		pll p = dfs2(j,i);
		r1 = max(r1,p.xx);
		if (p.xx > b1[0]) b1[1] = b1[0], b1[0] = p.xx;
		else if (p.xx > b1[1]) b1[1] = p.xx;
		r2 = max(r2,p.yy);
		r2 = max(r2,b1[0]+b1[1]);
	}
	return {r1,r2};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	a.resize(n);
	sum.resize(n);
	FOR(i,0,n) cin >> a[i];
	
	adj.resize(n);
	FOR(i,1,n) {
		ll u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(0,-1);
	
	ll res = dfs2(0,-1).yy;
	if (res > -oo/2) cout << res << endl;
	else cout << "Impossible" << endl;

}