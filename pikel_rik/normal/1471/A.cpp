#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, x;
		cin >> n >> x;

		vector<int> a(n);
		for (auto &item : a) cin >> item;

		long long mx = 0, mn = 0;
		for (int i = 0; i < n; i++) {
			mx += (a[i] + x - 1) / x;
			mn += a[i];
		}

		mn = (mn + x - 1) / x;
		cout << mn << ' ' << mx << '\n';
	}
	return 0;
}