/*
Author: QAQ Automaton
Lang: C++
Prog: C.cpp
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
int p[200005],fa[200005];
int is[200005],dep[200005];
int n;
vector<int> son[200005];
int t,dfn[200005],w[19][400005];
void dfs(int x){
	dfn[x]=++t;
	w[0][t]=dep[x];
	for(auto i:son[x]){
		dfs(i);
		w[0][++t]=dep[x];
	}
}
int lgo[400005];
void init_lca(){
	dfs(1);
	for(int i=1;1<<i<=t;++i){
		for(int j=1;j+(1<<i)-1<=t;++j)w[i][j]=min(w[i-1][j],w[i-1][j+(1<<(i-1))]);
	}
	lgo[1]=0;
	for(int i=2;i<=t;++i)lgo[i]=lgo[i>>1]+1;
}
int lca(int a,int b){
	a=dfn[a];b=dfn[b];
	if(a>b)swap(a,b);
	int lg=lgo[b-a+1];
	return min(w[lg][a],w[lg][b-(1<<lg)+1]);
}
bool tb(pii a){return ~a.x;}
int dl[4][4],ps[4];
pii merge(pii a,pii b){
	if(!(~a.x)||!(~b.x))return make_pair(-1,-1);
	if(!a.x)return b;
	ps[0]=a.x;	
	ps[1]=a.y;	
	ps[2]=b.x;	
	ps[3]=b.y;	
	for(int i=0;i<4;++i){
		dl[i][i]=0;
		for(int j=0;j<i;++j)dl[i][j]=dl[j][i]=dep[ps[i]]+dep[ps[j]]-2*lca(ps[i],ps[j]);
	}
	for(int i=0;i<4;++i)for(int j=i+1;j<4;++j){
		bool ok=1;
		for(int k=0;k<4;++k)if(dl[i][j]!=dl[i][k]+dl[k][j])ok=0;
		if(ok)return make_pair(ps[i],ps[j]);
	}
	return make_pair(-1,-1);
}
int las;
pii ans;
struct smt{
	pii sum;
	int ls,rs;
	smt *l,*r;
	smt(int la,int ra){
		ls=la;rs=ra;
		if(ls==rs){
			l=r=0;
			sum=make_pair(is[ls],is[ls]);
			return;
		}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
		sum=merge(l->sum,r->sum);
	}
	void reload(int x){
		if(ls==rs){sum=make_pair(is[ls],is[ls]);return;}
		if(x<=l->rs)l->reload(x);
		else r->reload(x);
		sum=merge(l->sum,r->sum);
	}
	void work(){
		if(las+1!=ls)return;
		pii nw=merge(ans,sum);
		if(tb(nw)){ans=nw;las=rs;return;}
		if(ls==rs)return;
		l->work();r->work();
	}
};
smt *rt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	read(n);
	for(int i=1;i<=n;++i){
		read(p[i]);
		is[p[i]]=i;
	}
	for(int i=2;i<=n;++i){
		read(fa[i]);
		dep[i]=dep[fa[i]]+1;
		son[fa[i]].push_back(i);
	}
	init_lca();
	rt=new smt(0,n-1);
	int q;
	read(q);
	for(;q;--q){
		int tp;
		read(tp);
		if(tp==2){
			las=-1;
			ans=make_pair(0,0);
			rt->work();
			write(las+1,'\n');
		}
		else{
			int u,v;
			read(u,v);
			swap(is[p[u]],is[p[v]]);
			rt->reload(p[u]);
			rt->reload(p[v]);
			swap(p[u],p[v]);
		}
	}
	return 0;
}