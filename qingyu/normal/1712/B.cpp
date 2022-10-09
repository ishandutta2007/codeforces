#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		if (n % 2 == 0) {
			for (int i = 0; i + 1 < n; i += 2) {
				a[i] = i + 2;
				a[i + 1] = i + 1;
			}
		}
		else {
			a[0] = 1;
			for (int i = 1; i + 1 < n; i += 2) {
				a[i] = i + 2;
				a[i + 1] = i + 1;
			}
		}
		for (int i = 0; i < n; ++i)
			std::cout << a[i] << " \n"[i == n - 1];
	}
	return 0;
}