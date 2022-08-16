#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<pair<int, int>> p(n + 1);
		p[0] = make_pair(1, 1);

		for (int i = 1; i <= n; i++) cin >> p[i].first;
		for (int i = 1; i <= n; i++) cin >> p[i].second;

		sort(p.begin(), p.end());

		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			int dx = p[i].first - p[i - 1].first, dy = p[i].second - p[i - 1].second;
			int par_s = (p[i - 1].first + p[i - 1].second) % 2;
			int par_t = (p[i].first + p[i].second) % 2;
			if (dy == dx) {
				ans += (!par_s) * dx;
			} else if (dy == 0) {
				if (!par_s) {
					ans += dx / 2;
				} else {
					ans += (dx + 1) / 2;
				}
			} else {
				if (par_s == 1 && par_t == 0) {
					ans += (dx - dy + 1) / 2;
				} else {
					ans += (dx - dy) / 2;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}