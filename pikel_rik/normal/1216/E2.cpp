#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	auto triangle = [&](long long n) -> long long {
		return (n * n + n) / 2;
	};

	auto sum_range = [&](long long a, long long b) -> long long {
		return triangle(b) - triangle(a - 1);
	};

	auto tot_digits = [&](long long n) -> long long {
		if (n <= 0) {
			return 0;
		}
		long long ans = 0;
		long long ten = 1;

		for (int d = 1; ten <= n; d++) {
			long long a = ten, b = min(10 * ten - 1, n);
			ans += d * sum_range(n - b + 1, n - a + 1);
			ten *= 10;
		}

		return ans;
	};

	while (q--) {
		long long k;
		cin >> k;

		long long lo = 0, hi = (int)1e9;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (tot_digits(mid) < k) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}

		int now = lo + 1;
		k -= tot_digits(lo);

		lo = 0, hi = now;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (tot_digits(mid) - tot_digits(mid - 1) < k) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}

		k -= tot_digits(lo) - tot_digits(lo - 1);

		string s = to_string(lo + 1);
		cout << s[k - 1] << '\n';
	}
	return 0;
}