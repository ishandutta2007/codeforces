/*
Author: QAQ Automaton
Lang: C++
Prog: F.cpp
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
int a[200005];
int tp[100005],l[100005],r[100005];
struct smt{
	int ls,rs;
	int sum0,sum1,stag,rtag;
	smt *l,*r;
	smt(int la,int ra){
		ls=la;rs=ra;
		sum0=rs-ls+1;
		sum1=0;
		stag=-1;
		rtag=0;
		if(ls==rs){l=r=0;return;}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
	}
	void put_stag(int x){
		stag=x;
		if(x==1){sum1=rs-ls+1;sum0=0;}
		else {sum0=rs-ls+1;sum1=0;}
	}
	void put_rtag(){
		if(~stag)stag^=1;
		rtag^=1;
		swap(sum0,sum1);
	}
	void push_down(){
		if(rtag){l->put_rtag();r->put_rtag();rtag=0;}
		if(~stag){
			l->put_stag(stag);
			r->put_stag(stag);
			stag=-1;
		}
	}
	void push_up(){
		sum0=l->sum0+r->sum0;
		sum1=l->sum1+r->sum1;
	}
	void set(int la,int ra,int w){
		if(la<=ls && rs<=ra){put_stag(w);return;}
		push_down();
		if(la<=l->rs)l->set(la,ra,w);
		if(r->ls<=ra)r->set(la,ra,w);
		push_up();
	}
	void rev(int la,int ra){
		if(la<=ls && rs<=ra){put_rtag();return;}
		push_down();
		if(la<=l->rs)l->rev(la,ra);
		if(r->ls<=ra)r->rev(la,ra);
		push_up();
	}
	int query(){
		if(ls==rs)return ls;
		push_down();
		if(l->sum0)return l->query();
		return r->query();
	}
};
smt *rt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,t=1;
	a[1]=1;
	read(n);
	for(int i=1;i<=n;++i){
		read(tp[i],l[i],r[i]);
		++r[i];
		a[++t]=l[i];
		a[++t]=r[i];
	}
	sort(a+1,a+t+1);
	t=unique(a+1,a+t+1)-a-1;
	rt=new smt(1,t);
	for(int i=1;i<=n;++i){
		l[i]=lower_bound(a+1,a+t+1,l[i])-a;	
		r[i]=lower_bound(a+1,a+t+1,r[i])-a-1;	
		if(tp[i]==1)rt->set(l[i],r[i],1);
		else if(tp[i]==2)rt->set(l[i],r[i],0);
		else rt->rev(l[i],r[i]);
		write(a[rt->query()],'\n');
	}
	return 0;
}