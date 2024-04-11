#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
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
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
int n;
ll Ans;
int a[200001],b[200001],l1,l2;
inline int issqr(int x){
	if(x==0) return 1;
	double ww=sqrt(x);
	int d=floor(ww), u=d+1;
	if(d*d==x||u*u==x) return 1;
	return 0;
}
inline int c1(int x){
	if(x==0) return 2;
	else return 1;
}
inline int c2(int x){
	double ww=sqrt(x);
	int d=floor(ww), u=d+1;
	return min(x-d*d,u*u-x);
}
int main(){
	qw(n);
	int x; F(i,1,n){
		scanf("%d",&x);
		if(issqr(x)) a[++l1]=c1(x);
		else b[++l2]=c2(x);
	}
	sort(a+1,a+l1+1);
	sort(b+1,b+l2+1);
	if(l1==l2) {puts("0"); return 0;}
	if(l1>l2){
		int l=l1-l2>>1;
		F(i,1,l) Ans+=a[i];
		printf("%I64d",Ans);
	}
	else{
		int l=l2-l1>>1;
		F(i,1,l) Ans+=b[i];
		printf("%I64d",Ans);
	}
	return 0;
}