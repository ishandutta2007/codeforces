#include <stdio.h>
#include <limits.h>

#define LL long long

LL a,b;
LL n,k;

int main() {
	LL i;
	scanf("%I64d %I64d",&n,&k);
	a = 1;
	b = 1e10;
	while(a < b) {
		LL m = (a+b)/2,p = 0;
		for(i=1;i<=m;i*=k)
			p += m/i;
		if(p >= n)
			b = m;
		else
			a = m+1;
	}
	printf("%I64d\n",b);
	return 0;
}