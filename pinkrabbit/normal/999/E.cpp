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

int n,m,s;
int X[100001],Y[100001];

int h[100001],H[100001],nxt[200001],to[200001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
inline void ins2(int x,int y){nxt[++tot]=H[x];to[tot]=y;H[x]=tot;}

int v[100001];

int dfn[100001], cnt,S;
int bel[100001];
int in[100001];

void DFS1(int u){
	v[u]=1;
	eF(h,i,u) if(!v[to[i]]) DFS1(to[i]);
	dfn[cnt--]=u;
}

void DFS2(int u){
	v[u]=0; bel[u]=S;
	eF(H,i,u) if(v[to[i]]) DFS2(to[i]);
}

int main(){
	int x,y;
	scanf("%d%d%d",&n,&m,&s); cnt=n;
	F(i,1,m) scanf("%d%d",&x,&y), ins(x,y), ins2(y,x), X[i]=x,Y[i]=y;
	F(i,1,n) if(!v[i]) DFS1(i);
	F(i,1,n) if(v[dfn[i]]) ++S,DFS2(dfn[i]);
	F(i,1,m){
		if(bel[X[i]]==bel[Y[i]]) continue;
		++in[bel[Y[i]]];
	}
	int Ans=0;
	F(i,1,S) if(in[i]==0) ++Ans;
	if(in[bel[s]]==0) --Ans;
	printf("%d",Ans);
	return 0;
}