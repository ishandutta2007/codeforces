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

bool is_prime(ll n) {
	for (ll i = 2; i*i <= n; i++) if (n%i == 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll N = 100;
	vl dp(N,-oo);
	dp[0] = 0;
	FOR(x,2,N) if (!is_prime(x)) {
		FOR(y,x,N) dp[y] = max(dp[y], dp[y-x]+1);
	}

	auto f = [&](ll x) {
		if (x < N) return dp[x];
		ll k = (x-N+10)/4;
		return k + dp[x-4*k];
	};


	ll q; cin >> q;
	while (q--) {
		ll x; cin >> x;
		ll res = f(x);
		if (res < 0) res = -1;
		cout << res << endl;
	}

}