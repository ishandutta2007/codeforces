/*
Author: QAQ Automaton
LANG: C++
PROG: E.cpp
Mail: cnyalilk@vip.qq.com
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
char s[1000005],t[1000005];
int len=0;
int f1[1000005],g1[1000005],inv1[1000005],pw1[1000005];
int f2[1000005],g2[1000005],inv2[1000005],pw2[1000005];
int p1=998244353,p2=1000000007;
int fpm(int a,int b,int p){
	int c=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
void append(char c){
	t[len]=c;
	f1[len]=c*pw1[len];
	f2[len]=c*pw2[len];
	if(len){
		f1[len]+=f1[len-1];
		f2[len]+=f2[len-1];
	}
	f1[len]%=p1;
	f2[len]%=p2;
	++len;
}
void init_s_hash(){
	int l=strlen(s);
	for(int i=0;i<l;++i){ g1[i]=s[i]*pw1[i];	
		g2[i]=s[i]*pw2[i];	
		if(i){
			g1[i]+=g1[i-1];
			g2[i]+=g2[i-1];
		}
		g1[i]%=p1;
		g2[i]%=p2;
	}
}
int same(int l1,int l2,int r1,int r2){
	return ((f1[l2]-(l1?f1[l1-1]:0)+p1)*inv1[l1]%p1==(g1[r2]-(r1?g1[r1-1]:0)+p1)*inv1[r1]%p1)
		&& ((f2[l2]-(l1?f2[l1-1]:0)+p2)*inv2[l1]%p2==(g2[r2]-(r1?g2[r1-1]:0)+p2)*inv2[r1]%p2);
}

void append(char *s){
	init_s_hash();
	int l=strlen(s);
	for(int i=l-1;~i;--i)if(len>i && same(len-i-1,len-1,0,i)){
		for(int j=i+1;j<l;++j){
			append(s[j]);
		}
		return;
	}
	for(int i=0;i<l;++i)append(s[i]);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n;
	read(n);
	pw1[0]=pw2[0]=1;
	inv1[0]=inv2[0]=1;
	int i1=fpm(17,p1-2,p1);
	int i2=fpm(13,p2-2,p2);
	for(int i=1;i<=1000000;++i){
		pw1[i]=pw1[i-1]*17%p1;
		pw2[i]=pw2[i-1]*13%p2;
		inv1[i]=inv1[i-1]*i1%p1;
		inv2[i]=inv2[i-1]*i2%p2;
	}
	for(int i=1;i<=n;++i){
		read(s);
		append(s);
	}
	write(t,'\n');
	return 0;
}