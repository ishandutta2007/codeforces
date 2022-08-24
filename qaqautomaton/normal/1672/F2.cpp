/*
Author: QAQAutoMaton
Lang: C++
Code: F2.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(qaq...) fprintf(stderr,qaq)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())
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
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
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

namespace run{
	int s[200005];
	int a[200005],b[200005];
	vector<int> to[200005];
	int dfn[200005],low[200005],t,c;
	int stk[200005],tp,col[200005];
	void dfs(int x){
		stk[++tp]=x;
		dfn[x]=low[x]=++t;
		for(auto i:to[x])if(!dfn[i]){
			dfs(i);
			chkmin(low[x],low[i]);
		}
		else if(!col[i])chkmin(low[x],dfn[i]);
		if(dfn[x]==low[x]){
			++c;
			stk[tp+1]=-1;
			while(stk[tp+1]!=x){
				col[stk[tp]]=c;
				--tp;
			}
		}
	}
	bool main(){
		int n;	
		read(n);
		for(int i=1;i<=n;++i)s[i]=0;
		for(int i=1;i<=n;++i){
			read(a[i]);
			++s[a[i]];
			to[i].clear();
		}
		for(int i=1;i<=n;++i)read(b[i]);
		int mxid=0,mx=0;
		for(int i=1;i<=n;++i)if(chkmax(mx,s[i]))mxid=i;
		for(int i=1;i<=n;++i){
			if(a[i]!=mxid && b[i]!=mxid){
				if(a[i]==b[i])return write("WA\n");
				to[a[i]].emplace_back(b[i]);
			}
		}
		for(int i=1;i<=n;++i)dfn[i]=col[i]=0;
		t=0;
		c=0;
		for(int i=1;i<=n;++i)if(!dfn[i]){
			dfs(i);
		}
		return write(c==n?"AC\n":"WA\n");
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F2.in","r",stdin);
	freopen("F2.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t)run::main();
	return 0;
}