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

void self_max(ll &a, ll b) {
	a = max(a,b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k;
	cin >> n >> k;

	vl want(1 << n);
	while (k--) {
		ll x; cin >> x;
		want[x-1] = true;
	}
	
	vector<vector<vvl>> dp(n+1, vector<vvl>(1 << n, vvl(2, vl(2, -oo))));
	
	for (ll i = 0; i < (1 << n); i += 2) {
		FOR(a,0,2) FOR(b,0,2) if (a+b == want[i]+want[i+1]) {
			self_max(dp[1][i][a][b], a || b);
		}
	}
	
	FOR(k,2,n+1) for (ll i = 0; i < (1 << n); i += (1 << k)) {
		ll j = i + (1 << (k-1));
		FOR(a,0,2) FOR(b,0,2) if (dp[k-1][i][a][b] >= 0) {
			FOR(c,0,2) FOR(d,0,2) if (dp[k-1][j][c][d] >= 0) {
				bool wb = a || c, lb = b || d, lb2 = (a && c) || lb;
				ll cur = wb + lb + lb2 + dp[k-1][i][a][b] + dp[k-1][j][c][d];
				self_max(dp[k][i][wb][lb], cur);
			}
		}
	}

	ll res = 0;
	FOR(a,0,2) FOR(b,0,2) res = max(res, dp[n][0][a][b] + (a || b));
	cout << res << endl;
}