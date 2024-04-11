/*
Author: QAQ-Automaton
LANG: C++
PROG: i.cpp
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
const signed inf=0x3f3f3f3f;
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
int a[3005],b[3005],c[3005],s[3005],tp[3005],wa[3005],wb[3005];
int n,m1,m2;	
int query(int x){
	int w=0;
	for(int i=1;i<=x;++i){tp[c[i]]=1;w+=a[c[i]];}
	for(int i=x+1;i<=n;++i){tp[c[i]]=2;w+=b[c[i]];}
	sort(c+1,c+x+1,cmp_a<wa>);
	sort(c+x+1,c+n+1,cmp_a<wb>);
	for(int i=m1+1;i<=x;++i){w+=wa[c[i]];tp[c[i]]=0;}
	for(int i=x+m2+1;i<=n;++i){w+=wb[c[i]];tp[c[i]]=0;}
	sort(c+1,c+n+1);
	sort(c+1,c+n+1,cmp_a<s>);
	return w;
}
int main(){
#ifdef QAQAutoMaton 
	freopen("i.in","r",stdin);
	freopen("i.out","w",stdout);
#endif
	read(n,m1,m2);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i){
		read(b[i]);
		wa[i]=-a[i];
		wb[i]=-b[i];
		s[i]=b[i]-a[i];
		c[i]=i;
	}
	sort(c+1,c+n+1,cmp_a<s>);
	int ans=0,mid=m1;
	for(int i=m1;i<=n-m2;++i){
		if(chkmax(ans,query(i)))mid=i;	
	}
	query(mid);
	write(ans,'\n');
	for(int i=1;i<=n;++i)if(tp[i]==1)write(i,' ');
	write('\n');
	for(int i=1;i<=n;++i)if(tp[i]==2)write(i,' ');
	write('\n');
	return 0;
}