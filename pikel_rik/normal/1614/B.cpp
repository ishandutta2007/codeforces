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

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] > a[j];
		});

		vector<int> x(n);
		for (int i = 0, cur_x = 1; i < n; i++) {
			if (i % 2 == 0) {
				x[ind[i]] = cur_x;
			} else {
				x[ind[i]] = -cur_x;
				cur_x += 1;
			}
		}

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += 2ll * abs(x[i]) * a[i];
		}

		cout << ans << '\n';
		cout << 0 << ' ';
		for (int i = 0; i < n; i++) {
			cout << x[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}