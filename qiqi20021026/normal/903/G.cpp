#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 800000
#define ls (x<<1)
#define rs (x<<1|1)
#define P(x,y) make_pair(x,y)

LL n,m,p,x,y,z,tot,head[N],a[N],b[N],f[N],mn[N],tag[N];
struct edge{LL v,l,nxt;}e[N];
set<pair<LL,LL> > se;

void add(LL x,LL y,LL z){e[++tot].v=y; e[tot].l=z; e[tot].nxt=head[x]; head[x]=tot;}

void build(LL x,LL l,LL r){
	if (l==r){mn[x]=b[l-1]; return;}
	LL mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	mn[x]=min(mn[ls],mn[rs]);
}

void psd(LL x){
	mn[ls]+=tag[x]; mn[rs]+=tag[x];
	tag[ls]+=tag[x]; tag[rs]+=tag[x];
	tag[x]=0;
}

void add(LL x,LL l,LL r,LL L,LL R,LL k){
	if (l>=L&&r<=R){mn[x]+=k; tag[x]+=k; return;}
	psd(x);
	LL mid=(l+r)>>1;
	if (L<=mid) add(ls,l,mid,L,R,k);
	if (R>mid) add(rs,mid+1,r,L,R,k);
	mn[x]=min(mn[ls],mn[rs]);
}

int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	for (LL i=1;i<n;++i) scanf("%lld%lld",&a[i],&b[i]);
	for (LL i=1;i<=m;++i){scanf("%lld%lld%lld",&x,&y,&z); add(x,y,z);}
	build(1,1,n);
	for (LL i=1;i<=n;++i){
		f[i]=a[i];
		for (LL j=head[i];j;j=e[j].nxt)
			add(1,1,n,1,e[j].v,e[j].l);
		f[i]+=mn[1];
		se.insert(P(f[i],i));
	}
	printf("%lld\n",se.begin()->first);
	while (p--){
		scanf("%lld%lld",&x,&y);
		se.erase(P(f[x],x));
		f[x]-=a[x]; f[x]+=a[x]=y;
		se.insert(P(f[x],x));
		printf("%lld\n",se.begin()->first);
	}
	
	return 0;
}