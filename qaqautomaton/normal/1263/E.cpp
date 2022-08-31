/*
Author: QAQAutomaton
LANG: C++
PROG: E.cpp
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
int is[1000005];
char s[1000005];
struct smt{
	int ls,rs;
	int mx,mn;
	int tag;
	smt *l,*r;
	smt(int la,int ra){
		ls=la;rs=ra;
		mx=mn=0;tag=0;
		if(ls==rs){l=r=0;return;}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
	}
	void put_tag(int x){
		tag+=x;mx+=x;mn+=x;
	}
	void push_down(){
		l->put_tag(tag);r->put_tag(tag);
		tag=0;
	}
	void add(int la,int ra,int w){
		if(la<=ls && rs<=ra){put_tag(w);return;}
		push_down();
		if(la<=l->rs)l->add(la,ra,w);
		if(r->ls<=ra)r->add(la,ra,w);
		mx=max(l->mx,r->mx);
		mn=min(l->mn,r->mn);
	}
	int getv(int x){
		if(ls==rs)return mx;
		push_down();
		return x<=l->rs?l->getv(x):r->getv(x);
	}
};
smt *rt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,at=1;
	read(n);
	read(s+1);
	rt=new smt(1,n);
	for(int i=1;i<=n;++i){
		if(s[i]=='L'){if(at>1)--at;}	
		else if(s[i]=='R')++at;
		else{
			int o=is[at];
			if(s[i]=='(')is[at]=1;
			else if(s[i]==')')is[at]=-1;
			else is[at]=0;
			rt->add(at,n,is[at]-o);
		}
		if(rt->getv(n)||rt->mn<0)write(-1,i==n?'\n':' ');
		else write(rt->mx,i==n?'\n':' ');
		
	}
	return 0;
}