#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		long long w, h;
		std::cin >> w >> h;
		long long ans = 0;
		for (int _ = 0; _ < 2; ++_) {
			int k;
			std::cin >> k;
			std::vector<long long> a(k);
			for (auto &x : a) std::cin >> x;
			ans = std::max(ans, (a[k - 1] - a[0]) * h);
		}
		for (int _ = 0; _ < 2; ++_) {
			int k;
			std::cin >> k;
			std::vector<long long> a(k);
			for (auto &x : a) std::cin >> x;
			ans = std::max(ans, (a[k - 1] - a[0]) * w);
		}
		std::cout << ans << '\n';
	}
}