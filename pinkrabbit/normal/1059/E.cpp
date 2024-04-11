#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
typedef long long LL;
// from_luogu
int n,L,w[100005],d[100005],faz[100005][17];
LL S,dep[100005];
int h[100001],nxt[100001],to[100001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int f[100005],g[100005];

void D(int u){
	eF(i,u) dep[to[i]]=dep[u]+w[to[i]], faz[to[i]][0]=u, d[to[i]]=d[u]+1, D(to[i]);
}

void DFS(int u){
	int Su=0, Mg=0;
	eF(i,u) DFS(to[i]), Su+=f[to[i]], Mg=max(Mg,g[to[i]]);
	int now=faz[u][0], D=0;
	dF(j,16,0){
		if(D+(1<<j)<L&&D+(1<<j)<d[u]&&dep[u]-dep[faz[now][j]]<=S)
			now=faz[now][j], D+=1<<j;
	}
	if(Mg) f[u]=Su, g[u]=Mg-1;
	else f[u]=Su+1, g[u]=D;
}

int main(){
	int x;
	scanf("%d%d%lld",&n,&L,&S);
	F(i,1,n) scanf("%d",w+i);
	F(i,1,n) if(w[i]>S) return puts("-1"),0;
	F(i,2,n) scanf("%d",&x), ins(x,i);
	d[1]=1; dep[1]=w[1]; D(1);
	F(j,1,16) F(i,1,n) faz[i][j]=faz[faz[i][j-1]][j-1];
	DFS(1);
	printf("%d",f[1]);
	return 0;
}