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
int a[25],I[25],b[25];
inline bool cmp(int p1,int p2){return a[p1]<a[p2];}
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i), I[i]=i;
	sort(I+1,I+n+1,cmp);
	F(i,1,n) b[I[i]]=a[I[i%n+1]];
	F(i,1,n) printf("%d ",b[i]);
	return 0;
}