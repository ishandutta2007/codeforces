#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
int n;
int a[1001], sons[1001], sons2[1001];
int q[1010], r=0;
int main(){
	scanf("%d",&n);
	F(i,2,n) scanf("%d",a+i), ++sons[a[i]];
	F(i,1,n) if(sons[i]==0) q[++r]=i;
	F(i,1,r) ++sons2[a[q[i]]];
	F(i,1,n) if(sons[i]!=0&&sons2[i]<3) {puts("No"); return 0;}
	puts("Yes");
	return 0;
}