/*
Author: QAQAutomaton
Lang: C++
Code: C2.cpp
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
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cp;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T,class T2>int chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int chkmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char *)(&inf),(unsigned char *)(&inf)+sizeof(inf),0x3f);
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
	template<typename A>
	inline bool read (A &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		while((x=gc())==' '||x=='\n' || x=='\r');
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'||*x==EOF))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	template<typename A>
	inline bool write (A x) {
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
struct matrix{
	int a[2][2];
	int *operator [](int b){return a[b];}
	const int *operator [](int b)const {return a[b];}
	matrix(){}
	matrix(int x){a[0][1]=x;a[1][0]=-x;a[0][0]=a[1][1]=0;}
};
matrix o;
matrix operator +(const matrix &a,const matrix &b){
	matrix c;
	c[0][0]=max(a[0][0]+b[0][0],a[0][1]+b[1][0]);
	c[0][1]=max(a[0][0]+b[0][1],a[0][1]+b[1][1]);
	c[1][0]=max(a[1][0]+b[0][0],a[1][1]+b[1][0]);
	c[1][1]=max(a[1][0]+b[0][1],a[1][1]+b[1][1]);
	return c;
}
int a[300005];
namespace zkw{
	matrix mx[1<<20|5];
	int N;
	void init(int n){
		N=1;
		while(N<=n)N<<=1;
		for(int i=0;i<N;++i)mx[i+N]=o;
		for(int i=1;i<=n;++i)mx[i+N]=a[i];
		for(int i=N-1;i;--i)mx[i]=mx[i<<1]+mx[i<<1|1];
	}
	void update(int x,int y){
		x+=N;
		mx[x]=y;
		for(;x>>=1;)mx[x]=mx[x<<1]+mx[x<<1|1];
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C2.in","r",stdin);
	freopen("C2.out","w",stdout);
#endif
	int t,n,q;
	o[0][1]=o[1][0]=-inf;
	read(t);
	for(;t;--t){
		read(n,q);
		for(int i=1;i<=n;++i){
			read(a[i]);
		}
		zkw::init(n);
		write(max(zkw::mx[1][0][0],zkw::mx[1][0][1]),'\n');
		for(;q;--q){
			int x,y;
			read(x,y);
			swap(a[x],a[y]);
			zkw::update(x,a[x]);
			zkw::update(y,a[y]);
			write(max(zkw::mx[1][0][0],zkw::mx[1][0][1]),'\n');
		}
	}
	return 0;
}