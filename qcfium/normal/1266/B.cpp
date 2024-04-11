#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	for (int i = 0; i < n; i++) {
		int64_t x;
		std::cin >> x;
		if (x >= 14 && x % 14 >= 1 && x % 14 <= 6) {
			std::cout << "YES" << std::endl;
		} else std::cout << "NO" << std::endl;
	}
	
	return 0;
}