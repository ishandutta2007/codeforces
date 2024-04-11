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
int n,k;
int a[2025],ans;
int ar[2][2025],sz[2];
int chk(int m){
	int at=0;
	for(int i=1;i<=m;++i)ar[0][i]=a[i];
	sz[0]=m;
	for(int i=1;i<=k;++i){
		sz[at^1]=0;
		for(int j=1;j<=sz[at];++j){
			while(ar[at][j]){
				ar[at^1][++sz[at^1]]=j;	
				if(sz[at^1]>n)return 0;
				--ar[at][j];
			}
		}
		if(sz[at^1]>n)return 0;
		at^=1;
		reverse(ar[at]+1,ar[at]+sz[at]+1);
	}
	return 1;
}
void dfs(int mx,int m){
	for(int i=1;i<=mx;++i){
		a[m]=i;
		if(chk(m)){
			++ans;	
			dfs(i,m+1);
		}
		else break;
	}
}
namespace solve1{
	const int p=998244353;
	int dp[2025][2025];
	void main(int n){
		dp[0][1]=1;
		for(int i=0;i<=n;++i){
			for(int j=1;j<=n;++j)if(dp[i][j]){
				for(int k=j;i+k<=n;++k){
					(dp[i+k][k]+=dp[i][j])>=p?dp[i+k][k]-=p:0;
				}
			}	
		}
		int s=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)(s+=dp[i][j])>=p?s-=p:0;
		}
		write(s,'\n');
	}
}
namespace solve2{
	const int p=998244353;
	map<pair<int,pii> ,int>dp;
	int n;
	int calc(int x,int atl,int y){
		chkmin(atl,y/x);
		if(!atl)return 1;
		pair<int,pii> mkp=make_pair(x,make_pair(atl,y));	
		if(dp.count(mkp))return dp[mkp];
		int s=calc(x+1,atl,y-x*atl)+calc(x,atl-1,y);
		if(s>=p)s-=p;
		return dp[mkp]=s;
	}
	void main(int N){
		n=N;
		write((calc(1,n,n)+p-1)%p,'\n');
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(n,k);
	
	if(k==1)solve1::main(n);
	else if(k==2)solve2::main(n);
	else{
		dfs(n,1);
		write(ans,'\n');
	}
	return 0;
}