#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k, m; cin >> n >> k >> m;
	vector<int> a(k);
	int sum = 0;
	for (int i = 0; i < k; i++) {
		cin >> a[i]; sum += a[i];
	}

	int ans = 0;
	for (int full = 0; full <= n; full++) {
		if (sum*full > m) break;
		int tmp = full*(k+1);

		int time_left = m - sum*full;
		vector<int> subs;
		for (int i = 0; i < k; i++) {
			for (int j = full; j < n; j++) {
				subs.push_back(a[i]);
			}
		}
		sort(subs.begin(), subs.end(), greater<int>());

		while (subs.size() && subs.back() <= time_left) {
			time_left -= subs.back(); subs.pop_back();
			tmp++;
		}

		ans = max(ans, tmp);
	}
	cout << ans;
	return 0;
}