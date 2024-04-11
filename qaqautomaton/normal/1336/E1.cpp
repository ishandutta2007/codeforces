/*
Author: QAQAutomaton
Lang: C++
Code: G1.cpp
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
int a[55],b[55];
const int p=998244353;
int n,m,x,k,s=1;	
void insert(int x){
	for(int i=m-1;~i;--i)if(x&(1ll<<i)){
		if(!a[i]){
			a[i]=x;
			for(int j=0;j<i;++j)if(a[i]&(1ll<<j))a[i]^=a[j];
			for(int j=i+1;j<m;++j)if(a[j]&(1ll<<i))a[j]^=a[i];
			return;
		}
		else{
			x^=a[i];
		}
	}
	(s<<=1)>=p?s-=p:s;
}
int f[1<<20|5];
int dp[37][37][1<<15|5];
int ans[37];
signed main(){
#ifdef QAQAutoMaton 
	freopen("G1.in","r",stdin);
	freopen("G1.out","w",stdout);
#endif
	read(n,m);
	for(int i=1;i<=n;++i){
		read(x);
		insert(x);
	}
	for(int i=0;i<m;++i)if(a[i]){
		++k;
		int l=0;
		for(int j=0;j<i;++j)if(!a[j]){
			if(a[i]&(1ll<<j))b[k]|=1LL<<l;
			++l;	
		}
	}
	if(k<=20){
		for(int i=0;i<k;++i)f[1<<i]=b[i+1];
		for(int i=1;i<1<<k;++i)if(i&(i-1))f[i]=f[i&(i-1)]^f[i&(-i)];
		for(int i=0;i<1<<k;++i)++ans[__builtin_popcountll(i)+__builtin_popcountll(f[i])];
	}
	else{
		dp[0][0][0]=1;	
		int l=m-k;
		for(int i=1;i<=k;++i){
			for(int j=0;j<i;++j){
				for(int w=0;w<1<<l;++w){
					(dp[i][j][w]+=dp[i-1][j][w])%=p;
					(dp[i][j+1][w^b[i]]+=dp[i-1][j][w])%=p;
				}
			}
		}
		for(int i=0;i<=k;++i)for(int j=0;j<1<<l;++j)(ans[i+__builtin_popcountll(j)]+=dp[k][i][j])%=p;
	}
	for(int i=0;i<=m;++i)write(ans[i]*s%p,i==m?'\n':' ');	
	return 0;
}