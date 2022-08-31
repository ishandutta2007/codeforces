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

		vector<pair<int, int>> ops;

		int cur = n;
		for (int i = n - 1; i >= 3; i--) {
			int cel = (cur + i - 1) / i;
			if (cel > i) {
				ops.emplace_back(n, i);
				cur = cel;
			}
			ops.emplace_back(i, n);
		}

		while (cur > 1) {
			ops.emplace_back(n, 2);
			cur = (cur + 1) / 2;
		}

		cout << ops.size() << '\n';
		for (auto &[x, y] : ops) {
			cout << x << ' ' << y << '\n';
		}
	}
	return 0;
}