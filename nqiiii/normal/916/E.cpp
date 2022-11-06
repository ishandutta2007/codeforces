#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=100000;
vector<int> g[maxn+10];
int n,m,fa[maxn+10],dep[maxn+10],sz[maxn+10],son[maxn+10],top[maxn+10],dfn[maxn+10],ed[maxn+10];
int dfscnt,rt; ll v[maxn+10],vvv[maxn+10];
struct node{int l,r; ll val,tag;}a[maxn*4+10];
void dfs1(int x){
	dep[x]=dep[fa[x]]+1; sz[x]=1;
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(e==fa[x]) continue;
		fa[e]=x; dfs1(e); sz[x]+=sz[e];
		if(sz[e]>sz[son[x]]) son[x]=e;
	}
}
void dfs2(int x){
	dfn[x]=++dfscnt;
	if(son[fa[x]]==x) top[x]=top[fa[x]]; else top[x]=x;
	if(son[x]) dfs2(son[x]);
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(e==fa[x]||e==son[x]) continue;
		dfs2(e);
	}
	ed[x]=dfscnt;
}
void build(int p,int l,int r){
	a[p].l=l; a[p].r=r; a[p].tag=0;
	if(l==r) a[p].val=v[l];
	else{
		int mid=(l+r)/2;
		build(p*2,l,mid); build(p*2+1,mid+1,r);
		a[p].val=a[p*2].val+a[p*2+1].val;
	}
}
void apply(int p,ll v){a[p].tag+=v; a[p].val+=(a[p].r-a[p].l+1)*v;}
void push(int p){
	apply(p*2,a[p].tag); apply(p*2+1,a[p].tag); a[p].tag=0;
}
void change(int p,int l,int r,ll v){
	if(l>r) return;
	if(a[p].l==l&&a[p].r==r) apply(p,v);
	else{
		int mid=(a[p].l+a[p].r)/2; push(p);
		if(r<=mid) change(p*2,l,r,v);
		else if(l>mid) change(p*2+1,l,r,v);
		else change(p*2,l,mid,v),change(p*2+1,mid+1,r,v);
		a[p].val=a[p*2].val+a[p*2+1].val;
	}
}
ll query(int p,int l,int r){
	if(l>r) return 0;
	if(a[p].l==l&&a[p].r==r) return a[p].val;
	int mid=(a[p].l+a[p].r)/2; push(p);
	if(r<=mid) return query(p*2,l,r); if(l>mid) return query(p*2+1,l,r);
	return query(p*2,l,mid)+query(p*2+1,mid+1,r);
}
int lca(int x,int y){
	for(;top[x]!=top[y];)
		if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
		else y=fa[top[y]];
	if(dep[x]<dep[y]) return x; else return y;
}
int getlca(int x,int y){
	int p=lca(x,y);
	if(dfn[rt]>=dfn[p]&&dfn[rt]<=ed[p]){
		int t1=lca(x,rt),t2=lca(y,rt);
		if(t1!=p&&t2!=p) printf("233\n");
		if(dep[t1]>dep[t2]) return t1; else return t2;
	}
	return p;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&vvv[i]);
	for(int i=1;i<n;++i){
		int l,r; scanf("%d%d",&l,&r); g[l].push_back(r); g[r].push_back(l);
	}
	dfs1(1); dfs2(1);
	for(int i=1;i<=n;++i) v[dfn[i]]=vvv[i];
	build(1,1,n); rt=1;
	for(int i=1;i<=m;++i){
		int op,x,y; ll v; scanf("%d%d",&op,&x);
		if(op==1) rt=x;
		else if(op==2){
			scanf("%d%lld",&y,&v); x=getlca(x,y);
			if(x==rt) change(1,1,n,v);
			else if(dfn[rt]>dfn[x]&&dfn[rt]<=ed[x]){
				 int p=rt;
				 for(;fa[p]!=x;){
				 	 p=fa[p];
				 	 if(dep[top[p]]>dep[x]) p=top[p]; else p=son[x];
				 }
				 change(1,1,dfn[p]-1,v); change(1,ed[p]+1,n,v);
			}else change(1,dfn[x],ed[x],v);
		}else if(op==3)
			if(x==rt) printf("%lld\n",query(1,1,n));
			else if(dfn[rt]>dfn[x]&&dfn[rt]<=ed[x]){
				 int p=rt;
				 for(;fa[p]!=x;){
				 	 p=fa[p];
				 	 if(dep[top[p]]>dep[x]) p=top[p]; else p=son[x];
				 }
				 printf("%lld\n",query(1,1,dfn[p]-1)+query(1,ed[p]+1,n));
			}else printf("%lld\n",query(1,dfn[x],ed[x]));
	}
	return 0;
}