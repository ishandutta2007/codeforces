#include <bits/stdc++.h>

int ans[8] = {0, 0, 1, 2, 3, 4, 6, 7};

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	int Q;
	std::cin >> Q;
	for (int q = 0; q < Q; ++q) {
		long long N;
		std::cin >> N;
		long long l = 0, r = N, k = -1;
		while (l <= r) {
			long long m = (l + r) >> 1;
			if (m * (m - 1) > 2 * (N - m)) {
				r = m - 1;
			} else {
				k = m;
				l = m + 1;
			}
		}
		/*
		if (N <= 7) 
			std::cout << ans[N] << std::endl;
		else
		*/
			std::cout << std::max (k * (k - 1) / 2 + (N - k), 2 * (N - k - 1)) << std::endl;
	}
}