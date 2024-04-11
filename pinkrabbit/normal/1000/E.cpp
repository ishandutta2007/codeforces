//luogu
#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(a,i,u) for(int i=a[u];i;i=nxt[i])
#define ll long long
#define ld double
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n,m;

int h[300005],H[300005],nxt[1200005],to[1200005],tot=1;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
inline void ins2(int x,int y){nxt[++tot]=H[x];to[tot]=y;H[x]=tot;}
int bj[600005];

int dfn[300001],low[300001],cnt;

void DFS(int u,int f){
	dfn[u]=low[u]=++cnt;
	eF(h,i,u) if(to[i]!=f){
		if(!dfn[to[i]]){
			DFS(to[i],u);
			if(low[to[i]]>dfn[u]){
				bj[i]=bj[i^1]=1;
			}
		}
		low[u]=min(low[u],low[to[i]]);
	}
}

int v[300001],bel[300001],S;

void DFS2(int u){
	v[u]=1; bel[u]=S;
	eF(h,i,u) if(!bj[i]){
		if(!v[to[i]]) DFS2(to[i]);
	}
}

int d[300001];

void DFS3(int u,int f){
	d[u]=d[f]+1;
	eF(H,i,u) if(to[i]!=f){
		DFS3(to[i],u);
	}
}

int main(){
	int x,y;
	scanf("%d%d",&n,&m);
	F(i,1,m) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	DFS(1,0);
	F(i,1,n){
		if(!v[i]) ++S,DFS2(i);
	}
	F(i,1,n){
		eF(h,j,i) if(bj[j]){
			ins2(bel[i],bel[to[j]]);
		}
	} d[0]=-1;
	DFS3(1,0);
	x=0;
	F(i,1,S) if(d[x]<d[i]) x=i;
	DFS3(x,0);
	int A=0;
	F(i,1,S) A=max(A,d[i]);
	printf("%d",A);
	return 0;
}