#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 1;
const ll LINF = (ll) 1e18 + 1;
const ld EPS = 1e-9;

void run() {
	int n;
	ll x0, y0;
	cin >> n;
	cin >> x0 >> y0;
	
	pair<ll, int> dir[8];
	for (int i = 0; i < 8; i++) {
		dir[i] = {LINF, ' '};
	}
	
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		ll x, y;
		cin >> x >> y;
		ll d = abs(x - x0) + abs(y - y0);
		
		if (x == x0) {
			if (y < y0) {
				dir[4] = min(dir[4], {d, c});
			} else if (y > y0) {
				dir[0] = min(dir[0], {d, c});
			}
		}
		
		if (y == y0) {
			if (x < x0) {
				dir[6] = min(dir[6], {d, c});
			} else if (x > x0) {
				dir[2] = min(dir[2], {d, c});
			}
		}
		
		if (x + y == x0 + y0) {
			if (y < y0) {
				dir[7] = min(dir[7], {d, c});
			} else if (y > y0) {
				dir[3] = min(dir[3], {d, c});
			}
		}
		
		if (x - y == x0 - y0) {
			if (y < y0) {
				dir[5] = min(dir[5], {d, c});
			} else if (y > y0) {
				dir[1] = min(dir[1], {d, c});
			}
		}
	}
	
	bool ok = false;
	
	for (int i = 0; i < 8; i++) {
		if (dir[i].first != LINF && dir[i].second == 'Q') {
			ok = true;
		}
	}
	
	for (int i = 0; i < 8; i += 2) {
		if (dir[i].first != LINF && dir[i].second == 'R') {
			ok = true;
		}
	}
	
	for (int i = 1; i < 8; i += 2) {
		if (dir[i].first != LINF && dir[i].second == 'B') {
			ok = true;
		}
	}
	
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	run();
	
	return 0;
}