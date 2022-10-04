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
int a[100001];
int main(){
	scanf("%d",&n);
	int last=0;
	For(i,n) {
		int x,y;
		scanf("%d%d",&x,&y);
		if(last<x) last=x;
		else last=x+((last-x)/y+1)*y;
	}
	printf("%d",last);
	return 0;
}