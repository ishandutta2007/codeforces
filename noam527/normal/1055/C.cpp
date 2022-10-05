#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

ll l[2], r[2], t[2];

ll calc() {
	ll le = max(l[0], l[1]);
	ll ri = min(r[0], r[1]);
	if (le > ri) return 0;
	return ri - le + 1;
}

int main() {
	fast;
	for (int i = 0; i < 2; i++) cin >> l[i] >> r[i] >> t[i];
	if (l[0] > l[1]) {
		swap(l[0], l[1]);
		swap(r[0], r[1]);
		swap(t[0], t[1]);
	}
	r[1] -= l[0];
	l[1] -= l[0];
	r[0] -= l[0];
	l[0] = 0;

	ll g = gcd(t[0], t[1]);

	ll diff = r[1] - l[1];
	l[1] = l[1] % g;
	r[1] = l[1] + diff;

	ll ans = calc();
	l[1] -= g;
	r[1] -= g;
	ans = max(ans, calc());
	finish(ans);
}