#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m, x;
		cin >> n >> m >> x;

		vector<int> a(n);
		for (auto &y : a) cin >> y;

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] < a[j];
		});

		vector<int> ans(n);
		for (int i = 0, j = 0; i < n; i++, j = (j + 1) % m) {
			ans[ind[i]] = j + 1;
		}

		cout << "YES\n";
		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}