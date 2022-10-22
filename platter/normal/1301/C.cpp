#include <cstdio>

long long n,m;

long long f(long long x) {
	return (x*x+x)/2;
}

int main(void) {
	int c;
	scanf("%d\n",&c);
	for(int t=0;t<c;t++) {
		scanf("%lld %lld\n",&n,&m);
		long long wid=(n-m)/(m+1);
		long long left=(n-m)%(m+1);
		printf("%lld\n",f(n)-left*f(wid+1)-(m+1-left)*f(wid));
	}
}