#include <bits/stdc++.h>

using namespace std;

bool solve() {
	int n, x0, y0, x1, y1, x2, y2, x, y;
	cin >> n >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x >> y;
	int xx = x0 ^ x1 ^ x2;
	int yy = y0 ^ y1 ^ y2;
	auto exist = [&](int xz, int yz) {
		return (x0 == xz && y0 == yz) ||
			(x1 == xz && y1 == yz) ||
			(x2 == xz && y2 == yz);
	};
	if (xx % 2 == x % 2 && yy % 2 == y % 2) {
		return false;
	}
	if (exist(1, 1) && exist(1, 2) && exist(2, 1)) {
		if ((x != 1) && (y != 1)) {
			return false;
		}
	}
	if (exist(1, n) && exist(1, n - 1) && exist(2, n)) {
		if ((x != 1) && (y != n)) {
			return false;
		}
	}
	if (exist(n, 1) && exist(n - 1, 1) && exist(n, 2)) {
		if ((x != n) && (y != 1)) {
			return false;
		}
	}
	if (exist(n, n) && exist(n - 1, n) && exist(n, n - 1)) {
		if ((x != n) && (y != n)) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		cout << (solve() ? "YES" : "NO") << '\n';;
	}
}