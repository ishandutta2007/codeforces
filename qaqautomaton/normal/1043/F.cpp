/*
Author: CNYALI_LK
LANG: C++
PROG: f.cpp
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
const int inf=0x3f3f3f3f;
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
	inline void read (int &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	inline void read (char &x) {
		x=gc();
	}
	inline void read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
	}
	template<typename A,typename ...B>
	inline void read(A &x,B &...y){
		read(x);read(y...);
	}
	// print a signed integer
	inline void write (int x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	inline void write (char x) {
		putc(x);
	}
	inline void write(const char *x){
		while(*x){putc(*x);++x;}
	}
	inline void write(char *x){
		while(*x){putc(*x);++x;}
	}
	template<typename A,typename ...B>
	inline void write(A x,B ...y){
		write(x);write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
int cnt[300005],a[300005],mxp[300005],pri[11],t;
int mul[1023],can[1023],dp[1023];
int main(){
#ifdef cnyali_lk
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
#endif
	int n,x;
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		cnt[a[i]]=1;
	}
	int m=300000;
	for(int i=2;i<=m;++i)cnt[1]+=cnt[i];
	for(int i=2;i<=m;++i){
		if(!mxp[i]){for(int j=i;j<=m;j+=i)mxp[j]=i;}
		for(int j=i+i;j<=m;j+=i){
			cnt[i]+=cnt[j];
		}
	}
	int ans=0x3f3f3f3f,t,tt;
	for(int i=1;i<=n;++i){
		t=0;
		while(a[i]>1){
			pri[t]=mxp[a[i]];
			while(!(a[i]%pri[t]))a[i]/=pri[t];
			++t;
		}
		tt=1<<t;
		mul[0]=1;
		can[0]=cnt[1];
		for(int j=1;j<tt;++j){
			mul[j]=mul[j&(j-1)]*pri[__builtin_ctz(j)];
			can[j]=cnt[mul[j]];
		}
		for(int j=tt-1;~j;--j){
			dp[j]=0x3f3f3f3f;
			--can[j];
			for(int k=j;k;){
				k=(k-1)&j;
				can[k]-=can[j];
			}
			can[j]=!!can[j];
		}
		dp[(1<<t)-1]=0;
		for(int j=1;j<tt;++j)for(int k=j;k;k=(k-1)&j)can[j]|=can[j-k];
		for(int j=tt-1;~j;--j){
			for(int k=j;k;k=(k-1)&j)
				if(can[tt-k-1])chkmin(dp[j-k],dp[j]+1);
		}
		chkmin(ans,dp[0]+1);
	}
	write(ans==0x3f3f3f3f?-1:ans,'\n');
	return 0;
}