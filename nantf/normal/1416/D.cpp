#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=666666,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qmo(int x){return x+(x>>31?mod:0);}
struct edge{
	int u,v,w;
	bool operator<(const edge &e)const{return w>e.w;}
}e[maxn];
int n,m,q,a[maxn],op[maxn],x[maxn],w[maxn],u_fa[maxn],cnt,el,head[maxn],to[maxn],nxt[maxn],fa[20][maxn];
int lft[maxn],rig[maxn],dcnt,id[maxn];
PII val[maxn*4];
inline int getfa(int x){
	return x==u_fa[x]?x:u_fa[x]=getfa(u_fa[x]);
}
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	fa[0][u]=f;
	FOR(i,1,19) fa[i][u]=fa[i-1][fa[i-1][u]];
	lft[u]=++dcnt;
	id[dcnt]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dfs(v,u);
	}
	rig[u]=dcnt;
}
void build(int o,int l,int r){
	if(l==r) return val[o]=MP(a[id[l]],l),void();
	int mid=(l+r)>>1;
	build(lson);build(rson);
	val[o]=max(val[o<<1],val[o<<1|1]); 
}
void update(int o,int l,int r,int p,int v){
	if(l==r) return val[o]=MP(v,l),void();
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p,v);
	else update(rson,p,v);
	val[o]=max(val[o<<1],val[o<<1|1]); 
}
PII query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return val[o];
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	return max(query(lson,ql,qr),query(rson,ql,qr));
}
int main(){
	n=read();m=read();q=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,m) e[i].u=read(),e[i].v=read(),e[i].w=q+1;
	FOR(i,1,q){
		op[i]=read();x[i]=read();
		if(op[i]==2) e[x[i]].w=i;
	}
	sort(e+1,e+m+1);
	cnt=n;
	FOR(i,1,2*n) u_fa[i]=i;
	FOR(i,1,m){
		int u=e[i].u,v=e[i].v;
		u=getfa(u);v=getfa(v);
		if(u==v) continue;
		u_fa[u]=u_fa[v]=++cnt;
		w[cnt]=e[i].w;
		add(cnt,u);add(cnt,v); 
	}
	FOR(i,1,cnt) if(getfa(i)==i) dfs(i,0);
	build(1,1,cnt);
	FOR(i,1,q) if(op[i]==1){
		int u=x[i];
		ROF(j,19,0) if(fa[j][u] && w[fa[j][u]]>=i) u=fa[j][u];
		PII p=query(1,1,cnt,lft[u],rig[u]);
		printf("%d\n",p.first);
		update(1,1,cnt,p.second,0);
	}
}