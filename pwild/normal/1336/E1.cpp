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

const ll MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;

	vl a(n);
	FOR(i,0,n) cin >> a[i];

	vl piv, ker;
	FOR(k,0,m) {
		ll r = sz(piv);

		FOR(i,r,n) if (a[i] & (1LL << k)) {
			swap(a[i],a[r]);
			break;
		}

		if (r < n && (a[r] & (1LL << k))) {
			piv.pb(k);
			FOR(i,0,n) if (i != r && (a[i] & (1LL << k))) a[i] ^= a[r];
		} else {
			ker.pb(k);
		}
	}

	ll r = sz(piv), k = sz(ker);

	vl res(m+1);

	if (sz(piv) <= m/2) {	
		FOR(mask,0,1 << r) {
			ll x = 0;
			FOR(i,0,r) if (mask & (1LL << i)) x ^= a[i];
			res[__builtin_popcountll(x)]++;
		}
	} else {
		vl b(r);
		FOR(i,0,r) for (ll j: ker) b[i] = 2*b[i] + !!(a[i] & (1LL << j));

		vvl dp(1 << k, vl(r+1));
		dp[0][0] = 1;

		FOR(i,0,r) {
			vvl ndp = dp;
			FOR(x,0,1 << k) FOR(j,0,r) ndp[x^b[i]][j+1] = (ndp[x^b[i]][j+1] + dp[x][j]) % MOD;
			dp = ndp;
		}

		FOR(x,0,1 << k) FOR(j,0,r+1) res[__builtin_popcountll(x) + j] += dp[x][j];
		FOR(i,0,m+1) res[i] %= MOD;
	}
	
	ll pw = 1;
	FOR(k,sz(piv),n) pw = 2*pw % MOD;

	FOR(i,0,m+1) res[i] = res[i]*pw % MOD;

	FOR(i,0,m+1) cout << res[i] << " \n"[i==m];
}