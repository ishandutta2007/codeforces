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

ll lcm(ll a, ll b) { return a/__gcd(a,b)*b; }

ll solve() {
	ll n; cin >> n;
	vl d(n);
	FOR(i,0,n) cin >> d[i];

	ll m = 1, g = 0;
	for (ll x: d) {
		g = __gcd(g,x);
		m = lcm(m,x);
		if (m > 1e12) return -1;
	}
	if (g > 1) {
		sort(all(d));
		ll q = d[0];
		FOR(i,0,n) {
			if (d[i] != q) return -1;
			q *= d[0];
		}
		m = q;
	}

	vl e;
	for (ll k = 1; k*k <= m; k++) if (m%k == 0) {
		e.pb(k);
		if (k != m/k) e.pb(m/k);
	}

	d.pb(1), d.pb(m);

	sort(all(d)), sort(all(e));

	return d == e ? m : -1LL;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << solve() << endl;
}