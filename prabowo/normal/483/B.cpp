#include <cstdio>

typedef long long LL;

LL cnt1, cnt2, x, y;
bool check (long long v) {
	LL res1 = cnt1 - v / y + v / (x * y);
	LL res2 = cnt2 - v / x + v / (x * y);	
	if (res1 < 0) res1 = 0; if (res2 < 0) res2 = 0;
	return res1 + res2 <= v - v / x - v / y + v / (x * y);
}

int main () {
	
	scanf ("%I64d %I64d %I64d %I64d", &cnt1, &cnt2, &x, &y);
	
	LL l = 1;
	LL r = cnt1 + cnt2 << 2;
	
	LL v = 0;
	while (l <= r) {
		LL mid = l + r >> 1;
		if (check(mid)) {
			v = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	
	printf ("%I64d\n", v);
	
	return 0;
}