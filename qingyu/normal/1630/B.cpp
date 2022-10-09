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
		std::vector<int> a(n), c(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
			--a[i];
			++c[a[i]];
		}
		int len = 1e9, _x = -1, _y = -1, sum = -n;
		for (int x = 0, y = -1; x < n; ++x) {
			while (y + 1 < n && sum < k) {
				++y;
				sum += 2 * c[y];
			}
			if (sum >= k) {
				if (len > y - x) {
					len = y - x;
					_x = x;
					_y = y;
				}
			}
			sum -= 2 * c[x];
		}
		printf("%d %d\n", _x + 1, _y + 1);
		std::vector<int> b(n);
		int last = 0, p = 1;
		for (int i = 0; i < n; ++i) {
			if (p == k) break;
			if (i) b[i] = b[i - 1];
			if (_x <= a[i] && a[i] <= _y) b[i]++;
			else b[i]--;
			if (b[i] == p) {
				printf("%d %d\n", last + 1, i + 1);
				last = i + 1;
				++p;
			}
		}
		printf("%d %d\n", last + 1, n);
	}
}