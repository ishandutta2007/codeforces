#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const ll mod=998244353,g=3,invg=332748118,inv2=499122177;
ll ksm(ll a,ll b){
	ll c=1;
	while(b){
		if(b%2==1) c=c*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return c;
}
using poly=vector<ll>;
poly FFT(poly F,bool flag){
	int n=F.size();
	vector<int> rev(n);
	for(int i=1;i<n;i++) rev[i]=rev[i>>1]>>1|(i&1?n>>1:0);
	for(int i=0;i<n;i++) if(i<rev[i]) swap(F[i],F[rev[i]]);
	for(int i=1;i<n;i*=2){
		ll wn=ksm(flag?g:invg,(mod-1)/(i*2));
		for(int j=0;j<n;j+=i*2){
			ll w=1;
			for(int k=j;k<j+i;k++){
				ll t=F[k+i]*w%mod;
				F[k+i]=(F[k]-t+mod)%mod;
				F[k]=(F[k]+t)%mod;
				w=w*wn%mod;
			}
		}
	}
	if(!flag){
		ll invn=ksm(n,mod-2);
		for(int i=0;i<n;i++) F[i]=F[i]*invn%mod;
	}
	return F;
}
const int maxn=3e5+5;
int n;
ll fac[maxn],ifac[maxn],pw[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		fac[0]=pw[0]=1;
		for(int i=1;i<=n;i++){
			fac[i]=fac[i-1]*i%mod;
			pw[i]=pw[i-1]*inv2%mod;
		}
		ifac[n]=ksm(fac[n],mod-2);
		for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
		poly F(n+1),G(n+1);
		for(int i=0;i*2<=n;i++) F[i*2]=ifac[i]*pw[i]%mod;
		for(int i=0;i<=n;i++) G[i]=ifac[i];
		int len=1;
		while(len<n*2+1) len*=2;
		F.resize(len);
		G.resize(len);
		F=FFT(F,1);
		G=FFT(G,1);
		for(int i=0;i<len;i++) F[i]=F[i]*G[i]%mod;
		F=FFT(F,0);
		ll ans=0;
		for(int i=0;i*2<=n;i+=2)
			ans=(ans+F[n-i*2]*fac[n-i]%mod*fac[i]%mod*ifac[i]%mod*ifac[i/2]%mod)%mod;
		printf("%lld\n",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}