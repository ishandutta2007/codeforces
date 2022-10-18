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

ll exp_mod(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n%2) res = res*a % MOD;
		a = a*a % MOD;
		n /= 2;
	}
	return res;
}

ll inv_mod(ll a) { return exp_mod(a,MOD-2); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;

	vvl a(n);
	ll m = 1e6 + 10;
	vl cnt(m);

	FOR(i,0,n) {
		ll k; cin >> k;
		a[i].resize(k);
		FOR(j,0,k) {
			cin >> a[i][j];
			cnt[a[i][j]]++;
		}
	}
	
	ll res = 0;
	FOR(i,0,n) for (ll x: a[i]) {
		res = (res + cnt[x] * inv_mod(n*sz(a[i]) % MOD * n % MOD)) % MOD;
	}
	cout << res << endl;
}