#include<bits/stdc++.h>
using namespace std;
const int maxn=200020;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,q,w[maxn],id[maxn],el,head[maxn],to[maxn],nxt[maxn],seq[maxn*2],sl,at[maxn],dep[maxn],logt[maxn*2],st[maxn*2][20];
inline void add(int a,int b){
	to[++el]=b;nxt[el]=head[a];head[a]=el;
}
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	seq[at[u]=++sl]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		seq[++sl]=u;
	}
}
void ST(){
	FOR(i,2,sl) logt[i]=logt[i>>1]+1;
	FOR(i,1,sl) st[i][0]=seq[i];
	FOR(j,1,19) FOR(i,1,sl-(1<<j)+1) st[i][j]=dep[st[i][j-1]]<dep[st[i+(1<<(j-1))][j-1]]?st[i][j-1]:st[i+(1<<(j-1))][j-1];
}
int lca(int u,int v){
	int l=at[u],r=at[v];
	if(l>r) swap(l,r);
	int k=logt[r-l+1];
	return dep[st[l][k]]<dep[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}
inline bool check(int u,int v,int x){
	if(u==-1 || v==-1 || x==-1) return false;
	int l=lca(u,v);
	return (lca(u,x)==x || lca(v,x)==x) && lca(l,x)==l;
}
struct node{
	int u,v;
	node operator+(const node &nd)const{
		if(!u) return nd;
		node ans;
		ans.u=ans.v=-1;
		if(check(u,v,nd.u) && check(u,v,nd.v)) ans.u=u,ans.v=v;
		if(check(u,nd.u,v) && check(u,nd.u,nd.v)) ans.u=u,ans.v=nd.u;
		if(check(u,nd.v,v) && check(u,nd.v,nd.u)) ans.u=u,ans.v=nd.v;
		if(check(v,nd.u,u) && check(v,nd.u,nd.v)) ans.u=v,ans.v=nd.u;
		if(check(v,nd.v,u) && check(v,nd.v,nd.u)) ans.u=v,ans.v=nd.v;
		if(check(nd.u,nd.v,u) && check(nd.u,nd.v,v)) ans.u=nd.u,ans.v=nd.v;
		return ans;
	}
}seg[maxn*4];
void build(int o,int l,int r){
	if(l==r) return void(seg[o]=(node){id[l],id[l]});
	int mid=(l+r)>>1;
	build(lson);build(rson);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
void update(int o,int l,int r,int p){
	if(l==r) return void(seg[o]=(node){id[p],id[p]});
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p);
	else update(rson,p);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
node query2(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return seg[o];
	int mid=(l+r)>>1;
	if(mid<ql) return query2(rson,ql,qr);
	if(mid>=qr) return query2(lson,ql,qr);
	return query2(lson,ql,qr)+query2(rson,ql,qr);
}
int query(int o,int l,int r,node nd){
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(~(nd+seg[o<<1]).u) return query(rson,nd+seg[o<<1]);
	else return query(lson,nd);
}
int main(){
	n=read();
	FOR(i,1,n) id[w[i]=read()]=i;
	FOR(i,2,n) add(read(),i);
	dfs(1,0);
	ST();
	build(1,0,n-1);
	q=read();
	while(q--){
		int op=read();
		if(op==1){
			int u=read(),v=read();
			swap(w[u],w[v]);
			id[w[u]]=u;id[w[v]]=v;
			update(1,0,n-1,w[u]);update(1,0,n-1,w[v]);
		}
		else printf("%d\n",~seg[1].u?n:query(1,0,n-1,(node){0,0}));
	}
}
// orz CDW SCOI AK