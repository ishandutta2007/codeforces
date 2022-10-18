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

ll popc(ll mask) { return __builtin_popcount(mask); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, foo;
	cin >> n >> foo >> foo;

	vector<pll> a(n), ev;
	FOR(i,0,n) {
		ll x, y;
		cin >> x >> y;
		x--;
		a[i] = {x,y};
		ev.eb(x,i);
		ev.eb(y,~i);
	}
	sort(all(ev));
	
	vl active, dp = {0};
	ll px = -1;
	for (auto [x,i]: ev) {
		ll m = sz(active);
		FOR(mask,0,1 << m) if (popc(mask) % 2) dp[mask] += x-px;
		px = x;
//		for (ll x: dp) cerr << x << " ";
//		cerr << endl;

		if (i >= 0) {
			active.pb(i);
			FOR(mask,0,1 << m) dp.pb(dp[mask]);
		} else {
			i = ~i;
			ll k = find(all(active), i) - begin(active);
			vl ndp(1 << (m-1), -oo);
			FOR(mask,0,1 << m) {
				ll mask1 = mask & ((1 << k) - 1);
				ll mask2 = (mask >> (k+1)) << k;
				ll nmask = mask1 | mask2;
				ndp[nmask] = max(ndp[nmask], dp[mask]);
			}
			active.erase(begin(active) + k);
			dp = ndp;
		}
//		for (ll x: dp) cerr << x << " ";
//		cerr << endl;
	}

	cout << dp[0] << endl;
}