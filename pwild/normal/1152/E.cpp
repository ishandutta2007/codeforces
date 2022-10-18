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

struct euler_tour {
	ll n;
	vector<vector<pll>> adj;
	vb used;
	vl pos, path;

	euler_tour(ll n, vector<pll> edges): n(n), adj(n), used(sz(edges)), pos(n) {
		FOR(i,0,sz(edges)) {
			auto e = edges[i];
			adj[e.xx].eb(e.yy,i);
			adj[e.yy].eb(e.xx,i);
		}
	}
	
	void rec(ll i) {
		while (pos[i] < sz(adj[i])) {
			ll p = pos[i]++;
			if (!used[adj[i][p].yy]) {
				used[adj[i][p].yy] = true;
				rec(adj[i][p].xx);
			}
		}
		path.pb(i);
	}

	bool construct() {
		ll odd = 0, s = -1;
		FOR(i,0,n) if (sz(adj[i])) {
			if (s == -1) s = i;
			if (sz(adj[i])%2) odd++, s = i;
		}
		if (odd > 2) return false;
		if (s == -1) return true;
		rec(s);
		return sz(path) == sz(used)+1;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;

	vl p(n-1), q(n-1);
	FOR(i,0,n-1) cin >> p[i];
	FOR(i,0,n-1) cin >> q[i];

	vector<pll> a(n-1);
	map<ll,ll> id;
	ll m = 0;
	FOR(i,0,n-1) {
		ll x = p[i], y = q[i];
		if (x > y) {
			cout << -1 << endl;
			return 0;
		}
		if (!id.count(x)) id[x] = m++;
		if (!id.count(y)) id[y] = m++;
		a[i] = {id[x],id[y]};
	}
	
	vl rid(sz(id));
	for (pll p: id) rid[p.yy] = p.xx;

	euler_tour E(sz(id), a);

	if (!E.construct()) {
		cout << -1 << endl;
		return 0;
	}

	for (ll x: E.path) cout << rid[x] << " ";
	cout << endl;



}