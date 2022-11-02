#include <bits/stdc++.h>
using namespace std;

long long a[100010], b[100010];

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d%I64d", &a[i], &b[i]);
		a[i] *= 2, b[i] *= 2;
	}
	if (n & 1) {
		printf("NO\n");
		return 0;
	}
	long long xx = -1, yy = -1;
	for (int i = 0; i < n; i++) {
		long long x = a[i] + a[(i + n / 2) % n] >> 1, y = b[i] + b[(i + n / 2) % n] >> 1;
		if (xx == -1) xx = x, yy = y;
		else if (xx != x || yy != y) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}