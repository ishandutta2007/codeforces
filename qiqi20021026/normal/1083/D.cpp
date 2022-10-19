#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 420000
#define ls (x<<1)
#define rs (x<<1|1)

const LL mod=1000000007;
LL n,ans,a[N],c[N],tag[N][2],lst[N],nxt[N],vis[N],cnt[N];
struct node{
	LL n,s,l,r,lr,sr,minl,maxl,minr,maxr;
	node(LL n=0,LL s=0,LL l=0,LL r=0,LL lr=0,LL sr=0,LL minl=0,LL maxl=0,LL minr=0,LL maxr=0):
		n(n),s(s),l(l),r(r),lr(lr),sr(sr),minl(minl),maxl(maxl),minr(minr),maxr(maxr){}
	node operator + (const node &p) const{
		return node(n+p.n,s+p.s,l+p.l,r+p.r,lr+p.lr,sr+p.sr,min(minl,p.minl),max(maxl,p.maxl),min(minr,p.minr),max(maxr,p.maxr));
	}
}s[N];

void build(LL x,LL l,LL r){
	tag[x][0]=tag[x][1]=-1;
	if (l==r){s[x]=node(1,l,1,n,n,l*n,1,1,n,n); return;}
	LL mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	s[x]=s[ls]+s[rs];
}

void psd(LL x){
	LL num,sum,u=tag[x][0],v=tag[x][1];
	if (~u){
		num=s[ls].n,sum=s[ls].s;
		s[ls]=node(num,sum,u*num,s[ls].r,u*s[ls].r,s[ls].sr,u,u,s[ls].minr,s[ls].maxr);
		num=s[rs].n,sum=s[rs].s;
		s[rs]=node(num,sum,u*num,s[rs].r,u*s[rs].r,s[rs].sr,u,u,s[rs].minr,s[rs].maxr);
		tag[ls][0]=tag[rs][0]=tag[x][0];
	}
	if (~v){
		num=s[ls].n,sum=s[ls].s;
		s[ls]=node(num,sum,s[ls].l,v*num,s[ls].l*v,sum*v,s[ls].minl,s[ls].maxl,v,v);
		num=s[rs].n,sum=s[rs].s;
		s[rs]=node(num,sum,s[rs].l,v*num,s[rs].l*v,sum*v,s[rs].minl,s[rs].maxl,v,v);
		tag[ls][1]=tag[rs][1]=tag[x][1];
	}
	tag[x][0]=tag[x][1]=-1;
}

void mdf(LL x,LL l,LL r,LL L,LL R,LL u,LL v){
	if (l>=L&&r<=R){
		LL num=s[x].n,sum=s[x].s;
		if (s[x].maxl<u){
			s[x]=node(num,sum,u*num,s[x].r,u*s[x].r,s[x].sr,u,u,s[x].minr,s[x].maxr);
			tag[x][0]=u;
		}
		if (s[x].minr>v){
			s[x]=node(num,sum,s[x].l,v*num,s[x].l*v,sum*v,s[x].minl,s[x].maxl,v,v);
			tag[x][1]=v;
		}
		if (s[x].minl>=u&&s[x].maxr<=v) return;
		LL mid=(l+r)>>1;
		psd(x);
		if (L<=mid) mdf(ls,l,mid,L,R,u,v);
		if (R>mid) mdf(rs,mid+1,r,L,R,u,v);
		s[x]=s[ls]+s[rs];
		return;
	}
	LL mid=(l+r)>>1;
	psd(x);
	if (L<=mid) mdf(ls,l,mid,L,R,u,v);
	if (R>mid) mdf(rs,mid+1,r,L,R,u,v);
	s[x]=s[ls]+s[rs];
}

node qry(LL x,LL l,LL r,LL L,LL R){
	if (l>=L&&r<=R) return s[x];
	LL mid=(l+r)>>1;
	psd(x);
	if (R<=mid) return qry(ls,l,mid,L,R);
	if (L>mid) return qry(rs,mid+1,r,L,R);
	return qry(ls,l,mid,L,R)+qry(rs,mid+1,r,L,R);
}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i){scanf("%lld",a+i); c[i]=a[i];}
	sort(c+1,c+n+1);
	for (LL i=1;i<=n;++i) a[i]=lower_bound(c+1,c+n+1,a[i])-c;
	for (LL i=1;i<=n;++i){lst[i]=vis[a[i]]+1; vis[a[i]]=i;}
	for (LL i=1;i<=n;++i) vis[a[i]]=n+1;
	for (LL i=n;i;--i){nxt[i]=vis[a[i]]-1; vis[a[i]]=i;}
	build(1,1,n);
	for (LL i=1,j=1;i<=n;++i){
		++cnt[a[i]];
		for (;cnt[a[i]]>1;++j) --cnt[a[j]];
		mdf(1,1,n,j,i,lst[i],nxt[i]);
		node p=qry(1,1,n,j,i);
		ans+=p.sr-i*p.s-p.lr+p.l*i;
	}
	printf("%lld\n",ans%mod);
	
	return 0;
}