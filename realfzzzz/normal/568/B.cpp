#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
const int maxn=4e3+5;
int n;
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
ll B[maxn],fac[maxn],ifac[maxn];
ll C(int n,int m){
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	B[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++) B[i]=(B[i]+C(i-1,j-1)*B[i-j]%mod)%mod;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll res=0;
		for(int j=i;j<=n;j++)
			res=(res+B[n-j]*C(n,j)%mod*C(j,i)%mod*((j-i)%2==0?1:mod-1)%mod)%mod;
		ans=(ans+(ksm(2,i)-1+mod)%mod*res%mod)%mod;
	}
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}