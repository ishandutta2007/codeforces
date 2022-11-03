#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	std::map<int, int> a[n];
	int cnt[200001] = { 0 };
	for (int i = 0; i < n; i++) {
		int x = ri();
		for (int j = 2; j * j <= x; j++) while (x % j == 0) a[i][j]++, cnt[j]++, x /= j;
		if (x > 1) a[i][x]++, cnt[x]++;
	}
	int64_t res = 1;
	for (int i = 2; i <= 200000; i++) if (cnt[i] >= n - 1) {
		std::vector<int> tmp(n);
		for (int j = 0; j < n; j++) tmp[j] = a[j][i];
		std::sort(tmp.begin(), tmp.end());
		for (int j = 0; j < tmp[1]; j++) res *= i;
	}
	printf("%" PRId64 "\n", res);
	
	return 0;
}