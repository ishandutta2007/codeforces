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

		vector<int> u(n), s(n);
		for (auto &x : u) cin >> x, --x;
		for (auto &x : s) cin >> x;

		vector<vector<long long>> v(n);
		for (int i = 0; i < n; i++) {
			v[u[i]].push_back(s[i]);
		}

		for (int i = 0; i < n; i++) {
			sort(v[i].begin(), v[i].end(), greater<>());
			partial_sum(v[i].begin(), v[i].end(), v[i].begin());
		}

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return v[i].size() < v[j].size();
		});

		for (int k = 1, i = 0; k <= n; k++) {
			while (i < n && v[ind[i]].size() < k) {
				i += 1;
			}
			long long ans = 0;
			for (int j = i, jj; j < n; j++) {
				for (jj = k - 1; jj + k < v[ind[j]].size(); jj += k);
				ans += v[ind[j]][jj];
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
	return 0;
}