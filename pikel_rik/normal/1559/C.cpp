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

		int j = find(a.rbegin(), a.rend(), 0) - a.rbegin();
		if (j == n) {
			cout << n + 1 << ' ';
			for (int i = 0; i < n; i++) {
				cout << i + 1 << ' ';
			}
			cout << '\n';
			continue;
		}

		j = n - j - 1;

		for (int i = 0; i <= j; i++) {
			cout << i + 1 << ' ';
		}
		cout << n + 1 << ' ';
		for (int i = j + 1; i < n; i++) {
			cout << i + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}