#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

ll calc(ll x) {
	if (x <= 3) return x;
	ll lo = 1, hi = (ll)1e9 + 10, mid;
	while (lo < hi) {
		mid = (lo + hi + 1) / 2;
		if (mid * mid <= x) lo = mid;
		else hi = mid - 1;
	}
	ll s = lo;
	ll res = 3 * (s - 1);
	if (s * s <= x) res++;
	if (s * s + s <= x) res++;
	if (s * s + s + s <= x) res++;
	return res;
}

void solve() {
	ll l, r;
	cin >> l >> r;
	cout << calc(r) - calc(l - 1) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}