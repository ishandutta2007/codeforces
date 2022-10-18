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

vector<pll> factorize(ll b) {
	vector<pll> fac;
	for (ll p = 2; p*p <= b; p++) if (b%p == 0) {
		ll e = 0;
		while (b%p == 0) b /= p, e++;
		fac.eb(p,e);
	}
	if (b > 1) fac.eb(b,1);
	return fac;
}

ll solve(ll a, ll b) {
	if (a%b != 0) return a;

	auto fac = factorize(b);

	ll res = 1;
	for (auto [p,e]: fac) {
		ll cur = a;
		while (cur%b == 0) cur /= p;
		assert(a%cur == 0);
		res = max(res,cur);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tc; cin >> tc;
	while (tc--) {
		ll p, q;
		cin >> p >> q;
		cout << solve(p,q) << endl;
	}
}