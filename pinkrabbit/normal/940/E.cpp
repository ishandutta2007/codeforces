#include<cstdio>
#include<algorithm>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
int n,c;
int a[100009],b[100009];
int que[100009],l=1,r=0;
ll sum,f[100009],g[100009];
int main(){
	scanf("%d%d",&n,&c);
	F(i,1,n) scanf("%d",a+i);
	F(i,1,n) sum+=a[i];
	if(c>n) {printf("%lld",sum); return 0;}
	F(i,1,c){
		while(l<=r&&a[que[r]]>=a[i]) --r;
		que[++r]=i;
	} b[1]=a[que[l]];
	F(i,c+1,n){
		if(que[l]<=i-c) ++l;
		while(l<=r&&a[que[r]]>=a[i]) --r;
		que[++r]=i;
		b[i-c+1]=a[que[l]];
	}
	F(i,1,n-c+1){
		if(i<=c) f[i]=b[i];
		else f[i]=b[i]+g[i-c];
		g[i]=max(g[i-1],f[i]);
	}
	printf("%lld",sum-g[n-c+1]);
	return 0;
}