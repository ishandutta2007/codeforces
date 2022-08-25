/*
Author: CNYALI_LK
LANG: C++
PROG: F.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<ll,ll> pii;
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
ll read(){
	ll s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
const ll p=1000000007;
ll fpm(ll a,ll b){
	ll c=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
ll y[1048575],qz[1048575],hz[1048575],inv[1048575],invf[1048575],finv[1048575];
ll Largrange(ll n,ll x){
	ll ans=0;
	qz[0]=1;
	for(ll i=1;i<=n;++i)qz[i]=qz[i-1]*(x-i)%p;
	hz[n+1]=1;
	for(ll i=n;i;--i)hz[i]=hz[i+1]*(x-i)%p;
	inv[1]=invf[0]=invf[1]=finv[0]=1;
	finv[1]=p-1;
	for(ll i=2;i<=n;++i){
		inv[i]=(p-p/i)*inv[p%i]%p;
		invf[i]=inv[i]*invf[i-1]%p;
		finv[i]=(p-inv[i])*finv[i-1]%p;
	}
	for(ll i=1;i<=n;++i){
		ans=(ans+y[i]*qz[i-1]%p*hz[i+1]%p*invf[i-1]%p*finv[n-i])%p;
	}
	return ans;
}
int main(){
#ifdef cnyali_lk
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	ll n,k;	
	n=read();
	k=read();
	for(ll i=1;i<=k+2&&i<=n;++i)y[i]=(y[i-1]+fpm(i,k))%p;
	if(n<=k+2)printf("%lld\n",y[n]);
	else printf("%lld\n",Largrange(k+2,n));
	return 0;
}