#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

ll modexp(ll x, ll n, ll m) {
	ll ans = 1;
	while (n) {
		if (n & 1) ans = ans * x % m;
		x = x * x % m;
		n /= 2;
	}
	return ans;
}

ll modinv(ll x, ll m) {
	return modexp(x, m - 2, m);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		ll k, l, r, p;
		cin >> k >> l >> r >> p;

		if (p == 2) {
			cout << ((k + 1) & 1) << '\n';
		} else {
			ll x = (k % p == 0 ? 0 : modexp(k, modexp(2, l, p - 1), p)), ans;
			if (x == 0) {
				ans = 1;
			} else if (x == 1) {
				ans = modexp(2, r - l + 1, p);
			} else {
				ans = (modexp(x, modexp(2, r - l + 1, p - 1), p) + p - 1) % p * modinv(x - 1, p) % p;
			}
			if (k % 2 != 0) {
				ll div = modexp(2, r - l, p);
				ans = ans * modinv(div, p) % p;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}