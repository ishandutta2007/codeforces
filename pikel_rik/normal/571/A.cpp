#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

ll choose(ll n, ll k) {
	ll ans = 1;
	k = min(k, n - k);
	for (int i = 0; i < k; i++) {
		ans *= n - i;
	}
	for (int i = 1; i <= k; i++) {
		ans /= i;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, l;
	cin >> a >> b >> c >> l;

	ll ans = choose(l + 3, 3);
	for (int rot = 0; rot < 3; rot++) {
		for (int i = a; i <= a + l; i++) {
			int left_over = l + a - i;
			if (left_over + b + c > i) {
				left_over -= left_over + b + c - i;
			}
			if (left_over >= 0) {
				ans -= choose(left_over + 2, 2);
			}
		}
		tie(a, b, c) = make_tuple(b, c, a);
	}
	cout << ans << '\n';
	return 0;
}