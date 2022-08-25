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
int fa[200005];
vector<int> to[200005];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int dep[200005];
int f[18][200005]; 
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[0][x]=fa;
	for(int i=1;i<=17;++i)f[i][x]=f[i-1][f[i-1][x]];
	for(auto i:to[x])if(i!=fa){
		dfs(i,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;~i;--i)if(dep[x]-(1<<i)>=dep[y])x=f[i][x];
	if(x==y)return x;
	for(int i=17;~i;--i)if(f[i][x]!=f[i][y]){x=f[i][x];y=f[i][y];}
	return f[0][x];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];	
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,u,v;
	read(n);
	for(int i=1;i<=n;++i){
		fa[i<<1]=i<<1;fa[i<<1|1]=i<<1|1;
	}
	for(int i=1;i<n;++i){
		read(u,v);
		to[u<<1].push_back(v<<1|1);
		to[u<<1|1].push_back(v<<1);
		to[v<<1].push_back(u<<1|1);
		to[v<<1|1].push_back(u<<1);
		fa[find(u<<1)]=find(v<<1|1);
		fa[find(u<<1|1)]=find(v<<1);
	}
	dfs(2,0);
	dfs(3,0);
	int q,x,y,k;
	read(q);
	for(;q;--q){
		read(x,y,u,v,k);
		int is=k&1,s=k+1;
		if(find(u<<1)==find(v<<1|is)){
			s=dis(u<<1,v<<1|is);
			if(find(x<<1)==find(y<<1|1)){
				if(find(u<<1)==find(x<<1)){
					chkmin(s,dis(u<<1,x<<1)+dis(v<<1|is,y<<1|1)+1);
					chkmin(s,dis(u<<1,y<<1|1)+dis(v<<1|is,x<<1)+1);
				}else{
					chkmin(s,dis(u<<1,x<<1|1)+dis(v<<1|is,y<<1)+1);
					chkmin(s,dis(u<<1,y<<1)+dis(v<<1|is,x<<1|1)+1);
				}
			}
		}
		else{
			if(find(x<<1)!=find(y<<1|1)){
				if(find(u<<1)==find(x<<1)){
					chkmin(s,dis(u<<1,x<<1)+dis(v<<1|is,y<<1|1)+1);
					chkmin(s,dis(u<<1,y<<1)+dis(v<<1|is,x<<1|1)+1);
				}else{
					chkmin(s,dis(u<<1,x<<1|1)+dis(v<<1|is,y<<1)+1);
					chkmin(s,dis(u<<1,y<<1|1)+dis(v<<1|is,x<<1)+1);
				}
			}
		}
		write(s<=k?"YES\n":"NO\n");
	}
	return 0;
}