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
		for (int i = 2; i <= n + 1; ++i) std::cout << i << " ";
		std::cout << '\n';
	}
}