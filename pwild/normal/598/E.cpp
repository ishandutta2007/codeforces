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

const ll N = 30, K = 50;
ll dp[N+1][N+1][K+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp,0x3f,sizeof(dp));

	dp[1][1][1] = 0;
	FOR(m,1,N+1) FOR(n,1,N+1) FOR(k,0,K+1) {
		if (k > m*n) continue;
		if (k == 0 || k == m*n) {
			dp[m][n][k] = 0;
			continue;
		}
		dp[m][n][k] = oo;
		FOR(m1,1,m) FOR(k1,0,k+1) {
			ll m2 = m-m1, k2 = k-k1;
			dp[m][n][k] = min(dp[m][n][k],dp[m1][n][k1]+dp[m2][n][k2]+n*n);		
		}
		FOR(n1,1,n) FOR(k1,0,k+1) {
			ll n2 = n-n1, k2 = k-k1;
			dp[m][n][k] = min(dp[m][n][k],dp[m][n1][k1]+dp[m][n2][k2]+m*m);		
		}
	}

	ll t; cin >> t;
	while (t--) {
		ll n, m, k; cin >> m >> n >> k;
		cout << dp[m][n][k] << endl;

	}

}