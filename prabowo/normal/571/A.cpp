#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL l, a, b, c;

LL C(LL x, LL y) {
	if (x < y) return 0;
	LL ret = 1;
	for (int i=0; i<y; i++) ret *= (x-i), ret /= (i + 1);
	return ret;
}

int main () {
	scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &l);
	
	LL ans = C(l+3, 3);
	for (int i=0; i<=l; i++) {
		ans -= C(min(a - b - c + i, l - i) + 2, 2);
		ans -= C(min(b - a - c + i, l - i) + 2, 2);
		ans -= C(min(c - a - b + i, l - i) + 2, 2);
	}
	
	printf("%I64d\n", ans);
	return 0;
}