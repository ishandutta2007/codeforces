#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 220000
#define M (N<<6)

LL n,ans;

struct segment_tree{
	int tot,i,rt[N],ls[M],rs[M];
	LL sum[M],tag[M];
	
	void nrp(){++i; rt[i]=rt[i-1];}
	
	void newnode(int &x,int y){
		x=++tot;
		ls[x]=ls[y]; rs[x]=rs[y]; tag[x]=tag[y];
	}

	void mdf(int &x,int y,int l,int r,int L,int R,LL t){
		newnode(x,y);
		if (l>=L&&r<=R){tag[x]+=t; return;}
		LL mid=(l+r)>>1;
		if (L<=mid) mdf(ls[x],ls[y],l,mid,L,R,t);
		if (R>mid) mdf(rs[x],rs[y],mid+1,r,L,R,t);
		sum[x]=sum[ls[x]]+sum[rs[x]]+tag[x]*(r-l+1);
	}
	void add(LL l,LL r,LL t){
		mdf(rt[i],rt[i],0,n,l,r,t);
	}
	
	LL qry(LL x,LL l,LL r,LL k){
		if (!x) return 0;
		LL mid=(l+r)>>1,ret=tag[x];
		if (k<=mid) ret+=qry(ls[x],l,mid,k);
		else ret+=qry(rs[x],mid+1,r,k);
		return ret;
	}
	LL qry(LL r,LL k){
		return qry(rt[r],0,n,k);
	}
}s1,s2;

#define ls (x<<1)
#define rs (x<<1|1)

int seg[N<<2],cov[N<<2],mx[N<<2];

void psd(LL x){
	if (~cov[x]){
		cov[ls]=cov[rs]=mx[ls]=mx[rs]=cov[x];
		cov[x]=-1;
	}
}

void cover(LL x,LL l,LL r,LL L,LL R,LL k){
	if (l>=L&&r<=R){
		cov[x]=mx[x]=k; return;
	}
	LL mid=(l+r)>>1;
	psd(x);
	if (L<=mid) cover(ls,l,mid,L,R,k);
	if (R>mid) cover(rs,mid+1,r,L,R,k);
	mx[x]=max(mx[ls],mx[rs]);
}

LL find(LL x,LL l,LL r,LL k){
	if (mx[x]<k) return 0;
	if (l==r) return l;
	LL mid=(l+r)>>1;
	psd(x);
	if (mx[rs]>=k) return find(rs,mid+1,r,k);
	return find(ls,l,mid,k);
}

#undef ls
#undef rs

int tot,rt[N],mn[M],ls[M],rs[M];

void mdf(int &x,LL y,LL l,LL r,LL t,LL k){
	x=++tot; ls[x]=ls[y]; rs[x]=rs[y];
	if (l==r){mn[x]=k; return;}
	LL mid=(l+r)>>1;
	if (t<=mid) mdf(ls[x],ls[y],l,mid,t,k);
	else mdf(rs[x],rs[y],mid+1,r,t,k);
	mn[x]=min(mn[ls[x]],mn[rs[x]]);
}

LL qry(LL x,LL l,LL r,LL L,LL R){
	if (L>R) return n+1;
	if (!x) return 0;
	if (l>=L&&r<=R) return mn[x];
	LL mid=(l+r)>>1,ret=n+1;
	if (L<=mid) ret=qry(ls[x],l,mid,L,R);
	if (R>mid) ret=min(ret,qry(rs[x],mid+1,r,L,R));
	return ret;
}

LL qry(LL x,LL l,LL r,LL k){
	if (l==r) return l;
	LL mid=(l+r)>>1;
	if (mn[ls[x]]<k) return qry(ls[x],l,mid,k);
	return qry(rs[x],mid+1,r,k);
}

void add(LL i,LL l,LL r,LL t){
	s1.add(l,r,t);
	s2.add(l,r,-t*(i-1));
}

LL calc(LL L,LL R,LL k){
	if (!k) return (R-L+1)*(R-L+2)/2;
	LL l=L,r=R,t=0;
	while (l<=r){
		LL mid=(l+r)>>1;
		if (qry(rt[mid],0,n,0,k-1)>=L){t=mid; r=mid-1;}
		else l=mid+1;
	}
	if (!t) return 0; --t;
	return (s1.qry(R,k)*R+s2.qry(R,k))-(s1.qry(t,k)*t+s2.qry(t,k))-(L-1)*(R-t);
}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i){
		s1.nrp(); s2.nrp();
		LL x,l,r,k; scanf("%lld%lld%lld%lld",&x,&l,&r,&k);
		x=(x+ans)%(n+1); k=(k+ans)%(n+1);
		l=(l+ans)%i+1; r=(r+ans)%i+1; if (l>r) swap(l,r);
		mdf(rt[i],rt[i-1],0,n,x,i);
		LL u=find(1,1,n,x+1),v=find(1,1,n,x);
		for (++u,v=min(v,i);u<=v;++u){
			LL w=u,t=qry(rt[i],0,n,u);
			LL j=1; for (;u+j<=v;j<<=1);
			for (;j;j>>=1)
				if (w+j<=v&&qry(rt[i],0,n,w+j)==t) w+=j;
			cover(1,1,n,u,w,t);
			add(i,x+1,t,w-u+1);
			u=w;
		}
		ans=calc(l,r,k)-calc(l,r,k+1);
		printf("%lld\n",ans);
	}
	
	return 0;
}