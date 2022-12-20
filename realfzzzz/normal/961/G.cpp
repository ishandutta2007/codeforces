#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,k;
typedef long long ll;
const ll mod=1e9+7;
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
ll S(int n,int m){
    ll ans=0;
    for(int i=0;i<=m;i++) ans=(ans+ifac[i]*ifac[m-i]%mod*ksm(m-i,n)%mod*(i%2==0?1:mod-1)%mod)%mod;
    return ans;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	ll s=0;
	for(int i=0;i<n;i++) s=(s+readint())%mod;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	printf("%lld\n",(S(n,k)+S(n-1,k)*(n-1)%mod)%mod*s%mod);
	return 0;
}