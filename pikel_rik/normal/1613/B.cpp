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
		for (int i = 1; i <= n / 2; i++) {
			cout << a[i] << ' ' << a[0] << '\n';
		}
	}
	return 0;
}