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
int n,a[maxn],c[maxn*3][2];
const ll mod=998244353;
ll ksm(ll a,ll b){
	ll c=1;
	while(b){
		if(b%2==1) c=c*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return c;
}
ll fac[maxn],ifac[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) c[a[i]][read()]++;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	int x=1;
	while(!c[x][0]&&!c[x][1]) x++;
	if(c[x][0]+c[x][1]==n){
		printf("%lld\n",fac[n]);
		return 0;
	}
	int s=0;
	ll ans=fac[n]*ifac[n-c[x+n-1][1]]%mod;
	for(int i=x;i<=x+n-1;i++){
		if(c[i][0]&&x+n-1-i>s) ans=0;
		else ans=ans*fac[c[i][0]]%mod;
		s+=c[i][0];
		if(i<x+n-1&&(c[i][1]>1||(c[i][1]&&i-x>s))) ans=0;
		s+=c[i][1];
	}
	if(s!=n) ans=0;
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}