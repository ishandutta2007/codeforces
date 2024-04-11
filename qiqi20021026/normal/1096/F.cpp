#include<bits/stdc++.h>

using namespace std;

#define N 800000
#define LL long long

const LL mod=998244353;
LL n,m,ans,fac[N],ifac[N],a[N],b[N],c[N],bit[N];

LL qry(LL x){LL ret=0; for (;x;x-=x&(-x)) ret+=bit[x]; return ret;}

void add(LL x){for (;x<=n;x+=x&(-x)) ++bit[x];}

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

void upd(LL &x,LL y){x=(x+y%mod+mod)%mod;}

int main(){
	scanf("%lld",&n);
	fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	ifac[n]=inv(fac[n]); for (LL i=n-1;~i;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	for (LL i=1;i<=n;++i){
		scanf("%lld",a+i);
		if (a[i]>0){
			upd(ans,m-qry(a[i])); add(a[i]);
			++m;
		}
	}
	ans=ans*fac[n-m]%mod;
	for (LL i=1;i<=n;++i) b[i]=b[i-1]+(a[i]==-1);
	for (LL i=n;i;--i) c[i]=c[i+1]+(a[i]==-1);
	for (LL i=1;i<=n;++i)
		if (a[i]>0){
			LL x=a[i]-qry(a[i]);
			upd(ans,x*c[i]%mod*fac[n-m-1]);
			x=n-a[i]-(m-qry(a[i]));
			upd(ans,x*b[i]%mod*fac[n-m-1]);
		}
	ans=ans*ifac[n-m]%mod;
	upd(ans,(n-m)*(n-m-1)%mod*inv(4));
	printf("%lld\n",ans);
	
	return 0;
}