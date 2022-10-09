#include <bits/stdc++.h>

const int N = 1 << 21;

int n, a[N], mx[N], sm[N];

inline void add(int S, int v) {
	if (v >= mx[S]) {
		sm[S] = mx[S];
		mx[S] = v;
	}
	else if (v > sm[S]) {
		sm[S] = v;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		add(a[i], i);
	}
	int len = 1 << 21;
	for (int h = 1; h < len; h <<= 1)
		for (int t = len / (h << 1), j = 0; j < len;j += (h << 1))
			for (int i = j; i < j + h; ++i) {
				add(i, mx[i + h]);
				add(i, sm[i + h]);
			}
	int ans = 0;
	for (int i = 1; i <= n - 2; ++i) {
		int res = a[i], S = 0;
		for (int k = 20; k >= 0; --k)
			if (!(a[i] >> k & 1)) {
				if (sm[S | (1 << k)] > i) {
					S |= 1 << k;
				}
			}
		ans = std::max(ans, res | S);
	}
	printf("%d\n", ans);
}