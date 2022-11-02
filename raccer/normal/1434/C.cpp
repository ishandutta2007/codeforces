#include <bits/stdc++.h>
using namespace std;

typedef long long num;

const long long INF = 0x3f3f3f3f3f3f3f3f;

long long a, b, c, d;

long long f(long long x) {
	long long ans = (x / d + 1) * a, lst = 0;
	if (x - c - 1 >= 0) {
		if (ans / b / c < (x - c - 1) / d + 1) return -INF - x;
		ans -= ((x - c - 1) / d + 1) * b * c;
		lst = (x - c - 1) / d * d + d;
	}
	if (lst > x) return ans;
	long long total = (x - lst) / d + 1;
//	cerr << "          total:" << total << endl;
//	cerr << "                        sum:" << (x - lst) * b * total << " " << b * d * (total - 1) * total / 2 << endl;
	ans += (b * d * (total - 1)) * total / 2;
	if (ans / b / total < (x - lst)) return -INF - x;
	ans -= (x - lst) * b * total;
	return ans;
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		long long aa, bb, cc, dd;
		scanf("%I64d%I64d%I64d%I64d", &aa, &bb, &cc, &dd);
		a = aa, b = bb, c = cc, d = dd;
		if (b * c < a) {
			printf("-1\n");
			continue;
		}
		if (d >= c) {
			printf("%I64d\n", (long long)a);
			continue;
		}
		long long l = 0, r = 1000000000000;
		while (l < r) {
			long long mid = l + r + 1 >> 1;
			if (f(mid * d) - f(mid * d - d) > 0) l = mid;
			else r = mid - 1;
		}
		printf("%I64d\n", (long long)f(l * d));
	}
	return 0;
}