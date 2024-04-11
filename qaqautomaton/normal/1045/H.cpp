/*
Author: QAQ-Automaton
LANG: C++
PROG: i.cpp
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
const ll p=1000000007;
char a[100005],b[100005];
ll A,B,C,D;
ll fac[200005],inv[200005],invf[200005];
ll fC(ll a,ll b){return a<0 || b<0 || a<b?0:fac[a]*invf[b]%p*invf[a-b]%p;}
ll f1(ll n,ll a,ll b,ll c,ll d){
	if(a+b+c+d+1!=n)return 0;
	if(c<b || c-b>1)return 0;
	return fC(b+d,b)*(c?fC(c+a-1,c-1):!a)%p;
	//a-00 b-01 c-10 d-11
	//0 -> c 
	//1 -> b+1
	//
}
ll ff(ll n){
	ll ans=0;
	for(ll i=1;i<n;++i)ans+=f1(i,A,B,C,D);
	return ans;
}
ll f(char *s){
	while(*s=='0')++s;
	ll n=strlen(s),ans=ff(n);	
	if(!n)return 0;
	else if(n==1)return !(A || B || C || D);
	ll xA=A,xB=B,xC=C,xD=D;
	for(ll i=1;i<n;++i){
		if(s[i]=='1')ans+=f1(n-i,xD,xC-(s[i-1]=='1'),xB,xA-(s[i-1]=='0'));
		--(s[i-1]=='0'?(s[i]=='0'?xA:xB):(s[i]=='0'?xC:xD));
	}
	if(!(xA||xB||xC||xD))++ans;
	return ans%p;
}
int main(){
#ifdef QAQAutoMaton
	freopen("i.in","r",stdin);
	freopen("i.out","w",stdout);
#endif
	read(a,b,A,B,C,D);	
	fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;
	for(ll i=2;i<=200001;++i){
		fac[i]=fac[i-1]*i%p;
		inv[i]=(p-p/i)*inv[p%i]%p;
		invf[i]=inv[i]*invf[i-1]%p;
	}
	ll n=strlen(a)-1;
	for(ll i=n;~i;--i){a[i]^=1;if(a[i]=='0')break;}
	write((f(b)-f(a)+p)%p,'\n');
	return 0;
}