#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}


int main() {
	int64_t a[3];
	for (auto &i : a) i = ri();
	puts("First");
	fflush(stdout);
	
	puts("200000000000");
	fflush(stdout);
	
	int n;
	scanf("%d", &n);
	if (n == -1) return 0;
	if (n == 0) return 0;
	n--;
	a[n] += 200000000000;
	
	int64_t cur[3];
	memcpy(cur, a, sizeof(a));
	std::sort(cur, cur + 3);
	
	printf("%" PRId64 "\n", cur[2] * 2 - cur[1] - cur[0]);
	fflush(stdout);
	scanf("%d", &n);
	if (n == -1) return 0;
	if (n == 0) return 0;
	
	a[n - 1] += cur[2] * 2 - cur[1] - cur[0];
	
	memcpy(cur, a, sizeof(a));
	std::sort(cur, cur + 3);
	printf("%" PRId64 "\n", cur[2] - cur[1]);
	fflush(stdout);
	
	return 0;
}