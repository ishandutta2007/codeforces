#include<bits/stdc++.h>

using namespace std;

#define N 800000
#define P(x,y) make_pair(x,y)
#define ff first
#define ss second
#define INF 0x3f3f3f3f
#define ls (x<<1)
#define rs (x<<1|1)

int n,m,p,cnt,dfn[N],low[N],stk[N],dep[N],seg[N];
int top,a[N],x,y,z,tot,head[N],clk,fa[N],tp[N],sz[N];
char op;
multiset<int> se[N];
vector<pair<int,int> > vec;
struct edge{int v,nxt;}e[N];

void add(int x,int y){e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;}

void dfs(int u,int fa){
	dfn[u]=low[u]=++clk; stk[top++]=u;
	for (int i=head[u],v;i;i=e[i].nxt)
		if (!dfn[v=e[i].v]){
			dfs(v,u); low[u]=min(low[v],low[u]);
			if (low[v]>=dfn[u]){
				vec.push_back(P(++cnt,u));
				int o; do{o=stk[--top]; vec.push_back(P(cnt,o));}while (o!=v);
			}
		}
		else if (v!=fa) low[u]=min(low[u],dfn[v]);
}

void dfs1(int u){
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]){
			fa[v]=u; dfs1(v); sz[u]+=sz[v];
		}
	if (!sz[u]) sz[u]=1;
}

void dfs2(int u){
	dfn[u]=++clk; dep[u]=dep[fa[u]]+1;
	if (!tp[u]) tp[u]=u; int t=0;
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]&&sz[v]>sz[t]) t=v;
	if (!t) return; tp[t]=tp[u]; dfs2(t);
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]&&v!=t) dfs2(v);
}

void mdf(int x,int l,int r,int t,int k){
	if (l==r){seg[x]=k; return;}
	int mid=(l+r)>>1;
	if (t<=mid) mdf(ls,l,mid,t,k);
	if (t>mid) mdf(rs,mid+1,r,t,k);
	seg[x]=min(seg[ls],seg[rs]);
}

int qry(int x,int l,int r,int L,int R){
	if (l>=L&&r<=R) return seg[x];
	int mid=(l+r)>>1,mn=INF;
	if (L<=mid) mn=min(mn,qry(ls,l,mid,L,R));
	if (R>mid) mn=min(mn,qry(rs,mid+1,r,L,R));
	return mn;
}

int main(){
	scanf("%d%d%d",&n,&m,&p); cnt=n;
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	memset(head,0,sizeof head); tot=0;
	memset(dfn,0,sizeof dfn); clk=0;
	for (int i=0;i<(int)vec.size();++i){
		add(vec[i].ff,vec[i].ss);
		add(vec[i].ss,vec[i].ff);
	}
	dfs1(1); dfs2(1);
	for (int i=1;i<=n;++i) mdf(1,1,cnt,dfn[i],a[i]);
	for (int i=n+1;i<=cnt;++i){
		for (int j=head[i],v;j;j=e[j].nxt)
			if ((v=e[j].v)!=fa[i]){
				se[i].insert(a[v]);
			}
		if (se[i].begin()!=se[i].end()) a[i]=*se[i].begin();
		else a[i]=INF;
		mdf(1,1,cnt,dfn[i],a[i]);
	}
	while (p--){
		scanf(" %c%d%d",&op,&x,&y);
		if (op=='C'){
			z=fa[x];
			if (z){
				se[z].erase(se[z].find(a[x]));
				se[z].insert(y);
				a[z]=*se[z].begin();
				mdf(1,1,cnt,dfn[z],a[z]);
			}
			a[x]=y; mdf(1,1,cnt,dfn[x],a[x]);
		}
		else{
			int ans=INF;
			for (;tp[x]!=tp[y];x=fa[tp[x]]){
				if (dep[tp[x]]<dep[tp[y]]) swap(x,y);
				ans=min(ans,qry(1,1,cnt,dfn[tp[x]],dfn[x]));
			}
			if (dep[x]>dep[y]) swap(x,y);
			ans=min(ans,qry(1,1,cnt,dfn[x],dfn[y]));
			if (x>n) ans=min(ans,a[fa[x]]);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}