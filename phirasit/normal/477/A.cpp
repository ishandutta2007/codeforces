#include <stdio.h>

#define MOD 1000000007

long long a, b;

int main() {
	scanf("%I64d%I64d", &a, &b);
	long long ans = 0;
	for(long long m = 1;m < b;m++) {
		long long sum = (a * (a + 1) / 2) % MOD;
		long long sum2 = (b * m) % MOD;
		ans = (ans + sum2 * sum + a * m) % MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}