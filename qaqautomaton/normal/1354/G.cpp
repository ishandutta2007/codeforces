/*
Author: QAQAutomaton
Lang: C++
Code: G.cpp
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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()/100);
int st[1005];
int vis[1005];
int a[1005];
int li[1005];
char s[1005];
int query(int *a,int *b,int n){
	printf("? %d %d\n",n,n);
	for(int i=1;i<=n;++i)printf("%d%c",a[i],i==n?'\n':' ');
	for(int i=1;i<=n;++i)printf("%d%c",b[i],i==n?'\n':' ');
	fflush(stdout);
	scanf("%s",s);
	if(s[0]=='F')return 1;
	else if(s[0]=='S')return -1;
	else if(s[0]=='E')return 0;
	exit(0);
}
void query_gift(int n){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(query(st,li,mid))r=mid-1;
		else l=mid+1;
	}
	printf("! %d\n",li[r+1]);
	fflush(stdout);
}

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)vis[i]=0;
	int w=1;while(w<=k)w<<=1;
	for(int i=1;i<=n;++i)a[i]=i;
	for(int i=1;i<=30;++i)if(query(a,a+rnd()%(n-1)+1,1)<0){printf("! 1\n");fflush(stdout);return;}
	vis[1]=1;
	int m=1;
	st[m]=1;
	int las=2;
	while(1){
		int m1=0;
		while(las<=n&&m1<m){
			if(vis[las])++las;
			else{
				li[++m1]=las;
				vis[las]=1;
				++las;
			}
		}
		if(query(st,li,m1)){query_gift(m1);return;}
		else{
			for(int i=1;i<=m1;++i)st[++m]=li[i];
		}
	}
}
signed main(){
	int t;
	scanf("%d",&t);
	for(;t;--t){
		solve();
	}
	return 0;
}