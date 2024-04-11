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

ll lis(vl a) {
	vl dp = {-oo};
	for (ll x: a) {
		ll k = upper_bound(all(dp),x) - begin(dp);
		if (k == sz(dp)) dp.pb(x);
		else dp[k] = min(dp[k],x);
	}
	return sz(dp)-1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll k[3];
	FOR(i,0,3) cin >> k[i];

	ll n = k[0] + k[1] + k[2];
	vl a(n);
	FOR(j,0,3) while (k[j]--) {
		ll x; cin >> x;
		a[x-1] = j;
	}
	
	cout << n - lis(a) << endl;

}