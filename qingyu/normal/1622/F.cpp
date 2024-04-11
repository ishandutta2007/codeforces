#include <bits/stdc++.h>

const int N = 1e6 + 50;

std::mt19937_64 s(std::chrono::steady_clock::now().time_since_epoch().count());

int n, pri[N], tot;
uint64_t h[N];
bool np[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	for (int i = 2; i <= n; ++i) {
		if (!np[i]) {
			pri[++tot] = i;
			h[i] = s();
		}
		for (int j = 1; j <= tot && i * pri[j] <= n; ++j) {
			np[i * pri[j]] = true;
			h[i * pri[j]] = h[i] ^ h[pri[j]];
		}
	}
	for (int i = 1; i <= n; ++i) h[i] ^= h[i - 1];
	uint64_t x = 0;
	for (int i = 1; i <= n; ++i) {
		x ^= h[i];
	}
	if (x == 0) {
		printf("%d\n", n);
		for (int i = 1; i <= n; ++i) printf("%d ", i);
	}
	else {
		if (n % 4 == 0) {
			printf("%d\n", n - 1);
			for (int i = 1; i <= n; ++i) {
				if (i != n / 2)
					printf("%d ", i);
			}
		}
		else {
			for (int i = 1; i <= n; ++i) {
				if ((x ^ h[i]) == 0) {
					printf("%d\n", n - 1);
					for (int j = 1; j <= n; ++j) if (i != j) printf("%d ", j);
					return 0;
				}
			}
			std::map<uint64_t, int> map;
			for (int i = 1; i <= n; ++i) {
				if (map.count(x ^ h[i])) {
					int j = map[x ^ h[i]];
					printf("%d\n", n - 2);
					for (int k = 1; k <= n; ++k)
						if (k != i && k != j)
							printf("%d ", k);
					return 0;
				}
				map[h[i]] = i;
			}
			assert(n % 4 != 0 && n % 4 != 2);
			printf("%d\n", n - 3);
			for (int i = 1; i <= n; ++i)
				if (i != n && i != (n - 1) / 2 && i != 2) {
					printf("%d ", i);
				}
			return 0;
		}
	}
	return 0;
}