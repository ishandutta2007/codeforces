#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a(n), b(n);
		if (n == 4 && k == 3)
			puts("-1");
		else {
			auto connect = [&](int x, int y) {
				a[x] = y, a[y] = x;
			};
			for (int i = 0; i < (n / 2); ++i)
				connect(i, (n - 1) ^ i);
			if (k == n - 1) {
				connect(n - 1, n - 2);
				connect(n - 3, 1);
				connect(0, 2);
			}
			else {
				connect(k, n - 1);
				connect(0, (n - 1) ^ k);
			}
			for (int i = 0; i < n; ++i)
				if (!b[i]) {
					printf("%d %d\n", i, a[i]);
					b[i] = b[a[i]] = true;
				}
		}
	}
}