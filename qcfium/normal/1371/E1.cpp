#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int p = ri();
	int a[n];
	for (auto &i : a) i = ri();
	std::sort(a, a + n, std::greater<>());
	int min = 1;
	for (int i = 0; i < n; i++) min = std::max(min, a[i] - (n - 1 - i));
	
	for (auto &i : a) i = n - (i - min);
	for (auto &i : a) i = std::min(i, n);
	for (int i = 0; i < n; i++) a[i] -= i;
	// for (auto i : a) printf("%d\n", i);
	// max : n, n - 1, 
	
	bool ok[n + 1];
	for (auto &i : ok) i = true;
	for (int i = 0; i < n; i++) {
		int max = n - i;
		int clearance = max - a[i];
		if (max == p) {
			for (int j = clearance; j <= n; j++) ok[j] = false;
		} else if (max > p && p >= a[i]) ok[p - a[i]] = false;
	}
	std::vector<int> res;
	for (int i = 0; i <= n; i++) if (ok[i]) res.push_back(i + min);
	printf("%d\n", (int) res.size());
	for (auto i : res) printf("%d ", i);
	puts("");
	
	return 0;
}