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

		sort(a.begin(), a.end());

		int mx = a[0];
		for (int i = 1; i < n; i++) {
			mx = max(mx, a[i] - a[i - 1]);
		}
		cout << mx << '\n';
	}
	return 0;
}