#include <stdio.h>

long long n,k;

int main() {
	scanf("%I64d %I64d",&n,&k);
	if(k <= n/2 + n%2)
		printf("%I64d\n",2*k-1);
	else
		printf("%I64d\n",2*(k-n/2-n%2));
	return 0;
}