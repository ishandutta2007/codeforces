/*
Author: QAQAutomaton
LANG: C++
PROG: C.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
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
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
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
vector<int> to[500005],f[500005],g[500005];
int u[500005],v[500005],w[500005],uv[500005],deg[500005];
int is[500005],id[500005],vis[500005];
priority_queue<int> p;
int q,n,k,m;
void dfs(int x,int fa){
	vis[id[x]]=1;
	int y=id[x],tf=0;
	f[y][0]=0;
	for(int i=1;i<=k;++i)f[y][i]=-inf;
	for(auto i:to[x])if(deg[uv[i]^x]>k){
		if(uv[i]^x^fa){
			dfs(uv[i]^x,x);
			int z=id[uv[i]^x];
			for(int j=k;j;--j){
				f[y][j]=max(f[y][j]+f[z][k],f[y][j-1]+g[z][k]);
			}
			f[y][0]+=f[z][k];
		}
		else{
			tf=w[i];		
		}
	}
	for(int i=0;i<k;++i)g[y][i+1]=f[y][i]+tf;
	g[y][0]=-inf;
	while(!p.empty())p.pop();
	for(auto i:to[x])if(deg[uv[i]^x]<=k)p.push(w[i]);
	int s=0;
	for(int i=1;i<=k;++i){
		if(!p.empty()){
			s+=p.top();p.pop();
		}
		chkmax(f[y][k],f[y][k-i]+s);
		chkmax(g[y][k],g[y][k-i]+s);
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	read(q);
	for(;q;--q){
		read(n,k);
		for(int i=1;i<=n;++i)to[i].clear();
		for(int i=1;i<=n;++i){deg[i]=0;id[i]=0;}
		for(int i=1;i<n;++i){
			read(u[i],v[i],w[i]);
			to[u[i]].push_back(i);
			to[v[i]].push_back(i);
			uv[i]=u[i]^v[i];
			++deg[u[i]];
			++deg[v[i]];
		}
		int cnt=0;
		for(int i=1;i<n;++i)if(deg[u[i]]<=k && deg[v[i]]<=k){cnt+=w[i];}
		m=0;
		for(int i=1;i<=n;++i){
			if(deg[i]>k){
				is[++m]=i;
				id[i]=m;
				vis[m]=0;
				f[m].resize(k+1);
				g[m].resize(k+1);
			}
		}
		for(int i=1;i<=m;++i)if(!vis[i]){
			dfs(is[i],0);
			cnt+=f[i][k];
		}
		write(cnt,'\n');
	}

	return 0;
}