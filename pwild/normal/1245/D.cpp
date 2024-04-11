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

struct dsu {
	ll n;
	vl p;

	dsu(ll n): n(n), p(n) { iota(all(p),0); }
	
	ll find(ll x) {
		if (x == p[x]) return x;
		return p[x] = find(p[x]);
	}

	bool unite(ll x, ll y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		
		if (rand() & 1) swap(x,y);
		p[y] = x;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl x(n), y(n), c(n), k(n);
	FOR(i,0,n) cin >> x[i] >> y[i];
	FOR(i,0,n) cin >> c[i];
	FOR(i,0,n) cin >> k[i];
	
	vector<tuple<ll,ll,ll>> edges;
	FOR(i,0,n) FOR(j,i+1,n) {
		ll dist = abs(x[i]-x[j]) + abs(y[i]-y[j]);
		ll cost = dist * (k[i] + k[j]);
		edges.eb(cost,i,j);
	}
	FOR(i,0,n) edges.eb(c[i],i,n);
	
	sort(all(edges));
	
	dsu D(n+1);
	ll res = 0;
	vl stations;
	vector<pll> conns;
	for (auto [cost,i,j]: edges) if (D.unite(i,j)) {
		res += cost;
		if (j == n) stations.pb(i);
		else conns.eb(i,j);
	}
	
	cout << res << endl;
	cout << sz(stations) << endl;
	for (ll x: stations) cout << x+1 << " ";
	cout << endl;
	cout << sz(conns) << endl;
	for (auto [x,y]: conns) cout << x+1 << " " << y+1 << endl;
}