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

const ll K = 60, MOD = 1e9 + 7;
ll p2[K+1];

void solve() {
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	vl prod(n,1);
	FOR(flip,0,2) {
		vl cnt(K);
		FOR(i,0,n) FOR(k,0,K) if (a[i] & (1LL << k)) cnt[k]++;
		
		FOR(j,0,n) {
			ll sum = 0;
			FOR(k,0,K) if (a[j] & (1LL << k)) {
				sum = (sum + cnt[k] * p2[k]) % MOD;
			}
			if (flip) sum = (n*(p2[K]-1) - sum) % MOD;
			prod[j] = prod[j] * sum % MOD;
		}
		
		FOR(i,0,n) a[i] = ((1LL << K) - 1) ^ a[i];
	}
	
	ll res = accumulate(all(prod),0LL) % MOD;
	if (res < 0) res += MOD;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	FOR(k,0,K+1) p2[k] = (1LL << k) % MOD;
	
	ll tc; cin >> tc;
	while (tc--) solve();
}