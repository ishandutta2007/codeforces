#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
typedef long long LL;
// from_luogu
int n; LL Ans;
int h[200001],nxt[400001],to[400001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int sz[200001],d[200001],C;
void DFS(int u,int f){
	sz[u]=1; if(d[u]=d[f]^1) ++C;
	eF(i,u) if(to[i]!=f) DFS(to[i],u), sz[u]+=sz[to[i]];
}

int main(){
	int x,y;
	scanf("%d",&n);
	F(i,2,n) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	DFS(1,0);
	F(i,2,n) Ans+=(LL)sz[i]*(n-sz[i]);
	Ans+=(LL)C*(n-C);
	printf("%lld",Ans/2);
	return 0;
}