/*
Author: QAQAutomaton
Lang: C++
Code: G.cpp
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
int a[55],b[55],l[55];
const int p=998244353;
int n,m,x,k,pw=0;	
void insert(int x){
	for(int i=m-1;~i;--i)if(x&(1ll<<i)){
		if(!l[i]){
			l[i]=x;
			for(int j=0;j<i;++j)if(l[i]&(1ll<<j))l[i]^=l[j];
			for(int j=i+1;j<m;++j)if(l[j]&(1ll<<i))l[j]^=l[i];
			return;
		}
		else{
			x^=l[i];
		}
	}
	++pw;
}
int f1[1<<20|5],f2[1<<20|5];
int cnt[55];
void dp(int *a,int k,int *cnt){
	int m=min(k,14),m2=k-m;
	for(int i=0;i<m;++i)f1[1<<i]=a[i+1];
	for(int i=0;i<m2;++i)f2[1<<i]=a[i+m+1];
	for(int i=1;i<1<<m;++i)if(i&(i-1))f1[i]=f1[i&(i-1)]^f1[i&(-i)];
	for(int i=1;i<1<<m2;++i)if(i&(i-1))f2[i]=f2[i&(i-1)]^f2[i&(-i)];
	for(int i=0;i<1<<m;++i)for(int j=0;j<1<<m2;++j)++cnt[__builtin_popcount(i)+__builtin_popcount(j)+__builtin_popcountll(f1[i]^f2[j])];
}
int xc[55];
int w[55][55];
int c[55];
int C[55][55];
void make(int *a,int *b,int k){
	for(int i=0;i<k;++i)a[i]=a[i+1]<<k|1ll<<i;
	for(int i=0;i<m;++i)c[i]=1ll<<i;
	for(int i=0;i<k;++i){
		for(int j=i+1;j<m;++j)if(__builtin_parityll(a[i]&c[j]))c[j]^=c[i];
	}
	for(int i=1;i<=(m-k);++i)b[i]=c[i+k-1]&((1LL<<k)-1);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	read(n,m);
	for(int i=1;i<=n;++i){
		read(x);
		insert(x);
	}
	for(int i=0;i<m;++i)if(l[i]){
		++k;
		int L=0;
		for(int j=0;j<i;++j)if(!l[j]){
			if(l[i]&(1ll<<j))a[k]|=1LL<<L;
			++L;	
		}
	}
	if(k<=27){
		dp(a,k,cnt);
		int s=1;
		for(;pw;--pw)s=(s<<1)%p;
		for(int i=0;i<=m;++i)write(cnt[i]*s%p,i==m?'\n':' ');
	}
	else{
		make(a,b,k);
		dp(b,m-k,xc);pw+=k;pw-=m;
		for(int i=0;i<=m;++i){
			C[i][0]=C[i][i]=1;
			for(int j=1;j<i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
		}
		for(int i=0;i<=m;++i){
			for(int j=0;j<=m;++j){
				for(int k=0;k<=i && k<=j;k+=2){
					w[i][j]=(w[i][j]+C[i][k]*C[m-i][j-k])%p;
				}
				for(int k=1;k<=i && k<=j;k+=2){
					w[i][j]=(w[i][j]-C[i][k]*C[m-i][j-k])%p;
				}
				if(w[i][j]<0)w[i][j]+=p;
			}
		}	
		int s=1;
		if(pw<0)for(;pw<0;++pw)s=(s*(p+1)>>1)%p;
		else for(;pw;--pw)s=(s<<1)%p;
		for(int i=0;i<=m;++i)for(int j=0;j<=m;++j)cnt[j]=(cnt[j]+xc[i]*w[i][j])%p;
		for(int i=0;i<=m;++i)write(cnt[i]*s%p,i==m?'\n':' ');
	}
	return 0;
}