#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> c(n);
	for (auto &x : c) cin >> x;

	long long ans = 0;
	for (int i = 0; i < n; i += 2) {
		long long mn = -1, sum = 0;
		for (int j = i + 1; j < n; j++) {
			if (j % 2 == 1) {
				if (c[i] >= -mn && c[j] >= sum - mn) {
					ans += 1 + min(c[i] + mn, c[j] - sum + mn);
				}
			}
			if (j % 2 == 0) {
				sum += c[j];
			} else {
				sum -= c[j];
			}
			mn = min(mn, sum);
		}
	}
	cout << ans << '\n';
	return 0;
}