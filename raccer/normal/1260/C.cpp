#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	return !b ? a : gcd(b, a % b);
}

int main () {
	int T; cin >> T;
	while (T--) {
		long long x, y, k; cin >> x >> y >> k;
		long long g = gcd(x, y);
		x /= g, y /= g;
		if (x > y) swap(x, y);
		if (x * (k - 1) + 1 < y) printf("REBEL\n");
		else printf("OBEY\n");
	}
	return 0;
}