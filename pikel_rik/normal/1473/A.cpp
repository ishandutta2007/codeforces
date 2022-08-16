#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, d;
		cin >> n >> d;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		sort(a.begin(), a.end());

		cout << (a[0] + a[1] <= d || all_of(a.begin(), a.end(), [&](auto x) { return x <= d; }) ? "YES" : "NO") << '\n';
	}
	return 0;
}