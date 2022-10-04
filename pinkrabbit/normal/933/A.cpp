#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
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
const int INF=0x3f3f3f3f;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
int n;
int a[2001],ans;
int f[2001][2001],g[2001][2001],k[2001][2001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	F(i,1,n){
		f[i][i]=(a[i]==1);
		F(j,i+1,n) f[i][j]=f[i][j-1]+(a[j]==1);
	}
	ans=Max(f[1][n],n-f[1][n]);
	F(i,1,n-1) ans=Max(ans,f[1][i]+(n-i-f[i+1][n]));
	F(i,1,n){
		g[i][i]=(a[i]==2); k[i][i]=(a[i]==1);
		F(j,i+1,n){
			g[i][j]=g[i][j-1]+(a[j]==2);
			k[i][j]=k[i][j-1];
			if(a[j]==1) k[i][j]=Max(k[i][j-1],g[i][j-1])+1;
		}
	}
	F(i,1,n) F(j,i+1,n){
		ans=Max(ans,f[1][i-1]+n-j-f[j+1][n]+Max(g[i][j],k[i][j]));
	}
	printf("%d",ans);
	return 0;
}