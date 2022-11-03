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
	return f?x:-x;
}
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int f[1000010],S[1000010],fact[1000010],ifact[1000010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi();
	fact[0]=1;for(int i=1;i<=n;++i)fact[i]=1ll*fact[i-1]*i%mod;
	ifact[n]=pow(fact[n],mod-2);for(int i=n;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	for(int i=k+2;i<=n;++i)f[i]=1ll*fact[i-2]*(0ll+i-k-1+S[i-1]-S[i-k-1]+mod)%mod,S[i]=(S[i-1]+1ll*f[i]*ifact[i-1])%mod;
	printf("%d\n",1ll*fact[n-1]*S[n]%mod);
	return 0;
}