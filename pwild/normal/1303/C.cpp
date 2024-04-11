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

void solve() {
	string a; cin >> a;
	vvl adj(26);
	FOR(i,0,sz(a)-1) {
		ll u = a[i]-'a', v = a[i+1]-'a';
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	for (vl &v: adj) {
		sort(all(v));
		v.erase(unique(all(v)),end(v));
	}


	vl deg(26);
	FOR(i,0,26) deg[i] = sz(adj[i]);

	bool ok = true;
	FOR(i,0,26) if (deg[i] > 2) ok = false;

	if (!ok) {
		cout << "NO" << endl;
		return;
	}

	vl mark(26), res;
	FOR(i,0,26) if (!mark[i] && deg[i] == 1) {
		mark[i] = true;
		res.pb(i);
		ll u = i, v = adj[i][0];
		while (deg[v] > 1) {
			res.pb(v);
			mark[v] = true;
			u = u ^ adj[v][0] ^ adj[v][1];
			swap(u,v);
		}
		mark[v] = true;
		res.pb(v);
	}
	
	FOR(i,0,26) if (deg[i] > 0 && !mark[i]) ok = false;

	if (ok) {
		cout << "YES" << endl;
		FOR(i,0,26) if (!mark[i]) res.pb(i);

		for (ll j: res) cout << char('a'+j);
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}