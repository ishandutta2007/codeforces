#include <stdio.h>
typedef long long LL;
LL n,a,b;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n*2;i++){
		static LL t1,t2;
		scanf("%lld%lld",&t1,&t2);
		a+=t1,b+=t2;
	}
	printf("%lld %lld\n",a/n,b/n);
}