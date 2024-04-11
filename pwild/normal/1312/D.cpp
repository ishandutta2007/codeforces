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

const ll N = 4e5 + 10, MOD = 998244353;
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

ll power(ll a, ll n) {
	ll res = 1;
	while (n--) res = res*a % MOD;
	return res;
}

ll solve(ll n, ll m) {
	if (n == 2) return 0;
	ll q = power(2,n-3);
	ll res = (n-2)*q % MOD;
	res = res * binom(m,n-1) % MOD;
	return res;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	precalc();

	ll n, m;
	cin >> n >> m;
	
	cout << solve(n,m) << endl;
}