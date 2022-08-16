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

		if (n == 2) {
			for (auto &x : a) cout << x << ' ';
			cout << '\n';
			continue;
		}

		int mn = INT_MAX;
		for (int i = 1; i < n; i++) {
			mn = min(mn, a[i] - a[i - 1]);
		}

		for (int i = 1; i < n; i++) {
			if (a[i] - a[i - 1] == mn) {
				for (int j = i; j < n; j++) {
					cout << a[j] << ' ';
				}
				for (int j = 0; j < i; j++) {
					cout << a[j] << ' ';
				}
				break;
			}
		}
		cout << '\n';
	}
	return 0;
}