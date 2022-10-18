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

	vl t(k);
	FOR(i,0,k) cin >> t[i];
	sort(all(t));

	ll N = n*(k+1);

	vl dp(N+1,oo);
	dp[0] = 0;
	
	FOR(i,0,n) {
		vl ndp(N+1,oo);
			
		FOR(j,0,N+1) if (dp[j] < oo) {
			ll ct = 0;
			FOR(jj,0,k) {
				ndp[j+jj] = min(ndp[j+jj], dp[j] + ct);
				ct += t[jj];
			}
			ndp[j+k+1] = min(ndp[j+k+1], dp[j] + ct);
		}
		
		dp = ndp;
	}
	
	ll res = 0;
	FOR(i,0,N+1) if (dp[i] <= m) res = i;
	cout << res << endl;
}