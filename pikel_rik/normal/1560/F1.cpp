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

		string num = to_string(n);

		long long ans = 9 * stoll(string(num.length(), '1'));

		int mask = 0;
		for (int i = 0; i < (int) num.length(); i++) {
			for (int digit = num[i] - '0' + 1; digit < 10; digit++) {
				for (int smaller = 0; smaller < 10; smaller++) {
					int new_mask = mask | (1 << digit) | (1 << smaller);
					if (__builtin_popcount(new_mask) > k) {
						continue;
					}
					string candidate = string(num.begin(), num.begin() + i) + string(1, '0' + digit) + string((int) num.length() - i - 1, '0' + smaller);
					ans = min(ans, stoll(candidate));
					break;
				}
			}
			mask |= 1 << (num[i] - '0');
		}
		if (__builtin_popcount(mask) <= k) {
			ans = min(ans, (long long)n);
		}
		cout << ans << '\n';
	}
	return 0;
}