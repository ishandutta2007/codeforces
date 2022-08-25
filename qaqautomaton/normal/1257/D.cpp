/*
Author: QAQAutomaton
LANG: C++
PROG: D.cpp
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
int w[200005];
pii a[200005],b[200005];
int lf[200005],rg[200005];
struct smt{
	int mxg,mxad;
	smt *l,*r;
	int ls,rs;
	smt(int la,int ra){
		mxg=mxad=0;
		ls=la;rs=ra;
		if(ls==rs){l=r=0;return;}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
	}
	~smt(){
		if(l)delete l;
		if(r)delete r;
	}
	int get(int x){
		if(ls==rs)return max(mxg,x+mxad);
		return max(max(mxg,x+mxad),(x<=l->rs?l->get(x):r->get(x)));
	}
	void setg(int la,int ra,int w){
		if(la<=ls && rs<=ra){chkmax(mxg,w);return;}
		if(la<=l->rs)l->setg(la,ra,w);
		if(r->ls<=ra)r->setg(la,ra,w);
	}

	void seta(int la,int ra,int w){
		if(la<=ls && rs<=ra){chkmax(mxad,w);return;}
		if(la<=l->rs)l->seta(la,ra,w);
		if(r->ls<=ra)r->seta(la,ra,w);
	}
};
smt *rt;
int vis[200005];
int getl(int x){return x==lf[x]?x:lf[x]=getl(lf[x]);}
int getr(int x){return x==rg[x]?x:rg[x]=getr(rg[x]);}
void work(int id,int w){
	vis[id]=1;
	if(vis[id-1]){
		lf[id]=id-1;
		rg[id-1]=id;
	}
	if(vis[id+1]){
		lf[id+1]=id;
		rg[id]=id+1;
	}
	int le=getl(id),ri=getr(id)+1;
	int par=max(ri-w+1,le);
	rt->setg(par,ri,ri);
	if(le<par)rt->seta(le,par-1,w);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int t,n,m;
	read(t);
	for(;t;--t){
		read(n);
		for(int i=1;i<=n;++i){
			read(w[i]);
			a[i]=make_pair(w[i],i);
		}
		rt=new smt(1,n+1);
		read(m);
		for(int i=1;i<=m;++i)read(b[i].x,b[i].y);
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		for(int i=m-1;i;--i)chkmax(b[i].y,b[i+1].y);
		for(int i=1;i<=n+1;++i)lf[i]=i,rg[i]=i;	
		for(int i=1;i<=n;++i)vis[i]=0;
		vis[0]=0;
		vis[n+1]=0;
		
		for(int i=1,j=0;i<=m;++i){
			while(j<n&&a[j+1].x<=b[i].x){
				++j;
				work(a[j].y,b[i].y);
			}
		}
		int at=1,nx,cnt=0;
		while(at<=n){
			nx=rt->get(at);
			if(at==nx){cnt=-1;break;}
			++cnt;
			at=nx;
		}
		delete rt;
		write(cnt,'\n');
	}
	return 0;
}