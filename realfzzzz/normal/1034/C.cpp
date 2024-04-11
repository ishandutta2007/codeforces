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
const int maxn=1e6+5;
int n,p[maxn];
ll s[maxn];
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
const ll mod=1e9+7;
ll f[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++) s[i]=read();
	for(int i=2;i<=n;i++) p[i]=read();
	for(int i=n;i>1;i--) s[p[i]]+=s[i];
	for(int i=1;i<=n;i++){
		ll d=gcd(s[i],s[1]);
		if(s[1]/d<=n) f[s[1]/d]++;
	}
	for(int i=n;i>0;i--) for(int j=2;i*j<=n;j++) f[i*j]+=f[i];
	for(int i=n;i>0;i--){
		f[i]=f[i]==i;
		if(f[i]) for(int j=2;i*j<=n;j++) f[i]=(f[i]+f[i*j])%mod;
	}
	printf("%lld\n",f[1]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}