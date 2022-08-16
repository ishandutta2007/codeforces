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

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = 0; i < n; i++) {
			cout << (1 << (32 - __builtin_clz(a[i]) - 1)) << ' ';
		}
		cout << '\n';
	}
	return 0;
}