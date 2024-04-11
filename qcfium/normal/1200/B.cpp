#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

bool solve() {
	int n = ri();
	int m = ri();
	int k = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri();
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] < a[i + 1] - k) {
			if (m >= a[i + 1] - k - a[i]) m -= a[i + 1] - k - a[i];
			else return false;
		} else m += a[i] - std::max(a[i + 1] - k, 0);
	}
	return true;
}

int main() {
	int t = ri();
	for (int i = 0; i < t; i++) std::cout << (solve() ? "YES" : "NO") << std::endl;
	return 0;
}