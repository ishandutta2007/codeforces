#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=1e6+5;
const ll mod=1e9+7,inv2=5e8+4;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
ll fac[maxn],ifac[maxn];
ll C(int n,int m){
	return m<0||m>n?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
	ifac[maxn-1]=ksm(fac[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	int T=read();
	while(T--){
		int n,m;
		n=read();
		m=read();
		ll k=read();
		if(!m){
			printf("0\n");
			continue;
		}
		if(m==n){
			printf("%lld\n",k*n%mod);
			continue;
		}
		ll pw=1,ans=0;
		for(int i=n-1;i>0;i--){
			pw=pw*inv2%mod;
			ans=(ans+k*i%mod*C(n-i-1,m-i)%mod*pw%mod)%mod;
		}
		printf("%lld\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}