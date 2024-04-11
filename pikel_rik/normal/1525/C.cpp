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

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		string s(n, 0);
		for (auto &ch : s) cin >> ch;

		vector<int> ans(n, -1);

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] < a[j];
		});

		array<vector<int>, 2> left, right;
		for (int i : ind) {
			bool f = a[i] % 2;
			if (s[i] == 'L') {
				if (!right[f].empty()) {
					int j = right[f].back();
					right[f].pop_back();
					ans[i] = ans[j] = (a[i] - a[j]) / 2;
				} else {
					left[f].push_back(i);
				}
			} else {
				right[f].push_back(i);
			}
		}

		for (int f = 0; f < 2; f++) {
			for (int i = 1; i < left[f].size(); i += 2) {
				int value = (a[left[f][i]] - a[left[f][i - 1]]) / 2;
				ans[left[f][i - 1]] = ans[left[f][i]] = a[left[f][i - 1]] + value;
			}

			reverse(right[f].begin(), right[f].end());
			for (int i = 1; i < right[f].size(); i += 2) {
				int value = (a[right[f][i - 1]] - a[right[f][i]]) / 2;
				ans[right[f][i - 1]] = ans[right[f][i]] = m - a[right[f][i - 1]] + value;
			}

			if (left[f].size() % 2 != 0 && right[f].size() % 2 != 0) {
				int i = left[f].back(), j = right[f].back();
				int value = max(a[i], m - a[j]);
				a[i] = abs(a[i] - value);
				a[j] = m - abs(m - (a[j] + value));
				ans[i] = ans[j] = (a[j] - a[i]) / 2 + value;
			}
		}

		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}