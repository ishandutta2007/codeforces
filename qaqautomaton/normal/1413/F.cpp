/*
Author: QAQAutoMaton
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
int n;
int u[500005],v[500005],uv[500005];
bitset<500005>c;
vector<int> to[500005];
bitset<500005>w,ww;
int dep[500005];
int mn[21][1000005],t;
int st[1000005];
int dfn[500005],low[500005],d;
int id[500005];
void dfs(int x,int f){
	mn[0][st[x]=++t]=dep[x];
	ww[dfn[x]=++d]=w[x];
	id[d]=x;
	for(auto i:to[x])if(i!=f){
		if(v[i]==x)swap(u[i],v[i]);
		w[uv[i]^x]=w[x]^c[i];
		dep[uv[i]^x]=dep[x]+1;
		mn[0][++t]=dep[x];
		dfs(uv[i]^x,i);
	}
	low[x]=d;
}
int lg[1000005];
void init(){
	for(int i=2;i<=t;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;(1<<i)<=t;++i)for(int j=1;j+(1<<i)-1<=t;++j)mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
}
int query(int l,int r){
	if(l>r)swap(l,r);
	int h=lg[r-l+1];
	return min(mn[h][l],mn[h][r-(1<<h)+1]);
}
int dist(int x,int y){
	return dep[x]+dep[y]-(query(st[x],st[y])<<1);
}
struct xmx{
	int s,u,v;
	xmx(){}
	xmx(int s,int u,int v):s(s),u(u),v(v){}
	xmx(int u,int v):u(u),v(v){s=dist(u,v);}
	xmx(int u):s(0),u(u),v(u){}
	void merge(int x){
		if(!~x)return;
		if(!~u){u=v=x;s=0;return;}
		int xu=u,xv=v;
		if(chkmax(s,dist(x,xu))){u=xu;v=x;}
		if(chkmax(s,dist(x,xv))){u=x;v=xv;}
	}
	void merge(xmx b){
		if(b.u)merge(b.u);
		if(b.v!=b.u)merge(b.v);
	}
};
xmx operator +(const xmx &a,const xmx &b){xmx c=a;c.merge(b);return c;}
struct smt{
	int ls,rs,rev;
	xmx mx0,mx1;
	smt *l,*r;
	smt(){}
	smt(int,int);
	void putrev(){rev^=1;swap(mx0,mx1);}
	void reverse(int la,int ra){
		if(la<=ls && rs<=ra){putrev();return;}
		if(rev){l->putrev();r->putrev();rev=0;}
		if(la<=l->rs)l->reverse(la,ra);
		if(r->ls<=ra)r->reverse(la,ra);
		mx0=l->mx0+r->mx0;
		mx1=l->mx1+r->mx1;
	}
};
smt *rt,node[1000005],*at=node;
smt *newsmt(int la,int ra){
	smt *rt=++at;
	*rt=smt(la,ra);
	return rt;
}
smt::smt(int la,int ra){
	ls=la;rs=ra;
	rev=0;
	if(ls==rs){if(ww[ls])mx1=id[ls],mx0=-1;else mx0=id[ls],mx1=-1;l=r=0;return;}
	int mid=(ls+rs)>>1;
	l=newsmt(ls,mid);
	r=newsmt(mid+1,rs);
	mx0=l->mx0+r->mx0;
	mx1=l->mx1+r->mx1;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int q;
	read(n);
	int w=0;
	for(int i=1;i<n;++i){
		read(u[i],v[i],w);
		c[i]=w;
		uv[i]=u[i]^v[i];
		to[u[i]].emplace_back(i);	
		to[v[i]].emplace_back(i);	
	}
	dfs(1,0);
	init();
	read(q);
	rt=newsmt(1,n);
	for(;q;--q){
		int x;
		read(x);
		rt->reverse(dfn[v[x]],low[v[x]]);
		write(max(rt->mx0.s,rt->mx1.s),'\n');
	}
	return 0;
}