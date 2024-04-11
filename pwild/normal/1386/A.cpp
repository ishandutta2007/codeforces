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

bool query(ll x) {
	cout << "? " << x << endl;
	cin >> x;
	return x;
}

//       0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6  7  8  9  0  1  2  3  4
vl dp = {0,0,1,2,2,2,2,3,3,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,9,9,10,10,10,10,11,11,12,12};
ll start_index(ll n) {
	if (n < 4) return dp[n];
	ll m = (n+1)/2;
	return m+1 - start_index(m);
}

void solve() {
	ll n; cin >> n;
	
	ll prev = start_index(n), sign = 1, lo = 0, hi = n;
	query(prev);
	while (hi-lo > 1) {
		ll mid = (lo+hi)/2;
		ll cur = prev + sign*mid;

		if (query(cur)) hi = mid;
		else lo = mid;
		
		prev = cur;
		sign = -sign;
	}
	cout << "= " << hi << endl;
}

int main() {
	FOR(n,2,sz(dp)) assert(start_index(n) == dp[n]);

	ll tc; cin >> tc;
	while (tc--) solve();
}