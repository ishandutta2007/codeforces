#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<pair<int, int>> dir = {
	{1, 1},
	{0, 1},
	{-1, 0},
	{-1, -1},
	{0, -1},
	{1, 0}
};

pair<int, int> solve_eq(int x1, int y1, int x2, int y2, int x, int y) {
	// v1*x1 + v2*x2 = x
	// v1*y1 + v2*y2 = y

	// v1*x1*y1 + v2*x2*y1 = x*y1
	// v1*y1*x1 + v2*y2*x1 = y*x1

	// v2*(x2*y1 - y2*x1) = x*y1 - y*x1
	// v2 = (x*y1 - y*x1)/(x2*y1 - y2*x1)
	if ((x2*y1 - y2*x1) == 0) return {-1, -1};
	if ((x1) == 0) return {-1, -1};

	int v2 = (x*y1 - y*x1)/(x2*y1 - y2*x1);
	int v1 = (x - v2*x2)/x1;

	return {v1, v2};
}

void solve() {
	int x, y; cin >> x >> y;
	int c[6];
	for (int i = 0; i < 6; i++) {
		cin >> c[i];
	}

	int ans = 4e18;
	// v1*x1 + v2*x2 = x
	// v1*y1 + v2*y2 = y
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			auto [v1, v2] = solve_eq(dir[i].first, dir[i].second, dir[j].first, dir[j].second, x, y);
			if (v1 < 0 || v2 < 0) continue;
			ans = min(ans, c[i]*v1 + c[j]*v2);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}