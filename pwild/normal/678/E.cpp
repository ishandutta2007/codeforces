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
	vector<vector<double>> p(n,vector<double>(n));
	FOR(i,0,n) FOR(j,0,n) cin >> p[i][j];
	
	vector<vector<double>> dp(1 << n,vector<double>(n));
	
	FOR(mask,0,1 << n) FOR(i,0,n) if (mask & (1 << i)) {
		if (__builtin_popcount(mask) == 1) {
			if (i == 0) dp[mask][i] = 1;
			else dp[mask][i] = 0;
		} else {
			dp[mask][i] = 0;
			FOR(j,0,n) if ((mask & (1 << j)) && j != i) {
				dp[mask][i] = max(dp[mask][i],
					p[i][j]*dp[mask ^ (1 << j)][i] + p[j][i]*dp[mask ^ (1 << i)][j]);
			}
		}
	}
	
	double res = 0;
	FOR(i,0,n) res = max(res,dp[(1 << n) - 1][i]);
	cout << fixed << setprecision(12) << res << endl;



}