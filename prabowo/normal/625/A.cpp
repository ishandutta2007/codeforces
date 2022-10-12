#include <cstdio>

typedef long long LL;

int main () {
	LL n, a, b, c;
	scanf ("%I64d %I64d %I64d %I64d", &n, &a, &b, &c);
	
	LL ans1 = n / a;
	if ((n % a - c) / (b - c) > 0)
		ans1 += (n % a - c) / (b - c);
	
	LL ans2 = (n - c) / (b - c);
	if (ans2 < 0) ans2 = 0;
	ans2 += (n - ans2 * (b - c)) / a;
	
	if (ans1 < ans2) printf ("%I64d\n", ans2);
	else printf ("%I64d\n", ans1);
	return 0;
}