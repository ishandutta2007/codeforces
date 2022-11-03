#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	if (n % 2) {
		std::cout << "YES" << std::endl;
		int res[2 * n];
		for (int i = 0; i < n; i++) {
			res[i] = 2 * i + 1;
			res[i + n] = 2 * i + 2;
			if (i % 2) std::swap(res[i], res[i + n]);
		}
		for (int i = 0; i < 2 * n; i++) {
			if (i) std::cout << " ";
			std::cout << res[i];
		}
	} else {
		std::cout << "NO" << std::endl;
	}
	return 0;
}