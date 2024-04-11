#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q, MOD;
	cin >> n >> q >> MOD;

	vector<int> fib(n);
	fib[1] = 1;
	for (int i = 2; i < n; i++) {
		fib[i] = (fib[i-1] + fib[i-2]) % MOD;
	}

	vector<int> a(n), b(n);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;

	vector<int> c(n), d(n);
	int zero_count = n;

	auto add = [&](int i, int x) {
		if (i >= n) return;
		zero_count -= d[i] == 0;
		d[i] = (d[i] + x) % MOD;
		zero_count += d[i] == 0;
	};

	for (int i = 0; i < n; i++) {
		c[i] = (a[i]-b[i]) % MOD;
		add(i, c[i]);
		if (i > 0) add(i, -c[i-1]);
		if (i > 1) add(i, -c[i-2]);
	}

	while (q--) {
		char c; cin >> c;
		int i, j;
		cin >> i >> j;
		i--;

		int sign = c == 'A' ? 1 : -1;

		// a[i] += fib[1], a[i+1] += fib[2], ... a[j-1] += fib[j-i]
		auto in_range = [&](int k) { return i <= k && k < j; };
		for (int k = i; k < j+2; k++) {
			if (k == i+2 && k < j) k = j;
			if (in_range(k)) add(k, sign*fib[k-i+1]);
			if (in_range(k-1)) add(k, -sign*fib[k-i]);
			if (in_range(k-2)) add(k, -sign*fib[k-i-1]);
		}

		cout << (zero_count == n ? "YES" : "NO") << '\n';
	}
}