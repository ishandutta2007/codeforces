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
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

const ll N = 2e5 + 10, MOD = 998244353;
ll dp[N][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k;
	cin >> n >> k;

	dp[0][0] = 1;
	dp[1][1] = 1;
	FOR(i,2,N) {
		dp[i][0] = (k-1)*dp[i-1][1] % MOD;
		dp[i][1] = ((k-2)*dp[i-1][1] + dp[i-1][0]) % MOD;
	}
	
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	ll res = 1;
	FOR(s,0,2) {
		vl b;
		for (ll i = s; i < n; i += 2) b.pb(a[i]);
		
		ll m = sz(b);
		
		if (b == vl(m,-1)) {
			res = k*res % MOD;
			FOR(i,1,m) res = (k-1)*res % MOD;
			continue;
		}
		
		ll i = 0;
		while (b[i] == -1) {
			res = (k-1)*res % MOD;
			i++;
		}
		
		while (true) {
			ll j = i+1;
			while (j < m && b[j] == -1) j++;

			if (j == m) {
				FOR(ii,i+1,m) res = (k-1)*res % MOD;
				break;
			}
			
			res = res * dp[j-i][ b[i] != b[j] ] % MOD;
			i = j;
		}
	}
	cout << res << endl;
}