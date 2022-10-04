#include<cstdio>
int n,k,t;
int main(){
	scanf("%d%d%d",&n,&k,&t);
	if(t<k) {printf("%d",t); return 0;}
	if(t>n) {printf("%d",n+k-t); return 0;}
	if(t>=k&&t<=n) {printf("%d",k); return 0;}
	return 0;
}