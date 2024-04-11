#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		vector<int> a(4);
		cin >> a[0] >> a[1] >> a[2] >> a[3];

		sort(a.begin(), a.end());

		int ans = 0;

		do {
			ans = max(min(a[0], a[1]) * min(a[2], a[3]), ans);
		} while (next_permutation(a.begin(), a.end()));

		cout << ans << '\n';
	}

	return 0;
}