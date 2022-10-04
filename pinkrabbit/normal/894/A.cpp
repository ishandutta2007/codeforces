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
int n,ans;
char a[1233];
int main(){
	scanf("%s",a+1); n=strlen(a+1);
	F(i,1,n-2)
	F(j,i+1,n-1)
	F(k,j+1,n) if(a[i]=='Q'&&a[j]=='A'&&a[k]=='Q') ++ans;
	printf("%d",ans);
	return 0;
}