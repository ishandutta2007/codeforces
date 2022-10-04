#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
using namespace std;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

const int Mod=19260817, G=93;
int n,m;
char mp1[2005][205];
char mp2[205][2005];
int vis[Mod];

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%s",mp1[i]+1);
	F(i,1,m) scanf("%s",mp2[i]+1);
	int s;
	F(i,1,n-m+1){
		s=0;
		F(k,i,i+m-1){
			F(j,1,m)
				s=(s*G+mp1[k][j]-'a')%Mod;
		}
		vis[s]=i;
	}
	F(i,1,n-m+1){
		s=0;
		F(j,1,m)
			F(k,i,i+m-1)
				s=(s*G+mp2[j][k]-'a')%Mod;
		if(vis[s]) {printf("%d %d",vis[s],i);return 0;}
	}
	return 0;
}