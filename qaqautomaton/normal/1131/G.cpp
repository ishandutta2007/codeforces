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
#define inf 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
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
ll n,m,k[250005];
vector<pii> blk[250005];
pii a[10000005],wstk[10000005],*wtop;
ll ls[10000005],rs[10000005],f[10000005],stk[10000005],*top;
void init(){
	ll x,y;
	read(n,m);
	for(ll i=1;i<=n;++i){
		read(k[i]);
		for(ll j=0;j<k[i];++j){
			read(x);
			blk[i].push_back(make_pair(x,0));
		}
		for(ll j=0;j<k[i];++j){
			read(blk[i][j].y);
		}
	}	
	read(n);
	m=0;
	for(ll w=1;w<=n;++w){
		read(x,y);
		for(auto i:blk[x]){
			a[++m]=i;
			a[m].y*=y;
		}
	}
	n=m;
}
ll solve(){
	top=stk;
	for(ll i=1;i<=n;++i){
		while(top!=stk && *top>i-a[i].x)--top;
		ls[i]=*top;
		*(++top)=i;
	}
	top=stk;
	for(ll i=n;i;--i){
		while(top!=stk && *top<i+a[i].x)--top;
		rs[i]=*top;
		*(++top)=i;
	}
	wtop=wstk;
	for(ll i=1;i<=n;++i){
		f[i]=f[ls[i]]+a[i].y;
		while(wtop!=wstk && wtop->y==i)--wtop;
		if(wtop!=wstk)chkmin(f[i],wtop->x);
		ll w=f[i-1]+a[i].y;
		while(wtop->y==rs[i] && wtop->x>w)--wtop;
		if(wtop==wstk || wtop->x>w)*(++wtop)=make_pair(w,rs[i]);
	}
//	for(ll i=1;i<=n;++i)write(a[i].x,' ',a[i].y,' ',ls[i],' ',rs[i],' ',f[i],'\n');
	return f[n];
}
int main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	init();
	write(solve(),'\n');
	return 0;
}