/*
Author: QAQAutomaton
Lang: C++
Code: H.cpp
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
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char *)(&inf),(unsigned char *)(&inf)+sizeof(inf),0x3f);
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
int xx[500005],xy[500005],sat[500005],xt[500005];
int fa[500005],siz[500005];
int find(int x){return x==fa[x]?x:find(fa[x]);}
pii stk[500005];
int v[500005],las[500005];
int tp;
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return;
	if(siz[x]>siz[y])swap(x,y);
	fa[x]=y;
	siz[y]+=siz[x];
	stk[++tp]={x,y};
}
struct smt{
	smt *l,*r;
	vector<int> vt;
	int ls,rs;
	void add(int la,int ra,int x){
		if(la<=ls && rs<=ra){vt.emplace_back(x);return;}
		if(la<=l->rs)l->add(la,ra,x);
		if(r->ls<=ra)r->add(la,ra,x);
	}
	void solve(){
		int ltp=tp;	
		for(auto i:vt)merge(xx[i],xy[i]);
		if(ls==rs){write(siz[find(v[ls])],'\n');}
		else{l->solve();r->solve();}
		while(tp>ltp){
			siz[stk[tp].y]-=siz[stk[tp].x];
			fa[stk[tp].x]=stk[tp].x;
			--tp;
		}
	}
	smt(){}
	smt(int,int);
};
smt *rt,node[1000005],*at=node;
smt *newsmt(int la,int ra){
	smt *rt=++at;
	*rt=smt(la,ra);
	return rt;
}
smt::smt(int la,int ra){
	ls=la;rs=ra;
	vt.clear();
	if(ls==rs){l=r=0;return;}
	int mid=(ls+rs)>>1;
	l=newsmt(ls,mid);
	r=newsmt(mid+1,rs);

}
signed main(){
#ifdef QAQAutoMaton 
	freopen("H.in","r",stdin);
	freopen("H.out","w",stdout);
#endif
	int n,q,k;
	read(n,q,k);
	for(int i=1;i<=n;++i)fa[i]=i,siz[i]=1;
	int at=1;
	int qc=0,mc=0;
	for(;q;--q){
		int tp;
		read(tp);
		if(tp==3){
			las[at]=qc;
			++at;
//			at-k
		}
		else if(tp==2){
			++qc;
			read(v[qc]);
		}
		else{
			++mc;
			read(xx[mc],xy[mc]);	
			sat[mc]=qc;
			xt[mc]=at;
		}
	}
	if(!qc)return 0;
	las[at]=qc;
	rt=newsmt(1,qc);
	for(int i=1;i<=mc;++i){
		if(sat[i]<las[min(xt[i]+k-1,at)]){
//			write(xx[i],' ',xy[i],' ',sat[i]+1,' ',las[min(xt[i]+k-1,at)],'\n');
			rt->add(sat[i]+1,las[min(xt[i]+k-1,at)],i);
		}
	}
	rt->solve();
	return 0;
}