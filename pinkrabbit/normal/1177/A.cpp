#include <cstdio>

typedef long long LL;

inline LL check(LL x) {
	LL Ans = 0, y = x, c = 1, k = 1;
	while (y) {
		if (y > 9) Ans += 9 * c * k;
		else Ans += (x - c + 1) * k;
		y /= 10;
		c *= 10, ++k;
	}
	return Ans;
}

inline int digit(LL x, LL y) {
	int dig[40], t = 0;
	while (x) dig[++t] = x % 10, x /= 10;
	return dig[t - y + 1];
}

LL K;

int main() {
	scanf("%lld", &K);
	LL l = 1, r = 1e12, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid) < K) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", digit(ans + 1, K - check(ans)));
	return 0;
}