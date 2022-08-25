/*
Author: CNYALI_LK
LANG: C++
PROG: B.cpp
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
ll c0,c1,n;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lls[31]; 
ll C(ll a,ll b){
	ll s=1,x,g;
	for(ll i=1;i<=b;++i)lls[i]=i;
	for(ll i=0;i<b;++i){
		x=a+b-i;
		for(ll j=1;j<=b;++j){
			g=gcd(lls[j],x);	
			x/=g;
			lls[j]/=g;
		}
		if(x>inf/s)return inf;
		s*=x;
	}
	return s;
}
#define chk if(tmp>n)return 1
ll check(ll x){
	ll tmp=x/c0+x/c1+1;
	chk;
	for(ll i=1;i<=26;++i){
		for(ll j=i;j*c0+i*c1<=x;++j){
			tmp+=C(j,i);
			chk;
		}
		for(ll j=i+1;j*c1+i*c0<=x;++j){
			tmp+=C(j,i);
			chk;
		}
	}
	return 0;
}
void Work(ll x,ll &tmp,ll &ans){
	tmp=x/c0+x/c1+1;
	ans=((x/c0)*(x/c0+1)*c0+(x/c1)*(x/c1+1)*c1)>>1;
	ll c;
	for(ll i=1;i<=26;++i){
		for(ll j=i;j*c0+i*c1<=x;++j){
			c=C(j,i);
			tmp+=c;
			ans+=c*(j*c0+i*c1);
		}
		for(ll j=i+1;j*c1+i*c0<=x;++j){
			c=C(j,i);
			tmp+=c;
			ans+=c*(j*c1+i*c0);
		}
	}
}

int main(){
#ifdef cnyali_lk
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	read(n,c0,c1);
	--n;
	if(c0>c1)swap(c0,c1);
	if(!c0)printf("%lld\n",n*c1);
	else{
		ll l=0,r=c1*26,mid;
		while(l<=r){
			mid=(l+r)>>1;	
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		ll c,s;
		Work(l-1,c,s);
		s+=(n-c)*l+n*(c0+c1);
		printf("%lld\n",s);
	}
	return 0;
}