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

const ll MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s, t;
	cin >> s >> t;
	
	ll n = sz(s), m = sz(t);

	vl dp(n+1,1);
	ll res = 0;
	FOR(k,0,n) {
		vl ndp(n-k);
		FOR(i,0,n-k) {
			if (i >= m || t[i] == s[k]) {
				ndp[i] = (ndp[i] + dp[i+1]) % MOD;
			}
			if (i+k >= m || t[i+k] == s[k]) {
				ndp[i] = (ndp[i] + dp[i]) % MOD;
			}
		}
		dp = ndp;
		if (k+1 >= m) res = (res + dp[0]) % MOD;
	}
	cout << res << endl;
}