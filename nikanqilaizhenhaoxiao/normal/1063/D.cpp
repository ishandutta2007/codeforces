#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	long long n, k, len, l, r;
	cin >> n >> l >> r >> k;
	len = (r >= l ? r - l + 1 : r + n - l + 1);
	long long ans = -1;

	if(len == n) {
		long long x;
		for (long long i = 1; i * i <= k; ++i) if(k % i == 0) {
			x = i;
			if(x >= n && x <= 2 * n) ans = max(ans, x - n);
			x = k / i;
			if(x >= n && x <= 2 * n) ans = max(ans, x - n);
		}
		++k;
		for (long long i = 1; i * i <= k; ++i) if(k % i == 0) {
			x = i;
			if(x > n && x <= 2 * n) ans = max(ans, x - n);
			x = k / i;
			if(x > n && x <= 2 * n) ans = max(ans, x - n);
		}
		cout << ans << endl;
		return 0;
	}

	if(k >= len && k <= 2 * len) {
		ans = max(ans, min(len, k - len + 1) + n - len);
	}
	cerr << ans << endl;

	for (long long x = n; x <= 1123456; ++x) {
		long long a = k % x, b = x - a;
		if(len <= a && a <= 2 * len && n - len <= b && b <= 2 * (n - len)) {
			ans = max(ans, x - n);
		}
		a = (k + 1) % x; b = x - a;
		if(len < a && a <= 2 * len && n - len <= b && b <= 2 * (n - len)) {
			ans = max(ans, x - n);
		}
	}
	cerr << ans << endl;

	for (long long t = 1; t <= 100000; ++t) {
		long long lb = 0, rb = k / t;
		while(lb <= rb) {
			long long mid = lb + rb >> 1;
			long long a = k - t * mid, b = mid - a;
			if(a < len || b > 2 * (n - len)) rb = mid - 1;
			else lb = mid + 1;
		}
		long long x = rb;
		if(n <= x && x <= 2 * n) {
			long long a = k - x * t, b = x - a;
			if(len <= a && a <= 2 * len && n - len <= b && b <= 2 * (n - len)) {
				ans = max(ans, x - n);
			}
		}
	}
	cerr << ans << endl;

	++k;
	for (long long t = 1; t <= 100000; ++t) {
		long long lb = 0, rb = k / t;
		while(lb <= rb) {
			long long mid = lb + rb >> 1;
			long long a = k - t * mid, b = mid - a;
			if(a < len || b > 2 * (n - len)) rb = mid - 1;
			else lb = mid + 1;
		}
		long long x = rb;
		if(n <= x && x <= 2 * n) {
			long long a = k - x * t, b = x - a;
			if(len < a && a <= 2 * len && n - len <= b && b <= 2 * (n - len)) {
				ans = max(ans, x - n);
			}
		}
	}
	cerr << ans << endl;

	cout << ans << endl;
	return 0;
}