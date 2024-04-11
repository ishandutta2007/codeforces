#include <bits/stdc++.h>
using namespace std;

const int K = 24;

int n, a[1 << K];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		set<int> masks;
		for (int j = 1; j < 8; j++) {
			int mask = 0;
			for (int k = 0; k < 3; k++) {
				if (j & (1 << k)) {
					mask |= (1 << (s[k] - 'a'));
				}
			}
			masks.insert(mask);
		}

		for (int mask : masks) {
			if (__builtin_popcount(mask) % 2 != 0) {
				a[mask] += 1;
			} else {
				a[mask] -= 1;
			}
		}
	}

	for (int i = 0; i < K; i++) {
		for (int mask = 0; mask < (1 << K); mask++) {
			if (mask & (1 << i)) {
				a[mask] += a[mask ^ (1 << i)];
			}
		}
	}

	int ans = 0;
	for (int mask = 0; mask < (1 << K); mask++) {
		ans ^= a[mask] * a[mask];
	}
	cout << ans << '\n';
	return 0;
}