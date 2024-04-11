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

		array<int, 3> c = {};
		for (auto &x : a) {
			c[x % 3] += 1;
		}

		int ans = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				while (c[j] > n / 3) {
					c[j] -= 1;
					c[(j + 1) % 3] += 1;
					ans += 1;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}