#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k, --m;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		k = min(k, m);

		int ans = 0;
		for (int front = 0; front <= k; front++) {
			int back = k - front;
			int now = INT_MAX;
			for (int other_front = 0; other_front <= m - k; other_front++) {
				int other_back = m - k - other_front;
				int total_front = front + other_front;
				int total_back = back + other_back;
				now = min(now, max(a[total_front], a[n - total_back - 1]));
			}
			ans = max(ans, now);
		}
		cout << ans << '\n';
	}
	return 0;
}