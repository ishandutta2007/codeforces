/*
Author: QAQ Automaton
Lang: C++
Prog: E.cpp
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
struct sq{
	int xl,yl,xr,yr;
};
sq a[100005];
int m1,m2;
int b[200005],c[200005];
int d[200005],e[200005];
int s[200005];
bool split(int,int);
bool splitx(int,int,int);
bool splity(int,int,int);
bool split(int l,int r){
/*	write("===\n");
	for(int i=l;i<=r;++i){
		write(a[i].xl,' ',a[i].yl,' ',a[i].xr,' ',a[i].yr,'\n');
	}
	write("===\n");*/
	if(l==r)return 1;
	for(int i=1;i<=m1;++i)b[i]=d[i]=0;
	for(int i=1;i<=m2;++i)c[i]=e[i]=0;
	for(int i=l;i<=r;++i){
		++b[a[i].xl];
		--b[a[i].xr];
		++c[a[i].yl];
		--c[a[i].yr];
		++d[a[i].xl];
		++e[a[i].yl];
	}
	for(int i=1;i<=m1;++i){
		b[i]+=b[i-1];
		d[i]+=d[i-1];
		if(d[i] && d[i]<=(r-l) && !b[i])return splitx(l,r,i);
	}
	for(int i=1;i<=m2;++i){
		c[i]+=c[i-1];
		e[i]+=e[i-1];
		if(e[i] && e[i]<=(r-l) && !c[i])return splity(l,r,i);
	}
//	write("GG!\n");
	return 0;
}
bool splitx(int l,int r,int s){
//	write("Split on x=",s,'\n');
	int al=l,ar=r;
	while(l<r){
		while(l<r && a[l].xr<=s)++l;
		while(l<r && a[r].xl>s)--r;
		if(l<r){
			swap(a[l],a[r]);
			++l;--r;
		}
	}
	if(a[r].xl>s)--r;
	return split(al,r) && split(r+1,ar);
}
bool splity(int l,int r,int s){
//	write("Split on y=",s,'\n');
	int al=l,ar=r;
	while(l<r){
		while(l<r && a[l].yr<=s)++l;
		while(l<r && a[r].yl>s)--r;
		if(l<r){
			swap(a[l],a[r]);
			++l;--r;
		}
	}
	if(a[r].yl>s)--r;
	return split(al,r) && split(r+1,ar);
}

signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n;
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i].xl,a[i].yl,a[i].xr,a[i].yr);
		++a[i].xl;++a[i].yl;
		b[i*2-1]=a[i].xl;
		b[i*2]=a[i].xr;
		c[i*2-1]=a[i].yl;
		c[i*2]=a[i].yr;
	}
	sort(b+1,b+n+n+1);
	m1=unique(b+1,b+n+n+1)-b-1;
	sort(c+1,c+n+n+1);
	m2=unique(c+1,c+n+n+1)-c-1;
	for(int i=1;i<=n;++i){
		a[i].xl=lower_bound(b+1,b+m1+1,a[i].xl)-b;
		a[i].xr=lower_bound(b+1,b+m1+1,a[i].xr)-b;
		a[i].yl=lower_bound(c+1,c+m2+1,a[i].yl)-c;
		a[i].yr=lower_bound(c+1,c+m2+1,a[i].yr)-c;
	}
	write(split(1,n)?"YES\n":"NO\n");
	return 0;
}