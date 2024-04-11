#include <cstdio>
#include <algorithm>
typedef long long ll;

int main() {
	int n, d, h;
	scanf("%d%d%d", &n, &d, &h);
	if ((h + h < d)) {
		puts("-1");
		return 0;
	}
	if (h == 1) {
		if (d == 1) {
			if (n == 2) {
				printf("%d %d\n", 1, 2);
			} else {
				puts("-1");
			}
		} else {
			for (int i = 2; i <= n; ++i) {
				printf("%d %d\n", 1, i);
			}
		}
		return 0;
	}
	if (d == h) {
		for (int i = 1; i <= h; ++i) {
			printf("%d %d\n", i, i + 1);
		}
		int ver = h + 2;
		while (ver <= n) {
			printf("%d %d\n", h, ver);
			++ver;
		}
		return 0;
	}
	for (int i = 1; i <= h; ++i) {
		printf("%d %d\n", i, i + 1);
	}
	int ver = h + 2;
	printf("1 %d\n", ver);
	for (int i = 0; i < d - h - 1; ++i) {
		printf("%d %d\n", ver, ver + 1);
		++ver;
	}
	++ver;
	while (ver <= n) {
		printf("%d %d\n", 1, ver);
		++ver;
	}
}