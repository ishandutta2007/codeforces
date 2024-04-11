/*
Author: QAQAutoMaton
Lang: C++
Code: A.cpp
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
int query(int);
int a[100005];
namespace grader{
	int a[100005];
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()/100);
	bool main(){
		int n;read(n);
		for(int i=1;i<=n;++i)a[i]=i;//read(a[i]);//a[i]=i;
		//shuffle(a+1,a+n+1,rnd);
		//for(int i=1;i<=n;++i)a[i]=i;
		a[0]=a[n+1]=inf;
		do{
			for(int i=1;i<=n;++i)::a[i]=0;
			int x=query(n);
			assert(a[x]<a[x-1] && a[x]<a[x+1]);
		}while(next_permutation(a+1,a+n+1));
		write("ok\n");
		return 0;
	}	
}
int ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	return y;
	return grader::a[x];
}
int xask(int x){if(a[x])return a[x];return a[x]=ask(x);}
int query(int n){
	if(n==1){return 1;}
	if(xask(1)<xask(2))return 1;
	if(xask(n-1)>xask(n))return n;
	int l=1,r=n;
	while(l+2<r){
		int mid=(l+r)>>1;
		if(xask(mid)>xask(1)){
			r=mid;
		}
		else if(xask(mid-1)<xask(mid))r=mid;
		else if(xask(mid+1)<xask(mid))l=mid;
		else return mid;
	}
	return l+1;
	while(l+2<r){
		debug("%d %d\n",l,r);
		int mid=(l+r)>>1;
		if(xask(1)<xask(mid))r=mid;
		else if(xask(n)<xask(mid))l=mid;
		else if(xask(mid)>xask(mid-1))r=mid;
		else if(xask(mid)>xask(mid+1))l=mid;
		else return mid;
	}
	return l+1;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	//return grader::main();
	
	int n;
	scanf("%d",&n);
	printf("! %d\n",query(n));
	/*read(n);
	write(query(n),'\n');*/
	return 0;
}