#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		auto k_xor = [&](int x, int y) -> int {
			int pw = 1, ans = 0;
			for (int i = 0; i < 20; i++) {
				ans += pw * (((x % k) + (y % k)) % k);
				pw *= k, x /= k, y /= k;
			}
			return ans;
		};

		auto k_inv = [&](int x) -> int {
			int pw = 1, ans = 0;
			for (int i = 0; i < 20; i++) {
				ans += pw * ((k - x % k) % k);
				pw *= k, x /= k;
			}
			return ans;
		};

		int k_pw = 1;
		while (k_pw < n) {
			k_pw *= k;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			//z = y ^ x'
			if (i == 0) {
				cout << i << endl;
			} else if (i % 2 != 0) {
				//z = (i - 1) - x
				cout << k_xor(k_inv(i), i - 1) << endl;
			} else {
				//z = -(i - 1) + x
				cout << k_xor(k_inv(i - 1), i) << endl;
			}
			int r;
			cin >> r;
			if (r == 1) {
				break;
			}
		}
	}
	return 0;
}