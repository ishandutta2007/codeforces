#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,m,x,y,z,rt,xb,tot,ans,q[N],head[N],mx[N],deep[N],top[N],fa[N],pre[N],pos[N],c[N],vis[N];
struct edge{int v,l,nxt;}e[N];

bool cmp(int x,int y){return mx[x]-deep[fa[top[x]]]>mx[y]-deep[fa[top[y]]];}

void add(int x,int y,int z){e[++tot].v=y; e[tot].l=z; e[tot].nxt=head[x]; head[x]=tot;}

void bfs(int x){
	memset(vis,0,sizeof vis);
	int t=0,w=1; q[1]=x; vis[x]=1;
	while (t<w){
		int u=q[++t];
		for (int i=head[u],v;i;i=e[i].nxt){
			v=e[i].v;
			if (vis[v]) continue;
			vis[v]=vis[u]+e[i].l; q[++w]=v;
		}
	}
	for (int i=1;i<=n;i++) if (vis[i]>vis[rt]) rt=i;
}

void dfs1(int u){
	mx[u]=deep[u];
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]){
			fa[v]=u; deep[v]=deep[u]+e[i].l;
			dfs1(v); mx[u]=max(mx[u],mx[v]);
		}
}

void dfs2(int u){
	if (!top[u]) top[u]=u; int t=0;
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u] && mx[v]>mx[t]) t=v;
	if (!t){c[++xb]=u; return;}
	top[t]=top[u]; dfs2(t);
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u] && v!=t) dfs2(v);
}

int getans(int x,int y){
	if (y*2-1>=xb) return pre[xb];
	if (y*2-1>=pos[top[x]]) return pre[y*2-1];
	int w=x;
	while (pos[top[w]]>=y*2) w=fa[top[w]];
	return pre[y*2-1]+mx[x]-deep[w]-min(min(pre[y*2-1]-pre[y*2-2],mx[w]-deep[w]),deep[w]);
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,z);
	}
	bfs(1); dfs1(rt); dfs2(rt);
	sort(c+1,c+xb+1,cmp);
	for (int i=1;i<=xb;i++) pos[top[c[i]]]=i,pre[i]=pre[i-1]+mx[c[i]]-deep[fa[top[c[i]]]];
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		x=(x+ans-1)%n+1; y=(y+ans-1)%n+1;
		printf("%d\n",ans=getans(x,y));
	}
	
	return 0;
}