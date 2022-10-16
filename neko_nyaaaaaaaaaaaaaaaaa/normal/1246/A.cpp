#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int ans = 10000;
	long long n, p; cin >> n >> p;
	for (int i = 1; i < 60; i++) {
		long long tmp = n - p*i;
		if (tmp <= 0) continue;

		int need = __builtin_popcountll(tmp);
		if (i >= need && i <= tmp) {
			ans = min(ans, i);
		}
	}
	if (ans == 10000) {
		cout << -1;
	} else {
		cout << ans;
	}

	return 0;
}