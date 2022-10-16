#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());

		if (binary_search(a.begin(), a.end(), x)) {
			cout << "1\n"; continue;
		} else {
			cout << max(2, (x + a.back() - 1)/(a.back())) << '\n';
		}
	}

	return 0;
}