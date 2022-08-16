#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int W, H;
		cin >> W >> H;

		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int w, h;
		cin >> w >> h;

		vector<pair<int, int>> possibilities;
		possibilities.emplace_back(0, 0);
		possibilities.emplace_back(0, H - h);
		possibilities.emplace_back(W - w, 0);
		possibilities.emplace_back(W - w, H - h);

		int ans = INT_MAX;
		for (auto &[x, y] : possibilities) {
			int x3 = x, y3 = y;
			int x4 = x + w, y4 = y + h;

			if (y2 <= y3) {
				ans = 0;
			} else if (y3 - (y2 - y1) >= 0) {
				ans = min(ans, y2 - y3);
			}

			if (y1 >= y4) {
				ans = 0;
			} else if (y4 + (y2 - y1) <= H) {
				ans = min(ans, y4 - y1);
			}

			if (x2 <= x3) {
				ans = 0;
			} else if (x3 - (x2 - x1) >= 0) {
				ans = min(ans, x2 - x3);
			}

			if (x1 >= x4) {
				ans = 0;
			} else if (x4 + (x2 - x1) <= W) {
				ans = min(ans, x4 - x1);
			}
		}
		cout << (ans == INT_MAX ? -1 : ans) << '\n';
	}
	return 0;
}