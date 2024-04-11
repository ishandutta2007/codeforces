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
	
	ll n, k, m; cin >> n >> k >> m;
	n++;
	vvl adj(n,vl(n));
	vl a(n);
	FOR(i,1,n) cin >> a[i];
	FOR(i,0,n) FOR(j,0,n) adj[i][j] = a[j];
	FOR(i,0,m) {
		ll x, y, c; cin >> x >> y >> c;
		adj[x][y] += c;
	}
	
	ll res = 0;
	vvl dp(1 << n,vl(n,-1));
	dp[1][0] = 0;
	FOR(mask,1,1 << n) FOR(i,0,n) if (dp[mask][i] >= 0) {
		FOR(j,0,n) if (!(mask & (1 << j))) {
			dp[mask | (1 << j)][j] =
				max(dp[mask | (1 << j)][j], dp[mask][i] + adj[i][j]);
		}
	}
	//FOR(j,0,n) FOR(mask,0,1 << n) cerr << dp[mask][j] << " \n"[mask+1 == 1 << n];
	FOR(mask,0,1 << n) if (__builtin_popcount(mask) == k+1)
		FOR(j,0,n) res = max(res, dp[mask][j]);
	cout << res << endl;

}