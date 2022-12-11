#include <stdio.h>

#define N 50010
#define LL long long

LL arr[N];
LL avg = 0;
LL n;

LL abs(LL x) {
	if(x < 0) return -x;
	return x;
}
int main() {
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++) {
		scanf("%lld",&arr[i]);
		avg += arr[i];
	}
	avg /= n;
	LL ans = 0;
	for(int i = 1;i <= n;i++) {
		ans += abs(avg - arr[i]);
		arr[i + 1] -= avg - arr[i];
	}
	printf("%I64d\n",ans);
	return 0;
}