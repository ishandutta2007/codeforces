#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n), min(n, 0x3f3f3f3f), max(n, 0xcfcfcfcf);
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];
		max[0] = a[0], min[n - 1] = a[n - 1];
		for (int i = 1; i < n; ++i)
			max[i] = std::max(a[i], max[i - 1]);
		for (int i = n - 2; i >= 0; --i)
			min[i] = std::min(a[i], min[i + 1]);
		bool ok = false;
		for (int i = 0; i + 1 < n; ++i)
			if (max[i] > min[i + 1])
				ok = true;
		puts(ok ? "YES" : "NO");
	}
}