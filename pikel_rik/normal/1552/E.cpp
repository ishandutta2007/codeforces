#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> c(n * k);
	for (auto &x : c) cin >> x, --x;

	int mx_intervals = (n + k - 2) / (k - 1);

	vector<pair<int, int>> ans(n);

	vector<int> last(n, -1);
	vector<bool> marked(n);

	for (int rep = 0; rep < mx_intervals; rep++) {
		for (int i = 0; i < n * k; i++) {
			if (marked[c[i]]) {
				continue;
			}
			if (last[c[i]] == -1) {
				last[c[i]] = i;
			} else {
				ans[c[i]] = make_pair(last[c[i]], i);
				marked[c[i]] = true;
				fill(last.begin(), last.end(), -1);
			}
		}
		fill(last.begin(), last.end(), -1);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
	}
	return 0;
}