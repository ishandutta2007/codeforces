#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		if (a > b) {
			a = n + 1 - a;
			b = n + 1 - b;
		}

		int t = b - 1;
		int nBom = b - a - 1;

		vector<int> s(m);

		for (int &e : s) {
			cin >> e;
		}
		sort(s.begin(), s.end());

		int l = 0, r = min(nBom, m);
		int ans = 0;

		while (r >= l) {
			int mid = (l + r) / 2;
			bool ok = 1;
			for (int i = 0; i < mid; i++) {
				if (s[i] + mid - i - 1 >= t) {
					ok = 0;
				}
			}
			if (ok) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		cout << ans << '\n';
	}


	return 0;
}