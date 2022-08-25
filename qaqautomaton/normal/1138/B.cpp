/*
Author: QAQ Automaton
Lang: C++
Prog: sequence.cpp
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
int s[2][2];
vector<int> as[2][2];
char x[3000005];
char y[3000005];

int n,m;
void push(int a11,int a10,int a01,int a00){
	while(a11){write(as[1][1].back(),' ');as[1][1].pop_back();--a11;}	
	while(a10){write(as[1][0].back(),' ');as[1][0].pop_back();--a10;}	
	while(a01){write(as[0][1].back(),' ');as[0][1].pop_back();--a01;}	
	while(a00){write(as[0][0].back(),' ');as[0][0].pop_back();--a00;}	
	exit(0);
}
void qaql(int a){
	int x10=s[1][0],x01=s[0][1]-(s[1][1]-a-a);
	if(x01<0 || x10<0)return;
	int w=min(x01,x10);
	x01-=w;x10-=w;if(x01+x10>s[0][0])return;
	int ss=(s[0][0]+x01+x10)>>1;
	push(s[1][1]-a,w,x01,ss-x01);
}
void qaqr(int a){
	int x01=s[0][1],x10=s[1][0]-(s[1][1]-a-a);
	if(x01<0 || x10<0)return;
	int w=min(x01,x10);
	x01-=w;x10-=w;if(x01+x10>s[0][0])return;
	int ss=(s[0][0]+x01+x10)>>1;
	push(a,(s[1][1]-a-a)+w,x01,ss-x01);
}

signed main(){
	read(n);
	m=n/2;
	read(x+1);
	read(y+1);
	for(int i=1;i<=n;++i){
		as[x[i]^'0'][y[i]^'0'].push_back(i);
		++s[x[i]^'0'][y[i]^'0'];
	}
	for(int a=0;a+a<=s[1][1];++a){
		qaql(a);
		qaqr(a);
	}
	write("-1\n");
	return 0;
}