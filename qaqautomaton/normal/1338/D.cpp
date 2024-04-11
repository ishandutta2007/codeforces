/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp
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
vector<int> to[100005];
int dp[100005][3][2];//dp[x][0/1/2][1/0] x//
void dfs(int x,int f){
	int m=to[x].size();
	for(int i=0;i<m;++i)if(to[x][i]==f){swap(to[x][i],to[x][m-1]);to[x].pop_back();--m;--i;}
	for(auto i:to[x])if(i!=f){
		dfs(i,x);
	}
	//x
	int mx0=0,mx1=0;
	for(auto i:to[x])if(i!=f){
		if(dp[i][2][0]>mx0){mx1=mx0;mx0=dp[i][2][0];}
		else chkmax(mx1,dp[i][2][0]);
	}
	dp[x][1][1]=dp[x][2][1]=mx0+1;
	dp[x][0][1]=mx0+mx1+1;
	for(auto i:to[x])if(i!=f)chkmax(dp[x][0][1],dp[i][1][0]+1);
	//x	
//	1,2 -> 2 	
//  0 -> 0
	for(auto i:to[x])if(i!=f)chkmax(dp[x][0][0],dp[i][0][1]);
	mx0=mx1=0;
	for(auto i:to[x])if(i!=f){
		if(dp[i][2][1]>mx0){mx1=mx0;mx0=dp[i][2][1];}
		else chkmax(mx1,dp[i][2][1]);
	}
	chkmax(dp[x][0][0],m-2+mx0+mx1);
	chkmax(dp[x][1][0],m-2+mx0+mx1);
	for(auto i:to[x])if(i!=f){
		chkmax(dp[x][1][0],m-1+dp[i][2][1]);
		chkmax(dp[x][2][0],m-1+dp[i][2][1]);
	}
	chkmax(dp[x][0][1],dp[x][0][0]);
	chkmax(dp[x][1][1],dp[x][1][0]);
	chkmax(dp[x][2][1],dp[x][2][0]);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n,u,v;
	read(n);
	for(int i=1;i<n;++i){
		read(u,v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dfs(1,0);
	write(max(dp[1][0][0],dp[1][0][1]),'\n');
	return 0;
}