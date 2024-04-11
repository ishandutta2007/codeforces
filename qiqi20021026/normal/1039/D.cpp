#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,x,y,clk,f[N],mx[N],mx2[N],tot,head[N],dfn[N],q[N],rec[N];
struct edge{int v,nxt;}e[N];

void add(int x,int y){
	e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;
}

void dfs(int u){
	dfn[u]=++clk; q[clk]=u;
	for (int i=head[u],v;i;i=e[i].nxt)
		if (!dfn[v=e[i].v]) dfs(v);
}

int pd(int x){
	if (~rec[x]) return rec[x];
	rec[x]=0;
	for (int i=n;i;--i){
		int u=q[i]; mx[u]=mx2[u]=0;
		for (int j=head[u],v;j;j=e[j].nxt)
			if (dfn[v=e[j].v]>dfn[u]){
				if (mx[v]>mx[u]){mx2[u]=mx[u]; mx[u]=mx[v];}
				else if (mx[v]>mx2[u]) mx2[u]=mx[v];
			}
		if (++mx[u]+mx2[u]>=x){mx[u]=0; ++rec[x];}
	}
	return rec[x];
}

void solve(int l,int r){
	int L=pd(l),R=pd(r);
	if (L==R){
		for (int i=l;i<=r;++i) f[i]=L;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid); solve(mid+1,r);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1);
	memset(rec,-1,sizeof rec);
	solve(1,n);
	for (int i=1;i<=n;++i) printf("%d\n",f[i]);
	
	return 0;
}