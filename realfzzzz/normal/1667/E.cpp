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
const int maxn=2e5+5;
int n;
const ll mod=998244353;
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
ll inv(ll x){
	return ifac[x]*fac[x-1]%mod;
}
ll C(int n,int m){
	return n<m?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
ll ans[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	ll s=0;
	for(int i=n;i>0;i--){
		ll res=i==1?fac[n-1]:fac[(n-1)/2]*ifac[(n-1)/2-i+1]%mod*fac[n-i]%mod;
		ans[i]=(res-s+mod)%mod;
		if(i>1) s=(s+res*inv(i-1)%mod)%mod;
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}