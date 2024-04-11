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
int a[200005];
struct edge{
	int u,v,w;
	edge(){}
	edge(int u,int v,int w):u(u),v(v),w(w){}
	bool operator <(const edge &b)const{return w>b.w;}
};
edge e[300005];
int tp[500005],v[500005];
int f[400005],fa[19][400005],w[400005];
vector<int> to[400005];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int l[400005],r[400005],c;
int xa[400005];
int n,m,q;	
void dfs(int x){
	l[x]=c+1;
	if(x<=n){
		a[++c]=xa[x];
	}
	else for(auto i:to[x])dfs(i);
	r[x]=c;
}
struct smt{
	int ls,rs;
	smt *l,*r;
	pii mx;
	smt(){}
	smt(int,int);
	pii query(int la,int ra){
		if(la<=ls && rs<=ra)return mx;
		pii ans(-inf,inf);
		if(la<=l->rs)chkmax(ans,l->query(la,ra));
		if(r->ls<=ra)chkmax(ans,r->query(la,ra));
		return ans;
	}
	void upd(int x){
		if(ls==rs){mx={0,ls};return;}
		if(x<=l->rs)l->upd(x);
		else r->upd(x);
		mx=max(l->mx,r->mx);
	}
};
smt *rt,node[400005],*at=node;
smt *newsmt(int la,int ra){
	smt *rt=++at;
	*rt=smt(la,ra);
	return rt;
}
smt::smt(int la,int ra){
	ls=la;rs=ra;
	if(ls==rs){mx={a[ls],ls};l=r=0;return;}
	int mid=(ls+rs)>>1;
	l=newsmt(ls,mid);
	r=newsmt(mid+1,rs);
	mx=max(l->mx,r->mx);
}
void query(int x,int y){
	for(int i=18;~i;--i)if(w[fa[i][x]]>=y)x=fa[i][x];
	pii ans=rt->query(l[x],r[x]);
	write(ans.x,'\n');
	rt->upd(ans.y);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	read(n,m,q);
	for(int i=1;i<=n;++i)read(xa[i]);
	for(int i=1;i<=m;++i){
		read(e[i].u,e[i].v);
		e[i].w=q+1;
	}
	for(int i=1;i<=q;++i){
		read(tp[i],v[i]);
		if(tp[i]==2)e[v[i]].w=i;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;++i){f[i]=i;w[i]=inf;}
	int t=n;
	for(int i=1;i<=m;++i){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			++t;
			f[x]=f[y]=f[t]=fa[0][x]=fa[0][y]=t;
			w[t]=e[i].w;
			to[t].emplace_back(x);
			to[t].emplace_back(y);
		}
	}
	for(int i=1;i<=t;++i)if(!fa[0][i]){
		fa[0][i]=t+1;
		to[t+1].emplace_back(i);
	}
	++t;
	for(int i=1;i<=18;++i){
		for(int j=1;j<=t;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	}
	dfs(t);
	rt=newsmt(1,n);
	for(int id=1;id<=q;++id)if(tp[id]==1){
		query(v[id],id);
	}
	return 0;
}