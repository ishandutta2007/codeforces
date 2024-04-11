#include <bits/stdc++.h>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
#define yesno(X) cout << ((X) ? "YES" : "NO") << endl
#define noyes(X) cout << ((X) ? "NO" : "YES") << endl
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll gcd(ll x, ll y) {
	return !y ? x : gcd(y, x % y);
}

ll p, q, b, g;

void solve() {
	cin >> p >> q >> b;
	g = gcd(p, q);
	p /= g, q /= g;

	g = gcd(q, b);
	while (g > 1 && q > 1) {
		while (q % g == 0) q /= g;
		g = gcd(q, b);
	}
	if (q == 1) cout << "Finite" << endl;
	else cout << "Infinite" << endl;
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--) solve();
}