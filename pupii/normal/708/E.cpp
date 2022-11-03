#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int f[1510][1510],sf1[1510],sf2[1510],fact[100010],ifact[100010],g[1510],sg[1510],pP[100010],piP[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	int a=gi(),b=gi(),P=1ll*a*pow(b,mod-2)%mod,iP=mod+1-P;
	int K=gi();
	fact[0]=1;for(int i=1;i<=K;++i)fact[i]=1ll*fact[i-1]*i%mod;
	ifact[K]=pow(fact[K],mod-2);for(int i=K;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	pP[0]=piP[0]=1;
	for(int i=1;i<=K;++i)pP[i]=1ll*pP[i-1]*P%mod;
	for(int i=1;i<=K;++i)piP[i]=1ll*piP[i-1]*iP%mod;
	g[0]=sg[0]=piP[K];
	for(int i=1;i<=std::min(K,m);++i)g[i]=1ll*pP[i]*piP[K-i]%mod*fact[K]%mod*ifact[i]%mod*ifact[K-i]%mod;
	for(int i=1;i<=m;++i)sg[i]=(sg[i-1]+g[i])%mod;
	f[0][m]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)sf1[j]=(f[i-1][j]+sf1[j-1])%mod;
		for(int j=1;j<=m;++j)sf2[j]=(1ll*g[j]*sf1[j]+sf2[j-1])%mod;
		for(int j=1;j<=m;++j)f[i][j]=1ll*g[m-j]*(1ll*sg[j-1]*(sf1[m]-sf1[m-j]+mod)%mod-sf2[j-1]+mod)%mod;
	}
	int ans=0;
	for(int i=1;i<=m;++i)ans=(ans+f[n][i])%mod;
	printf("%d\n",ans);
	return 0;
}