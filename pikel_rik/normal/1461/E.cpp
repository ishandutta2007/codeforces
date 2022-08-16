#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

ll k, l, r, t, x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> k >> l >> r >> t >> x >> y;

	r -= l;
	k -= l;
	l -= l;

	if (y >= x) {
		if (x + y <= r) {
			cout << "Yes\n";
		} else {
			ll cur = k;
			bool ok = true;
			for (int i = 0; i <= x + 50 && t > 0; i++) {
				if (cur + y <= r) {
					cur += y;
				}
				ll iter = cur / x;
				cur %= x;
				ok &= iter > 0;
				t -= iter;
			}
			cout << (ok ? "Yes" : "No") << '\n';
		}
	} else {
		if (k + y > r) {
			k -= x;
			t--;
		}
		if (ld(k) + ld(t) * (y - x) >= ld(l)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}