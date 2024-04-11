#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	std::cin >> T;

	while (T--) {
		int n, m;
		std::cin >> n >> m;
		std::cout << (n * m + 2) / 3 << '\n';
	}
}