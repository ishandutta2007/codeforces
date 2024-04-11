#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 800000
#define ls (x<<1)
#define rs (x<<1|1)
#define INF 0x3f3f3f3f

int n,a[N],pos[N],bit[N],mn[N],mn2[N],num[N],tag[N];
LL ans,out[N];

void add(int x){
	for (;x<=n;x+=x&(-x)) ++bit[x];
}

int qry(int x){
	int ret=0;
	for (;x;x-=x&(-x)) ret+=bit[x];
	return ret;
}

void upd(int x){
	mn[x]=min(mn[ls],mn[rs]); num[x]=0;
	if (mn[ls]==mn[x]) num[x]+=num[ls];
	if (mn[rs]==mn[x]) num[x]+=num[rs];
	mn2[x]=INF;
	if (mn[ls]!=mn[x]) mn2[x]=mn[ls];
	if (mn[rs]!=mn[x]) mn2[x]=mn[rs];
	mn2[x]=min(mn2[x],min(mn2[ls],mn2[rs]));
}

void psd(int x){
	if (~tag[x]){
		if (tag[x]>mn[ls]){mn[ls]=tag[x]; tag[ls]=tag[x];}
		if (tag[x]>mn[rs]){mn[rs]=tag[x]; tag[rs]=tag[x];}
		tag[x]=-1;
	}
}

void open(int x,int l,int r,int k){
	if (l==r){
		mn[x]=0; num[x]=1;
		ans+=qry(k);
		return;
	}
	int mid=(l+r)>>1;
	psd(x);
	if (k<=mid) open(ls,l,mid,k);
	if (k>mid) open(rs,mid+1,r,k);
	upd(x);
}

void mdf(int x,int l,int r,int L,int R,int k){
	if (L>R) return;
	if (mn[x]>=k) return;
	int mid=(l+r)>>1;
	if (l>=L&&r<=R){
		if (mn2[x]>=k){
			tag[x]=k;
			ans+=(LL)(qry(mn[x])+1)*num[x];
			mn[x]=k;
			ans-=(LL)qry(mn[x])*num[x];
		}
		else{psd(x); mdf(ls,l,mid,L,R,k); mdf(rs,mid+1,r,L,R,k); upd(x);}
		return;
	}
	psd(x);
	if (L<=mid) mdf(ls,l,mid,L,R,k);
	if (R>mid) mdf(rs,mid+1,r,L,R,k);
	upd(x);
}

void build(int x,int l,int r){
	tag[x]=-1;
	if (l==r){mn[x]=mn2[x]=INF; num[x]=0; return;}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	upd(x);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",a+i); pos[a[i]]=i;
	}
	build(1,1,n);
	for (int i=1;i<=n;++i){
		int j=pos[i];
		add(j);
		open(1,1,n,j);
		mdf(1,1,n,j+1,n,j);
		out[i]+=ans;
	}
	memset(bit,0,sizeof bit);
	build(1,1,n);
	ans=0;
	for (int i=1;i<=n;++i){
		int j=n-pos[i]+1;
		add(j);
		open(1,1,n,j);
		mdf(1,1,n,j+1,n,j);
		out[i]+=ans;
	}
	for (int i=1;i<=n;++i) printf("%lld\n",out[i]-i);
	
	return 0;
}