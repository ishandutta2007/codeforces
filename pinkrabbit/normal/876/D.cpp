#include<cstdio>
#include<algorithm>
#include<cstring>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define F2(i,a,b) for(int i=a;i<b;++i)
int n,fa[300005],o=0;
int ff(int x){return fa[x]?fa[x]=ff(fa[x]):x;}
int main(){
	int x,y;
	scanf("%d",&n);
	printf("1 ");
	F(T,1,n){
		scanf("%d",&x);
		if(x==n) o=1;
		fa[x+1]=ff(x);
		y=n+1-ff(n+1);
		printf("%d ",T-y+1);
	}
	return 0;
}