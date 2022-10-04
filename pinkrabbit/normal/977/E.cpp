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
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n,m,Ans;

int h[200001],nxt[400001],to[400001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int vis[200001],d[200001],stk[200001],top;

void DFS(int u){
	vis[u]=1; stk[++top]=u;
	eF(i,u) if(!vis[to[i]]) DFS(to[i]);
}

int main(){
	int x,y;
	scanf("%d%d",&n,&m);
	F(i,1,m) scanf("%d%d",&x,&y), ins(x,y), ins(y,x), ++d[x], ++d[y];
	F(i,1,n) if(!vis[i]){
		top=0; DFS(i);
		int ok=1;
		if(top<=2) continue;
		F(j,1,top) if(d[stk[j]]!=2) ok=0;
		if(ok) ++Ans;
	} printf("%d",Ans);
	return 0;
}