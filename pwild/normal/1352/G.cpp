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

bool check(vl p) {
	FOR(i,0,sz(p)-1) {
		ll d = abs(p[i]-p[i+1]);
		if (d < 2 || d > 4) return false;
	}
	return true;
}

vl solve(ll n) {
	if (n < 4) return {-1};
	if (n == 4) return {2,4,1,3};
	if (n == 5) return {1,3,5,2,4};

	vl mid = n%2 ? vl{6,2,4,1,3,5,7} : vl{5,2,4,1,3,6};
	
	vl res;
	for (ll x = n-1; x > 5+n%2; x -= 2) res.pb(x);
	for (ll x: mid) res.pb(x);
	for (ll x = 8+n%2; x <= n; x += 2) res.pb(x);
	return res;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		vl res = solve(n);
		for (ll x: res) cout << x << " ";
		cout << endl;
	}
}