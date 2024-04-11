/*
Author: QAQAutomaton
Lang: C++
Code: G.cpp
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
int p[27];
char s[200005],t[200005];
ll f1[200005];
cp w1[1<<19|5],w2[1<<19|5],w3[1<<19|5],w4[1<<19|5],w5[1<<19|5],w6[1<<19|5],w7[1<<19|5];
cp w[1<<20|5];
int rev[1<<19|5];
void dft(cp *a,int N){
	for(int i=1;i<N;++i){
		rev[i]=rev[i>>1]>>1|((i&1)*(N>>1));
		if(i<rev[i])swap(a[i],a[rev[i]]);
	}
	for(int i=1;i<N;i<<=1){
		for(int j=0;j<N;j+=i+i){
			for(int k=0;k<i;++k){
				cp u=a[j+k],v=a[j+k+i]*w[i+k];
				a[j+k]=u+v;a[i+j+k]=u-v;
			}
		}
	}
}
void idft(cp *a,int N){
	reverse(a+1,a+N);
	dft(a,N);
	for(int i=0;i<N;++i)a[i]/=N;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	for(int i=1;i<=26;++i){
		int x;
		read(x);
		p[x]=i;
//		read(p[i]);	
	}
	read(t);
	read(s+1);
	int n=strlen(s+1),m=strlen(t);
	for(int i=1;i<=n;++i){
		int a=s[i]-'a'+1,pa=p[a];
		f1[i]=a*a*pa*pa+f1[i-1];
		w2[i]=-2*(a*a*pa+a*pa*pa);
		w3[i]=a*a+pa*pa+4*a*pa;
		w4[i]=-2*(a+pa);
	}
	ll cnt=0;
	for(int i=0;i<m;++i){
		int b=t[i]-'a'+1;
		w5[m-i]=b;
		w6[m-i]=b*b;
		w7[m-i]=b*b*b;
		cnt+=b*b*b*b;
	}
	int N=1;
	while(N<=n+1)N<<=1;
	for(int i=1;i<N;i<<=1)for(int j=0;j<i;++j)w[i+j]=cp(cos(j*pi/i),sin(j*pi/i));
	dft(w2,N);
	dft(w3,N);
	dft(w4,N);
	dft(w5,N);
	dft(w6,N);
	dft(w7,N);
	for(int i=0;i<N;++i){
		w1[i]=w2[i]*w5[i]+w3[i]*w6[i]+w4[i]*w7[i];
	}
	idft(w1,N);
	for(int i=1;i+m-1<=n;++i){
		double w=cnt+w1[i+m].real()+f1[i+m-1]-f1[i-1];
		if(fabs(w)>0.5)putc('0');
		else putc('1');
	}
	putc('\n');
	return 0;
}
//a2pa2