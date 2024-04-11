#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int t = ri();
	for (int i = 0; i < t; i++) {
		int64_t a, b, n, m;
		scanf("%" SCNd64 "%" SCNd64 "%" SCNd64 "%" SCNd64 , &a, &b, &n, &m);
		int64_t min = std::min(a, b);
		bool res = min >= m && n + m <= a + b;
		puts(res ? "Yes" : "No");
	}
	return 0;
}