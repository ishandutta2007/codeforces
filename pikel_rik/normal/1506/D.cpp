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

		map<int, int> cnt;
		for (int i = 0, x; i < n; i++) {
			cin >> x, cnt[x] += 1;
		}

		int mx = 0;
		for (auto &[x, c] : cnt) {
			mx = max(mx, c);
		}

		cout << (2 * mx <= n ? (n % 2) : 2 * mx - n) << '\n';
	}
	return 0;
}