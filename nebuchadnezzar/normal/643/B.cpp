#include <cstdio>
#include <algorithm>

int v[1010];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	if (n < 5 || n + 1 > k) {
		puts("-1");
		return 0;
	}
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int sz = 0;
	v[++sz] = a;
	v[++sz] = c;
	for (int i = 1; i <= n; ++i) {
		if (i != a && i != b && i != c && i != d) {
			v[++sz] = i;
			if (sz == 3) {
				v[++sz] = d;
			}
		}
	}
	v[++sz] = b;
	for (int i = 1; i <= n; ++i) {
		printf("%d ", v[i]);
	}
	puts("");
	printf("%d %d %d ", v[2], v[1], v[3]);
	for (int i = n; i >= 4; --i) printf("%d ", v[i]);
	puts("");
}