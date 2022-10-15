#include <cstdio>

int z[123456], s[123456];

int main() {
	int c = getchar();
	while (c <= 32) c = getchar();
	int n = 0;
	while (c > 32) {
		s[n++] = c;
		c = getchar();
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		--l;
		--r;
		int len = (r - l + 1);
		k %= len;
		for (int j = l; j <= r; j++) {
			z[(j - l + k) % len] = s[j];
		}
		for (int j = l; j <= r; j++) s[j] = z[j - l];
	}
	for (int i = 0; i < n; i++) putchar(s[i]);
	puts("");
}