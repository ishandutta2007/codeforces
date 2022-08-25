/*
Author: CNYALI_LK
LANG: C++
PROG: A.cpp
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
typedef long long ll;
typedef pair<ll,ll> pii;
const signed inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>ll dcmp(T a,T b){return a>b;}
template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
	const ll SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; ll f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// prll the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed lleger
	inline void read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}

	inline void read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	inline void read (char &x) {
		x=gc();
	}
	inline void read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
	}
	template<typename A,typename ...B>
	inline void read(A &x,B &...y){
		read(x);read(y...);
	}
	// prll a signed lleger
	inline void write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}

	inline void write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	inline void write (char x) {
		putc(x);
	}
	inline void write(const char *x){
		while(*x){putc(*x);++x;}
	}
	inline void write(char *x){
		while(*x){putc(*x);++x;}
	}
	template<typename A,typename ...B>
	inline void write(A x,B ...y){
		write(x);write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
const ll p=1000000007;
ll fpm(ll a,ll b){
	ll c=1;for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;return c;
}

struct xll{
	ll a,b;//a+b sqrt(5)
	xll(){a=b=0;}
	xll(ll x){a=x;b=0;}
	xll(ll x,ll y){a=x;b=y;}
	xll operator +(xll other){return xll((a+other.a)%p,(b+other.b)%p);}
	xll operator -(xll other){return xll((a-other.a+p)%p,(b-other.b+p)%p);}
	xll operator *(xll other){return xll((a*other.a+5*b*other.b)%p,(a*other.b+b*other.a)%p);}
	xll operator /(xll other){
		ll inv=fpm((5*other.b*other.b%p+p-other.a*other.a%p)%p,p-2);
//		printf("Calc %lld,%lld / %lld,%lld = %lld,%lld\n",a,b,other.a,other.b,(5*b*other.b%p+p-a*other.a%p)*inv%p,(a*other.b%p+p-b*other.a%p)*inv%p);
		return xll((5*b*other.b%p+p-a*other.a%p)*inv%p,(a*other.b%p+p-b*other.a%p)*inv%p);
	}
};
//#define xll double
xll fpm(xll a,ll b){
	xll c=1;
	for(;b;b>>=1,a=a*a)if(b&1)c=c*a;
	return c;
}
xll a,b;
ll f[205],c[205][205];
int main(){
#ifdef cnyali_lk
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	ll k,l,r;
	read(k,l,r);
	l+=2;r+=3;
	f[0]=1;
	for(ll i=0;i<k;++i){
		for(ll j=i;~j;--j){
			f[j+1]=(f[j+1]+f[j])%p;
			f[j]=f[j]*(p-i)%p;
		}
	}
	ll half=(p+1)>>1;
	/*a=(1+sqrt(5))/2;
	  b=(1-sqrt(5))/2;*/
	a=xll(half,half);
	b=xll(half,p-half);
	/*	xll a1=1,b1=1;
		for(int i=1;i<=10;++i){
		a1=a1*a;
		b1=b1*b;
		printf("%lld %lld\n",((a1-b1)/(a-b)).a,((a1-b1)/(a-b)).b);
		}*/
	xll s=1,ans=0,x,sum;
	c[0][0]=1;
	for(ll i=1;i<=k;++i){
		s=s*(a-b);
		c[i][0]=c[i][i]=1;
		for(ll j=1;j<i;++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
		x=1;
		for(ll j=1;j<=i;++j)x=x*a;
		sum=0;
		for(ll j=0;j<=i;++j){
			ll af=c[i][j];
			if(j&1)af=p-af;
			//			printf("===%lld,%lld\n",(((fpm(x,r)-fpm(x,l))/(x-xll(1))*xll(af))).a,(((fpm(x,r)-fpm(x,l))/(x-xll(1))*xll(af))).b);
			if(x.a==1 && x.b==0){
				sum=(sum+xll((r-l)%p)*xll(af));
			}
			else sum=sum+((fpm(x,r)-fpm(x,l))/(x-xll(1))*xll(af));
			x=x/a*b;	
		}
		ans=ans+sum*xll(f[i])/s;
	}
	ll Ans=ans.a,w=1;
	for(ll i=1;i<=k;++i){w=w*i%p;}
	Ans=Ans*fpm(w,p-2)%p;
	printf("%lld\n",Ans);
	return 0;
}