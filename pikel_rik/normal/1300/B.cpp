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

		vector<int> a(2 * n);
		for (auto &x : a) cin >> x;

		sort(a.begin(), a.end());
		cout << a[n] - a[n - 1] << '\n';
	}
	return 0;
}