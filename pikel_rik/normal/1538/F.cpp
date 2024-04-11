#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int l, r;
		cin >> l >> r;

		long long ten = 1, ans = 0;
		for (; ten <= r; ten *= 10) {
			ans += r / ten - l / ten;
		}
		cout << ans << '\n';
	}
	return 0;
}