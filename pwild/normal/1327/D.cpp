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
	vl p(n), c(n);
	FOR(i,0,n) cin >> p[i], p[i]--;
	FOR(i,0,n) cin >> c[i];
	
	vl mark(n);
	ll res = oo;
	FOR(i,0,n) if (!mark[i]) {
		vl cyc;
		for (ll j = i; !mark[j]; j = p[j]) {
			cyc.pb(j), mark[j] = 1;
		}
	
		ll k = sz(cyc);
		for (ll d = 1; d <= k; d++) if (k%d == 0) {
			if (d >= res) continue;
			
			FOR(i,0,d) {
				bool ok = true;
				for (ll j = 1; j < k/d; j++) {
					ll a = cyc[i], b = cyc[j*d+i];
					if (c[a] != c[b]) ok = false;
					if (!ok) break;
				}
				if (ok) res = min(res, d);
			}
		}
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}