#include <stdio.h>

long long A, B, n;

long long val(int l, int r) {
	long long len = r - l + 1ll;
	long long lf = A + (l - 1ll) * B, rg = A + (r - 1ll) * B;
	return len * (lf + rg) / 2ll; 
}
int main() {
	scanf("%I64d%I64d%I64d", &A, &B, &n);
	for(int i = 0;i < n;i++) {
		long long l, t, m;
		scanf("%I64d%I64d%I64d", &l, &t, &m);
		long long a = l - 1ll, b = l + t;
		while(a < b) {
			long long mid = (a + b) / 2ll + 1ll;
			(val(l, mid) <= m*t && val(mid, mid) <= t) ? a = mid : b = mid - 1;	
		}
		printf("%I64d\n", a == l - 1ll? -1ll : a);
	}
	return 0;
}