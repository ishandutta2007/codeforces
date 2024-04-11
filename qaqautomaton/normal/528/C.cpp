/*
Author: QAQAutomaton
Lang: C++
Code: C.cpp
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
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
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
int to[500005],lst[500005],beg[100005],e;
void add(int u,int v){
	to[++e]=v;lst[e]=beg[u];beg[u]=e;
	to[++e]=u;lst[e]=beg[v];beg[v]=e;
}
int deg[100005];
bitset<100005> od;
bitset<500005> is;
bitset<250005> fn;
int fa[100005];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
vector<int> xto[100005];
void dfs(int x){
	for(int &i=beg[x];i;)if(!fn[i>>1]){
		fn[i>>1]=1;is[i]=1;
		int v=to[i];
		i=lst[i];
		dfs(v);
	}
	else i=lst[i];
}
void dfs2(int x,int f){
	int tf=0;
	for(auto i:xto[x]){
		int v=to[i]^to[i^1]^x;
		if(v!=f){
			dfs2(v,x);
			od[x]=od[x]^od[v];
		}else tf=i;
	}
	if(od[x]){is[tf]=is[tf]^1;is[tf^1]=is[tf^1]^1;}
}
int c[100005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,m,u,v;
	read(n,m);
	e=1;
	int hs=0;
	for(int i=1;i<=m;++i){
		read(u,v);
		++deg[u];++deg[v];
		if(u==v){++c[u];++hs;}
		else{
			add(u,v);	
		}
	}
	for(int i=1,las=0;i<=n;++i){
		if(deg[i]&1){
			++deg[i];if(las){add(las,i);las=0;}else las=i;
		}
	}
	int las=0;
	for(int i=1;i<=n;++i){
		if((deg[i]>>1)&1){
			od[i]=1;
			if(las)las=0;else las=i;
		}
	}
	if(las){++c[las];deg[las]+=2;++hs;od[las]=0;}
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(int i=2;i<e;i+=2){
		if(find(to[i])!=find(to[i+1])){
			xto[to[i]].push_back(i);
			xto[to[i+1]].push_back(i);
			fa[find(to[i])]=find(to[i+1]);
		}
	}
	dfs(1);
	dfs2(1,0);
	write((e>>1)+hs,'\n');
	for(int i=2;i<=e;++i)if(is[i])write(to[i],' ',to[i^1],'\n');
	for(int i=1;i<=n;++i)for(;c[i];--c[i])write(i,' ',i,'\n');
	return 0;
}