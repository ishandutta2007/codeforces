#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int k, n, m;
		cin >> k >> n >> m;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> b(m);
		for (auto &x : b) cin >> x;

		vector<int> ans;

		int pages = k;
		for (int i = 0, j = 0; i < n || j < m;) {
			if (i < n && a[i] == 0) {
				ans.push_back(0);
				i += 1, pages += 1;
			} else if (j < m && b[j] == 0) {
				ans.push_back(0);
				j += 1, pages += 1;
			} else if (i < n && a[i] <= pages) {
				ans.push_back(a[i]);
				i += 1;
			} else if (j < m && b[j] <= pages) {
				ans.push_back(b[j]);
				j += 1;
			} else {
				ans.clear();
				break;
			}
		}

		if (ans.empty()) {
			cout << "-1\n";
		} else {
			for (auto &move : ans) cout << move << ' ';
			cout << '\n';
		}
	}
	return 0;
}