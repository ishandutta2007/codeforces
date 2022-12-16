#include <stdio.h>
#include <stdlib.h>
typedef long long LL;
LL s,x,n,res=1;
int main(){
	scanf("%lld%lld",&s,&x); n=s-x;
	if(n<0||(n&1)){putchar('0');exit(0);}
	for(int i=1;i<=60;++i){
		if(((x>>(i-1))&1)&&((n>>i)&1)==0)res<<=1;
		if(((x>>(i-1))&1)&&((n>>i)&1)==1){putchar('0');exit(0);}
	}
	if(n==0)res-=2;
	printf("%lld",res);
}