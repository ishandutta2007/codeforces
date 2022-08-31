/*
Author: CNYALI_LK
LANG: C++
PROG: C.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %I64d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %I64d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
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
const ll p=998244353,N=1233333;
ll fac[N],inv[N],invf[N];
ll fpm(ll a,ll b){
	if(a<0)a+=p;
	b%=(p-1);
	ll c=1;
	while(b){
		if(b&1)c=c*a%p;
		a=a*a%p;
		b>>=1;
	}
	return c;
}
ll C(ll n,ll k){
	return fac[n]*invf[k]%p*invf[n-k]%p;
}
int main(){
#ifdef cnyali_lk
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	ll n;
	n=read();
	fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;
	for(ll i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%p;
		inv[i]=(p-p/i)*inv[p%i]%p;
		invf[i]=inv[i]*invf[i-1]%p;
	}
	ll ans=0;
	for(ll i=1;i<=n;++i){
		ans+=2*C(n,i)*(i&1?1:p-1)%p*fpm(3,i+(n-i)*n)%p;
		ans+=3*C(n,i)*(i&1?1:p-1)%p*(fpm(fpm(3,n-i)-1,n)-fpm(3,n*(n-i))+p)%p;
		ans%=p;
	}
	cout<<ans<<endl;
	return 0;


}