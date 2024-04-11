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

void cat(ll a) {
	vl d;
	for (ll i = 1; i*i <= a; i++) if (a % i == 0) d.pb(i), d.pb(a/i);
	vl d2;
	for (ll x: d) for (ll y: d) d2.pb(x*y);

	for (ll x: d2) {
		ll y = a*a/x;
		if (x % 2 != y % 2) continue;
		ll b = abs(x-y)/2, c = (x+y)/2;
		if (!b || !c) continue;
		assert(a*a + b*b == c*c);
		cout << b << " " << c << endl;
		exit(0);
	}
}

void hyp(ll c) {
	for (ll m = 1; m*m <= c; m++) for (ll n = 1; m*m + n*n <= c; n++) {
		if (c % (m*m + n*n)) continue;
		ll k = c / (m*m + n*n);
		ll a = k*(m*m - n*n), b = 2*k*m*n;
		if (!a || !b) continue;
		assert(a*a + b*b == c*c);
		cout << a << " " << b << endl;
		exit(0);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	cat(n);
	hyp(n);
	cout << -1 << endl;

}