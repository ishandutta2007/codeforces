#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

const ll K = 76, N = 20, MOD = 1e9 + 7;
ll dp[K][1 << N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	string a; cin >> a;
	
	ll res = 0;
	
	dp[0][0] = 1;
	FOR(i,1,n+1) {
		memset(dp[i],0,sizeof(dp[i]));
		dp[i][0] = 1;
		
		ll x = 0;
		FOR(len,1,i+1) {
			ll j = i-len;

			if (len > i) break;
			if (a[i-len] == '1') x += len < 10 ? 1 << (len-1) : 1000;
			//cerr << ii << " " << len << " " << x << endl;
			if (x > N) break;
			if (x == 0) continue;

			FOR(mask,0,1 << N) {
				ll nmask = mask | (1 << (x-1));
				dp[i][nmask] += dp[j][mask];
				if (dp[i][nmask] > MOD) dp[i][nmask] %= MOD;
			}
		}
		
		FOR(k,1,N) res = (res + dp[i][(1 << k) - 1]) % MOD;
	}

	cout << res << endl;
}