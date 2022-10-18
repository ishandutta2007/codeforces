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
	vl p, s;

	dsu(ll n): n(n), p(n), s(n,1) { iota(all(p),0); }
	
	ll find(ll x) {
		if (x == p[x]) return x;
		return p[x] = find(p[x]);
	}

	ll size(ll x) {
		return s[find(x)];
	}

	bool unite(ll x, ll y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		
		if (rand() & 1) swap(x,y);
		p[y] = x;
		s[x] += s[y];
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;

	vector<dsu> D(2,dsu(n));

	vector<vector<pll>> adj(n);
	FOR(i,1,n) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].eb(b,c);
		adj[b].eb(a,c);
		D[c].unite(a,b);
	}
	
	ll res = -n;
	FOR(i,0,n) {
		res += D[0].size(i) * D[1].size(i);
	}
	cout << res << endl;
}