/*
Author: QAQAutoMaton
Lang: C++
Code: G.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
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
vector<pii> to[200005],bk[200005];
int t=0;
int dfn[200005],low[200005];
int stk[200005],tp,col[200005],c;
vector<int> nd[200005];
void dfs(int x){
	dfn[x]=low[x]=++t;
	stk[++tp]=x;
	for(auto i:to[x])if(!dfn[i.x]){
		dfs(i.x);
		chkmin(low[x],low[i.x]);
	}
	else if(!col[i.x])chkmin(low[x],dfn[i.x]);
	if(dfn[x]==low[x]){
		++c;
		while(stk[tp+1]!=x){
			nd[c].emplace_back(stk[tp]);
			col[stk[tp]]=c;--tp;
		}
	}
}
int gc;
int xg[200005];
bitset<200005>vis;
int w1[200005];
int w2[200005];
void xdfs(int x,int lw){
	if(!vis[x]){w1[x]=lw;vis[x]=1;}
	else{
		return;
	}
	for(auto i:to[x])xdfs(i.x,lw+i.y);
}
void ydfs(int x,int lw){
	if(!vis[x]){w2[x]=lw;vis[x]=1;}
	else{
		return;
	}
	for(auto i:bk[x])ydfs(i.x,lw+i.y);
}
void work(int x){
	gc=0;
	xdfs(nd[x][0],0);
	for(auto i:nd[x])vis[i]=0;
	ydfs(nd[x][0],0);
	for(auto i:nd[x])for(auto j:to[i])gc=__gcd(w2[j.x]+w1[i]+j.y,gc);
	xg[x]=gc;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,m;	
	int u,v,w;
	read(n,m);
	for(int i=1;i<=m;++i){
		read(u,v,w);
		to[u].emplace_back(v,w);
	}
	for(int i=1;i<=n;++i)if(!dfn[i]){
		dfs(i);
	}
	for(int i=1;i<=n;++i){
		for(int j=to[i].size()-1;~j;--j)if(col[to[i][j].x]!=col[i]){swap(to[i][j],to[i].back());to[i].pop_back();}
	}
	for(int i=1;i<=n;++i){
		for(auto j:to[i])bk[j.x].emplace_back(i,j.y);
	}
	for(int i=1;i<=c;++i){
		work(i);
	}
	int q;
	read(q);
	for(;q;--q){
		int x,s,t;
		read(x,s,t);
		if((t-s)%__gcd(xg[col[x]],t))write("NO\n");
		else write("YES\n");
	}
	return 0;
}