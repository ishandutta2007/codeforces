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

		int xor_sum = accumulate(a.begin(), a.end(), 0, bit_xor<>());

		if (xor_sum == 0) {
			int now = 0, split = -1;
			for (int i = 0; i + 1 < n; i++) {
				xor_sum ^= a[i];
				now ^= a[i];
				if (xor_sum == now) {
					split = i;
					break;
				}
			}
			cout << (split == -1 ? "NO" : "YES") << '\n';
		} else {
			int prefix = 0;
			bool found1 = false, found2 = false;
			for (int i = 0; i + 1 < n; i++) {
				prefix ^= a[i];
				found2 |= prefix == 0 && found1;
				found1 |= prefix == xor_sum;
			}
			cout << (found1 && found2 ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}