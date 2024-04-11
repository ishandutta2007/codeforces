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

const ll MOD = 1e9 + 7, N = 2e6 + 100;
ll pf[N], inv[N], fac[N], invfac[N];

ll f(ll r, ll a) {
	if (r == 0) {
		return a > 0 ? 2 : 1;
	}
	
	ll res = (2*a + r) * fac[r+a-1] % MOD;
	res = res * invfac[r] % MOD;
	res = res * invfac[a] % MOD;
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
	
	iota(pf,pf+N,0);
	FOR(i,2,N) if (pf[i] == i) {
		for (ll j = i*i; j < N; j += i) pf[j] = min(pf[j],i);
	}

	ll q; cin >> q;
	while (q--) {
		ll r, n; cin >> r >> n;
		
		ll res = 1;
		while (n > 1) {
			ll p = pf[n], a = 0;
			while (n % p == 0) n /= p, a++;
			res = res * f(r,a) % MOD;
		}
		cout << res << "\n";
	}

}