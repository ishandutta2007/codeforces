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

const ll MOD = 1000000007;

ll phi(ll n) {
	vector<pll> pf;
	for (ll k = 2; k*k <= n; k++) if (n % k == 0) {
		ll deg = 0;
		while (n % k == 0) deg++, n /= k;
		pf.eb(k,deg);
	}
	if (n > 1) pf.eb(n,1);
	
	ll res = 1;
	for (pll p: pf) {
		res *= (p.xx-1);
		FOR(i,1,p.yy) res *= p.xx;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;
	k = (k+1)/2;
	
	while (k--) {
		if (n == 1) break;
		n = phi(n);
	}
	cout << (n % MOD) << endl;
}