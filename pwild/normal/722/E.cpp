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

const ll N = 100100, MOD = 1e9 + 7;

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

ll f[2*N+1], fi[2*N+1];

ll ch(ll k1, ll k2) {
	ll n = k1+k2, k = k1;
	if (k < 0 || k > n) return 0;
	return f[n]*fi[k] % MOD * fi[n-k] % MOD;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	f[0] = fi[0] = 1;
	FOR(i,1,2*N+1) f[i] = i*f[i-1] % MOD, fi[i] = modInv(f[i]);

	ll r, c, k, s;
	cin >> r >> c >> k >> s;
	
	vector<pll> p(k);
	FOR(i,0,k) cin >> p[i].xx >> p[i].yy, p[i].xx--, p[i].yy--;
	sort(all(p));
	/*if (find(all(p),pll(r-1,c-1)) == end(p))*/ p.eb(r-1,c-1);
	
	ll n = sz(p), h = 22;

	vvl dp(n,vl(h));
	FOR(i,0,n) FOR(j,0,h) {
		dp[i][j] = ch(p[i].xx,p[i].yy);
		FOR(jj,0,j) dp[i][j] = (dp[i][j] - dp[i][jj]) % MOD;
		if (j == h-1) break;
		
		FOR(ii,0,i) dp[i][j] = (dp[i][j] - dp[ii][j]*ch(p[i].xx-p[ii].xx,p[i].yy-p[ii].yy)) % MOD;
	}	
	
	ll res = 0;
	FOR(j,0,h) {
		res = (res + s*dp[n-1][j]) % MOD;
		s = (s+1)/2;
	}
	res = res * modInv(ch(r-1,c-1)) % MOD;
	if (res < 0) res += MOD;
	cout << res << endl;	
}