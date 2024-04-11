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
	ll n; cin >> n;
	ll m = n;
	vector<pll> fac;
	for (ll p = 2; p*p <= n; p++) if (n%p == 0) {
		ll e = 0;
		while (n%p == 0) n /= p, e++;
		fac.eb(p,e);
	}
	if (n > 1) fac.eb(n,1);
	n = m;

	set<ll> divs;
	for (ll k = 1; k*k <= n; k++) if (n%k == 0) {
		divs.insert(k), divs.insert(n/k);
	}
	divs.erase(1);

	ll ans = 0;
	vl res;
	auto add_multiples = [&](ll p) {
		vl add;
		for (ll x: divs) if (x%p == 0) add.pb(x);
		for (ll x: add) divs.erase(x), res.pb(x);
	};

	if (sz(fac) == 2) {
		if (fac[0].yy == 1 && fac[1].yy == 1) {
			ans = 1;
			res = vl(all(divs));
			divs.clear();
		} else {
			if (fac[0].yy == 1) swap(fac[0],fac[1]);
			ll p = fac[0].xx, q = fac[1].xx;
			divs.erase(p), divs.erase(q), divs.erase(p*q), divs.erase(p*p*q);
			res.pb(p);
			add_multiples(p);
			res.pb(p*q);
			res.pb(q);
			add_multiples(q);
			res.pb(p*p*q);
		}
	} else {
		vl ps;
		for (auto [p,e]: fac) ps.pb(p);
		ps.pb(fac[0].xx);
		FOR(i,0,sz(fac)) {
			ll p = ps[i], q = ps[i+1];
			divs.erase(p), divs.erase(p*q);
		}
		
		FOR(i,0,sz(fac)) {
			ll p = ps[i], q = ps[i+1];
			res.pb(p);
			add_multiples(p);
			res.pb(p*q);
		}
	}

	assert(divs.empty());
	for (ll x: res) cout << x << " ";
	cout << endl << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}