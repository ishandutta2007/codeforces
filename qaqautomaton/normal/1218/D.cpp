/*
Author: QAQ Automaton
Lang: C++
Prog: D.cpp
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
int f[131072],g[131072],s;
int f2[131072],g2[131072];
vector<pii> to[100005];
const int p=1000000007;
const int p2=19260817;
int fa[100005],fw[100005];
int dfn[100005],t;
const int i2=500000004;
const int i22=9630409;
void FWT(int *a,int n){
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=i+i){
			for(int k=0;k<i;++k){
				int u=a[j+k],v=a[j+k+i];
				a[j+k]=(u+v)%p;
				a[j+k+i]=(u-v+p)%p;
			}
		}
	}
}
void iFWT(int *a,int n){
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=i+i){
			for(int k=0;k<i;++k){
				int u=a[j+k],v=a[j+k+i];
				a[j+k]=(u+v)*i2%p;
				a[j+k+i]=(u-v+p)*i2%p;
			}
		}
	}
}
void FWT2(int *a,int n){
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=i+i){
			for(int k=0;k<i;++k){
				int u=a[j+k],v=a[j+k+i];
				a[j+k]=(u+v)%p2;
				a[j+k+i]=(u-v+p2)%p2;
			}
		}
	}
}
void iFWT2(int *a,int n){
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=i+i){
			for(int k=0;k<i;++k){
				int u=a[j+k],v=a[j+k+i];
				a[j+k]=(u+v)*i22%p2;
				a[j+k+i]=(u-v+p2)*p2%p2;
			}
		}
	}
}

void dfs(int x,int ff){
	fa[x]=ff;
	dfn[x]=++t;
	for(auto i:to[x])if(i.x!=ff){
		if(!dfn[i.x]){
			fw[i.x]=i.y;
			s^=i.y;
			dfs(i.x,x);
		}else if(dfn[i.x]<dfn[x]){
			g[0]=1;
			g2[0]=1;
			int xo=i.y;
			for(int j=x;j!=i.x;j=fa[j]){
				++g[fw[j]^xo];
				++g2[fw[j]^xo];
			}
			FWT(g,1<<17);
			FWT2(g2,1<<17);
			for(int i=0;i<1<<17;++i){
				f[i]=f[i]*g[i]%p;g[i]=0;
				f2[i]=f2[i]*g2[i]%p2;g2[i]=0;
			}
		}
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n,m,u,v,w;
	read(n,m);
	for(;m;--m){
		read(u,v,w);
		to[u].push_back(make_pair(v,w));to[v].push_back(make_pair(u,w));
	}
	s=0;
	for(int i=0;i<1<<17;++i){f[i]=1;f2[i]=1;}
	dfs(1,0);
	g[s]=1;
	FWT(g,1<<17);
	for(int i=0;i<1<<17;++i)f[i]=f[i]*g[i]%p;
	iFWT(f,1<<17);

	g2[s]=1;
	FWT2(g2,1<<17);
	for(int i=0;i<1<<17;++i)f2[i]=f2[i]*g2[i]%p2;
	iFWT2(f2,1<<17);
	for(int i=0;i<1<<17;++i)if(f2[i]||f[i]){
		write(i,' ',f[i],'\n');
		return 0;
	}
	return 0;
}