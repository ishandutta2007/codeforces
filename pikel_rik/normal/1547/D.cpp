#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> ans(n); ans[0] = 0;
		for (int i = 1; i < n; i++) {
			int submask = a[i - 1] ^ ans[i - 1];
			for (int j = 0; j < 30; j++) {
				if (submask >> j & 1) {
					if (!(a[i] >> j & 1)) {
						ans[i] |= 1 << j;
					}
				}
			}
		}

		for (auto &x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}