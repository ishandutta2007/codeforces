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
const int maxn=5e3+5;
int n,m,k;
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
ll fac[maxn*2],ifac[maxn*2];
ll C(int n,int m){
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	k=read();
	if(n==1){
		printf("1\n");
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<=n+m;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n+m]=ksm(fac[n+m],mod-2);
	for(int i=n+m-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	ll res1=0,res2=0;
	for(int i=0;i*k<=m&&i<=n;i++)
		res1=(res1+C(n,i)*(i%2==0?1:mod-1)%mod*C(n+m-i*k-1,m-i*k)%mod)%mod;
	for(int i=k;i<=m;i++) res2=(res2+C(m-i+n-2,n-2))%mod;
	printf("%lld\n",(C(n+m-1,n-1)-res1+mod)%mod*ksm(res2*n%mod,mod-2)%mod);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}