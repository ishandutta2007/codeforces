#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

	auto unq = [&](vector<int> c) -> int {
		sort(c.begin(), c.end());
		return unique(c.begin(), c.end()) - c.begin();
	};

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x, --x;

		int distinct = unq(a);

		int unmatched = 0;
		vector<int> b(n, -1);
		vector<bool> used(n);

		if (distinct == n - 1) {
			vector<vector<int>> match(n);

			for (int i = 0; i < n; i++) {
				match[a[i]].push_back(i);
			}

			for (int i = 0; i < n; i++) {
				if (match[i].size() == 1) {
					b[match[i][0]] = i;
					used[i] = true;
				}
			}

			unmatched = 1;
			for (int i = 0; i < n; i++) {
				if (match[i].size() == 2) {
					int other = -1;
					for (int j = 0; j < n; j++) {
						if (j != i && !used[j]) {
							other = j;
						}
					}
					if (other == match[i][0]) {
						b[match[i][0]] = i;
						b[match[i][1]] = other;
					} else {
						b[match[i][0]] = other;
						b[match[i][1]] = i;
					}
				}
			}
		} else {
			vector<int> ind;
			for (int i = 0; i < n; i++) {
				if (!used[a[i]]) {
					b[i] = a[i];
					used[a[i]] = true;
				} else {
					unmatched += 1;
					ind.push_back(i);
				}
			}

			vector<int> unused;
			for (int i = 0; i < n; i++) {
				if (!used[i]) {
					unused.push_back(i);
				}
			}

			while (true) {
				bool repeat = false;
				for (int i = 0; i < (int) ind.size(); i++) {
					if (ind[i] == unused[i]) {
						repeat = true;
					}
				}
				if (!repeat) {
					for (int i = 0; i < (int) ind.size(); i++) {
						b[ind[i]] = unused[i];
					}
					break;
				}
				shuffle(unused.begin(), unused.end(), rng);
			}
		}
		cout << n - unmatched << '\n';
		for (auto &x : b) cout << x + 1 << ' ';
		cout << '\n';	}
	return 0;
}