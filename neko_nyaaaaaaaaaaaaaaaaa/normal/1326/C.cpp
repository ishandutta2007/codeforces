#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	int ans1 = 0, ans2 = 1;
	int prv = -1, cur = 0;

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x >= (n - k + 1)) {
			ans1 += x;

			if (prv >= (n - k + 1)) {
				ans2 = (ans2 * cur) % M;
			}
			cur = 1;
			prv = x;
		} else {
			cur++;
		}
	}
	cout << ans1 << ' ' << ans2;

	return 0;
}