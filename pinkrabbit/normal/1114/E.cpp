#include <cstdio>
#include <algorithm>
// lg
inline unsigned Uran() {
	static unsigned x = 20021005;
	return x ^= x << 17, x ^= x >> 13, x ^= x << 5;
}
inline int Mran(int L, int R) {
	return Uran() % (R - L + 1) + L;
}

int N, cnt, d;

int main() {
	scanf("%d", &N);
	int l = N, r = 1e9, mid, x, mx = N - 1;
	while (l <= r) {
		mid = (l + r) >> 1;
		printf("> %d\n", mid - 1);
		fflush(stdout);
		scanf("%d", &x);
		++cnt;
		if (x) mx = mid, l = mid + 1;
		else r = mid - 1;
	}
	while (cnt < 60) {
		printf("? %d\n", Mran(1, N));
		fflush(stdout);
		scanf("%d", &x);
		++cnt;
		d = std::__gcd(d, mx - x);
	}
	printf("! %d %d\n", mx - (N - 1) * d, d);
	return 0;
}