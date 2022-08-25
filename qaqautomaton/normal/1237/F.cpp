/*
Author: QAQAutomaton
LANG: C++
PROG: F.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int inf;
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
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
	}
}__INIT___;
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
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
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
#define x1 wxwakioi
#define x2 cfakioi
#define y1 cyakioi
#define y2 sysakioi
int h[3605],l[3605];
int c[3605][3605];
int C[3605][3605];
int a[3605][3605];
int b[3605][3605];
int fac[3605];
const int p=998244353;
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,m,k,x1,x2,y1,y2;
	read(n,m,k);
	for(int i=1;i<=k;++i){
		read(x1,y1,x2,y2);
		if(h[x1])return write("0\n");
		if(h[x2])return write("0\n");
		if(l[y1])return write("0\n");
		if(l[y2])return write("0\n");
		h[x1]=h[x2]=1;
		l[y1]=l[y2]=1;
	}
	fac[0]=1;
	for(int i=1;i<=3600;++i)fac[i]=(ll)fac[i-1]*i%p;
	for(int i=0;i<=3600;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	}
	c[0][0]=1;
	int ch=0;
	for(int i=1;i<=n;++i){
		ch+=!h[i];
		c[i][0]=1;
		for(int j=1;j<=n;++j){
			c[i][j]=c[i-1][j];
			if(i>1 && !h[i] && !h[i-1])c[i][j]=(c[i][j]+c[i-2][j-1])%p;
		}
	}
	for(int i=0;i<=n && i+i<=ch;++i)for(int j=0;j<=n;++j)a[i][j]=(ll)c[n][i]*C[ch-i*2][j]%p;
	int cl=0;
	for(int i=1;i<=m;++i){
		cl+=!l[i];
		c[i][0]=1;
		for(int j=1;j<=m;++j){
			c[i][j]=c[i-1][j];
			if(i>1 && !l[i] && !l[i-1])c[i][j]=(c[i][j]+c[i-2][j-1])%p;
		}
	}
	for(int i=0;i<=m && i+i<=cl;++i)for(int j=0;j<=m;++j)b[i][j]=(ll)c[m][i]*C[cl-i*2][j]%p;
	int ans=0;
	for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)ans=(ans+(ll)a[i][j]*b[j][i]%p*fac[i]%p*fac[j]%p)%p;
	write(ans,'\n');

	return 0;
}