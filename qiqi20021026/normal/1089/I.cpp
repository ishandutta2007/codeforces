#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 500

LL T,mod,n,fac[N],f[N],g[N],dp[N],h[N];

void upd(LL &x,LL y){x=(x+y)%mod;}

int main(){
	scanf("%lld%lld",&T,&mod);
	n=400;
	fac[0]=fac[1]=1;
	f[1]=1;
	for (LL i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%mod;
		memset(dp,0,sizeof dp); dp[0]=1;
		for (LL j=1;j<=i;++j){
			for (LL k=1;k<=j&&k<i;++k){
				upd(dp[j],dp[j-k]*(f[k]+g[k]));
			}
		}
		g[i]=dp[i];
		f[i]=(fac[i]-g[i]*2%mod+mod)%mod;
	}
	memset(dp,0,sizeof dp);
	for (LL i=1;i<=n;++i) dp[i]=(f[i]+g[i]*2)%mod;
	for (LL i=1;i<=n;++i) h[i]=f[i];
	for (LL i=2;i<=n;++i){
		for (LL j=n;j;--j){
			dp[j]=0;
			for (LL k=1;k<=j;++k) upd(dp[j],dp[j-k]*(f[k]+g[k]*2));
			if (j>i) upd(h[j],-h[i]*dp[j]%mod+mod);
		}
	}
	h[2]=2;
	while (T--){
		scanf("%lld",&n);
		printf("%lld\n",h[n]);
	}
	
	return 0;
}