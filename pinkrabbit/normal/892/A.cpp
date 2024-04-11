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
int a[100001],b[100001];
long long sum;
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i), sum+=a[i];
	F(i,1,n) scanf("%d",b+i);
	sort(b+1,b+n+1);
	if(sum<=b[n]+b[n-1]) puts("Yes");
	else puts("No");
	return 0;
}