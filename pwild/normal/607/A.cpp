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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vector<pll> a(n);
	FOR(i,0,n) cin >> a[i].xx >> a[i].yy;
	sort(all(a));
	
	vl dp(n);
	ll res = n;
	FOR(i,0,n) {
		ll j = lower_bound(all(a),pll(a[i].xx-a[i].yy,0)) - begin(a);
		dp[i] = i-j;
		if (j > 0) dp[i] += dp[j-1];
		res = min(res,dp[i] + (n-i-1));
	}
	cout << res << endl;

}