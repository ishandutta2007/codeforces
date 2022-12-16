#include <bits/stdc++.h>

int M, N;
int cyc[100];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		std::cout << 1 << std::endl;
		std::cin >> cyc[i];
		if (cyc[i] == 0) return 0;
		if (cyc[i] == -2) return 0;
	}
	int l = 1, r = M, cnt = 0;
	while (l <= r) {
		int m = (l + r) / 2, x;
		std::cout << m << std::endl;
		std::cin >> x;
		if (x == 0) return 0;
		if (x == -2) return 0;
		if (cyc[cnt] * x == 1) l = m + 1;
		else r = m - 1;
		cnt = (cnt + 1) % N;
	}
}