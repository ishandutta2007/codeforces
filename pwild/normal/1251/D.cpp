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

ll solve() {
	ll n, s;
	cin >> n >> s;
	
	vl lo(n), hi(n);
	FOR(i,0,n) {
		cin >> lo[i] >> hi[i];
		s -= lo[i];
	}
	
	auto check = [&](ll x) {
		vl cost(n);
		FOR(i,0,n) {
			if (lo[i] >= x) cost[i] = 0;
			else if (hi[i] < x) cost[i] = oo;
			else cost[i] = x-lo[i];
		}
		sort(all(cost));
		ll rem = s;
		FOR(i,0,n/2+1) {
			rem -= cost[i];
			if (rem < 0) return false;
		}
		return true;
	};
	
	ll left = 0, right = 1e9 + 10;
	assert(check(left));
	assert(!check(right));
	while (right-left > 1) {
		ll mid = (left+right)/2;
		if (check(mid)) left = mid;
		else right = mid;
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << solve() << endl;
}