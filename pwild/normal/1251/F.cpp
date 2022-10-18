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

const ll N = 2e6 + 10, MOD = 998244353, alpha = 3;
ll inv[N], fac[N], inv_fac[N], pow2[N];

void precalc() {
	pow2[0] = 1;
	FOR(n,1,N) pow2[n] = 2*pow2[n-1] % MOD;

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

ll exp_mod(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n&1) res = res*a % MOD;
		a = a*a % MOD;
		n /= 2;
	}
	return res;
}

ll inv_mod(ll a) { return exp_mod(a,MOD-2); }

vl ntt(vl v, ll p) {
	vl res = v;
	for (ll step = sz(v)/2; step; step /= 2) {
		ll n = sz(v)/step;
		ll wn = exp_mod(alpha,(MOD-1)/n), w = 1;
		if (p < 0) wn = inv_mod(wn);
		FOR(i,0,n/2) {
			FOR(j,0,step) {
				ll t = w * res[j + step*(2*i+1)] % MOD;
				v[j + step*i] = (res[j + step*2*i] + t) % MOD;
				v[j + step*(i+n/2)] = (res[j + step*2*i] - t) % MOD;
			}
			w = w*wn % MOD;
		}
		res = v;
	}
	ll Ni = inv_mod(sz(v));
	if (p < 0) for (ll &x: res) x = x*Ni % MOD;
	return res;
}

vl operator*(vl a, vl b) {
	ll n = 1;
	while (n < sz(a)+sz(b)) n *= 2;
	a.resize(n), b.resize(n);
	a = ntt(a,1), b = ntt(b,1);
	vl c(n);
	FOR(i,0,n) c[i] = a[i]*b[i] % MOD;
	c = ntt(c,-1);
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	precalc();

	ll n, k;
	cin >> n >> k;

	vl a(n), b(k);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,k) cin >> b[i];
	sort(all(a)), sort(all(b));
	
	vvl dp;
	for (ll h: b) {
		ll sing = 0, doub = 0;
		FOR(i,0,n) if (i == 0 || a[i] != a[i-1]) {
			if (a[i] >= h) break;
			if (i+1 < n && a[i+1] == a[i]) doub++;
			else sing++;
		}
		
		swap(sing,doub);
		vl p(2*sing+1), q(doub+1);
		FOR(i,0,2*sing+1) p[i] = binom(2*sing,i);
		FOR(i,0,doub+1) q[i] = binom(doub,i) * pow2[i] % MOD;
		
		dp.pb(p*q);
	}

	ll q; cin >> q;
	while (q--) {
		ll c; cin >> c;
		ll res = 0;
		FOR(i,0,k) {
			ll x = c/2 - b[i] - 1;
			if (x >= 0 && x < sz(dp[i])) res += dp[i][x];
		}
		res %= MOD;	
		if (res < 0) res += MOD;
		cout << res << endl;
	}
}