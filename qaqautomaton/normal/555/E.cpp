/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
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
vector<int> to[300005];
int dfn[300005],low[300005],t,stk[300005],tp;
int xu[300005],xv[300005],uv[300005];
int col[300005],c;
void dfs_bcc(int x,int f){
	dfn[x]=low[x]=++t;
	stk[++tp]=x;
	for(auto i:to[x])if(i!=f){
		int v=uv[i]^x;
		if(!dfn[v]){dfs_bcc(v,i);chkmin(low[x],low[v]);}
		else if(dfn[v]<dfn[x])chkmin(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		stk[tp+1]=-1;
		++c;
		while(stk[tp+1]!=x){
			col[stk[tp]]=c;
			--tp;
		}
	}
}
int f[200005];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int fa[19][200005],dep[200005];
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[0][x]=f;
	for(int i=1;i<=18;++i)fa[i][x]=fa[i-1][fa[i-1][x]];
	dfn[x]=++t;
	for(auto i:to[x])if(i!=f)dfs(i,x);
	low[x]=t;
}
int c0[200005],c1[200005];
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=18;~i;--i)if(dep[x]-(1<<i)>=dep[y])x=fa[i][x];
	if(x==y)return x;
	for(int i=18;~i;--i)if(fa[i][x]!=fa[i][y]){x=fa[i][x];y=fa[i][y];}
	return fa[0][x];
}
void addx(int x,int y){
	if(x==y)return;
	if(dfn[x]<=dfn[y] && low[y]<=low[x]){
		++c1[y];
		--c1[x];
	}
	else if(dfn[y]<=dfn[x] && low[x]<=low[y]){
		++c0[x];--c0[y];
	}
	else{
		int l=lca(x,y);
		++c0[x];++c1[y];
		--c0[l];--c1[l];
	}
}
void fdfs(int x,int f){
	for(auto i:to[x])if(i!=f){fdfs(i,x);c0[x]+=c0[i];c1[x]+=c1[i];}
	if(c0[x]&&c1[x])exit(write("No\n"));
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,m,q;
	read(n,m,q);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		int &u=xu[i],&v=xv[i];
		read(u,v);
		uv[i]=u^v;
		to[u].emplace_back(i);
		to[v].emplace_back(i);
		f[find(u)]=find(v);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i])dfs_bcc(i,0);
	}
	for(int i=1;i<=n;++i)to[i].clear();
	for(int i=1;i<=m;++i)if(col[xu[i]]!=col[xv[i]]){
		to[col[xu[i]]].emplace_back(col[xv[i]]);	
		to[col[xv[i]]].emplace_back(col[xu[i]]);	
	}
	n=c;
	for(int i=1;i<=n+1;++i){dfn[i]=low[i]=0;}
	t=0;
	for(int i=1;i<=n;++i)if(!dfn[i]){
		to[n+1].emplace_back(i);
		dfs(i,0);
	}
	for(int i=1;i<=q;++i){
		int u,v;
		read(u,v);
		if(find(u)!=find(v))return write("No\n");
		addx(col[u],col[v]);
	}
	fdfs(n+1,0);
	write("Yes\n");
	return 0;
}