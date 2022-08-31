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
		for (int i = 0, r; i < n; i++) {
			cin >> r;
			ans += r == 1 || r == 3;
		}
		cout << ans << '\n';
	}
	return 0;
}