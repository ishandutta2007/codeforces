#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		long long x, y;
		std::cin >> x >> y;
		std::cout << x * x << " " << - y * y << '\n';
	}
}