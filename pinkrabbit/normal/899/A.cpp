#include<cstdio>
int n,a,b;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i) scanf("%d",&x), x==1?++a:++b;
	if(a<b) printf("%d",a);
	else printf("%d",b+(a-b)/3);
	return 0;
}