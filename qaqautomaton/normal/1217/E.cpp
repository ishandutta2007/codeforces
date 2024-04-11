/*
Author: QAQ Automaton
Lang: C++
Prog: E.cpp
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
int n,m;
pii operator +(pii a,pii b){
	if(a.x<b.x){return make_pair(a.x,min(a.y,b.x));}
	return make_pair(b.x,min(a.x,b.y));
}
struct pairs{
	pii a[9];
	pii &operator[](int b){return a[b];}
	pairs operator +(pairs b){
		pairs c;
		for(int i=0;i<9;++i)c[i]=a[i]+b[i];
		return c;
	}
};
int a[200005];
struct smt{
	pairs sum;
	int ls,rs;
	smt *l,*r;
	smt(int la,int ra){
		ls=la;rs=ra;
		if(ls==rs){
			l=r=0;
			for(int i=0,j=1;i<9;++i,j=j*10){
				if(a[ls]/j%10)sum[i]=make_pair(a[ls],inf);
				else sum[i]=make_pair(inf,inf);
			}
		}
		else{
			int mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
			sum=l->sum+r->sum;
		}
	}
	void update(int x){
		if(ls==rs){
			for(int i=0,j=1;i<9;++i,j=j*10){
				if(a[ls]/j%10)sum[i]=make_pair(a[ls],inf);
				else sum[i]=make_pair(inf,inf);
			}
			return;
		}
		if(x<=l->rs)l->update(x);
		else r->update(x);
		sum=l->sum+r->sum;
	}
	pairs query(int la,int ra){
		if(la<=ls && rs<=ra)return sum;
		pairs xs;
		for(int i=0;i<9;++i)xs[i]=make_pair(inf,inf);
		if(la<=l->rs)xs=xs+l->query(la,ra);
		if(r->ls<=ra)xs=xs+r->query(la,ra);
		return xs;
	}
};
smt *rt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i)read(a[i]);
	rt=new smt(1,n);
	int tp,x,y;
	for(;m;--m){
		read(tp,x,y);
		if(tp==1){
			a[x]=y;
			rt->update(x);
		}
		else{
			pairs sum=rt->query(x,y);
			int ans=inf+inf;
			for(int i=0;i<9;++i)if(sum[i].y<inf)chkmin(ans,sum[i].x+sum[i].y);
			write(ans==inf*2?-1:ans,'\n');

		}
	}
	return 0;
}