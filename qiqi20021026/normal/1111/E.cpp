#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300000

const int mod=1000000007;
int n,m,x,y,p,q,rt,clk,ans,a[N],par[N][22],f[320],g[320],dep[N],head[N],tot,xb,stk[N],dfn[N];
struct edge{int v,nxt;}e[N];
bool vis[N];
set<int> se;

bool cmp(int x,int y){return dfn[x]<dfn[y];}

void add(int x,int y){
	e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;
}

void calc(int u){
	dfn[u]=++clk;
	dep[u]=dep[par[u][0]]+1;
	for (int i=1;i<=20;++i) par[u][i]=par[par[u][i-1]][i-1];
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=par[u][0]){
			par[v][0]=u; calc(v);
		}
}

int lca(int u,int v){
	if (dep[u]>dep[v])
		for (int i=20;~i;--i) if (dep[par[u][i]]>=dep[v]) u=par[u][i];
	if (dep[v]>dep[u])
		for (int i=20;~i;--i) if (dep[par[v][i]]>=dep[u]) v=par[v][i];
	for (int i=20;~i;--i)
		if (par[u][i]!=par[v][i]){u=par[u][i]; v=par[v][i];}
	return u==v?u:par[u][0];
}

void dfs(int u,int fa,int num){
	if (vis[u]){
		memcpy(g,f,sizeof g);
		memset(f,0,sizeof f);
		for (int i=num+1;i<=q;++i)
			f[i]=(g[i-1]+(LL)g[i]*(i-num))%mod;
	}
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa) dfs(v,u,num+vis[u]);
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	calc(1);
	memset(head,0,sizeof head); tot=0;
	while (m--){
		scanf("%d%d%d",&p,&q,&rt);
		for (int i=1;i<=p;++i){scanf("%d",a+i); vis[a[i]]=1;}
		if (!vis[rt]) a[++p]=rt;
		sort(a+1,a+p+1,cmp);
		stk[xb=1]=a[1];
		for (int i=2;i<=p;++i){
			int u=a[i],v=lca(u,stk[xb]);
			for (;xb>1&&dep[v]<dep[stk[xb-1]];--xb){
				add(stk[xb-1],stk[xb]); add(stk[xb],stk[xb-1]);
				se.insert(stk[xb-1]); se.insert(stk[xb]);
			}
			if (dep[v]<dep[stk[xb]]){
				add(v,stk[xb]); add(stk[xb],v);
				se.insert(v); se.insert(stk[xb--]);
			}
			if (stk[xb]!=v) stk[++xb]=v;
			stk[++xb]=u;
		}
		for (int i=1;i<xb;++i){
			add(stk[i],stk[i+1]); add(stk[i+1],stk[i]);
			se.insert(stk[i]); se.insert(stk[i+1]);
		}
		memset(f,0,sizeof f); f[0]=1;
		dfs(rt,0,0);
		ans=0; for (int i=1;i<=q;++i) ans=(ans+f[i])%mod;
		printf("%d\n",ans);
		for (int i=1;i<=p;++i) vis[a[i]]=0;
		tot=0; for (auto it:se) head[it]=0; se.clear();
	}
	
	return 0;
}