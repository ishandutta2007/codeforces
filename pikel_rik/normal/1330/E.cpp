#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = (1 << 22);

int h, g, a[N];

bool ok(int i) {
	while (true) {
		if (a[i << 1] == 0 && a[i << 1 | 1] == 0) {
			break;
		}
		if (a[i << 1] > a[i << 1 | 1]) {
			i = i << 1;
		} else {
			i = i << 1 | 1;
		}
	}
	int msb = 32 - __builtin_clz(i) - 1;
	return msb >= g;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> h >> g;
		for (int i = 1; i < (1 << h); i++) cin >> a[i];
		fill(a + (1 << h), a + (1 << (h + 1)), 0);

		vector<int> ops;
		for (int i = 1; i < (1 << g); i++) {
			while (ok(i)) {
				ops.push_back(i);
				int j;
				for (j = i; a[j << 1] || a[j << 1 | 1];) {
					if (a[j << 1] > a[j << 1 | 1]) {
						a[j] = a[j << 1];
						j = j << 1;
					} else {
						a[j] = a[j << 1 | 1];
						j = j << 1 | 1;
					}
				}
				a[j] = 0;
			}
		}

		ll ans = 0;
		for (int i = 1; i < (1 << g); i++) {
			ans += a[i];
		}
		cout << ans << '\n';
		for (int i : ops) cout << i << ' '; cout << '\n';
	}
	return 0;
}