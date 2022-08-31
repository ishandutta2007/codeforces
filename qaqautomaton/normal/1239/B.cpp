/*
Author: QAQ Automaton
Lang: C++
Prog: B.cpp
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
		while(!(*x=='\n'||*x==' '||*x=='\r'||*x==EOF))*(++x)=gc();
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
int inf;
struct _init_{
    _init_(){
        memset(&inf,0x3f,sizeof(inf));
    }
};
_init_ ___INIT__;
char s[300005];
int qz[300005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	int n;
	read(n);
	read(s+1);
	int mn=0,cnt=0;
	for(int i=1;i<=n;++i){
		qz[i]=qz[i-1]+(s[i]=='('?1:-1);
		if(chkmin(mn,qz[i]))cnt=0;
		if(mn==qz[i])++cnt;
	}
	if(qz[n])return write("0\n1 1\n");
	int mx=cnt,a=1,b=1,x=0,y=0;
	for(int i=1;i<=n;++i){
		if(qz[i]==mn){
			if(!x)x=i;
			y=i;
		}	
	}
	if(y<n){
		int c=0;
		for(int i=1;i<=n;++i)c+=(i<x||y<i)&&qz[i]==mn+1;
		if(chkmax(mx,c)){a=x;b=y+1;}
	}
	x=0;y=0;
	for(int i=1;i<=n;++i){
		if(qz[i]==mn||qz[i]==mn+1){
			if(!x)x=i;
			y=i;
		}	
	}
	++y;
	while(y<=n && s[y]!='(')++y;
	while(x && s[x]!=')')--x;
	if(y<=n && x){
		int c=0;
		for(int i=1;i<=n;++i)c+=((i<x||y<=i) && qz[i]==mn+2)||((x<=i && i<y && qz[i]==mn));
		if(chkmax(mx,c)){a=x;b=y;}
	}
	int las=0,c=-inf;
	for(int i=1;i<=n;++i){
		if(s[i]==')')if(chkmax(mx,c)){a=las;b=i;}
		if(qz[i]==mn){
			c=-inf;
		}
		else{
			if(s[i]=='('){
				if(chkmax(c,0))las=i;
			}
			if(qz[i]==mn+1)++c;
		}
	}
	las=0,c=-inf;
	for(int i=1;i<=n;++i){
		if(s[i]==')')if(chkmax(mx,c+cnt)){a=las;b=i;}
		if(qz[i]==mn||qz[i]==mn+1){
			c=-inf;
		}
		else{
			if(s[i]=='('){
				if(chkmax(c,0))las=i;
			}
			if(qz[i]==mn+2)++c;
		}
	}
	write(mx,'\n',a,' ',b,'\n');
	return 0;
}