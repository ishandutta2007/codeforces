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

		vector<string> a(n);
		for (auto &x : a) cin >> x;

		vector<string> ans(n, string(m, 0));

		bool ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[i][j] = ((i + j) % 2 == 0 ? 'R' : 'W');
				ok &= ans[i][j] == a[i][j] || a[i][j] == '.';
			}
		}

		if (ok) {
			cout << "YES\n";
			for (auto &s : ans) cout << s << '\n';
			continue;
		}

		ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[i][j] = ((i + j) % 2 == 0 ? 'W' : 'R');
				ok &= ans[i][j] == a[i][j] || a[i][j] == '.';
			}
		}

		if (ok) {
			cout << "YES\n";
			for (auto &s : ans) cout << s << '\n';
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}