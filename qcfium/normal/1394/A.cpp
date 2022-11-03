#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}


int main() {
	int n = ri();
	int d = ri();
	int m = ri();
	int a[n];
	for (auto &i : a) i = ri();
	std::sort(a, a + n, std::greater<>());
	
	int cnt = 0;
	for (auto i : a) if (i > m) cnt++;
	
	int64_t sum[n + 1];
	sum[0] = 0;
	for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
	
	int64_t res = 0;
	for (int i = 0; i <= cnt; i++) {
		int64_t used = std::max<int64_t> (0, 1 + (int64_t) (i - 1) * (d + 1));
		if (used > n) continue;
		res = std::max(res, sum[i] + sum[std::min<int64_t>(n, cnt + n - used)] - sum[cnt]);
	}
	printf("%" PRId64 "\n", res);
	
	return 0;
}