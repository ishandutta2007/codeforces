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

bool is_ok(ll x) {
	return __builtin_popcount(x+1) == 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll x; cin >> x;
	
	ll res = 0;
	vl ans;

	while (!is_ok(x)) {
		ll j = -1;
		FOR(i,0,25) if ((1 << i) <= x && (x & (1 << i)) == 0) j = i;
		assert(j != -1);
		ans.pb(j+1);
		res++;
		x ^= (1 << (j+1)) - 1;
		
		if (is_ok(x)) break;
		res++, x++;
	}
	
	cout << res << endl;
	if (!sz(ans)) return 0;
	for (ll x: ans) cout << x << " ";
	cout << endl;
}