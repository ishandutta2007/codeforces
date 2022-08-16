#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while (q--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(k);
		for (auto &x : a) cin >> x, --x;

		vector<int> t(k);
		for (auto &x : t) cin >> x;

		vector<int> ac(n, -1);
		for (int i = 0; i < k; i++) {
			ac[a[i]] = i;
		}

		vector<int> ans(n, INT_MAX);

		int mn = INT_MAX;
		for (int i = 0; i < n; i++) {
			int j = ac[i];
			if (j != -1) {
				mn = min(mn, t[j] - a[j]);
			}
			if (mn != INT_MAX) {
				ans[i] = min(ans[i], mn + i);
			}
		}

		mn = INT_MAX;
		for (int i = n - 1; i >= 0; i--) {
			int j = ac[i];
			if (j != -1) {
				mn = min(mn, t[j] + a[j]);
			}
			if (mn != INT_MAX) {
				ans[i] = min(ans[i], mn - i);
			}
		}

		for (auto &x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}