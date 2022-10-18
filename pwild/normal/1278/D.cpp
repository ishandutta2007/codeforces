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

bool solve() {
	ll n; cin >> n;
	
	vl a(2*n);
	vl from(n), to(n);
	FOR(k,0,n) {
		ll i, j;
		cin >> i >> j;
		i--, j--;
		a[i] = k, a[j] = ~k;
		from[k] = i, to[k] = j;
	}

	dsu D(n);
	map<ll,ll> active;
	
	FOR(i,0,2*n) {
		if (a[i] >= 0) {
			active[i] = a[i];
		} else {
			ll k = ~a[i];
			auto it = active.find(from[k]);
			assert(it != end(active));
			assert(it->yy == k);
			for ( it++; it != end(active); it++) {
				if (!D.unite(k, it->yy)) return false;
			}
			active.erase(from[k]);
		}
	}
	
	FOR(i,1,n) if (D.find(i) != D.find(0)) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << (solve() ? "YES" : "NO") << endl;
}