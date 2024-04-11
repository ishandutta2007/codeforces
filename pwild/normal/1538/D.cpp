#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

ll f(ll n) {
	ll res = 0;
	for (ll k = 2; k*k <= n; k++) {
		while (n%k == 0) n /= k, res++;
	}
	res += n > 1;
	return res;
}

ll solve(ll a, ll b, ll k) {
	if (a > b) swap(a,b);
	if (k == 1) return b > a && b%a == 0;
	return k <= f(a) + f(b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tc; cin >> tc;
	while (tc--) {
		ll a, b, k;
		cin >> a >> b >> k;
		cout << (solve(a,b,k) ? "Yes" : "No") << endl;
	}
}