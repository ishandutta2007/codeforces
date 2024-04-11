#include <bits/stdc++.h>

using namespace std;

long long get(int n, int m) {
	if (n == 1) {
		int x = m % 6;
		if (x <= 3) return m - x;
		if (x == 4) return m - 2;
		if (x == 5) return m - 1;
		return m;
	}
	if (n == 2) {
		if (m <= 2) return 0;
		if (m == 3) return 4;
		if (m == 7) return 12;
		return m * 2;
	}
	long long x = 1ll * n * m;
	return (x >> 1ll) << 1ll;
}

int main() {
	int n, m;
	cin >> n >> m;
	if (n > m) {
		swap(n, m);
	}
	cout << get(n, m) << endl;
	return 0;
}