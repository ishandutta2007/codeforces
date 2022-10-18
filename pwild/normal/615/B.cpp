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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m; cin >> n >> m;
	vvl adj(n);
	FOR(i,0,m) {
		ll u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}

	ll res = 0;
	vl dp(n,1);
	FOR(i,0,n) {
		for (const ll &j: adj[i]) if (j < i) dp[i] = max(dp[i],dp[j]+1);
		res = max(res,dp[i]*sz(adj[i]));
	}
	cout << res << endl;

}