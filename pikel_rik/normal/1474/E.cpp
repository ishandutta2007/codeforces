#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto sq = [&](int x) -> long long {
		return (long long)x * x;
	};

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		if (n == 2) {
			cout << "1\n2 1\n1\n1 2\n";
			continue;
		}

		vector<int> p(n);
		iota(p.begin(), p.end(), 1);
		vector<pair<int, int>> ans;

		long long seconds = 0;

		auto do_swap = [&](int i, int j) -> void {
			swap(p[i], p[j]);
			ans.emplace_back(i + 1, j + 1);
			seconds += sq(i - j);
		};

		for (int i = 1; i < n - 1; i++) {
			if (sq(i) >= sq(i - n + 1)) {
				if (p[0] == 1) {
					do_swap(0, n - 1);
				}
				do_swap(i, 0);
			} else {
				do_swap(i, n - 1);
			}
		}

		cout << seconds << '\n';
		for (auto &x : p) cout << x << ' '; cout << '\n';
		reverse(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for (auto &[i, j] : ans) cout << i << ' ' << j << '\n';
	}
	return 0;
}