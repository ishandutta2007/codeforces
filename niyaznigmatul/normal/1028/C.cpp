/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

struct rect {
	int x1, y1, x2, y2;

	rect inters(rect const &a) const {
		return {std::max(x1, a.x1), std::max(y1, a.y1), std::min(x2, a.x2), std::min(y2, a.y2)};
	}
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<rect> r(n);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		r[i] = {x1, y1, x2, y2};
	}
	vector<rect> mx(r.begin(), r.end());
	for (int i = 1; i < n; i++) {
		mx[i] = mx[i].inters(mx[i - 1]);
	}
	int const INF = 1 << 30;
	rect f = {-INF, -INF, INF, INF};
	for (int i = n - 1; i >= 0; i--) {
		rect cur = f;
		if (i > 0)
			cur = cur.inters(mx[i - 1]);
		if (cur.x1 <= cur.x2 && cur.y1 <= cur.y2) {
			cout << cur.x1 << ' ' << cur.y1 << endl;
			return 0;
		}
		f = f.inters(r[i]);
	}
	assert(false);
}