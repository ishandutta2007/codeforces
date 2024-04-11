#include <stdio.h>
long long a[100];
int main(){
	long long n;scanf("%I64d",&n);
	a[0] = 1;
	a[1] = 2;
	int i;
	for(i=2;a[i-1]<=n;i++){
		a[i]=a[i-1]+a[i-2];
	}
	printf("%d\n",i-2);
}