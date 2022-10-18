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
	
	ll n, m, k; cin >> n >> m >> k;
	vl c(n);
	FOR(i,0,n) cin >> c[i], c[i]--;
	vvl p(n,vl(m));
	FOR(i,0,n) FOR(j,0,m) cin >> p[i][j];

	vector<vvl> dp(n+1,vvl(k+1,vl(m,oo)));
	
	if (c[0] < 0) {
		FOR(h,0,m) dp[1][1][h] = p[0][h];
	} else {
		dp[1][1][c[0]] = 0;
	}
	
	
	FOR(i,1,n) FOR(j,1,k+1) FOR(h,0,m) {
		if (dp[i][j][h] >= oo) continue;
		if (c[i] < 0) {
			FOR(h2,0,m) {
				if (j + (h != h2) > k) continue;
				dp[i+1][j + (h != h2)][h2] =
					min(dp[i+1][j + (h != h2)][h2],dp[i][j][h] + p[i][h2]);
			}
		} else {
			ll h2 = c[i];
			if (j + (h != h2) > k) continue;
			dp[i+1][j + (h != h2)][h2] =
				min(dp[i+1][j + (h != h2)][h2],dp[i][j][h]);
		}
	}
	ll res = oo;
	FOR(h,0,m) res = min(res,dp[n][k][h]);
	if (res == oo) res = -1;
	cout << res << endl;
}