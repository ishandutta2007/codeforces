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

void solve() {
	ll n; cin >> n;

	vvl adj(n);
	FOR(i,0,n) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vl deg(n);
	FOR(i,0,n) deg[i] = sz(adj[i]);

	queue<ll> q;
	dsu D(n);
	
	FOR(i,0,n) if (deg[i] == 1) q.push(i);
	
	while (sz(q)) {
		ll i = q.front();
		deg[i] = 0;
		q.pop();
		for (ll j: adj[i]) if (deg[j]) {
			D.unite(i,j);
			if (--deg[j] == 1) q.push(j);
		}
	}
	
	vl count(n);
	FOR(i,0,n) count[D.find(i)]++;
	
	ll res = n*(n-1);
	for (ll k: count) res -= k*(k-1)/2;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}