#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k1, k2;
		cin >> n >> k1 >> k2;

		int w, b;
		cin >> w >> b;

		int white = min(k1, k2) + abs(k1 - k2) / 2, black = n - max(k1, k2) + abs(k1 - k2) / 2;
		cout << (w <= white && b <= black ? "YES" : "NO") << '\n';
	}
	return 0;
}