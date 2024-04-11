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
const int p=1000000007;
struct Z{
	uint x;
	Z(){}
	Z(uint a){
		x=a;
	}
};
inline uint modp(const uint x){
	return x<p?x:x-p;
}
inline Z operator+(const Z x1, const Z x2) { return modp(x1.x+x2.x);}
inline Z operator-(const Z x1, const Z x2) { return modp(x1.x+p-x2.x);}
inline Z operator-(const Z x) {return x.x?p-x.x:0;}
inline Z operator*(const Z x1, const Z x2) { return static_cast<ull>(x1.x)*x2.x%p;}
void exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
inline Z Inv(const Z a){
	int x,y;
	exgcd(p,a.x,x,y);
	return y<0?y+=p:y;
}
inline Z operator/(const Z x1, const Z x2) { return x1*Inv(x2);}

inline Z &operator++(Z &x1){x1.x==p-1?x1.x=0:++x1.x;return x1;} 
inline Z &operator--(Z &x1){x1.x?--x1.x:x1.x=p-1;return x1;}
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }

vector<pii> to[200005];
void link(int u,int v){
	if(u<0){
		u=-u;
		to[u].emplace_back(v,1);
		to[v].emplace_back(u,1);
	}
	else{
		to[u].emplace_back(v,0);
		to[v].emplace_back(u,0);
	}
}
Z ans[2];
bitset<200005> vis;
int n,m;
namespace chain{
	int node[200005],w[200005];
	int t;
	void dfs(int x){
		vis[x]=1;
		for(auto i:to[x])if(!vis[i.x]){
			node[++t]=i.x;w[t]=i.y;
			dfs(i.x);
		}
	}
	Z f[2][2],g[2][2],h[2];
	//f[last][xorsum]
	void solve(int x){
		node[t=1]=x;
		dfs(x);	
		int at=0;
		f[0][0]=f[1][0]=f[1][1]=f[0][1]=0;
		if(x<=m){
			f[0][0]=f[1][0]=1;	
			at=1;
		}
		else{
			f[0][w[2]]=f[1][w[2]^1]=1;
			at=2;	
		}
		while(at+2<=t){
			at+=2;
			g[0][0]=g[0][1]=g[1][0]=g[1][1]=0;
			for(int x=0;x<2;++x)for(int y=0;y<2;++y)for(int z=0;z<2;++z)
				g[x][((x^w[at])|(y^w[at-1]))^z]+=f[y][z];
			for(int x=0;x<2;++x)for(int y=0;y<2;++y)f[x][y]=g[x][y];
		}
		if(at+1<=t){
			Z f0=ans[0],f1=ans[1],g0=f[0][0]+f[1][1],g1=f[0][1]+f[1][0];
			if(w[t]){swap(g0,g1);}
			ans[0]=f0*g0+f1*g1;
			ans[1]=f0*g1+f1*g0;
		}
		else{
			Z f0=ans[0],f1=ans[1],g0=f[0][0]+f[1][0],g1=f[0][1]+f[1][1];
			ans[0]=f0*g0+f1*g1;
			ans[1]=f0*g1+f1*g0;
		}
	}
}
namespace circle{
	int node[200005],w[200005];
	int t;
	void dfs(int x){
		vis[x]=1;
		for(auto i:to[x])if(!vis[i.x]){
			node[++t]=i.x;w[t]=i.y;
			dfs(i.x);
		}
	}
	Z f[2][2],g[2][2],h[2];
	void solve(int x){
		node[t=1]=x;
		w[1]=to[x][1].y;
		dfs(x);	
		h[0]=h[1]=0;
		for(int v=0;v<2;++v){
			f[0][0]=f[1][0]=f[1][1]=f[0][1]=0;
			f[v][0]=1;
			int at=1;
			while(at+2<=t){
				at+=2;
				g[0][0]=g[0][1]=g[1][0]=g[1][1]=0;
				for(int x=0;x<2;++x)for(int y=0;y<2;++y)for(int z=0;z<2;++z)
					g[x][((x^w[at])|(y^w[at-1]))^z]+=f[y][z];
				for(int x=0;x<2;++x)for(int y=0;y<2;++y)f[x][y]=g[x][y];
			}
			for(int x=0;x<2;++x)for(int y=0;y<2;++y)h[((x^w[at+1])|(v^w[1]))^y]+=f[x][y];
		}
		Z f0=ans[0],f1=ans[1];
		ans[0]=f0*h[0]+f1*h[1];
		ans[1]=f0*h[1]+f1*h[0];
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int x,k;	
	read(n,m);
	for(int i=1;i<=n;++i){
		read(k);
		for(;k;--k){
			read(x);
			link(x,i+m);
		}
	}
	ans[0]=1;
	for(int i=1;i<=n+m;++i)if(!vis[i] && to[i].size()<=1)chain::solve(i);
	for(int i=1;i<=m;++i)if(!vis[i])circle::solve(i);
	write(ans[1].x,'\n');
	return 0;
}