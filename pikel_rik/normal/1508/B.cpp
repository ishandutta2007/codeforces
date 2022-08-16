#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto solve = [&](int n, long long k) -> vector<int> {
		vector<int> ans(n);
		for (int i = 0; i < n;) {
			for (int j = i; j < n; j++) {
				if (n - 2 - j >= 0 && k > (1ll << (n - 2 - j))) {
					k -= (1ll << (n - 2 - j));
				} else {
					for (int jj = i; jj <= j; jj++) {
						ans[jj] = j - (jj - i);
					}
					i = j + 1;
					break;
				}
			}
		}
		return ans;
	};

	while (t--) {
		int n; long long k;
		cin >> n >> k;

		if (n <= 60 && k > (1ll << (n - 1))) {
			cout << "-1\n";
			continue;
		}

		for (int i = 1; i <= n - min(n, 61); i++) {
			cout << i << ' ';
		}
		auto v = solve(min(n, 61), k);
		for (auto &x : v) cout << n - min(n, 61) + x + 1 << ' ';
		cout << '\n';
	}
	return 0;
}