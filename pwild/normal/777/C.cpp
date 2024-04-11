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
	
	ll m, n; cin >> m >> n;
	vvl a(m, vl(n));
	FOR(i,0,m) FOR(j,0,n) cin >> a[i][j];
	
	vvl dp(m,vl(n));
	FOR(i,0,m) FOR(j,0,n) {
		dp[i][j] = 1;
		if (i > 0 && a[i-1][j] <= a[i][j]) dp[i][j] = dp[i-1][j]+1;
	}
	
	vl best(m);
	FOR(i,0,m) FOR(j,0,n) best[i] = max(best[i],dp[i][j]);

	ll q; cin >> q;
	while (q--) {
		ll l, r; cin >> l >> r;
		l--, r--;
		bool res = best[r] >= r-l+1;
		cout << (res ? "Yes\n" : "No\n");
	}
}