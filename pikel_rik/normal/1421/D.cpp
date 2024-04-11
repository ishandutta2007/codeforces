#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int dir_x[6] = {1, 0, -1, -1, 0, 1};
int dir_y[6] = {1, 1, 0, -1, -1, 0};

int sign(int x) {
	if (x < 0) {
		return -1;
	} else if (x > 0) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		ll x, y;
		cin >> x >> y;

		vector<ll> c(6);
		for (ll& i : c) cin >> i;

		for (int rep = 0; rep < 6; rep++) {
			for (int mask = 0; mask < (1 << 6); mask++) {
				int xx = 0, yy = 0;
				ll cost = 0;
				for (int i = 0; i < 6; i++) {
					if (mask & (1 << i)) {
						xx += dir_x[i];
						yy += dir_y[i];
						cost += c[i];
					}
				}
				for (int i = 0; i < 6; i++) {
					if (xx == dir_x[i] && yy == dir_y[i]) {
						c[i] = min(c[i], cost);
					}
				}
			}
		}

		ll ans = 0;
		if (x < 0) {
			ans += c[2] * abs(x);
		} else {
			ans += c[5] * abs(x);
		}

		if (y < 0) {
			ans += c[4] * abs(y);
		} else {
			ans += c[1] * abs(y);
		}

		for (int i = 0; i < 6; i++) {
			if (sign(x) == dir_x[i] && sign(y) == dir_y[i]) {
				ll dist = min(abs(x), abs(y));
				if (x < 0) {
					x += dist;
				} else {
					x -= dist;
				}

				if (y < 0) {
					y += dist;
				} else {
					y -= dist;
				}

				ll cost = c[i] * dist;
				if (x < 0) {
					cost += c[2] * abs(x);
				} else {
					cost += c[5] * abs(x);
				}

				if (y < 0) {
					cost += c[4] * abs(y);
				} else {
					cost += c[1] * abs(y);
				}
				ans = min(ans, cost);
				break;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}