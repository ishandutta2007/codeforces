#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int &x : a) std::cin >> x;
		auto solve = [&](int x) {
			if (x >= 0 && x % 3 == 0) return x / 3;
			return 0x3f3f3f3f;
		};
		int ans = 0x3f3f3f3f;
		for (int c1 : {0, 1})
			for (int c2 : {0, 1, 2}) {
				int upper = 0;
				for (int x : a) {
					int min = 0x3f3f3f3f;
					for (int i = 0; i <= c1; ++i)
						for (int j = 0; j <= c2; ++j)
							min = std::min(min, solve(x - i - j * 2));
					upper = std::max(upper, min);
				}
				ans = std::min(ans, upper + c1 + c2);
			}
		std::cout << ans << '\n';
	}
}