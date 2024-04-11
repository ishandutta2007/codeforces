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
int n,m,t,x;	
int u[105],v[105],c[105];
double w[105][20005],s[105][20005],f[105][20005],ff[105][20005];
typedef complex<double> cp;
cp old[155][32769],nw[155][32769];
cp *sv[10005][105];
map<int,int> mp;
int gg[105],dis[105][105];
int rev[32769],ct;
cp ww[17][32769],iww[17][32769];
int lg[32769];
void FFT(cp *a,int n,int flg){
	for(int i=1;i<n;++i){
		if(i<rev[i])swap(a[i],a[rev[i]]);
	}
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=i+i){
			for(int k=0;k<i;++k){
				cp u=a[j+k],v=a[j+k+i]*(flg==1?ww[lg[i]][k]:iww[lg[i]][k]);
				a[j+k]=u+v;
				a[j+k+i]=u-v;
			}
		}
	}	
	if(flg<0)for(int i=0;i<n;++i)a[i]/=n;
}
void work(int l,int mid,int r){
	int N=1;
	while(N<=r-l)N<<=1;
	int id;
	for(int i=1;i<N;++i)rev[i]=(rev[i>>1]>>1)|((i&1)*(N>>1));
	if(mp.count(r-l)){
		id=mp[r-l];
	}
	else{
		id=mp[r-l]=++ct;
		for(int i=1;i<=m;++i){
			sv[id][i]=new cp[N];
			for(int j=0;j<=r-l;++j){
				sv[id][i][j]=w[i][j];
			}
			for(int j=r-l+1;j<N;++j)sv[id][i][j]=0;
			FFT(sv[id][i],N,1);
		}
	}
	for(int j=l;j<=mid;++j){
		for(int i=1;i<=n;++i)old[i][j-l]=f[i][j];
	}
	for(int j=mid-l+1;j<N;++j)for(int i=1;i<=n;++i)old[i][j]=0;
	for(int i=1;i<=n;++i)FFT(old[i],N,1);
	for(int i=1;i<=m;++i){
		for(int j=0;j<N;++j)nw[i][j]=old[v[i]][j]*sv[id][i][j];
		FFT(nw[i],N,-1);
		for(int j=mid+1;j<=r;++j){
			ff[i][j]+=nw[i][j-l].real();
		}
	}
}
void solve(int l,int r){
	if(l==r){
		for(int i=1;i<=m;++i){
			ff[i][l]+=s[i][l+1]*gg[v[i]];
			chkmin(f[u[i]][l],ff[i][l]+c[i]);
		}
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	work(l,mid,r);
	solve(mid+1,r);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(n,m,t,x);
	int a;
	for(int i=1;i<n;++i)for(int j=0;j<=t;++j)f[i][j]=1e10;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dis[i][j]=i==j?0:inf;
	for(int i=1;i<=m;++i){
		read(u[i],v[i],c[i]);
		chkmin(dis[u[i]][v[i]],c[i]);
		for(int j=1;j<=t;++j){read(a);w[i][j]=a/100000.;}
		for(int j=t;j;--j)s[i][j]=w[i][j]+s[i][j+1];
	}
	int s=0;
	for(int i=1;i<32768;i<<=1){
		lg[i]=++s;
		for(int j=0;j<i;++j){
			ww[lg[i]][j]=cp(cos(j*pi/i),sin(j*pi/i));
			iww[lg[i]][j]=cp(cos(j*pi/i),-sin(j*pi/i));
		}
	}
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)chkmin(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;++i)gg[i]=x+dis[i][n];
	solve(0,t);
	printf("%.10lf\n",f[1][t]);
	return 0;
}