#include <stdio.h>
#include <stdlib.h>
typedef long long LL;
int n,m,x,y; LL k;
int main(){
	scanf("%d%d%I64d",&n,&m,&k);
	if(k<n){printf("%I64d 1",k+1);exit(0);}
	k-=n; m--;
	if((k/m)%2==1){
		x=n-k/m;
		y=m+1-k%m;
	}else{
		x=n-k/m;
		y=k%m+2;
	}
	printf("%d %d",x,y);
}