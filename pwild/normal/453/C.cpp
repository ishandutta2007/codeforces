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

const ll maxN = 100010;

vl adj[maxN];
ll x[maxN];
bool mark[maxN];
vl res;

void dfs(ll i) {
	mark[i] = true;
	res.pb(i+1);
	x[i] = !x[i];
	for (const ll &j: adj[i]) if (!mark[j]) {
		dfs(j);
		res.pb(i+1);
		x[i] = !x[i];
		if (x[j]) {
			res.pb(j+1); x[j] = !x[j];
			res.pb(i+1); x[i] = !x[i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;

	FOR(i,0,m) {
		ll u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	FOR(i,0,n) cin >> x[i];
	
	FOR(i,0,n) if (x[i]) {
		dfs(i);
		if (x[i]) res.pop_back();
		break;
	}
	FOR(i,0,n) if (x[i] && !mark[i]) {
		cout << -1 << endl;
		return 0;
	}
	cout << sz(res) << endl;
	FOR(i,0,sz(res)-1) cout << res[i] << " ";
	if (sz(res)) cout << res[sz(res)-1] << endl;

}