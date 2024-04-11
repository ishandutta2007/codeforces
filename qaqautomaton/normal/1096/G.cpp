/*
Author: QAQ-Automaton
LANG: C++
PROG: g.cpp
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
template<class T>ll dcmp(T a,T b){return a>b;} template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];} 
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
		*x=0;
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
vector<ll> a,c;
const ll p=998244353,g=3,ig=332748118;
ll rev[2148579];
ll fpm(ll a,ll b){
	ll c=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
void NTT(vector<ll> &a,ll n,ll flg){
	for(ll i=1;i<n;++i){
		rev[i]=(rev[i>>1]>>1) | ((i&1) *(n>>1));
		if(i<rev[i])swap(a[i],a[rev[i]]);
	}
	for(ll i=1;i<n;i<<=1){
		ll ww=fpm(flg==1?g:ig,(p-1)/i/2),w,u,v;
		for(ll j=0;j<n;j+=i+i){
			w=1;
			for(ll k=0;k<i;++k){
				u=a[j+k];v=a[j+k+i]*w%p;
				a[j+k]=(u+v)%p;
				a[j+k+i]=(u+p-v)%p;
				w=w*ww%p;
			}
		}
	}
	if(flg==-1){
		ll in=fpm(n,p-2);
		for(ll i=0;i<n;++i)a[i]=a[i]*in%p;
	}
}

void Square(){
	ll n=a.size(),N=1;
	for(;N<n+n;N<<=1);
	a.resize(N);	
	NTT(a,N,1);
	for(ll i=0;i<N;++i)a[i]=a[i]*a[i]%p;
	NTT(a,N,-1);
	a.resize(n*2-1);
}
void Times(){
	ll n=a.size()-1,m=c.size()-1,N=1;	
	for(;N<=n+m;N<<=1);
	a.resize(N);
	c.resize(N);
	NTT(a,N,1);
	NTT(c,N,1);
	for(ll i=0;i<N;++i)c[i]=c[i]*a[i]%p;
	NTT(c,N,-1);
	NTT(a,N,-1);
	a.resize(n+1);
	c.resize(n+m+1);
}
void fpm(ll b){
	c.resize(1);
	c[0]=1;
	for(;b;b>>=1){
		if(b&1)Times();
		if(b!=1)Square();
	}
}
int main(){
#ifdef QAQAutoMaton 
	freopen("g.in","r",stdin);
	freopen("g.out","w",stdout);
#endif
	ll n,k,x;
	read(n,k);
	a.resize(10);
	for(ll i=1;i<=k;++i){
		read(x);
		a[x]=1;
	}
	fpm(n>>1);
	ll cnt=0;
	for(auto i:c){
		cnt=(cnt+i*i)%p;
	}
	write(cnt,'\n');

	return 0;
}