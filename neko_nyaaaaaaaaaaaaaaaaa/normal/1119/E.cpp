#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &i: a) {
		cin >> i;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 && a[i] >= 3) {
			a[i] -= 3;
			ans++;
		}
	}

	int pairs = 0;
	for (int i = n-1; i >= 0; i--) {
		if (a[i] == 1) {
			if (pairs > 0) {
				pairs -= 2;
				ans++;
			}
		} else {
			pairs += a[i];
		}
	}

	ans += pairs/3;

	cout << ans;

	return 0;
}