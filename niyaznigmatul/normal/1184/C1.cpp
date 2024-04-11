/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;


struct point {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);	
	int n;
	cin >> n;
	n = 4 * n + 1;
	vector<point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i < n; i++) {
		int minx = 100;
		int miny = 100;
		int maxx = -1;
		int maxy = -1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			minx = min(minx, a[j].x);
			miny = min(miny, a[j].y);
			maxx = max(maxx, a[j].x);
			maxy = max(maxy, a[j].y);
		}
		if (maxx - minx != maxy - miny) {
			continue;
		}
		bool bad = false;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (a[j].y != miny && a[j].y != maxy && a[j].x != minx && a[j].x != maxx) {
				bad = true;
				break;
			}
		}
		if (!bad) {
			cout << a[i].x << ' ' << a[i].y << endl;
			return 0;
		}
	}
	assert(false);
}