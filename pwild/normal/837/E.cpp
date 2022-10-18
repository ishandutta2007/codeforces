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

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a%b); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll x, y; cin >> x >> y;
	
	ll res = 0;
	while (true) {
		ll g = gcd(x,y);
		x /= g, y /= g;
		
		if (x == 1) {
			res += y;
			break;
		}
		
		// gcd(x,y-k) > 1
		ll z = 0;
		auto foo = [&](ll d) {
			if (d == 1) return;
			z = max(z,(y/d)*d);
		};

		for (ll d = 1; d*d <= x; d++) if (x % d == 0) {
			foo(d), foo(x/d);
		}
		res += y-z;
		y = z;
	}
	cout << res << endl;
}