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

ll n, m;
vl cat;
vvl adj;

ll dfs(ll i, ll p, ll cats) {
	if (cats+cat[i] > m) return 0;
	if (p != -1 && sz(adj[i]) == 1) return 1;
	ll res = 0;
	for (ll j: adj[i]) if (j != p) res += dfs(j,i,(cat[i] ? cats+1 : 0));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	cat = vl(n);
	FOR(i,0,n) cin >> cat[i];
	
	adj = vvl(n);
	FOR(i,1,n) {
		ll x, y; cin >> x >> y;
		x--, y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	cout << dfs(0,-1,0) << endl;
}