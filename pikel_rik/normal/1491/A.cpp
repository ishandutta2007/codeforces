#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int c1 = accumulate(a.begin(), a.end(), 0), c0 = n - c1;
	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int x;
			cin >> x, --x;
			if (a[x]) {
				c1 -= 1;
				c0 += 1;
			} else {
				c0 -= 1;
				c1 += 1;
			}
			a[x] = 1 - a[x];
		} else {
			int k;
			cin >> k;
			cout << (k <= c1 ? 1 : 0) << '\n';
		}
	}
	return 0;
}