#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		int a, b;
		std::cin >> a >> b;
		if (a > b) {
			std::cout << a + b << '\n';
		}
		else {
			std::cout << b - b % a / 2 << '\n';
		}
	}
}