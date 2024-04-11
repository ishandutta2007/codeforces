/*
Author: QAQ Automaton
Lang: C++
Prog: E.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
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
		while(!(*x=='\n'||*x==' '||*x=='\r'||*x==EOF))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	// print a signed integer
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
int inf;
struct _init_{
    _init_(){
        memset(&inf,0x3f,sizeof(inf));
    }
};
_init_ ___INIT__;
int a[11][11],n;
int f[11][131];
int is[131],i100;
const int p=1000000007;
int fpm(int a,int b){int c=1;for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;return c;}
struct lll{
	unsigned long long a,b;
	void set(int x){
		if(x<64)a|=1ULL<<x;
		else b|=1ULL<<(x-64);
	}
	void reset(){
		a=b=0;
	}
	lll &operator |=(lll ano){this->a|=ano.a;this->b|=ano.b;return *this;}
	bool operator ==(lll ano){return b==ano.b&&a==ano.a;}
	bool operator [](int ano){return !!(ano<64?a&(1ULL<<ano):b&(1ULL<<(ano-64)));}
};

bool operator <(const lll &a,const lll &b){return a.b<b.b||(a.b==b.b && a.a<b.a);}
bool operator >(const lll &a,const lll &b){return a.b>b.b||(a.b==b.b && a.a>b.a);}
map<lll,int> st[8];
lll mx;
int dfs(int x,lll w){
	if(x==n)return w==mx;
	if(st[x].count(w))return st[x][w];
	int ans=0;
	lll ng;

	lll s[n];
	for(int j=0;j<n;++j)s[j].reset();
	for(int i=0;i<1<<n;++i)if(w[i])for(int j=0;j<n;++j)if(!(i&(1<<j)))
		s[j].set(i|(1<<j));
	for(int i=0;i<1<<n;++i){
		ng=w;
		for(int j=0;j<n;++j)if(i&(1<<j))ng|=s[j];
		ans=(ans+f[x][i]*dfs(x+1,ng))%p;
	}
	return st[x][w]=ans;
}
lll stt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(n);
	for(int i=0;i<1<<n;++i)mx.set(i);
	stt.set(0);
	i100=fpm(100,p-2);
	for(int i=0;i<n;++i)for(int j=0;j<n;++j){
		read(a[i][j]);
		a[i][j]=a[i][j]*i100%p;
	}
	for(int i=0;i<n;++i)is[1<<i]=i;
	for(int i=0;i<n;++i){
		for(int j=0;j<1<<n;++j){
			f[i][j]=1;
			for(int k=0;k<n;++k)if(j&(1<<k))f[i][j]=f[i][j]*a[k][i]%p;
			else f[i][j]=f[i][j]*(p+1-a[k][i])%p;
		}
	}
	write(dfs(0,stt),'\n');
	return 0;
}