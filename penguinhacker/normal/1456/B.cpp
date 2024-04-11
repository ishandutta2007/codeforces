#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define lbit(x) 31 - __builtin_clz(x)

int n, a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i + 2 < n; ++i) {
		if (lbit(a[i]) == lbit(a[i + 1]) && lbit(a[i]) == lbit(a[i + 2])) {
			cout << 1;
			return 0;
		}
	}
	assert(n < 100);
	int ans = 6969;
	for (int i = 0; i + 1 < n; ++i) {
		int curl = 0;
		for (int l = 0; i - l >= 0; ++l) {
			int curr = 0;
			curl ^= a[i - l];
			for (int r = 0; i + 1 + r < n; ++r) {
				curr ^= a[i + 1 + r];
				if (curl > curr) {
					ans = min(ans, l + r);
					break;
				}
			}
		}
	}
	cout << (ans != 6969 ? ans : -1);
	return 0;
}