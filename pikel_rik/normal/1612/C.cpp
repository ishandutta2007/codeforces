#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto sum = [&](long long n) -> long long {
		return (n * n + n) / 2;
	};

	while (t--) {
		long long k, x;
		cin >> k >> x;

//		long long one_message = sum(k) + sum(k - 1);
//		long long emote_triangles = x / one_message;
//		x %= one_message;

		auto f = [&](long long n) -> long long {
			if (n <= k) {
				return sum(n);
			} else {
				n -= k;
				return sum(k) + sum(k - 1) - sum(k - 1 - n);
			}
		};

		long long lo = 0, hi = 2 * k - 1;
		while (lo < hi) {
			long long mid = lo + (hi - lo) / 2;
			if (f(mid) >= x) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}

//		cout << (2 * k - 1) * emote_triangles + lo << '\n';
		cout << lo << '\n';
	}
	return 0;
}