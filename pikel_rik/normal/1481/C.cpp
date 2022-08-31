#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n), b(n), c(m);
		for (auto &x : a) cin >> x, --x;
		for (auto &x : b) cin >> x, --x;
		for (auto &x : c) cin >> x, --x;

		int pos = find(b.begin(), b.end(), c.back()) - b.begin();
		if (pos == n) {
			cout << "NO\n";
			continue;
		}

		vector<int> x(m);

		vector<vector<int>> unmatched(n);
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				unmatched[b[i]].push_back(i);
			}
		}

		if (!unmatched[c.back()].empty()) {
			pos = unmatched[c.back()][0];
		}

		for (int i = 0; i < m; i++) {
			if (!unmatched[c[i]].empty()) {
				x[i] = unmatched[c[i]].back();
				a[unmatched[c[i]].back()] = c[i];
				unmatched[c[i]].pop_back();
			} else {
				x[i] = pos;
				a[pos] = c[i];
			}
		}

		if (a == b) {
			cout << "YES\n";
			for (auto &elem : x) cout << elem + 1 << ' ';
			cout << '\n';
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}