#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
inline void qw(int&X){scanf("%d",&X);}
inline void qw(int&X,int&Y){scanf("%d%d",&X,&Y);}
inline void qw(int&X,int&Y,int&Z){scanf("%d%d%d",&X,&Y,&Z);}
inline void qw(ll&X,ll&Y,ll&Z){scanf("%I64d%I64d%I64d",&X,&Y,&Z);}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
ll n,a,b;
int extgcd(ll a, ll b,ll &x, ll &y){
    int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else  x = 1, y = 0;
    return d;
}//d = gcd(a, b);
int main(){
	qw(n,a,b);
	ll x,y,d,X,Y;
	d=extgcd(a,b,x,y);
	if(n%d!=0) {puts("NO"); return 0;}
	x*=n/d, y*=n/d;
	X=x, Y=y;
	if(x<0) X=(x%b+b)%b, Y=y-(X-x)/b*a;
	if(y<0) Y=(y%a+a)%a, X=x-(Y-y)/a*b;
	if(X<0||Y<0) {puts("NO"); return 0;}
	printf("YES\n%I64d %I64d",X,Y);
	return 0;
}