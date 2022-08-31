#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	constexpr int limit = 25;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];

		bool possible = true;
		for (int i = 1; i <= min(limit, n); i++) {
			bool divisible = true;
			for (int j = 1; j <= i; j++) {
				divisible &= a[i] % (j + 1) == 0;
			}
			possible &= !divisible;
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}