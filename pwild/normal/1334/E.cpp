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

const ll N = 100, MOD = 998244353;
ll inv[N], fac[N], inv_fac[N];

void precalc() {
	inv[1] = 1;
	FOR(n,2,N) inv[n] = (MOD - (MOD/n)*inv[MOD%n] % MOD) % MOD;

	fac[0] = 1;
	FOR(n,1,N) fac[n] = n*fac[n-1] % MOD;

	inv_fac[0] = 1;
	FOR(n,1,N) inv_fac[n] = inv[n]*inv_fac[n-1] % MOD;
}

ll multinomial(const vl &a) {
	ll res = fac[accumulate(all(a),0LL)];
	for (ll x: a) res = res * inv_fac[x] % MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	precalc();

	ll n; cin >> n;
	vl p, a;

	for (ll i = 2; i*i <= n; i++) if (n%i == 0) {
		ll k = 0;
		while (n%i == 0) n /= i, k++;
		p.pb(i), a.pb(k);
	}
	if (n > 1) p.pb(n), a.pb(1);
	ll m = sz(p);

	ll q; cin >> q;
	while (q--) {
		ll u, v;
		cin >> u >> v;

		vl s, t;
		FOR(i,0,m) {
			ll b = 0, c = 0;
			while (u%p[i] == 0) u /= p[i], b++;
			while (v%p[i] == 0) v /= p[i], c++;
			
			if (b < c) s.pb(c-b); else t.pb(b-c);
		}
		
		ll res = multinomial(s) * multinomial(t) % MOD;
		if (res < 0) res += MOD;
		cout << res << '\n';
	}
}