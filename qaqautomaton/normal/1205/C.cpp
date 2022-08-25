/*
Author: QAQ Automaton
LANG: C++
PROG: C.cpp
Mail: cnyalilk@vip.qq.com
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
int query(int x,int y,int x1,int y1){
	cout<<"? "<<x<<' '<<y<<' '<<x1<<' '<<y1<<endl;
	cout.flush();
	cin>>x;
	return x;
}
int a[55][55],is[55][55],x[2505],y[2505],t;
vector<pii> to[2505];
void dfs(int u,int c=1,int f=0){
	a[x[u]][y[u]]=c;
	for(auto i:to[u])if(i.x!=f)dfs(i.x,c^i.y,u);
}
void add(int x1,int y1,int x2,int y2){
	int u=is[x1][y1],v=is[x2][y2],w=query(x1,y1,x2,y2)^1;
	to[u].push_back(make_pair(v,w));
	to[v].push_back(make_pair(u,w));
}
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){is[i][j]=++t;x[t]=i;y[t]=j;}
	add(1,1,2,2);
	add(1,2,2,3);
	for(int i=1;i+2<=n;++i)add(1,i,1,i+2);
	for(int i=1;i+2<=n;++i)add(2,i,2,i+2);
	for(int i=3;i<=n;++i)for(int j=1;j<=n;++j)add(i-2,j,i,j);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)a[i][j]=-1;
	dfs(1);
	dfs(2);
	bool ed=0;
	for(int i=1;i+1<=n&&!ed;++i)for(int j=1;j+2<=n && !ed;++j){
		if(
			(a[i][j]==a[i][j+2])==(a[i][j+1]==a[i+1][j+2])||
			(a[i][j]==a[i+1][j+1])==(a[i][j+1]==a[i+1][j+2])||
			(a[i][j]==a[i+1][j+1])==(a[i+1][j]==a[i+1][j+2])
				){add(i,j,i+1,j+2);ed=1;}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)a[i][j]=-1;
	dfs(1);
	cout<<"!\n";
	for(int i=1;i<=n;++i,cout<<'\n')for(int j=1;j<=n;++j)cout<<a[i][j];
	cout.flush();
	return 0;
}