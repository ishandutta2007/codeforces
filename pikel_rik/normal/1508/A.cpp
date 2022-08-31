#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	array<pair<int, int>, 3> pairs;
	pairs[0] = {0, 1}, pairs[1] = {1, 2}, pairs[2] = {0, 2};

	while (t--) {
		int n;
		cin >> n;

		array<string, 3> a;
		for (int i = 0; i < 3; i++) cin >> a[i];

		array<int, 3> c;
		for (int i = 0; i < 3; i++) c[i] = count(a[i].begin(), a[i].end(), '0');

		string ans;
		ans.reserve(3 * n);
		for (auto [x, y] : pairs) {
			if (c[x] >= n && c[y] >= n) {
				int taken = min(c[x], c[y]), i = 0, j = 0;
				for (; taken > 0;) {
					while (a[x][i] != '0') {
						ans += a[x][i];
						i += 1;
					}
					while (a[y][j] != '0') {
						ans += a[y][j];
						j += 1;
					}
					ans += '0';
					i += 1, j += 1;
					taken -= 1;
				}
				for (; i < 2 * n; i++) {
					ans += a[x][i];
				}
				for (; j < 2 * n; j++) {
					ans += a[y][j];
				}
				break;
			} else if (c[x] <= n && c[y] <= n) {
				int taken = min(2 * n - c[x], 2 * n - c[y]), i = 0, j = 0;
				for (; taken > 0;) {
					while (a[x][i] != '1') {
						ans += a[x][i];
						i += 1;
					}
					while (a[y][j] != '1') {
						ans += a[y][j];
						j += 1;
					}
					ans += '1';
					i += 1, j += 1;
					taken -= 1;
				}
				for (; i < 2 * n; i++) {
					ans += a[x][i];
				}
				for (; j < 2 * n; j++) {
					ans += a[y][j];
				}
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}