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

		int min_ops = 0;
		for (int i = 0; i < n; i++) {
			min_ops = max(min_ops, max(0, a[i] - i - 1));
		}
		cout << min_ops << '\n';
	}
	return 0;
}