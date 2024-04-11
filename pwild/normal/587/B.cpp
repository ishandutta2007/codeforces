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

const ll MOD = 1e9 + 7;

ll compress(vl &a) {
	ll n = sz(a);
	set<ll> as;
	FOR(i,0,n) as.insert(a[i]);
	ll R = 0;
	map<ll,ll> rk;
	for (ll x: as) rk[x] = R++;
	FOR(i,0,n) a[i] = rk[a[i]];
	return R;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, l, k; cin >> n >> l >> k;
	vl a(n); FOR(i,0,n) cin >> a[i];

	ll R = compress(a);

	if (l < n) {
		cout << l << endl;
		return 0;
	}

	ll N = k*n;
	vl b(N), dp(N);
	
	vl cnt(R);
	FOR(i,0,n) cnt[a[i]]++;
	FOR(i,0,n) dp[i] = 1;
	FOR(j,1,k) {
		FOR(i,0,R-1) cnt[i+1] = (cnt[i+1] + cnt[i]) % MOD;
		vl ncnt(R);
		FOR(i,j*n,(j+1)*n) {
			b[i] = a[i%n];
			dp[i] = (cnt[b[i]] + 0) % MOD;
			ncnt[b[i]] = (ncnt[b[i]] + dp[i]) % MOD;
		}
		cnt = ncnt;
	}
	
	ll res = 0;

	ll reps = l/n;
	FOR(j,0,k) {
		if (reps < 0) break;
		FOR(i,j*n,(j+1)*n) {
			res = (res + dp[i] * (reps % MOD)) % MOD;
		}
		reps--;
	}
	
	FOR(j,0,k) {
		FOR(i,j*n,j*n + l%n) {
			if (i < l) res = (res + dp[i]) % MOD;
		}
	}
	
	if (res < 0) res += MOD;
	cout << res << endl;

}