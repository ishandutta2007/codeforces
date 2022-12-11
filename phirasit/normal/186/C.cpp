#include <stdio.h>
#define MOD 1000000007

long long n;

long long pow2(long long k) {
	long long ans,j;
	if(k == 0) return 1;
	if(k == 1) return 2;
	j = pow2(k/2);
	ans = (j*j)%MOD;
	if(k%2) ans *= 2;
	return ans%MOD;
}
int main() {
	long long p;
	scanf("%I64d",&n);
	p = pow2(n);
	printf("%I64d\n",(p*(p+1)/2)%MOD);
	return 0;
}