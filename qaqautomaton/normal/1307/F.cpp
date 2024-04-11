/*
Author: QAQAutomaton
Lang: C++
Code: F.cpp
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
vector<int> to[400005];
int dep[400005];
int fa[400005][21];
int q[400005],*l=q+1,*r=q;
void dfs(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=18;++i)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto i:to[x])if(i!=f)dfs(i,x);
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	for(int i=18;~i;--i)if(dep[a]-(1<<i)>=dep[b])a=fa[a][i];
	if(a==b)return a;
	for(int i=18;~i;--i)if(fa[a][i]!=fa[b][i]){a=fa[a][i];b=fa[b][i];}
	return fa[a][0];
}
int dist(int a,int b){return dep[a]+dep[b]-2*dep[lca(a,b)];}
int dis[400005],id[400005],f[400005];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int kthf(int a,int n){
	for(int i=18;~i;--i)if(n&(1<<i))a=fa[a][i];
	return a;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,k,m,u,v;
	read(n,k,m);
	for(int i=1;i<n;++i){
		read(u,v);	
		to[u].push_back(i+n);
		to[v].push_back(i+n);
		to[i+n].push_back(u);
		to[i+n].push_back(v);
	}
	dfs(1,0);	
	int x;
	for(int i=1;i<=n+n-1;++i)dis[i]=inf;
	for(int i=1;i<=m;++i){
		read(x);
		*(++r)=x;
		dis[x]=0;
		id[x]=i;
		f[i]=i;
	}
	while(l<=r){
		if(dis[*l]<k){
			for(auto i:to[*l])if(chkmin(dis[i],dis[*l]+1)){
				*(++r)=i;
				id[i]=id[*l];
			}
			else f[find(id[*l])]=find(id[i]);
		}
		++l;
	}
	int q;
	read(q);
	for(;q;--q){
		read(u,v);
		int l=lca(u,v),len=dep[u]+dep[v]-2*dep[l];
		if(len<=k+k)write("YES\n");
		else{
			int au=dep[u]-dep[l]>=k?kthf(u,k):kthf(v,len-k);
			int av=dep[v]-dep[l]>=k?kthf(v,k):kthf(u,len-k);
			if(id[au]&&id[av] && find(id[au])==find(id[av]))write("YES\n");
			else write("NO\n");
		}
	}
	return 0;
}