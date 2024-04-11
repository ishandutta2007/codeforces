#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 2000000
#define INF 0x3f3f3f3f3f3f3f3fLL
#define ls (x<<1)
#define rs (x<<1|1)

LL n,m,tot,x,y,z,mn[N],mx[N],s[N],d[N],dep[N],a[N],fa[N],head[N],tag[N],ans[N];
struct edge{LL v,nxt;}e[N];
struct node{LL i,l,r;};
vector<node> p[N];

void add(LL x,LL y){
	e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;
}

void build(LL x,LL l,LL r){
	if (l==r){s[x]=!d[l]?dep[l]:INF; return;}
	LL mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	s[x]=min(s[ls],s[rs]);
}

void psd(LL x){
	s[ls]+=tag[x]; s[rs]+=tag[x];
	tag[ls]+=tag[x]; tag[rs]+=tag[x];
	tag[x]=0;
}

void mdf(LL x,LL l,LL r,LL L,LL R,LL k){
	if (L>R) return;
	if (l>=L&&r<=R){s[x]+=k; tag[x]+=k; return;}
	LL mid=(l+r)>>1;
	psd(x);
	if (L<=mid) mdf(ls,l,mid,L,R,k);
	if (R>mid) mdf(rs,mid+1,r,L,R,k);
	s[x]=min(s[ls],s[rs]);
}

LL qry(LL x,LL l,LL r,LL L,LL R){
	if (L>R) return INF;
	if (l>=L&&r<=R) return s[x];
	LL mid=(l+r)>>1,mn=INF;
	psd(x);
	if (L<=mid) mn=min(mn,qry(ls,l,mid,L,R));
	if (R>mid) mn=min(mn,qry(rs,mid+1,r,L,R));
	return mn;
}

void dfs(LL u){
	for (LL i=0;i<(LL)p[u].size();++i){
		LL x=p[u][i].l,y=p[u][i].r,z=p[u][i].i;
		ans[z]=qry(1,1,n,x,y);
	}
	for (LL i=head[u],v;i;i=e[i].nxt){
		v=e[i].v;
		mdf(1,1,n,mn[v],mx[v],-a[v]);
		mdf(1,1,n,1,mn[v]-1,a[v]);
		mdf(1,1,n,mx[v]+1,n,a[v]);
		dfs(v=e[i].v);
		mdf(1,1,n,mn[v],mx[v],a[v]);
		mdf(1,1,n,1,mn[v]-1,-a[v]);
		mdf(1,1,n,mx[v]+1,n,-a[v]);
	}
}

int main(){
	scanf("%lld%lld",&n,&m);
	for (LL i=1;i<=n;++i) mn[i]=mx[i]=i;
	for (LL i=2;i<=n;++i){
		scanf("%lld%lld",fa+i,a+i);
		++d[fa[i]];
		dep[i]=dep[fa[i]]+a[i];
		add(fa[i],i);
	}
	for (LL i=n;i>=2;--i){
		mn[fa[i]]=min(mn[fa[i]],mn[i]);
		mx[fa[i]]=max(mx[fa[i]],mx[i]);
	}
	for (LL i=1;i<=m;++i){
		scanf("%lld%lld%lld",&x,&y,&z);
		p[x].push_back((node){i,y,z});
	}
	build(1,1,n);
	dfs(1);
	for (LL i=1;i<=m;++i) printf("%lld\n",ans[i]);
	
	return 0;
}