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
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	vvl dp(4,vl(n+1,-oo));
	dp[0][0] = 0;
	
	vector<vb> up(4,vb(n+1));

	FOR(i,0,4) FOR(j,0,n+1) {
		if (j) dp[i][j] = max(dp[i][j],dp[i][j-1] + (i%2 ? -1 : 1) * a[j-1]);
		else up[i][j] = true;
		if (i) {
			if (dp[i-1][j] > dp[i][j]) {
				dp[i][j] = dp[i-1][j];
				up[i][j] = true;
			}
		} 
	}
	
	ll i = 3, j = n;
	vl res;
	while (i > 0 || j > 0) {
		if (up[i][j]) res.pb(j), i--;
		else j--;
	}
	cout << res[2] << " " << res[1] << " " << res[0] << endl;
}