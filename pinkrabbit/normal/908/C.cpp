#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
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
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline int Abs(int X){return X<0?-X:X;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
int n,r;
int x[1005];
long double Ans[1005];
int main(){
	qw(n,r);
	F(i,1,n) qw(x[i]);
	F(i,1,n){
		int o=0;
		F(j,1,i-1){
			if(Abs(x[j]-x[i])<=r+r){
				o=1;
				long long aa=4*r*r-(x[i]-x[j])*(x[i]-x[j]);
				long double xx=sqrt(aa)+Ans[j];
				if(Ans[i]<xx) Ans[i]=xx;
			}
		}
		if(o==0) Ans[i]=r;
	}
	F(i,1,n) printf("%.10f ",(double) Ans[i]);
	return 0;
}