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

		vector<int> x(k);
		for (int i = 0; i < k; i++) cin >> x[i];

		sort(x.rbegin(), x.rend());

		int ans = 0;

		long long sum = 0;
		for (int i = 0; i < k; i++) {
			sum += n - x[i];
			if (sum < n) {
				ans = max(ans, i + 1);
			}
		}

		cout << ans << '\n';
	}
	return 0;
}