#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int lim_6 = 4;
	constexpr int lim_8 = 4;

	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;

		long long ans = LLONG_MAX;
		for (int cnt_6 = 0; cnt_6 <= lim_6; cnt_6++) {
			for (int cnt_8 = 0; cnt_8 <= lim_8; cnt_8++) {
				long long new_n = n - 6 * cnt_6 - 8 * cnt_8;
				long long now = 15 * cnt_6 + 20 * cnt_8;
				if (new_n >= 0) {
					now += 25 * ((new_n + 9) / 10);
				}
				ans = min(ans, now);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}