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

const ll N = 1e6 + 10, MOD = 998244353;
ll dp[N][2];

ll height(ll n) {
	return 32 - __builtin_clz(n);
}

ll rec(ll n, bool s) {
	if (dp[n][s] != -1) return dp[n][s];
	
	ll res = 0;
	FOR(a,1,n-1) {
		ll b = n-1-a;
		if (height(a) != height(b)) continue;
		assert(height(a) == height(n)-1);
		res = (res + rec(a,!s)*rec(b,1)) % MOD;
	}
	return dp[n][s] = res;
}

ll f(ll n) {
	return rec(n,0) + rec(n,1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dp,-1,sizeof dp);
	dp[1][0] = 1, dp[1][1] = 0;
	dp[2][0] = 0, dp[2][1] = 1;
	dp[3][0] = 0, dp[3][1] = 0;
	dp[4][0] = 0, dp[4][1] = 1;

	//FOR(n,1,1000) if (f(n)) cout << n << " " << f(n) << endl;

	set<ll> s;
	ll a = 1, b = 2;
	
	while (a < 2e6) {
		s.insert(a);
		s.insert(b);
		ll c = 2*b, d = c+1;
		s.insert(c);
		s.insert(d);
		a = 2*c+1, b = a+1;
	}
	
	//for (ll x: s) cout << x << endl;
	
	ll n; cin >> n;
	cout << s.count(n) << endl;
}