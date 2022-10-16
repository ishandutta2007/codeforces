#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<pair<int, int>> ans;

	vector<int> pos1;
	vector<int> pos2;
	vector<int> pos3;
	for (int i = n; i > 0; i--) {
		if (a[i] == 1) {
			pos1.push_back(i); // may use later
		} else if (a[i] == 2) {
			// match with a 1 immediately
			if (pos1.empty()) {
				cout << "-1\n"; exit(0);
			}

			int col = pos1.back(); pos1.pop_back();
			ans.emplace_back(i, i);
			ans.emplace_back(i, col);

			pos2.push_back(i);
			// may use later for matching 3
		} else if (a[i] == 3) {
			// try to match with another 3 first
			if (!pos3.empty()) {
				int col = pos3.back();
				ans.emplace_back(i, i);
				ans.emplace_back(i, col);

				pos3.push_back(i);
				continue;
			}

			// try to match with a 2
			if (!pos2.empty()) {
				int col = pos2.back(); pos2.pop_back();
				ans.emplace_back(i, i);
				ans.emplace_back(i, col);

				pos3.push_back(i);
				continue;
			}

			// try to match with a 1
			if (!pos1.empty()) {
				int col = pos1.back(); pos1.pop_back();
				ans.emplace_back(i, i);
				ans.emplace_back(i, col);
				ans.emplace_back(col, col);

				pos3.push_back(i);
				continue;
			}
			cout << "-1\n"; exit(0);
		}
	}

	for (int i: pos1) {
		ans.emplace_back(i, i);
	}

	cout << ans.size() << '\n';
	for (auto [u, v]: ans) cout << u << ' ' << v << '\n';

	return 0;
}