#include <bits/stdc++.h>

const int N = 1e5 + 50;
int n, a[N];

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		bool all_one = true;
		for (int j = 2; j < n; ++j)
			if (a[j] != 1)
				all_one = false;
		if (all_one) {
			std::cout << -1 << '\n';
			continue;
		}
		if (n == 3 && a[2] % 2 == 1) {
			std::cout << -1 << '\n';
			continue;
		}
		long long ans = 0;
		for (int j = 2; j < n; ++j) {
			ans += (a[j] + 1) >> 1;		
		}
		std::cout << ans << '\n';
	}
}