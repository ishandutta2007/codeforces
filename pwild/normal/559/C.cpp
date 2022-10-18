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

const ll MOD = 1e9 + 7, M = 300000;

ll modExp(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n % 2) res = res*a % MOD;
		a = a*a % MOD;
		n /= 2;
	}
	return res;
}

ll modInv(ll a) {
	return modExp(a, MOD-2);
}

ll f[M], fi[M];

ll c(ll n, ll k) {
	if (k < 0 || k > n) return 0;
	return f[n]*fi[k] % MOD * fi[n-k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	f[0] = fi[0] = 1;
	FOR(i,1,M) f[i] = i*f[i-1] % MOD, fi[i] = modInv(f[i]);

	ll h, w, n; cin >> h >> w >> n;
	vector<pll> p(n);
	FOR(i,0,n) cin >> p[i].xx >> p[i].yy, p[i].xx--, p[i].yy--;
	p.eb(h-1,w-1);
	sort(all(p));
	

	vl dp(n+1);
	FOR(i,0,n+1) {
		dp[i] = c(p[i].xx+p[i].yy,p[i].xx);
		FOR(j,0,i) dp[i] = (dp[i] - dp[j]*c(p[i].xx-p[j].xx+p[i].yy-p[j].yy,p[i].xx-p[j].xx)) % MOD;
		if (dp[i] < 0) dp[i] += MOD;
	}	
	cout << dp[n] << endl;	


}