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
		int g = 0;
		for (int i = 0; i < 30; ++i) {
			int cnt = 0;
			for (int x : a) cnt += (x >> i & 1);
			g = std::gcd(g, cnt);
		}
		for (int i = 1; i <= n; ++i)
			if (g % i == 0)
				std::cout << i << " ";
		std::cout << '\n';
	}
}