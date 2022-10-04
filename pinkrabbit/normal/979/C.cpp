#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n,S,T;
ll Ans;
int f[300001],siz[300001];
int h[300001],nxt[600001],to[600001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

void DFS(int u,int fa){
	siz[u]=1; if(u==T) f[u]=1;
	eF(i,u) if(to[i]!=fa) DFS(to[i],u), siz[u]+=siz[to[i]], f[u]|=f[to[i]];
}

int main(){ int x,y; 
	scanf("%d%d%d",&n,&S,&T); Ans=(ll)n*(n-1);
	F(i,2,n) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	DFS(S,0);
	int cnt=1;
	eF(i,S){
		if(!f[to[i]]) cnt+=siz[to[i]];
	}
	Ans-=(ll)cnt*siz[T];
	printf("%I64d",Ans);
	return 0;
}