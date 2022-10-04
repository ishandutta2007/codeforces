#include<cstdio>
int n,x,a[1001],less,ans;
int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i]<x) ++less;
		if(a[i]==x) ++ans;
	}
	printf("%d",ans+x-less);
	return 0;
}