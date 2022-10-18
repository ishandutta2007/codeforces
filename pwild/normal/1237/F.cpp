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

const ll N = 4000,  MOD = 998244353;
ll inv[N], fac[N], inv_fac[N];

void precalc() {
	inv[1] = 1;
	FOR(n,2,N) inv[n] = (MOD - (MOD/n)*inv[MOD%n] % MOD) % MOD;

	fac[0] = 1;
	FOR(n,1,N) fac[n] = n*fac[n-1] % MOD;

	inv_fac[0] = 1;
	FOR(n,1,N) inv_fac[n] = inv[n]*inv_fac[n-1] % MOD;
}

ll binom(ll n, ll k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * inv_fac[k] % MOD * inv_fac[n-k] % MOD;
}

// number of ways to place k dominos in an interval of length n
ll interval_dominos(ll n, ll k) {
	return binom(n-k, k);
}

// calc(a)[k] = number of ways to place k dominos in the gaps
vl calc(vl a) {
	ll n = sz(a);
	vl v;
	FOR(i,0,n) if (!a[i] && (i == 0 || a[i-1])) {
		ll j = i;
		while (j < n && !a[j]) j++;
		v.pb(j-i);
	}
	
	vl dp(1,1);
	for (ll x: v) {
		vl ndp(sz(dp)+x/2);
		FOR(i,0,sz(dp)) FOR(j,0,x/2+1) {
			ndp[i+j] = (ndp[i+j] + dp[i] * interval_dominos(x,j)) % MOD;
		}
		dp = ndp;
	}
	return dp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	precalc();

	ll m, n, k;
	cin >> m >> n >> k;
	
	vl a(m), b(n);
	while (k--) {
		ll i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		i1--, j1--, i2--, j2--;
		a[i1] = a[i2] = 1;
		b[j1] = b[j2] = 1;
	}
	
	ll cnta = m - accumulate(all(a),0);
	ll cntb = n - accumulate(all(b),0);
	vl dpa = calc(a), dpb = calc(b);
	
	ll res = 0;
	FOR(i,0,max(m,n)) FOR(j,0,max(m,n)) {
		if (i >= sz(dpa)) continue;
		if (j >= sz(dpb)) continue;
		
		ll cur = dpa[i] * dpb[j] % MOD;
		cur = cur * binom(cnta-2*i,j) % MOD;
		cur = cur * binom(cntb-2*j,i) % MOD;
		cur = cur * fac[i] % MOD;
		cur = cur * fac[j] % MOD;

		res = (res + cur) % MOD;
	}
	cout << res << endl;
}