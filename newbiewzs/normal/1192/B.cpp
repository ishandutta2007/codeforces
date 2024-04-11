#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int n,q,w,x,y,z;
const int N=2e6;
inline ll read(){
	char c=getchar();ll s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
struct node{
	int next,to;
	ll dis;
	int id;
}a[N*2];
int head[N],cnt;
ll las;
ll val[N];
void add(int e,int r,ll t,int w){
	a[++cnt].next=head[e];a[cnt].to=r;a[cnt].dis=t;a[cnt].id=w;head[e]=cnt;
}
ll deep[N];
int to[N];
int pre[N],prv[N],st[N*2],top;
ll minn[N],maxx[N],lm[N],ml[N],da[N];
ll lazy[N];
void jia(int u,ll x){
	minn[u]-=2ll*x;
	maxx[u]+=x;
	ml[u]-=x;
	lm[u]-=x;
	lazy[u]+=x;
	return ;
}
void pushdown(int u){
	if(!lazy[u])return ;
	jia(ls,lazy[u]);
	jia(rs,lazy[u]);
	lazy[u]=0;
	return ;
}
void dfs(int u,int fa){
	st[++top]=u;
	pre[u]=top;
	for(int i=head[u];i;i=a[i].next){
		if(a[i].to==fa)continue;
		deep[a[i].to]=deep[u]+a[i].dis;
		to[a[i].id]=a[i].to;
		dfs(a[i].to,u);
		st[++top]=u;
	}
	prv[u]=top;
}
void update(int u){
	maxx[u]=max(maxx[ls],maxx[rs]);
	minn[u]=max(minn[ls],minn[rs]);
	lm[u]=max(max(lm[ls],lm[rs]),maxx[ls]+minn[rs]);
	ml[u]=max(max(ml[ls],ml[rs]),minn[ls]+maxx[rs]);
	da[u]=max(max(da[ls],da[rs]),max(lm[ls]+maxx[rs],maxx[ls]+ml[rs]));
}
void add(int u,int l,int r,int L,int R,int x){
	if(L<=l and R>=r){
		jia(u,x);
		return ;
	}
	pushdown(u);
	if(L<=mid)add(ls,l,mid,L,R,x);
	if(R>mid)add(rs,mid+1,r,L,R,x);
	update(u);
	return ;
}
void build(int u,int l,int r){
	if(l==r){
		minn[u]=-2ll*deep[st[l]];
		maxx[u]=deep[st[l]];
		lm[u]=-deep[st[l]];
		ml[u]=-deep[st[l]];
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(u);
}
signed main(){
	n=read();q=read();w=read();
	for(int i=1;i<n;i++){
		x=read();y=read();z=read();
		val[i]=z;
		add(x,y,z,i);add(y,x,z,i);
	}
	dfs(1,0);
	build(1,1,top);
	for(int i=1;i<=q;i++){
		x=read();y=read();
		x=(x+las)%(n-1)+1;
		y=(y+las)%w;
		add(1,1,top,pre[to[x]],prv[to[x]],y-val[x]);
		val[x]=y;
		las=da[1];
		printf("%lld\n",las);
	}
	return 0;
}