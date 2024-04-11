#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f;
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

const ll maxN = 5010;
vector<pll> adj[maxN];
ll dp[maxN][maxN], p[maxN][maxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, T; cin >> n >> m >> T;
	while (m--) {
		ll u, v, t; cin >> u >> v >> t;
		u--, v--;
		adj[u].eb(v,t);
	}
	
	ll ans = -oo;
	memset(dp,0x3f,sizeof dp);
	dp[0][0] = 0;
	FOR(k,0,n) {
		FOR(i,0,n) if (dp[k][i] < oo) {
			for (const auto &e: adj[i]) {
				if (dp[k][i] + e.yy < dp[k+1][e.xx]) {
					dp[k+1][e.xx] = dp[k][i] + e.yy, p[k+1][e.xx] = i;
				}
			}
		}
		if (dp[k+1][n-1] <= T) ans = k+1;
	}
	
	cout << ans+1 << endl;
	vl res;
	ll i = n-1;
	FORD(k,0,ans+1) {
		res.pb(i);
		i = p[k][i];
	}
	reverse(all(res));
	FOR(i,0,ans+1) cout << res[i]+1 << " \n"[i==ans];
}