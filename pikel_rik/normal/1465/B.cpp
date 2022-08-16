#include <bits/stdc++.h>
using namespace std;

bool fair(long long x) {
	bool ok = true;
	for (long long n = x; n; n /= 10) {
		int d = n % 10;
		ok &= d == 0 || x % d == 0;
	}
	return ok;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long x;
		cin >> x;

		while (!fair(x)) x++;
		cout << x << '\n';
	}
	return 0;
}