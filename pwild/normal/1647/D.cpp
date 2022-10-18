#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
	if (n < 2) return false;
	for (int k = 2; k*k <= n; k++) {
		if (n%k == 0) return false;
	}
	return true;
}

bool solve(int x, int d) {
	int y = x, k = 0;
	while (y%d == 0) y /= d, k++;

	
	if (k == 1) return false;
	if (y > 1 && !is_prime(y)) return true;
	if (is_prime(d)) return false;
	if (k >= 4) return true;
	if (k == 2) return false;
	if (d%y == 0 && d/y == y) return false;
	return true;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int x, d;
		cin >> x >> d;
		cout << (solve(x,d) ? "YES" : "NO") << '\n';
	}
}