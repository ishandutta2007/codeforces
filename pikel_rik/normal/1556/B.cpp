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
		for (auto &x : a) {
			cin >> x, x %= 2;
		}

		long long ans = LLONG_MAX;
		for (int odd : {0, 1}) {
			long long now = 0;
			int j = 1;
			for (int i = 0; i < n; i++) {
				if (a[i] == odd) {
					now += abs(i - j);
					j += 2;
				}
			}
			if ((n % 2 != 0 && j == n) || (n % 2 == 0 && j == n + 1)) {
				ans = min(ans, now);
			}
		}

		cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
	}
	return 0;
}