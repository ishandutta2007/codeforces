#include <stdio.h>
#include <math.h>

long long n;

int main() {
	scanf("%I64d", &n);
	if(n == 0) {
		printf("1\n");
		return 0;
	}
	int ls = n;
	long long cnt = 0;
	for(long long i = 1;i <= n;i++) {
		long long t = sqrt(n*n-i*i);
		if(ls > t) {
			cnt += ls-t-1;
		}
		ls = t;
	}
	cnt += n-1;
	long long ans = 4*cnt + 4;
	printf("%I64d\n", ans);
	return 0;
}