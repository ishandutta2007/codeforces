#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
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
int f[4010][2010],p[2010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi(),l=1ll*gi()*pow(n<<1|1,mod-2)%mod;
	p[0]=1;for(int i=1;i<=n;++i)p[i]=1ll*i*p[i-1]%mod;
	f[0][0]=1;
	for(int i=0;i<n<<1;++i){
		for(int j=std::min(n,i);~j;--j){
			f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%mod;
			if(j)f[i+1][j-1]=(f[i+1][j-1]+1ll*f[i][j]*j)%mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n<<1;++i)
		for(int j=k;j<=n;++j)
			ans=(ans+1ll*f[i][j]*f[(n<<1)-i][j]%mod*p[j])%mod;
	printf("%lld\n",1ll*ans*l%mod*pow(f[n<<1][0],mod-2)%mod);
	return 0;
}