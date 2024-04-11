#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> h(n);
		for (auto &x : h) cin >> x;

		int ans = 0;
		for (int i = 0; i < k; i++) {
			ans = 0;
			for (int j = 1; j < n; j++) {
				if (h[j - 1] >= h[j]) {
					ans = j;
				} else break;
			}
			if (ans < n - 1) {
				h[ans] += 1;
			} else {
				ans = -2;
				break;
			}
		}

		cout << ans + 1 << '\n';
	}
	return 0;
}