#include <stdio.h>
#define N 1000005
const int P=998244353;
long long inv[N];
long long ex(long long b, int i) {
	long long p=1;
	for(; i; i>>=1, b=b*b%P) if(i&1) p=p*b%P;
	return p;
}
int main() {
	int n, i, ans, binom, power;
	scanf("%d", &n);
	inv[1]=1;
	for(i=2; i<=n; ++i) inv[i]=inv[P%i]*(P-P/i)%P;
	power=ex(3,n);
	ans=(ex((power+P-1)%P,n)*3-ex((power+P-3)%P,n)*2%P+P-ex(power,n)+P)%P;
	binom=n&1?1:-1;
	power=1;
	for(i=0; i<n; ++i) {
		if(i) {
			binom=(P-binom)*(n-i+1ll)%P*inv[i]%P;
			power=power*3ll%P;
		}
		ans=(ans+binom*ex(power-1, n)*3ll)%P;
	}
	printf("%d\n", ans<0?ans+P:ans);
	return 0;
}