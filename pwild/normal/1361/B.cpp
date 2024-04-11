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

const ll M = 1e6 + 10, MOD = 1e9 + 7;

ll exp_mod(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n%2) res = res*a % MOD;
		a = a*a % MOD;
		n /= 2;
	}
	return res;
}

bool exp_ok(ll a, ll n) {
	if (a == 1) return true;
	ll res = 1;
	FOR(k,0,n) {
		res *= a;
		if (res > M) return false;
	}
	return true;
}

ll solve() {
	ll n, p;
	cin >> n >> p;
	
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a), greater<ll>());

	ll x = 0, prv = M;
	bool large = false;
	for (ll cur: a) {
		ll y = exp_mod(p, prv-cur);

		if (large) {
			x = (x*y + MOD-1) % MOD;
		} else if (x == 0) {
			x = 1;
		} else if (exp_ok(p, prv-cur) && x*y <= M) {
			x = x*y - 1;
		} else {
			large = true;
			x = (x*y + MOD-1) % MOD;
		}
		prv = cur;
	}
	x = x * exp_mod(p, prv) % MOD;
	if (x < 0) x += MOD;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << solve() << endl;
}