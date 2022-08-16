#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> cnt(m);
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			cnt[x % m] += 1;
		}

		int ans = 0;
		ans += cnt[0] > 0;
		ans += m % 2 == 0 && cnt[m / 2] > 0;

		for (int i = 1; 2 * i < m; i++) {
			if (cnt[i] == 0 && cnt[m - i] == 0)
				continue;
			if (cnt[i] < cnt[m - i])
				swap(cnt[i], cnt[m - i]);

			ans += 1;
			if (cnt[i] - cnt[m - i] > 1) {
				ans += cnt[i] - cnt[m - i] - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}