#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int s;
		cin >> s;

		int ans = 0;
		for (int i = 1; s > 0; i += 2) {
			if (s >= i) {
				s -= i;
				ans += 1;
			} else {
				break;
			}
		}
		ans += !!s;
		cout << ans << '\n';
	}
	return 0;
}