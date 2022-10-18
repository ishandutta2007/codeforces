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
#define DBGDO(X) ({ if(0) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll N = 200100, MOD = 1e9 + 7;
ll inv[N], fac[N], invfac[N];

ll b(ll n, ll k) {
	if (n < 0 || k > n) return 0;
	return fac[n] * invfac[k] % MOD * invfac[n-k] % MOD;
}

ll g(ll n, ll k, ll h) {
	h++;
	if (k == 0) return n == 0;
	n -= k*h;
	if (n < 0) return 0;
	return b(n+k-1,k-1);
}

ll calc(ll f, ll w, ll h) {
	ll res = 0;
	FOR(k,0,100010) {
		// fwfw
		ll same = g(f,k,0) * g(w,k,h);
		// wfwf
		if (k) res = (res + 2*same) % MOD;
		else res = (res + same) % MOD;
		// fwfwf
		res = (res + g(f,k+1,0) * g(w,k,h)) % MOD;
		// wfwfw
		res = (res + g(f,k,0) * g(w,k+1,h)) % MOD;
	}
	return res;
}

ll mod_exp(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) res = res * a % MOD;
		a = a * a % MOD;
		n /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	inv[1] = 1;
	FOR(n,2,N) inv[n] = (MOD - inv[MOD%n] * (MOD/n) % MOD) % MOD;

	fac[0] = 1;
	FOR(n,1,N) fac[n] = n*fac[n-1] % MOD;
	
	invfac[0] = 1;
	FOR(n,1,N) invfac[n] = inv[n] * invfac[n-1] % MOD;
	
	ll f, w, h; cin >> f >> w >> h;
	
	ll num = calc(f,w,h), denom = calc(f,w,0);
	if (!denom) {
		cout << 1 << endl;
		return 0;
	}
	DBGDO(num);
	DBGDO(denom);
	ll res = num * mod_exp(denom, MOD-2) % MOD;
	cout << res << endl;
}