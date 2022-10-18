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
	
	ll n, m;
	cin >> n >> m;
	
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	auto ok = [&](ll k) {
		ll bmin = 0;
		for (ll x: a) {
			ll dist = bmin-x;
			if (dist < 0) dist += m;
			if (dist <= k) continue;
			if (x < bmin) return false;
			bmin = x;
		}
		return true;
	};

	ll rmin = -1, rmax = m;
	while (rmax-rmin > 1) {
		ll r = (rmin+rmax)/2;
		if (ok(r)) rmax = r; else rmin = r;
	}
	cout << rmax << endl;
}