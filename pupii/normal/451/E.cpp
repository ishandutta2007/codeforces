#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
il int C(ll n,int m){
	if(n<0)return 0;
	int ret=1;
	n%=mod;while(m--)ret=1ll*ret*(n--)%mod;
	return ret;
}
ll f[21],sum[1<<20],lg[1<<20];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),ans=0;ll m=gi();
	for(int i=0;i<n;++i)f[i]=gi();
	for(int i=0;i<n;++i)lg[1<<i]=i;
	for(int i=0;i<1<<n;++i){
		int res=__builtin_popcount(i)&1?mod-1:1;
		if(i)sum[i]=f[lg[i&-i]]+sum[i^(i&-i)]+1;
		ans=(ans+1ll*res*C(m-sum[i]+n-1,n-1))%mod;
	}
	int orz=1;for(int i=1;i<n;++i)orz=1ll*orz*i%mod;
	printf("%lld\n",1ll*ans*pow(orz,mod-2)%mod);
	return 0;
}