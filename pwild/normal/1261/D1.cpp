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

ll exp_mod(ll a, ll n) {
	ll res = 1;
	for (; n; n /= 2) {
		if (n%2) res = res*a % MOD;
		a = a*a % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	precalc();

	ll n, k;
	cin >> n >> k;

	vl a(n);
	FOR(i,0,n) cin >> a[i];
	ll d = 0;
	FOR(i,0,n) d += a[i] != a[(i+1)%n];
	
	ll same = 0;
	FOR(m,0,d/2+1) {
		ll cur = binom(d,m) * binom(d-m,m) % MOD;
		cur = cur * exp_mod(k-2,d-2*m) % MOD;
		cur = cur * exp_mod(k,n-d) % MOD;
		same = (same + cur) % MOD;
	}
	
	ll res = (exp_mod(k,n) - same) * exp_mod(2,MOD-2) % MOD;
	if (res < 0) res += MOD;
	cout << res << endl;
}