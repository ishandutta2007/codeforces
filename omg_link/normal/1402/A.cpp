#include <stdio.h>
#define MN 100000
typedef long long LL;

int n;
LL a[MN+5];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n==1){
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		puts("1 1");
		printf("%d\n",-a[1]);
	}else{
		printf("%d %d\n",1,n-1);
		for(int i=1;i<=n-1;i++){
			LL tmp = 1ll*(n-1)*(a[i]%n);
			printf("%lld ",tmp);
			a[i] += tmp;
		}
		puts("");
		printf("%d %d\n",n,n);
		for(int i=n;i<=n;i++){
			LL tmp = -a[n]%n;
			printf("%lld ",tmp);
			a[i] += tmp;
		}
		puts("");
		printf("%d %d\n",1,n);
		for(int i=1;i<=n;i++){
			LL tmp = 1ll*n*(-a[i]/n);
			printf("%lld ",tmp);
			a[i] += tmp;
		}
		puts("");
	}
}