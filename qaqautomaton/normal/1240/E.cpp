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
int s[1000005],a[1000005];
int n,x,m,w[500005];
bool chk(int x,int y,int a,int b){
	if(b<2)return 0;	
	if(a<y)return 0;
	a-=y;
	if(a<(y/x)*2)return 0;
	a-=((y-1)/x)*2;
	if(a>=2)return 1;
	int mo=y%x;
	for(int i=(y/x)*x;i<=n;i+=x){
		a+=s[i+x-1]-s[i+mo-1];
		if(a>=2)return 1;
	}
	return 0;
}
bool chk2(int x,int y,int a,int b){
	if(!b)return 0;
	if(a<y)return 0;
	if(w[m]<y*2)return 0;
	a-=y;
	if(a<(y*2/x))return 0;
	a-=(y*2-1)/x;
	if(a>=1)return 1;
	int mo=(y*2)%x;
	for(int i=(y<<1)/x*x;i<=n;i+=x){
		if(s[i+x-1]-s[i+mo-1])return 1;
	}
	return 0;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(m);
	for(int i=1;i<=m;++i){
		read(w[i]);
		++a[w[i]];
	}
	sort(w+1,w+m+1);
	n=500000;
	for(int i=1;i<=n+n;++i)s[i]=s[i-1]+a[i];
	x=a[n];
	int ans=0;
	for(int i=2,k=n;i<=n;++i){
		int j=i,w=0;
		while(j<=n){
			w+=(s[n]-s[j-1]);
			j+=i;
		}
		while(k>1 && !chk(i,k,w,x) &&!chk2(i,k,w,x)){
			--k;
			x+=a[k];
		}
		if(k>1)chkmax(ans,i*k);
	}
	write(ans,'\n');
	return 0;
}