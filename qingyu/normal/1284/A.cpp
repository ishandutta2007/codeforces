#include <bits/stdc++.h>

std::string s[105], t[105];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> s[i];
	for (int i = 1; i <= m; ++i) std::cin >> t[i];
	int tt = n * m / std::gcd(n, m);
	int q;
	std::cin >> q;
	while (q--) {
		int k, a = 1, b = 1;
		std::cin >> k;
		--k;
		k %= tt;
		for (int i = 1; i <= k; ++i) {
			a = a % n + 1;
			b = b % m + 1;
		}
		std::cout << s[a] << t[b] << '\n';
	}
	return 0;
}