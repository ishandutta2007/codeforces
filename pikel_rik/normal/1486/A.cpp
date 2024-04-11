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

		long long sum = a[0]; a[0] = 0;

		bool ok = true;
		for (int i = 1; i < n; i++) {
			ok &= sum + a[i] > a[i - 1];
			if (a[i] > a[i - 1]) {
				sum += a[i] - a[i - 1] - 1;
			} else {
				sum -= a[i - 1] + 1 - a[i];
			}
			a[i] = a[i - 1] + 1;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}