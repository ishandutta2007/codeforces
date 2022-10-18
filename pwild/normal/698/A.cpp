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
	vvl dp(n+1,vl(3,-oo));
	dp[0][0] = 0;
	FOR(i,0,n) {
		dp[i+1][0] = max(dp[i][0],max(dp[i][1],dp[i][2]));
		FOR(b,1,3) if (b & a[i]) {
			FOR(j,0,3) if (j != b) dp[i+1][b] = max(dp[i+1][b],dp[i][j]+1);
		}
	}
	cout << n - max(dp[n][0],max(dp[n][1],dp[n][2])) << endl;

}