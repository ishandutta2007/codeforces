#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		for (int i = 0; i + 1 < n; i++) {
			while (a[i] > 0 && k > 0) {
				a[i] -= 1;
				a[n - 1] += 1;
				k -= 1;
			}
		}

		for (auto &x : a) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}