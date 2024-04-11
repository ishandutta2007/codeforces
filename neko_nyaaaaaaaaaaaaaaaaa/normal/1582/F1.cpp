#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> lst(512, 500000); lst[0] = 0;
	while (n--) {
		int x; cin >> x;
		vector<bool> ok(512);

		for (int i = 0; i < 512; i++) {
			ok[i] = (lst[i] < x);
		}

		for (int i = 0; i < 512; i++) {
			if (ok[i]) {
				lst[i^x] = min(lst[i^x], x);
			}
		}
	}

	int cnt = 0; stringstream ss;
	for (int i = 0; i < 512; i++) {
		if (lst[i] < 500000) {
			ss << i << ' '; cnt++;
		}
	}
	cout << cnt << '\n' << ss.str() << '\n';

	return 0;
}