/*
Author: QAQ-Automaton
LANG: C++
PROG: G.cpp
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
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;} template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;} template<class T>T sqr(T a){return a*a;}
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
	inline bool read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}

	inline bool read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		x=gc();
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	// prll a signed lleger
	inline bool write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}

	inline bool write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) {
		putc(x);
		return 0;
	}
	inline bool write(const char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y){
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
ll n,k,N,in,gp[65537],igp[65537];
typedef vector<ll> poly;
const ll p=998244353;
poly f0,f1,f2,nf0,nf1,nf2,pa,pb;
poly rev;
ll fpm(ll a,ll b){ll c=1;for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;return c;}
void NTT(poly &f,ll flag){
	assert(f.size()==N);
    for(ll i=1;i<N;++i){
        if(i<rev[i])swap(f[i],f[rev[i]]);
    }
    for(ll i=1;i<N;i<<=1){
        ll ww=flag==1?gp[i]:igp[i];
        for(ll j=0;j<N;j+=i+i){
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
        for(ll i=0;i<N;++i)f[i]=f[i]*in%p;
    }
}
void mul(poly &c,poly a,poly b){
	a.resize(N);
	b.resize(N);
	c.resize(N);
	NTT(a,1);
	if(a.begin()!=b.begin())NTT(b,1);
	for(ll i=0;i<N;++i)c[i]=a[i]*b[i]%p;
	NTT(c,-1);
	c.resize(k+1);
/*	
	c.resize(k+1);
	b.resize(k+1);
	for(int i=0;i<=k;++i){
		c[i]=0;
		for(int j=0;j<=i;++j)c[i]=(c[i]+a[j]*b[i-j])%p;
	}*/
}
void calc(ll n){
	if(n==1){
		f0.resize(k+1);
		f1.resize(k+1);
		f2.resize(k+1);
		f0[0]=f1[0]=f0[1]=1;
		return;
	}
	calc(n>>1);
	f0.resize(N);
	f1.resize(N);
	f2.resize(N);
	NTT(f0,1);
	NTT(f1,1);
	NTT(f2,1);
	pa.resize(N);
	pb.resize(N);
	for(int i=0;i<N;++i)pa[i]=f0[i]*f0[i]%p;
	for(int i=0;i<N;++i)pb[i]=f1[i]*f1[i]%p;
	NTT(pa,-1);
	NTT(pb,-1);
	nf0.resize(k+1);
	for(ll i=0;i<=k;++i)nf0[i]=(pa[i]+(i?pb[i-1]:0))%p;

	if(!(n&1)){
		pa=pb;
		for(int i=0;i<N;++i)pb[i]=f2[i]*f2[i]%p;
		NTT(pb,-1);
		nf2.resize(k+1);
		for(ll i=0;i<=k;++i)nf2[i]=(pa[i]+(i?pb[i-1]:0))%p;
	}

	for(int i=0;i<N;++i)pa[i]=f0[i]*f1[i]%p;
	for(int i=0;i<N;++i)pb[i]=f1[i]*f2[i]%p;
	NTT(pa,-1);
	NTT(pb,-1);
	nf1.resize(k+1);
	for(ll i=0;i<=k;++i)nf1[i]=(pa[i]+(i?pb[i-1]:0))%p;

	if(n&1){
		f2=nf1;
		f1=nf0;
		f0.resize(k+1);
		f0[0]=1;
		for(ll i=1;i<=k;++i)f0[i]=(f1[i]+f1[i-1]+f2[i-1])%p;
	}
	else{
		f0=nf0;f1=nf1;f2=nf2;
	}

	/*write(n,'\n');
	  for(auto i:f0)write(i,' ');write('\n');
	  for(auto i:f1)write(i,' ');write('\n');
	  for(auto i:f2)write(i,' ');write('\n');*/
}
int main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	read(n,k);
	for(N=1;N<=2*k;N<<=1);
	rev.resize(N);
	gp[N>>1]=fpm(3,(p-1)/N);
	igp[N>>1]=fpm(332748118,(p-1)/N);
	for(int i=N>>1;i>1;i>>=1){
		gp[i>>1]=gp[i]*gp[i]%p;
		igp[i>>1]=igp[i]*igp[i]%p;
	}
	for(int i=1;i<N;++i)rev[i]=(rev[i>>1]>>1)|((i&1)*(N>>1)); 
	in=fpm(N,p-2);
	calc(n);
	for(int i=1;i<=k;++i)
		write(f0[i],i==k?'\n':' ');
	return 0;
}