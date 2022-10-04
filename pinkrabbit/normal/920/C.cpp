#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#define ll long long
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
int n,q;
int a[200001],b[200001];
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	char ch;
	F2(i,1,n) if((ch=getchar())!='1'&&ch!='0') --i; else b[i]=ch-'0';
	int lst=1;
	F(i,1,n){
		if(!b[i]) sort(a+lst,a+i+1), lst=i+1;
	} sort(a+lst,a+n+1);
	F(i,1,n) if(a[i]!=i) {puts("NO"); return 0;}
	puts("YES");
	return 0;
}