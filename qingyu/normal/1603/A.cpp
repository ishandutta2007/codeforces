#include <bits/stdc++.h>

int main() {
	int T;
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1), b(n + 1);
		for (int i = 1; i <= n; ++i) {
			std::cin >> a[i];
			b[i] = 1;
			while (a[i] % (b[i] + 1) == 0) ++b[i];
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i)
			if (b[i] > i) {
				ok = false;
				break;
			}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}