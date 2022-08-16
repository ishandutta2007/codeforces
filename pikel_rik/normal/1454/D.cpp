#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		vector<pair<ll, int>> factors;

		ll x = n;
		for (int i = 2; (ll)i * i <= x; i++) {
			if (x % i == 0) {
				factors.emplace_back(i, 0);
				while (x % i == 0) {
					factors.back().second++;
					x /= i;
				}
			}
		}

		if (x > 1) {
			factors.emplace_back(x, 1);
		}

		int mx = 0;
		for (auto [p, c] : factors) {
			mx = max(mx, c);
		}

		vector<ll> ans(mx, 1);

		for (auto [p, c] : factors) {
			for (int i = mx - 1; i >= mx - c; i--) ans[i] *= p;
		}

		cout << mx << '\n';
		for (auto item : ans) cout << item << ' '; cout << '\n';
	}
	return 0;
}