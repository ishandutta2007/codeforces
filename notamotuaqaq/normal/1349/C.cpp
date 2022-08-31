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
short dis[1005][1005];
bitset<1005> vis[1005],w[1005];
char s[1005];
int q[1000005],*l=q+1,*r=q;
void add(int x,int y,int w){
	if(chkmin(dis[x][y],w))*(++r)=x<<16|y;
}
void bfs(){
	for(;l<=r;++l){
		int x=*l>>16,y=*l&65535;
		vis[x][y]=1;
		add(x-1,y,dis[x][y]+1);
		add(x+1,y,dis[x][y]+1);
		add(x,y-1,dis[x][y]+1);
		add(x,y+1,dis[x][y]+1);
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,m,q;
	read(n,m,q);
	for(int i=1;i<=n;++i){
		read(s+1);	
		for(int j=1;j<=m;++j)w[i][j]=s[j]=='1';
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)dis[i][j]=inf;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
		if(i>1&&w[i-1][j]==w[i][j])add(i,j,0);else
		if(j>1&&w[i][j-1]==w[i][j])add(i,j,0);else
		if(i<n&&w[i+1][j]==w[i][j])add(i,j,0);else
		if(j<m&&w[i][j+1]==w[i][j])add(i,j,0);
	}
	bfs();
	for(;q;--q){
		int x,y;
		ll t;
		read(x,y,t);
		if(!vis[x][y])putc(w[x][y]+'0');
		else{
			if(dis[x][y]>t)putc(w[x][y]+'0');
			else putc((((t-dis[x][y])&1)^(w[x][y]))+'0');
		}
		putc('\n');
	}
	return 0;
}