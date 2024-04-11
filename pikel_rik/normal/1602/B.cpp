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

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<vector<int>> states(1, a);

		vector<int> cnt(n + 1);
		for (int i = 1;; i++) {
			fill(cnt.begin(), cnt.end(), 0);
			for (auto &x : states[i - 1]) {
				cnt[x] += 1;
			}
			states.emplace_back(states[i - 1]);

			bool converged = true;
			for (auto &x : states[i]) {
				converged &= x == cnt[x];
				x = cnt[x];
			}
			if (converged) {
				break;
			}
		}

		int q;
		cin >> q;

		while (q--) {
			int x, k;
			cin >> x >> k, --x;

			k = min(k, (int) states.size() - 1);
			cout << states[k][x] << '\n';
		}
	}
	return 0;
}