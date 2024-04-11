/*
Author: QAQ-Automaton
LANG: C++
PROG: G.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define inf 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
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
int f[3][55][55][55],sum[55][55][55];
int x[55],y[55];
int a[2505][55],b[2505][55],c[2505][55];
vector<pii> sa[2505],sb[2505],sc[2505];
const int p=1e9+7;
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,t;
	read(n,t);
	a[0][0]=b[0][0]=c[0][0]=1;
	for(int i=1;i<=n;++i){
		read(x[i],y[i]);
		if(y[i]==1)	for(int j=n;j;--j){for(int k=x[i];k<=t;++k)a[k][j]=(a[k][j]+a[k-x[i]][j-1])%p;}
		if(y[i]==2)	for(int j=n;j;--j){for(int k=x[i];k<=t;++k)b[k][j]=(b[k][j]+b[k-x[i]][j-1])%p;}
		if(y[i]==3)	for(int j=n;j;--j){for(int k=x[i];k<=t;++k)c[k][j]=(c[k][j]+c[k-x[i]][j-1])%p;}
	}/*
	for(int i=0;i<=t;++i)for(int j=0;j<=n;++j)if(a[i][j])write('a',i,' ',j,' ',a[i][j],'\n');
	for(int i=0;i<=t;++i)for(int j=0;j<=n;++j)if(b[i][j])write('b',i,' ',j,' ',a[i][j],'\n');
	for(int i=0;i<=t;++i)for(int j=0;j<=n;++j)if(c[i][j])write('c',i,' ',j,' ',a[i][j],'\n');*/
	for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)for(int k=0;k<=n;++k){
		if(i+j+k==0)continue;
		if(i+j+k==1)f[i?0:(j?1:2)][i][j][k]=1;
		else{
			if(i)f[0][i][j][k]=i*(f[1][i-1][j][k]+f[2][i-1][j][k])%p;
			if(j)f[1][i][j][k]=j*(f[0][i][j-1][k]+f[2][i][j-1][k])%p;
			if(k)f[2][i][j][k]=k*(f[0][i][j][k-1]+f[1][i][j][k-1])%p;
		}
		sum[i][j][k]=(f[0][i][j][k]+f[1][i][j][k]+f[2][i][j][k])%p;
	}
	for(int i=0;i<=t;++i){
		for(int j=0;j<=n;++j){
			if(a[i][j])sa[i].push_back(make_pair(j,a[i][j]));
			if(b[i][j])sb[i].push_back(make_pair(j,b[i][j]));
			if(c[i][j])sc[i].push_back(make_pair(j,c[i][j]));
		}
	}
	int ans=0;
	for(int i=0;i<=t;++i)for(int j=0;j<=t-i;++j){
		if(sa[i].empty()||sb[j].empty()||sc[t-i-j].empty())continue;
		for(auto x:sa[i])for(auto y:sb[j])for(auto z:sc[t-i-j]){
			ans=(ans+sum[x.x][y.x][z.x]*x.y%p*y.y%p*z.y%p)%p;
		}
	}
	write(ans,'\n');
	return 0;
}