#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
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
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
inline int Abs(int X){return X<0?-X:X;}
int n,p,l,r;
int main(){
	scanf("%d%d%d%d",&n,&p,&l,&r);
	if(l==1&&r==n){puts("0");return 0;}
	if(l==1){printf("%d",Abs(p-r)+1);return 0;}
	if(r==n){printf("%d",Abs(p-l)+1);return 0;}
	printf("%d",Min(Abs(p-r),Abs(p-l))+r-l+2);
	return 0;
}