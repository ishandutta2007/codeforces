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

void self_max(ll &a, ll b) { a = max(a,b); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n, p;
	cin >> m >> n >> p;
	vl a(m), b(n), c(p);
	FOR(i,0,m) cin >> a[i];
	FOR(j,0,n) cin >> b[j];
	FOR(k,0,p) cin >> c[k];
	sort(all(a), greater<ll>());
	sort(all(b), greater<ll>());
	sort(all(c), greater<ll>());

	vector<vvl> dp(m+1, vvl(n+1, vl(p+1)));

	FOR(i,0,m+1) FOR(j,0,n+1) FOR(k,0,p+1) {
		if (i < m) self_max(dp[i+1][j][k], dp[i][j][k]);
		if (j < n) self_max(dp[i][j+1][k], dp[i][j][k]);
		if (k < p) self_max(dp[i][j][k+1], dp[i][j][k]);

		if (i < m && j < n) self_max(dp[i+1][j+1][k], dp[i][j][k] + a[i]*b[j]);
		if (i < m && k < p) self_max(dp[i+1][j][k+1], dp[i][j][k] + a[i]*c[k]);
		if (j < n && k < p) self_max(dp[i][j+1][k+1], dp[i][j][k] + b[j]*c[k]);
	}
	cout << dp[m][n][p] << endl;
}