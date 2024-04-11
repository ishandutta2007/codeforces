#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 3000000
#define ls (x<<1)
#define rs (x<<1|1)

LL n,sum,a[N],b[N],c[N],f[N],g[N],p[N],seg[N],tag[N];
bool fl;

void build(LL x,LL l,LL r){
	if (l==r){seg[x]=c[l]; return;}
	LL mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	seg[x]=max(seg[ls],seg[rs]);
}

void psd(LL x){
	seg[ls]+=tag[x]; seg[rs]+=tag[x];
	tag[ls]+=tag[x]; tag[rs]+=tag[x];
	tag[x]=0;
}

void mdf(LL x,LL l,LL r,LL L,LL R,LL k){
	L=max(L,1LL); R=min(R,n);
	if (L>R) return;
	if (l>=L&&r<=R){seg[x]+=k; tag[x]+=k; return;}
	LL mid=(l+r)>>1;
	psd(x);
	if (L<=mid) mdf(ls,l,mid,L,R,k);
	if (R>mid) mdf(rs,mid+1,r,L,R,k);
	seg[x]=max(seg[ls],seg[rs]);
}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i){
		scanf("%lld",a+i);
		sum+=a[i];
	}
	sort(a+1,a+n+1,greater<LL>());
	for (LL i=1;i<=n;++i){
		LL l=1,r=min(a[i]-1,i-1);
		if (l<=r){++f[l]; --f[r+1];}
		l=a[i],r=i-1;
		if (l<=r){g[l]+=a[i]; g[r+1]-=a[i];}
	}
	for (LL i=1;i<=n;++i){
		f[i]+=f[i-1];
		g[i]+=g[i-1];
		b[i]=b[i-1]+a[i];
		c[i]=b[i]-f[i]*i-g[i]-i*(i-1);
	}
	for (LL i=1;i<=n;){
		LL j=i;
		for (;j<=n&&a[i]==a[j];++j);
		--j;
		for (LL k=j;i<=j;++i,--k) p[i]=k;
	}
	build(1,1,n);
	for (LL i=0;i<=n;++i){
		if (i>0){
			LL x=p[i];
			mdf(1,1,n,x,n,-1);
			mdf(1,1,n,a[x],x-1,1);
		}
		if ((sum-i)&1) continue;
		if (seg[1]<=0){fl=1; printf("%lld ",i);}
	}
	if (!fl) puts("-1");
	
	return 0;
}