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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		vector<string> a(n);
		FOR(i,0,n) cin >> a[i];

		ll u = a[0][1], v = a[1][0];
		ll x = a[n-1][n-2], y = a[n-2][n-1];

		vector<pll> res;
		if (u == v) {
			if (x == u) res.eb(n-1,n-2);
			if (y == u) res.eb(n-2,n-1);
		} else if (x == y) {
			if (u == x) res.eb(0,1);
			if (v == x) res.eb(1,0);
		} else {
			res.eb(1,0);
			if (x == u) res.eb(n-1,n-2);
			if (y == u) res.eb(n-2,n-1);
		}
		
		cout << sz(res) << endl;
		for (auto [i,j]: res) cout << i+1 << " " << j+1 << endl;
	}
}