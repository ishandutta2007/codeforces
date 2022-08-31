#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n), d(n);
		for (auto &x : a) cin >> x, --x;

		auto recurse = [&](int l, int r, int lvl, const auto &self) -> void {
			int mx = max_element(a.begin() + l, a.begin() + r + 1) - a.begin();
			d[mx] = lvl;
			if (mx != l) {
				self(l, mx - 1, lvl + 1, self);
			}
			if (mx != r) {
				self(mx + 1, r, lvl + 1, self);
			}
		};

		recurse(0, n - 1, 0, recurse);
		for (auto &x : d) cout << x << ' '; cout << '\n';
	}
	return 0;
}