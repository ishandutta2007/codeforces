#include<cstdio>
#define rg register
int main(){
	int n;scanf("%d",&n);
	switch(n%4){
	case 0:
		puts("0");
		printf("%d ",n/2);
		for(rg int i=1;i<=n>>2;++i)printf("%d %d ",i,n-i+1);
		break;
	case 1:
		puts("1");
		n-=1;
		printf("%d ",n/2);
		for(rg int i=1;i<=n>>2;++i)printf("%d %d ",i+1,n-i+2);
		break;
	case 2:
		puts("1");
		n-=2;
		printf("%d ",n/2+1);
		for(rg int i=1;i<=n>>2;++i)printf("%d %d ",i,n-i+1);
		printf("%d",n+1);
		break;
	default:
		puts("0");
		n-=3;
		printf("%d ",n/2+2);
		for(rg int i=1;i<=n>>2;++i)printf("%d %d ",i+1,n-i+2);
		printf("%d 1",n+2);
	}
	return 0;
}