/*
Author: QAQAutoMaton
Lang: C++
Code: D.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
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
const uint p=998244353;
struct Z{
	uint x;
	Z(uint a=0):x(a){}
    Z& operator++(){x=x==p-1?0:x+1;return *this;}
    Z& operator--(){x=x?x-1:p-1;return *this;}
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
inline Z Inv(const Z x){
	int a,b;
	exgcd(p,x.x,a,b);
	return b<0?b+p:b;
}
inline Z operator/(const Z x1,const Z x2){return x1*Inv(x2);}
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }
vector<int> to[405];
int d[405][405];
int s[405][405];
int n,m;
int q[405],*l,*r;
int xu[605],xv[605];
void bfs(int x,int *d){
	for(int i=1;i<=n;++i)d[i]=inf;
	d[*(l=r=q)=x]=0;
	for(;l<=r;++l){
		for(auto i:to[*l])if(chkmin(d[i],d[*l]+1))*(++r)=i;
	}
}
int cnt[405];
Z ans[405][405];
int a[405],b[405];
int val[405][405];
bitset<405>e[405];
int c[405];
int u[405];
Z calc(int x,int y){
	for(int i=1;i<=n;++i){a[i]=d[x][i];b[i]=d[y][i];}
	for(int i=1;i<=n;++i){
		++s[a[i]][b[i]];
		val[a[i]][b[i]]=i;
	}
	Z ans(1);
	for(int i=0;i<=d[x][y];++i){if(s[i][d[x][y]-i]!=1){ans=0;goto END;}u[i]=val[i][d[x][y]-i];}
	for(int i=0;i<d[x][y];++i){
		if(!e[u[i]][u[i+1]]){ans=0;goto END;}
	}
	for(int i=1;i<=n;++i)c[i]=0;
	for(int i=1;i<=m;++i){
		int u=xu[i],v=xv[i];
		if(a[u]>a[v])swap(u,v);
		if(a[u]+1==a[v] && b[u]+1==b[v])++c[v];
	}
	for(int i=1;i<=n;++i)if(a[i]+b[i]!=d[x][y]){
		ans*=c[i];
	}
	END:;
	for(int i=1;i<=n;++i){
		s[a[i]][b[i]]=0;
	}
	return ans;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	read(n,m);
	for(int i=1;i<=m;++i){
		int u,v;
		read(u,v);
		xu[i]=u;xv[i]=v;
		to[u].emplace_back(v);
		to[v].emplace_back(u);
		e[u][v]=e[v][u]=1;
	}
	for(int i=1;i<=n;++i){
		bfs(i,d[i]);
	}
	for(int u=1;u<=n;++u){
		for(int v=u+1;v<=n;++v){
			ans[u][v]=ans[v][u]=calc(u,v);
		}
		int *xd=d[u];
		for(int i=1;i<=n;++i)c[i]=0;
		for(int i=1;i<=m;++i){
			int x=xu[i],y=xv[i];
			if(xd[x]>xd[y])swap(x,y);
			if(xd[x]+1==xd[y])++c[y];
		}
		ans[u][u]=1;
		for(int i=1;i<=n;++i)if(i!=u)ans[u][u]*=c[i];
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)write(ans[i][j].x,j==n?'\n':' ');
	return 0;
}