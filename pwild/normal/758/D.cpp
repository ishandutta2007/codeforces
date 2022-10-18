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

const ll N = 100, M = ll(1e18) + 10;
ll val[N][N];
ll dp[N][N];

ll b, n;
string a;

ll rec(ll k, ll i) {
	if (k == 0) return dp[k][i];
	
	if (dp[k][i] != -1) return dp[k][i];
	
	dp[k][i] = M;
	FOR(j,i+1,n+1) if (val[i][j] != -1) {
		ll x = rec(k-1, j);
		if (x == M) continue;
		double cur = val[i][j] * pow(b,k-1) + x;
		if (cur > M) continue;

		ll y = val[i][j];
		FOR(t,0,k-1) y *= b;
		y += x;
		dp[k][i] = min(dp[k][i], y);
	}
	return dp[k][i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> b >> a;
	n = sz(a);
	
	memset(val,-1,sizeof val);
	FOR(i,0,n) FOR(j,i+1,n+1) {
		if (a[i] == '0') {
			if (j == i+1) val[i][j] = 0;
		} else {
			ll x = 0;
			FOR(k,i,j) {
				x = 10*x + a[k]-'0';
				if (x >= b) break;
			}
			if (x < b) val[i][j] = x;
		}
	}
	
	memset(dp,-1,sizeof dp);
	
	dp[0][n] = 0;
	FOR(k,1,n) dp[k][n] = M;
	FOR(i,0,n) dp[0][i] = M;

	ll K = 1, q = M;
	while (q > 1) K++, q /= b;
	
	ll res = M;
	FOR(k,1,K+1) res = min(res,rec(k,0));
	cout << res << endl;

}