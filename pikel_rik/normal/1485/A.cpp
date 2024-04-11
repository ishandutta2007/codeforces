#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		int ans = INT_MAX;
		for (int i = b; i <= b + 30; i++) {
			if (i == 1) continue;
			int c = i - b;
			for (int n = a; n; n /= i) {
				c += 1;
			}
			ans = min(ans, c);
		}
		cout << ans << '\n';
	}
	return 0;
}