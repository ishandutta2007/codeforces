#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
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
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int strong[2010],f[2010][2010],dp[2010];
int pp[2010],pp2[2010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a=gi(),b=gi(),p=1ll*a*pow(b,mod-2)%mod;
	pp[0]=pp2[0]=1;
	for(int i=1;i<=n;++i)pp[i]=1ll*pp[i-1]*p%mod,pp2[i]=1ll*pp2[i-1]*(mod+1-p)%mod;
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		f[i][0]=1;
		for(int j=1;j<=i;++j)f[i][j]=(1ll*f[i-1][j-1]*pp[i-j]+1ll*f[i-1][j]*pp2[j])%mod;
	}
	strong[1]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<i;++j)strong[i]=(strong[i]+1ll*strong[j]*f[i][j])%mod;
		strong[i]=(mod+1-strong[i])%mod;
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<i;++j)dp[i]=(dp[i]+1ll*strong[j]*f[i][j]%mod*(dp[j]+dp[i-j]+1ll*j*(i-j)%mod+1ll*j*(j-1)/2%mod))%mod;
		dp[i]=(dp[i]+1ll*strong[i]*f[i][i]%mod*(1ll*i*(i-1)/2%mod))%mod;
		dp[i]=1ll*dp[i]*pow(mod+1-1ll*strong[i]*f[i][i]%mod,mod-2)%mod;
	}
	printf("%d\n",dp[n]);
	return 0;
}