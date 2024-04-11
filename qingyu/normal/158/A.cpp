#include <bits/stdc++.h>

int main() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a.begin(), a.end(), std::greater<int>());
	int limit = std::max(1, a[k - 1]);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] >= limit)
			++cnt;
	std::cout << cnt;
}