#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#define For(i,a) for(int i=1;i<=a;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dFor(i,a) for(int i=a;i>=1;--i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
int n,m,k;
int a[100001],A[10001],t;
int vis[10001];
int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n) scanf("%d",a+i);
	F(i,1,n){
		if(!vis[a[i]]) A[++t]=i;
		vis[a[i]]=1;
	}
	if(t>=k){
		puts("YES");
		F(i,1,k) printf("%d ",A[i]);
	}
	else puts("NO");
	return 0;
}