#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		int count = 0;
		for (int i = 0; i < k; ++i) if (a[i] > k) ++count;
		std::cout << count << '\n';
	}
	return 0;
}