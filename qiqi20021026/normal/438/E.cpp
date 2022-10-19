#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 800000

const LL mod=998244353;
LL rev[N];

void upd(LL &x,LL y){
	x=(x+y)%mod;
}

LL inv(LL x){
	return x==1?1:(mod-mod/x)*inv(mod%x)%mod;
}

LL pw(LL x,LL k){
	if (!k) return 1;
	LL tmp=pw(x*x%mod,k>>1);
	return k&1?tmp*x%mod:tmp;
}

void ntt_init(LL &n){
	LL k=0; for (;1<<k<n;++k);
	n=1<<k; rev[0]=0;
	for (LL i=1;i<n;++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
}

void ntt(LL f[],LL n){
	for (LL i=0;i<n;++i) if (i<rev[i]) swap(f[i],f[rev[i]]);
	for (LL i=0;1<<i<n;++i){
		LL t=1<<i,wn=pw(3,(mod-1)/t/2);
		for (LL j=0;j<n;j+=t<<1){
			LL *f1=f+j,*f2=f+j+t,w=1;
			for (LL k=0;k<t;++k){
				LL tmp=f2[k]*w%mod;
				f2[k]=(f1[k]-tmp)%mod;
				f1[k]=(f1[k]+tmp)%mod;
				w=w*wn%mod;
			}
		}
	}
}

LL n,m,a[N],f[N],g[N],A[N],F[N],G[N],C[N];

void solve(LL l,LL r){
	if (l==r){
		upd(f[l],g[l]);
		return;
	}
	LL mid=(l+r)>>1;
	solve(l,mid);
	LL len=(r-l)*2; ntt_init(len);
	LL I=inv(len);
	for (LL i=0;i<len;++i) F[i]=G[i]=A[i]=0;
	for (LL i=l;i<=mid;++i) F[i-l]=f[i];
	for (LL i=0;i<=r-l;++i) A[i]=a[i];
	ntt(F,len); ntt(A,len);
	for (LL i=0;i<len;++i) C[i]=F[i]*A[i]%mod;
	ntt(C,len); reverse(C+1,C+len);
	for (LL i=mid+1;i<=r;++i){
		upd(g[i],C[i-l]*I);
	}
	if (l==0){
		for (LL i=l;i<=mid;++i) G[i-l]=g[i];
		ntt(G,len);
		for (LL i=0;i<len;++i) C[i]=F[i]*G[i]%mod;
		ntt(C,len); reverse(C+1,C+len);
		for (LL i=mid+1;i<=r;++i){
			upd(f[i],C[i]*I);
		}
	}
	else{
		for (LL i=0;i<=r-l;++i) G[i]=g[i];
		ntt(G,len);
		for (LL i=0;i<len;++i) C[i]=F[i]*G[i]%mod;
		for (LL i=0;i<len;++i) F[i]=G[i]=0;
		for (LL i=0;i<=r-l;++i) F[i]=f[i];
		for (LL i=l;i<=mid;++i) G[i-l]=g[i];
		ntt(F,len); ntt(G,len);
		for (LL i=0;i<len;++i) upd(C[i],F[i]*G[i]);
		ntt(C,len); reverse(C+1,C+len);
		for (LL i=mid+1;i<=r;++i){
			upd(f[i],C[i-l]*I);
		}
	}
	solve(mid+1,r);
}

int main(){
	scanf("%lld%lld",&n,&m);
	for (LL i=1;i<=n;++i){
		LL x; scanf("%lld",&x);
//		LL x=rand()*rand()%100000+1;
		a[x]=1;
	}
	f[0]=1;
	solve(0,m);
	for (int i=1;i<=m;++i) printf("%lld\n",(f[i]+mod)%mod);
	
	return 0;
}