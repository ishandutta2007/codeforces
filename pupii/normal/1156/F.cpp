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
	return f?x:-x;
}
int a[5010],suf[5010],inv[5010],f[5010][5010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)++a[gi()];
	for(int i=n;i;--i)suf[i]=a[i]+suf[i+1];
	inv[1]=1;for(int i=2;i<=n;++i)inv[i]=mod-1ll*inv[mod%i]*(mod/i)%mod;
	for(int i=1;i<=n;++i)if(a[i])f[1][i]=1ll*a[i]*inv[n]%mod;
	for(int i=2;i<=n;++i){
		int sum=0;
		for(int j=1;j<=n;++j){
			f[i][j]=1ll*a[j]*sum%mod;
			sum=(sum+1ll*inv[n-i+1]*f[i-1][j])%mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(a[j]>1)ans=(ans+1ll*inv[n-i]*f[i][j]%mod*(a[j]-1))%mod;
	printf("%d\n",ans);
	return 0;
}