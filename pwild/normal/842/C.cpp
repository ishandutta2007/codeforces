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

ll n;
vl a;
vvl adj;
vl res;

void dfs(ll i, ll g, set<ll> &h, ll p) {
	ll ng = __gcd(g,a[i]);
	set<ll> nh;
	nh.insert(g);
	for (ll x: h) nh.insert(__gcd(x,a[i]));
	
	res[i] = max(ng, *nh.rbegin());

	for (ll j: adj[i]) if (j != p) dfs(j, ng, nh, i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	a.resize(n);
	FOR(i,0,n) cin >> a[i];

	adj.resize(n);
	FOR(i,1,n) {
		ll u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	res.resize(n);
	set<ll> h;
	dfs(0,0,h,-1);
	FOR(i,0,n) cout << res[i] << " \n"[i+1==n];
}