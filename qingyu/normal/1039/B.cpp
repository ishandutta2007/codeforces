#include <bits/stdc++.h>

inline int64_t max(int64_t a, int64_t b) { return a > b ? a : b; }
inline int64_t min(int64_t a, int64_t b) { return a < b ? a : b; }

bool ask(int64_t l, int64_t r) {
	std::cout << l << ' ' << r << std::endl;
	std::string s;
	std::cin >> s;
	return s == "Yes";
}
int main() {
	std::mt19937 g(time(0));
	int64_t n, k, L, R, now, mid;
	std::cin >> n >> k;
	for (L = 1, R = n;;) {
		while (R - L > 42)
			if (ask(L, mid = L + R >> 1)) L = max(1ll, L - k), R = min(n, mid + k);
			else L = max(1ll, mid + 1 - k), R = min(n, R + k);
		now = L + llabs(g()) % (R - L + 1);
		if (ask(now, now)) return 0;
		else L = max(1ll, L - k), R = min(n, R + k);
	}
	return 0;
}