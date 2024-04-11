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

		array<int, 4> a;
		for (auto &x : a) cin >> x;

		bool possible = false;
		for (int mask = 0; mask < (1 << 4); mask++) {
			array<int, 4> temp = a;
			for (int i = 0; i < 4; i++) {
				if (mask & (1 << i)) {
					temp[i] -= 1;
					temp[(i + 1) & 3] -= 1;
				}
			}
			bool ok = true;
			for (int i = 0; i < 4; i++) {
				ok &= 0 <= temp[i] && temp[i] < n - 1;
			}
			possible |= ok;
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}