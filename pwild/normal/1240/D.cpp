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

const ll A[] = {234574354,455485345,529493967};
const ll MOD[] = {ll(1e9+7), ll(1e9+9), ll (1e9+123)};

const ll N = 3e5 + 10;
ll Apow[3][N];

typedef array<ll,3> hv;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	FOR(k,0,3) {
		Apow[k][0] = 1;
		FOR(i,1,N) Apow[k][i] = Apow[k][i-1] * A[k] % MOD[k];
	}

	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		vl a(n);
		FOR(i,0,n) cin >> a[i];

		hv h = {0,0,0};
		map<hv,ll> last_idx;
		last_idx[h] = 0;
		vl stk;

		vl jump(n,n+1);

		FOR(i,0,n) {
			ll depth = sz(stk), sign;
			if (depth && stk.back() == a[i]) {
				stk.pop_back();
				depth--, sign = -1;
			} else {
				stk.pb(a[i]);
				sign = 1;
			}
			FOR(k,0,3) {
				h[k] += sign * a[i] * Apow[k][depth];
				h[k] %= MOD[k];
				if (h[k] < 0) h[k] += MOD[k];
			}
			if (last_idx.count(h)) {
				jump[ last_idx[h] ] = i+1;
			}
			last_idx[h] = i+1;
		}
		
		vl dp(n+2);

		ll res = 0;
		FORD(i,0,n) if (jump[i] <= n) {
			dp[i] = 1 + dp[jump[i]];
			res += dp[i];
		}
		cout << res << endl;
	}
}