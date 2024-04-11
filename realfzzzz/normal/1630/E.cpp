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
int n,m,cnt[maxn],c[maxn];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
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
ll inv(int x){
	return ifac[x]*fac[x-1]%mod;
}
ll f[maxn],g[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[read()]++;
		m=0;
		for(int i=1;i<=n;i++) if(cnt[i]) c[++m]=cnt[i];
		if(m==1){
			printf("1\n");
			continue;
		}
		int d=0;
		for(int i=1;i<=m;i++) d=gcd(d,c[i]);
		fac[0]=1;
		for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
		ifac[n]=ksm(fac[n],mod-2);
		for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
		for(int i=1;i<=n;i++) f[i]=g[i]=0;
		for(int i=1;i<=d;i++) if(d%i==0){
			f[i]=fac[n/i];
			for(int j=1;j<=m;j++) f[i]=f[i]*ifac[c[j]/i]%mod;
			ll s=0;
			for(int j=1;j<=m;j++) s=(s+ksm(c[j]/i,2))%mod;
			g[i]=(ksm(n/i,2)-s+mod)%mod*f[i]%mod*inv(n/i)%mod*inv(n/i-1)%mod*n%mod;
		}
		ll s1=0,s2=0;
		for(int i=1;i<=n;i++){
			s1=(s1+f[n/gcd(n,i)])%mod;
			s2=(s2+g[n/gcd(n,i)])%mod;
		}
		printf("%lld\n",s2*ksm(s1,mod-2)%mod);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}