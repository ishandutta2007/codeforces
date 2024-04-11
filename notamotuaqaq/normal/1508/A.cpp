/*
Author: QAQAutoMaton
Lang: C++
Code: A.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(qaq...) fprintf(stderr,qaq)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())
using namespace std;
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cp;
typedef pair<int,int> pii;
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
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
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
bitset<200005> a,b,c;
char s[200005];
pii wab[200005],wbc[200005],wac[200005];
int t1,t2,t3;
int n;
namespace run{
	void out(int x){
		pii *w;
		bitset<200005> *ax,*bx;
		if(x==1){
			w=wab;
			ax=&a;bx=&b;
		}
		else if(x==2){
			w=wbc;
			ax=&b;bx=&c;
		}
		else{
			w=wac;
			ax=&a;bx=&c;
		}
		w[n+1]={n+n+1,n+n};
		for(int i=1;i<=n+1;++i){
			for(int j=w[i-1].x+1;j<w[i].x;++j)putc((*ax)[j]+'0');
			for(int j=w[i-1].y+1;j<=w[i].y;++j)putc((*bx)[j]+'0');
		}
		putc('\n');
	}
	bool xab(int x,int y){wab[++t1]={x,y};if(t1==n){out(1);return 1;}return 0;}
	bool xbc(int x,int y){wbc[++t2]={x,y};if(t2==n){out(2);return 1;}return 0;}
	bool xac(int x,int y){wac[++t3]={x,y};if(t3==n){out(3);return 1;}return 0;}
	bool main(){
		read(n);
		read(s+1);for(int i=1;i<=n+n;++i)a[i]=s[i]=='1';
		read(s+1);for(int i=1;i<=n+n;++i)b[i]=s[i]=='1';
		read(s+1);for(int i=1;i<=n+n;++i)c[i]=s[i]=='1';
		t1=t2=t3=0;
		int x1=1,x2=1,x3=1;
		while(1){
			if(b[x2]==c[x3]){if(xbc(x2,x3))return 0;++x2;++x3;}
			else{
				if(a[x1]==b[x2]){if(xab(x1,x2))return 0;++x1;++x2;}
				else{if(xac(x1,x3))return 0;++x1;++x3;}
			}
		}
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t){
		run::main();
	}
	return 0;
}