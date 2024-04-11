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

struct euler_path {
	ll n, m;
	vector<vector<pll>> adj;
	vl pos, used, path;

	euler_path(ll n, vector<pll> e): n(n), m(sz(e)), adj(n), pos(n), used(m) {
		FOR(i,0,m) adj[e[i].xx].eb(e[i].yy,i);
		FOR(i,0,m) adj[e[i].yy].eb(e[i].xx,i);
	}
	
	void rec(ll i) {
		while (pos[i] < sz(adj[i])) {
			ll j, k;
			tie(j,k) = adj[i][ pos[i]++ ];
			if (!used[k]) used[k] = true, rec(j);
		}
		path.pb(i);
	}

	bool construct() {
		ll odd = 0, s = 0;
		FOR(i,0,n) if (sz(adj[i])) {
			if (!odd) s = i;
			odd += sz(adj[i]) % 2;
		}
		if (odd > 0) return false;
		rec(s);
		return sz(path) == m+1;
	}
};

bool solve(vl a, vl b, ll k, bool output = false) {
	ll n = 1 << k, m = sz(a);
	vector<pll> e(m);
	map<pll,set<ll>> ids;
	FOR(i,0,m) {
		ll u = a[i]%n, v = b[i]%n;
		if (u > v) swap(u,v);
		e[i] = {u,v};
		if (output) ids[e[i]].insert(i);
	}
	
	euler_path E(n, e);
	if (!E.construct()) return false;
	
	if (output) {
		cout << k << endl;
		FOR(j,0,m) {
			ll u = E.path[j], v = E.path[j+1];
			pll f(min(u,v), max(u,v));
			assert(sz(ids[f]));
			ll i = *begin(ids[f]);
			ids[f].erase(begin(ids[f]));
			
			bool bw = false;
			if (a[i]%n != u || b[i]%n != v) bw = true, swap(u,v);
			assert(a[i]%n == u && b[i]%n == v);
			
			if (bw) cout << 2*i+2 << " " << 2*i+1 << " ";
			else    cout << 2*i+1 << " " << 2*i+2 << " ";
		}
		cout << endl;
	}

	return true;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n), b(n);
	FOR(i,0,n) cin >> a[i] >> b[i];

	ll kmin = 0, kmax = 21;
	while (kmax-kmin > 1) {
		ll k = (kmin+kmax)/2;
		if (solve(a, b, k)) kmin = k; else kmax = k;
	}
	assert(solve(a, b, kmin, true));
}