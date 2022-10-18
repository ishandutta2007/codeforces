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

bool dfs(ll i, vl &side, vvl &cur, vector<vector<pair<ll,char>>> &adj, char c) {
	cur[side[i]].pb(i);
	for (auto e: adj[i]) {
		// (side[i] ^ side[e.xx]) == (e.yy == c)
		if (side[e.xx] != -1) {
			if ((side[i] ^ side[e.xx]) != (e.yy != c)) return false;
			continue;
		}
		if (e.yy == c) side[e.xx] = side[i]; else side[e.xx] = !side[i];
		if (!dfs(e.xx,side,cur,adj,c)) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	
	vector<vector<pair<ll,char>>> adj(n);
	FOR(i,0,m) {
		ll u, v; char c;
		cin >> u >> v >> c;
		u--, v--;
		adj[u].eb(v,c);
		adj[v].eb(u,c);
	}
	vl res(n+1);
	for (char c: {'R','B'}) {
		bool ok = true;
		vl nres, side(n,-1);
		FOR(i,0,n) if (side[i] == -1) {
			vvl cur(2);
			side[i] = 0;
			ok = ok && dfs(i,side,cur,adj,c);
			if (sz(cur[1]) < sz(cur[0])) swap(cur[0],cur[1]);
			for (ll j : cur[0]) nres.pb(j);
		}
		if (!ok) continue;
		if (sz(nres) < sz(res)) res = nres;
	}
	if (sz(res) > n) cout << -1 << endl;
	else {
		cout << sz(res) << endl;
		FOR(i,0,sz(res)) cout << res[i]+1 << " \n"[i+1 == sz(res)];
	}
}