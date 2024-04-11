#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		auto check = [&](int mid) {
			auto b = a;
			int rem = k;
			for (int i = 0; i < n; ++i) {
				if (b[i] * 2 < mid) {
					b[i] = 1e9;
					--rem;
				}
			}
			if (rem < 0) return false;
			if (rem >= 2) return true;
			if (rem == 1) return *std::max_element(b.begin(), b.end()) >= mid;
			for (int i = 0; i + 1 < n; ++i)
				if (b[i] >= mid && b[i + 1] >= mid)
					return true;
			return false;
		};
		int l = 1, r = 1e9, ans = -1;
		while (l <= r) {
			const int mid = l + r >> 1;
			if (check(mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		std::cout << ans << '\n';
	}
	return 0;
}