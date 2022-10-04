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
int n,L;
int c[101];
ll sum;
ll ans=9223372036854775000ll;
int main(){
	scanf("%d%d",&n,&L);
	F(i,1,n) scanf("%d",c+i);
	F(i,2,n) if(c[i]>c[i-1]+c[i-1]) c[i]=c[i-1]+c[i-1];
	dF(i,n-1,1) if(c[i]>c[i+1]) c[i]=c[i+1];
	dF(i,n,1) sum+=1ll*(L>>(i-1))*c[i], L&=((1<<(i-1))-1), ans=Min(ans,sum+c[i]);
	ans=Min(ans,sum);
	printf("%I64d",ans);
	return 0;
}