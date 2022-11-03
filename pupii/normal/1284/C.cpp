#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,mod,fact[250010],ifact[250010];
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}return ret;
}
int C(int n,int m){return 1ll*fact[n]*ifact[m]%mod*ifact[n-m]%mod;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();mod=gi();
	fact[0]=1;for(int i=1;i<=n;++i)fact[i]=1ll*fact[i-1]*i%mod;
	ifact[n]=pow(fact[n],mod-2);for(int i=n;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=(ans+1ll*(n-i+1)*(n-i+1)%mod*fact[i]%mod*fact[n-i])%mod;
	printf("%d\n",ans);
	return 0;
}