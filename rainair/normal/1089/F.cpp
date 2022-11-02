#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long llong;
const llong maxn = 1e6;
llong n, m, a[maxn + 3];

llong gcd(llong a, llong b) {
	return b ? gcd(b, a % b) : a;
}

llong exgcd(llong a, llong b, llong &x, llong &y) {
	if (!b) { x = 1, y = 0; return a; }
	llong d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main() {
	scanf("%lld", &n);
	for (llong i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			a[++m] = i;
			if (i * i != n) a[++m] = n / i;
		}
	}
	sort(a + 1, a + m + 1);
	llong p = 1, q = 2, x, y;
	while (q <= m && gcd(a[p], a[q]) > 1) q++;
	if (q > m) puts("NO"), exit(0);
	p = a[p], q = a[q];
	exgcd(p, q, x, y);
	x = -x, y = -y + n / q;
	llong t = (max(0ll, -x) + q - 1) / q;
	x += t * q, y -= t * p;
	t = (max(0ll, -y) + p - 1) / p;
	x -= t * q, y += t * p;
	if (x > y) swap(x, y), swap(p, q);
	if (x < 0) puts("NO"), exit(0);
	puts("YES");
	if (x == 0) puts("1"), printf("%lld %lld\n", y, n / q);
	else puts("2"), printf("%lld %lld\n", x, n / p), printf("%lld %lld\n", y, n / q);
	return 0;
}