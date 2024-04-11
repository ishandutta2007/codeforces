#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int W, H; cin >> W >> H;
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int w, h; cin >> w >> h;

		if ((w + (x2 - x1)) > W && (h + (y2 - y1)) > H) {
			cout << "-1\n"; continue;
		}

		int ans = 1000000000;
		// left side
		if (w + (x2 - x1) <= W) {
			int gap = x1;
			if (gap >= w) ans = 0;
			else ans = min(ans, abs(w - gap));
		}
		// right side
		if (w + (x2 - x1) <= W) {
			int gap = W - x2;
			if (gap >= w) ans = 0;
			else ans = min(ans, abs(w - gap));
		}
		// up side
		if (h + (y2 - y1) <= H) {
			int gap = y1;
			if (gap >= h) ans = 0;
			else ans = min(ans, abs(h - gap));
		}
		// down side
		if (h + (y2 - y1) <= H) {
			int gap = H - y2;
			if (gap >= h) ans = 0;
			else ans = min(ans, abs(h - gap));
		}

		cout << ans << '\n';
	}

	return 0;
}