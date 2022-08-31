/*
Author: QAQAutoMaton
Lang: C++
Code: E.cpp
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
	int n;
	int l[100005];
	int r[100005];
	vector<pii> ask[100005];
	int w[200005];
	int lm[100005],rm[100005],fa[100005];
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){
		x=find(x);y=find(y);
		if(x!=y){
			fa[y]=x;
			chkmin(lm[x],lm[y]);
			chkmax(rm[x],rm[y]);
		}
	}
	vector<int> *xc;
	int xv;
	struct smt{
		int ls,rs;
		vector<int> vt;
		smt *l,*r;
		smt(){}
		smt(int,int);
		void xfind(int x){
			if(ls<rs){
				if(x<=l->rs)l->xfind(x);
				else r->xfind(x);
			}
			for(auto i:vt){
				if(!xv){xv=i;}
				else merge(xv,i);
			}
			if(!vt.empty()){xc=&vt;vt.clear();}
		}
		void add(int la,int ra,int w){
			if(la<=ls && rs<=ra){vt.emplace_back(w);return;}
			if(la<=l->rs)l->add(la,ra,w);
			if(r->ls<=ra)r->add(la,ra,w);
		}
	};
	smt *rt,node[400005],*at=node;
	smt *newsmt(int la,int ra){
		smt *rt=at;++at;
		*rt=smt(la,ra);
		return rt;
	}
	smt::smt(int la,int ra){
		ls=la;rs=ra;
		vt.clear();
		ls=la;rs=ra;
		if(ls==rs){
			l=r=0;return;
		}
		int mid=(ls+rs)>>1;
		l=newsmt(ls,mid);
		r=newsmt(mid+1,rs);
	}
	void preadds(){
		++n;
		read(l[n],r[n]);
	}
	void preaddq(){
		int x,y;
		read(y,x);
		ask[n].emplace_back(x,y);
	}
	void make(int x,int y){
		xv=0;
		xc=0;
		rt->xfind(x);
		if(xv){merge(xv,y);xc->emplace_back(xv);}
	}
	void add_seg(int x){
		make(l[x],x);
		make(r[x],x);
		if(l[x]+1<r[x])
			rt->add(l[x]+1,r[x]-1,x);
	}
	bool query(int x,int y){
		int xl=lm[find(x)],xr=rm[find(x)];
		return (xl<l[y] && l[y]<xr) || (xl<r[y] && r[y]<xr);
	}
	void do_query(){
		int t=0;
		for(int i=1;i<=n;++i){
			w[++t]=l[i];w[++t]=r[i];
		}
		sort(w+1,w+t+1);
		t=unique(w+1,w+t+1)-w-1;
		for(int i=1;i<=n;++i){
			l[i]=lower_bound(w+1,w+t+1,l[i])-w;
			r[i]=lower_bound(w+1,w+t+1,r[i])-w;
			fa[i]=i;
			lm[i]=l[i];rm[i]=r[i];
		}
		rt=newsmt(1,t);
		for(int i=1;i<=n;++i){
			add_seg(i);
			for(auto w:ask[i])write(query(w.x,w.y)?"YES\n":"NO\n");
		}
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int q;	
	read(q);
	for(;q;--q){
		int tp;
		read(tp);
		if(tp==1){
			run::preadds();
		}
		else{
			run::preaddq();
			//write(run::query()?"YES\n":"NO\n");
		}
	}
	run::do_query();
	return 0;
}