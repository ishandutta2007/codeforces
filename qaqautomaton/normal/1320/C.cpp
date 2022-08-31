/*
Author: QAQAutomaton
Lang: C++
Code: C.cpp
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
pii a[200005],b[200005];
pair<int,pii> c[200005];
int w[200005];
struct smt{
	int ad,mx;
	int ls,rs;
	smt *l,*r;
	smt(int la,int ra){
		ad=0;
		ls=la;rs=ra;
		if(ls==rs){l=r=0;mx=-b[ls].y;}
		else{
			int mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
			mx=max(l->mx,r->mx);
		}
	}
	void put_tag(int w){
		ad+=w;mx+=w;
	}
	void push_down(){
		l->put_tag(ad);
		r->put_tag(ad);
		ad=0;
	}
	void add(int la,int ra,int w){
		if(la<=ls && rs<=ra){put_tag(w);return;}
		push_down();
		if(la<=l->rs)l->add(la,ra,w);
		if(r->ls<=ra)r->add(la,ra,w);
		mx=max(l->mx,r->mx);
	}
};
smt *rt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,m,p;
	read(n,m,p);
	for(int i=1;i<=n;++i){
		read(a[i].x,a[i].y);
	}
	for(int i=1;i<=m;++i){
		read(b[i].x,b[i].y);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(int i=1;i<=m;++i)w[i]=b[i].x;
	rt=new smt(1,m);
	for(int i=1;i<=p;++i){
		read(c[i].x,c[i].y.x,c[i].y.y);	
		c[i].y.x=upper_bound(w+1,w+m+1,c[i].y.x)-w;
	}
	sort(c+1,c+p+1);
	int mx=-inf;
	for(int i=1,j=1;i<=n;++i){
		while(j<=p && a[i].x>c[j].x){
			if(c[j].y.x<=m)rt->add(c[j].y.x,m,c[j].y.y);
			++j;
		}
		chkmax(mx,rt->mx-a[i].y);
	}
	write(mx,'\n');
	return 0;
}