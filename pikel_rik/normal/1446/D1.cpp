#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n), cnt(min(n, 100));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[--a[i]]++;
	}

	int mx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
	if (count(cnt.begin(), cnt.end(), cnt[mx]) > 1) {
		cout << n << '\n';
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < min(n, 100); i++) {
		if (cnt[i] == 0 || i == mx) continue;
		vector<int> mp(2 * n + 1, -2);
		int sum = 0;

		mp[n] = -1;
		for (int j = 0; j < n; j++) {
			if (a[j] == mx) {
				sum -= 1;
			} else if (a[j] == i) {
				sum += 1;
			}
			if (mp[n + sum] == -2) {
				mp[n + sum] = j;
			} else {
				ans = max(ans, j - mp[n + sum]);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}