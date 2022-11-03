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
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int ifact[200010];
int S(int n,int m){
	int ret=0;
	for(int i=0,M=1;i<=m;++i,M=mod-M)ret=(ret+1ll*M*ifact[i]%mod*ifact[m-i]%mod*pow(m-i,n))%mod;
	return ret;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi(),W=0;
	for(int i=1;i<=n;++i)W=(W+gi())%mod;
	ifact[0]=1;for(int i=1;i<=n;++i)ifact[i]=1ll*ifact[i-1]*i%mod;
	ifact[n]=pow(ifact[n],mod-2);for(int i=n;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	printf("%d\n",1ll*W*(S(n,k)+1ll*(n-1)*S(n-1,k)%mod)%mod);
	return 0;
}