#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int n, s, c3, c4, c5, ans = inf, a3, a4, a5;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s;
	int x;
	while(n--) {
		cin >> x;
		if(x == 3) c3++;
		if(x == 4) c4++;
		if(x == 5) c5++;
	}
	int l = lcm(c3, c5);
	for(int k4 = 0; k4 <= s / c4; k4++) {
		int z = k4 * c4, xlim = c3 * k4, ylim = c5 * k4;
		n = s - z;
		auto chk = [&](int x, int y) {
			if(0 <= x && x <= xlim && y >= ylim && x % c3 == 0 && y % c5 == 0) {
				int c = abs(x - z) + abs(y - z);
				if(c < ans) ans = c, a3 = x, a4 = k4, a5 = y;
			}
		};
		for(int x = xlim; x > xlim - l; x -= c3) chk(x, n - x);
		for(int y = ylim; y < ylim + l; y += c5) chk(n - y, y);
		if(n <= z << 1) {
			int xs = z / c3 * c3, ys = z / c5 * c5;
			for(int x = xs; x > xs - l; x -= c3) chk(x, n - x);
			for(int y = ys; y > ys - l; y -= c5) chk(n - y, y);
		} else {
			int xs = (z + c3 - 1) / c3 * c3, ys = (z + c5 - 1) / c5 * c5;
			for(int x = xs; x < xs + l; x += c3) chk(x, n - x);
			for(int y = ys; y < ys + l; y += c5) chk(n - y, y);
		}
	}
	if(ans == inf) cout << -1;
	else cout << a3 / c3 << ' ' << a4 << ' ' << a5 / c5;
}