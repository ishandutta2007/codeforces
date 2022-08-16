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

		vector<long long> c(n);
		for (auto &x : c) cin >> x;

		long long up = n * c[0];
		long long right = n * c[1];
		long long ans = up + right;

		long long up_mn = c[0], right_mn = c[1];
		for (int i = 2; i < n; i++) {
			if (i % 2 == 0) {
				if (c[i] < up_mn) {
					up += (n - i / 2) * (c[i] - up_mn);
					up_mn = c[i];
				} else {
					up += c[i] - up_mn;
				}
			} else {
				if (c[i] < right_mn) {
					right += (n - i / 2) * (c[i] - right_mn);
					right_mn = c[i];
				} else {
					right += c[i] - right_mn;
				}
			}
			ans = min(ans, up + right);
		}
		cout << ans << '\n';
	}
	return 0;
}