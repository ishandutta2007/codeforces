#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n; n *= 2;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		sort(a.begin(), a.end());

		int ans_x = -1;
		vector<pair<int, int>> ans;
		for (int i = 0; i < n - 1; i++) {
			int x = a[i] + a[n - 1];
			multiset<int, greater<>> s(a.begin(), a.end());

			bool ok = true;
			vector<pair<int, int>> cur_ans;

			while (!s.empty()) {
				int now = *s.begin();
				s.erase(s.begin());

				auto it = s.find(x - now);
				if (it == s.end()) {
					ok = false;
					break;
				} else {
					cur_ans.emplace_back(now, x - now);
					s.erase(it);
					x = now;
				}
			}

			if (ok) {
				ans_x = a[i] + a[n - 1];
				ans = cur_ans;
				break;
			}
		}

		if (ans_x == -1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << ans_x << '\n';
			for (const auto &p : ans) cout << p.first << ' ' << p.second << '\n';
		}
	}
	return 0;
}