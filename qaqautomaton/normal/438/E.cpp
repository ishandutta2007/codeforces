/*
Author: CNYALI_LK
LANG: C++
PROG: polynomial.cpp
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
namespace Polynomial{
	const ll p=998244353,g_=3;
	ll rev[266667];
	ll fpm(ll a,ll b){
		ll c=1;
		while(b){
			if(b&1)c=c*a%p;
			a=a*a%p;
			b>>=1;
		}
		return c;
	}
	void Rev(ll n,ll *f){
		for(ll i=0;i<=n&&i<n-i;++i)swap(f[i],f[n-i]);
	}
	void NTT(ll *f,ll n,ll flag){
		for(ll i=1;i<n;++i){
			rev[i]=(rev[i>>1]>>1)|((i&1)*(n>>1));
			if(i<rev[i])swap(f[i],f[rev[i]]);
		}
		for(ll i=1;i<n;i<<=1){
			ll ww=fpm(g_,flag*((p-1)/(i+i))+p-1);
			for(ll j=0;j<n;j+=i+i){
				ll w=1,u,v;	
				for(ll k=0;k<i;++k){
					u=f[j+k];v=f[j+k+i]*w%p;
					f[j+k]=(u+v)%p;
					f[j+k+i]=(u-v+p)%p;
					w=w*ww%p;
				}
			}
		}
		if(!~flag){
			ll in=fpm(n,p-2);
			for(ll i=0;i<n;++i)f[i]=f[i]*in%p;
		}
	}
	ll f1[266667],g1[266667];
	void Mul(ll n,ll *f,ll m,ll *g,ll *h){
		ll N=1;
		while(N<=n+m)N<<=1;
		for(ll i=0;i<N;++i){f1[i]=f[i];if(i>n)f[i]=0;}
		for(ll i=0;i<N;++i){g1[i]=g[i];if(i>m)g[i]=0;}
		NTT(f,N,1);
		if(f!=g)NTT(g,N,1);
		for(ll i=0;i<N;++i)h[i]=f[i]*g[i]%p;
		NTT(h,N,-1);
		if(f!=h){for(ll i=0;i<N;++i)f[i]=f1[i];}
		if(g!=h){for(ll i=0;i<N;++i)g[i]=g1[i];}
	}
	/*
1: Inv
2: Div ln
3. Sqrt exp
4. Sqrt Pow
*/
	ll h1[266667],h2[266667],h3[266667],h4[266667];
	void Inv(ll n,ll *f,ll *g){
		if(n==1){
			g[0]=fpm(*f,p-2);
			g[1]=g[2]=g[3]=0;
			return;
		}
		else{
			ll m=(n+1)>>1;
			Inv(m,f,g);
			ll N=1;
			while(N<=n+m+m-3)N<<=1;
			for(ll i=0;i<N;++i){f1[i]=f[i];if(i>=n)f[i]=0;if(i>=m)g[i]=0;}
			NTT(f,N,1);
			NTT(g,N,1);
			for(ll i=0;i<N;++i)g[i]=(g[i]+g[i]-g[i]*g[i]%p*f[i]%p+p)%p;
			NTT(g,N,-1);
			for(ll i=0;i<N;++i)f[i]=f1[i];
			for(ll i=n;i<N;++i)g[i]=0;
		}
	}
	void Div(ll n,ll *f,ll m,ll *g,ll *q,ll *r){
		Rev(n,f);
		Rev(m,g);
		Inv(n-m+1,g,h2);
		for(ll i=n-m+1;i<=n+n-m-m+2;++i)q[i]=0;
		Rev(n,f);
		Rev(m,g); 
		Rev(n-m,q);
		Mul(m,g,n-m,q,r);
		for(ll i=0;i<=n;++i){r[i]=(f[i]-r[i]+p)%p;}
	}
	void Sqrt(ll n,ll *f,ll *g){
		if(n==1){
			g[0]=(ll)(sqrt(f[0])+0.5);
			g[1]=0;
		}
		else{
			ll m;
			Sqrt(m=(n+1)>>1,f,g);
			Mul(m-1,g,m-1,g,h3);
			if(n-1>m+m-2)h3[n-1]=0;
			for(ll i=0;i<n;++i)h3[i]=(h3[i]+f[i])%p;
			for(ll i=0;i<m;++i)g[i]=g[i]*2%p;
			Inv(n,g,h4);
			Mul(n-1,h4,n-1,h3,g);
			for(ll i=n;i<n+n;++i)g[i]=0;
		}
	}
	ll inv[266667];
	void Integ(ll n,ll *f,ll *g){
		inv[1]=1;
		for(ll i=2;i<=n+1;++i)inv[i]=(p-p/i)*inv[p%i]%p;
		for(ll i=n;~i;--i)g[i+1]=f[i]*inv[i+1]%p;
		g[0]=0;
	}
	void Deriv(ll n,ll *f,ll *g){
		for(ll i=1;i<=n;++i)g[i-1]=f[i]*i%p;
		g[n]=0;
	}
	void ln(ll n,ll *f,ll *g){
		Inv(n,f,h2);
		Deriv(n-1,f,g);
		Mul(n-1,h2,n-2,g,g);
		for(ll i=n-1;i<=n+n-3;++i)g[i]=0;
		Integ(n-2,g,g);
	}
	void exp(ll n,ll *f,ll *g){
		if(n==1){
			g[0]=1;
			g[1]=0;
		}
		else{
			exp((n+1)>>1,f,g);
			ln(n,g,h3);
			for(int i=0;i<n;++i){
				h3[i]=(f[i]-h3[i]+p)%p;
			}
			h3[0]=(h3[0]+1)%p;
			Mul(n-1,h3,(n-1)>>1,g,g);
			for(int i=n;i<n+n;++i)g[i]=0;
		}
	}
	void Pow(ll n,ll *f,ll k,ll *g){
		ln(n,f,h4);
		for(ll i=0;i<n;++i)h4[i]=(h4[i]*k)%p;
		exp(n,h4,g);
	}
}
using namespace Polynomial;
ll f[266667],g[266667],h[266667];
int main(){
#ifdef cnyali_lk
	freopen("polynomial.in","r",stdin);
	freopen("polynomial.out","w",stdout);
#endif
	ll n,m;
	n=read();m=read()+1;
	f[0]=1;
	for(;n;--n){
		f[read()]=p-4;
	}
	Sqrt(m,f,g);
	g[0]=(g[0]+1)%p;
	Inv(m,g,f);
	for(ll i=1;i<m;++i)printf("%lld\n",(f[i]+f[i])%p);
	

	return 0;
}