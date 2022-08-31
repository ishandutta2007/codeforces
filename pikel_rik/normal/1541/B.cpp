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
		for (int i = 0; i < n; i++) cin >> a[i];

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] < a[j];
		});

		long long ans = 0;
		for (int i : ind) {
			for (int j : ind) {
				if ((long long)a[i] * a[j] > 2 * n || a[j] >= a[i]) {
					break;
				}
				ans += a[i] * a[j] == i + j + 2;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}