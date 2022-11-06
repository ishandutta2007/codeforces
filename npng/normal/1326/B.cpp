#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=200000;
int n;
int b[Maxn+5];
int a[Maxn+5],c[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	c[1]=0;
	for(int i=1;i<=n;i++){
		a[i]=c[i]+b[i];
		c[i+1]=max(c[i],a[i]);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}