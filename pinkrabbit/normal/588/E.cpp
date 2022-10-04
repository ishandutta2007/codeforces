#include<cstdio>
#define R register
int n,m,q;
int h[100001],g[100001],Q[100001],nxt[500001],to[500001],o[500001],tot,fa[100001];
inline void ins1(R int x,R int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
inline void ins2(R int x,R int y,R int i){nxt[++tot]=Q[x];to[tot]=y;o[tot]=i;Q[x]=tot;}
inline void ins3(R int x,R int y){nxt[++tot]=g[x];to[tot]=y;g[x]=tot;}
int rt[100001],ls[3800001],rs[3800001],val[3800001],cnt;
int X[100001],Y[100001],a[100001];
int LCA[200001],f[200001];
int ff(R int x){return f[x]?f[x]=ff(f[x]):x;}
void build(int &f,R int l,R int r){
	if(l==r) {f=++cnt; return;}
	build(ls[f],l,l+r>>1), build(rs[f],(l+r>>1)+1,r);
}
void Modify(int &f,R int l,R int r,R int p){
	ls[++cnt]=ls[f], rs[cnt]=rs[f], val[cnt]=val[f]+1, f=cnt;
	if(l==r) return;
	int mid=l+r>>1;
	if(mid<p) Modify(rs[f],mid+1,r,p);
	else Modify(ls[f],l,mid,p);
}
int Search(R int f1,R int f2,R int f3,int f4,R int l,R int r,R int k){
	if(l==r) return l;
	int mid=l+r>>1, x=val[ls[f1]]+val[ls[f2]]-val[ls[f3]]-val[ls[f4]];
	return x<k?Search(rs[f1],rs[f2],rs[f3],rs[f4],mid+1,r,k-x):Search(ls[f1],ls[f2],ls[f3],ls[f4],l,mid,k);
}
void dfs1(R int u){
	rt[u]=rt[u==1?0:fa[u]];
	for(R int i=g[u];i;i=nxt[i]) Modify(rt[u],1,m,to[i]);
	for(R int i=h[u];i;i=nxt[i]) if(!fa[to[i]]) fa[to[i]]=u, dfs1(to[i]);
}
void dfs2(R int u){
	for(R int i=h[u];i;i=nxt[i]) if(to[i]!=fa[u]) dfs2(to[i]), f[to[i]]=u;
	for(R int i=Q[u];i;i=nxt[i]) if(LCA[o[i]]) LCA[o[i]]=ff(to[i]); else LCA[o[i]]=u;
}
void print(R int f1,R int f2,R int f3,int f4,R int p){
	int kkk=val[f1]+val[f2]-val[f3]-val[f4];
	printf("%d",p<kkk?p:kkk);
	for(R int i=1;i<=kkk&&i<=p;++i) printf(" %d",Search(f1,f2,f3,f4,1,m,i));
	puts("");
}
void print(R int f,R int l,R int r){
	if(l==r) {printf("%d ",val[f]); return;}
	print(ls[f],l,l+r>>1); print(rs[f],(l+r>>1)+1,r);
}
void init(){
	scanf("%d%d%d",&n,&m,&q);
	for(R int i=1,x,y;i<n;++i) scanf("%d%d",&x,&y), ins1(x,y), ins1(y,x);
	for(R int i=1,x;i<=m;++i) scanf("%d",&x), ins3(x,i);
	build(rt[0],1,n);
	fa[1]=-1; dfs1(1); fa[1]=0;
//	for(R int i=1;i<=n;++i) print(rt[i],1,m), puts("");
	for(R int i=1,x,y;i<=q;++i){
		scanf("%d%d%d",X+i,Y+i,a+i);
		ins2(X[i],Y[i],i), ins2(Y[i],X[i],i);
	} dfs2(1);
//	for(R int i=1;i<=q;++i) printf("%d-%d : %d\n",X[i],Y[i],LCA[i]);
}
int main(){
	init();
	for(R int i=1;i<=q;++i) print(rt[X[i]],rt[Y[i]],rt[LCA[i]],rt[fa[LCA[i]]],a[i]);
	return 0;
}