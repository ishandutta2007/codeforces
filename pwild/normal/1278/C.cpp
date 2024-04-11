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
	vl a(n), b(n);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> b[i];
	reverse(all(b));
	
	vl dp(2*n+1,-oo);
	dp[n] = 0;
	ll dep = n;

	FOR(i,0,n) {
		dep += a[i] == 1 ? 1 : -1;
		dp[dep] = max(dp[dep], i+1);
	}
	
	ll res = dp[n];
	dep = n;
	FOR(i,0,n) {
		dep += b[i] == 2 ? 1 : -1;
		res = max(res, i+1+dp[dep]);
	}
	
	res = 2*n-res;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}