#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto solve = [&](int n, int m, const auto &self) -> int {
		if (n == 0) {
			return m + 1;
		} else if (n > m) {
			return 0;
		} else {
			int lg_n = 32 - __builtin_clz(n) - 1;
			int lg_m = 32 - __builtin_clz(m) - 1;

			if (m == (1 << (lg_m + 1)) - 1) {
				return m + 1;
			} else if (lg_n == lg_m) {
				return self(n ^ (1 << lg_n), m ^ (1 << lg_m), self);
			} else {
				int ans = self(n, m ^ (1 << lg_m), self);
				return (1 << lg_m) + ans;
			}
		}
	};

	while (t--) {
		int n, m;
		cin >> n >> m;

		cout << solve(n, m, solve) << '\n';
	}
	return 0;
}