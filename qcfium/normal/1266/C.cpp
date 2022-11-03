#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int h = ri();
	int w = ri();
	if (h == 1 && w == 1) {
		std::cout << 0 << std::endl;
	} else if (h == 1) {
		for (int i = 2; i <= w + 1; i++) std::cout << i << " ";
		std::cout << std::endl;
	} else if (w == 1) {
		for (int i = 2; i <= h + 1; i++) std::cout << i << std::endl;
	} else {
		for (int i = 1; i <= h; i++) {
			for (int j = h + 1; j <= h + w; j++) {
				std::cout << i * j << " ";
			}
			std::cout << std::endl;
		}
	}
	
	return 0;
}