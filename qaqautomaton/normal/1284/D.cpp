/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp 
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
		while(!(*x=='\n'||*x=='\r'))*(++x)=gc();
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
int la[100005],lb[100005],ra[100005],rb[100005];
int as[200005],bs[200005];
struct node{
	int al,ar,bl,br;
	bool operator <(node b){return ar<b.ar;}
};
node nd[100005];
int n;
struct smt{
	int rt,lt,rmn,lmn;
	int ls,rs;
	smt *l,*r;
	smt(int la,int ra){
		rmn=lmn=lt=rt=inf;	
		ls=la;rs=ra;
		if(ls==rs){l=r=0;return;}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
	}
	void reset(){
		lmn=rmn=lt=rt=inf;
		if(ls==rs)return;
		l->reset();
		r->reset();
	}
	int qr(int la,int ra){
		if(la<=ls && rs<=ra)return rmn;
		int xm=inf;
		if(la<=l->rs)chkmin(xm,l->qr(la,ra));
		if(ra>=r->ls)chkmin(xm,r->qr(la,ra));
		return xm;
	}
	int ql(int la,int ra){
		if(la<=ls && rs<=ra)return lmn;
		int xm=inf;
		if(la<=l->rs)chkmin(xm,l->ql(la,ra));
		if(ra>=r->ls)chkmin(xm,r->ql(la,ra));
		return xm;
	}
	void wkr(int x,int y){
		chkmin(rmn,y);
		if(ls==rs)return;
		if(x<=l->rs)l->wkr(x,y);
		else r->wkr(x,y);
	}
	void wkl(int x,int y){
		chkmin(lmn,y);
		if(ls==rs)return;
		if(x<=l->rs)l->wkl(x,y);
		else r->wkl(x,y);
	}
};
smt *rt;
void work(int n2){
	sort(nd+1,nd+n+1);
	rt->reset();
	for(int i=n;i;--i){
		if(nd[i].bl>1 && rt->qr(1,nd[i].bl-1)<=nd[i].ar)exit(write("NO\n"));
		if(nd[i].br<n2 && rt->ql(nd[i].br+1,n2)<=nd[i].ar)exit(write("NO\n"));
		rt->wkr(nd[i].br,nd[i].al);
		rt->wkl(nd[i].bl,nd[i].al);
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	read(n);
	for(int i=1;i<=n;++i){
		read(la[i],ra[i],lb[i],rb[i]);
		as[i*2-1]=la[i];as[i*2]=ra[i];
		bs[i*2-1]=lb[i];bs[i*2]=rb[i];
	}
	sort(as+1,as+n+n+1);
	sort(bs+1,bs+n+n+1);
	rt=new smt(1,n+n);
	int ma=unique(as+n+1,as+n+n+1)-as-1;
	int mb=unique(bs+n+1,bs+n+n+1)-bs-1;
	for(int i=1;i<=n;++i){
		la[i]=lower_bound(as+1,as+ma+1,la[i])-as;
		lb[i]=lower_bound(bs+1,bs+mb+1,lb[i])-bs;
		ra[i]=lower_bound(as+1,as+ma+1,ra[i])-as;
		rb[i]=lower_bound(bs+1,bs+mb+1,rb[i])-bs;
	}
	for(int i=1;i<=n;++i){
		nd[i].al=la[i];		
		nd[i].bl=lb[i];		
		nd[i].ar=ra[i];		
		nd[i].br=rb[i];		
	}
	work(mb);
	for(int i=1;i<=n;++i){
		nd[i].al=lb[i];		
		nd[i].bl=la[i];		
		nd[i].ar=rb[i];		
		nd[i].br=ra[i];		
	}
	work(ma);
	write("YES\n");
	return 0;
}