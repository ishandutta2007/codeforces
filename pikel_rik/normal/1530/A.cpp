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

		int ans = 0;
		for (; n > 0; n /= 10) {
			ans = max(ans, n % 10);
		}
		cout << ans << '\n';
	}
	return 0;
}