/*
Author: QAQAutomaton
Lang: C++
Code: C.cpp
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
const int inf=0x6fffffffffffffff;
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
int n;
int a[100005],b[100005],c[100005];
/*
 a+b-c-r <=  x+y-z <= r+a+b-c
 a-b+c-r <=  x-y+z <= r+a-b+c
-a+b+c-r <= -x+y+z <= r-a+b+c
 a+b+c-r <=  x+y+z <= r+a+b+c
*/
bool chk(int r){
	int al=-inf,ar=inf,bl=-inf,br=inf,cl=-inf,cr=inf,dl=-inf,dr=inf;
	for(int i=1;i<=n;++i){
		chkmin(ar,a[i]+b[i]-c[i]+r);
		chkmax(al,a[i]+b[i]-c[i]-r);
		chkmin(br,a[i]-b[i]+c[i]+r);
		chkmax(bl,a[i]-b[i]+c[i]-r);
		chkmin(cr,-a[i]+b[i]+c[i]+r);
		chkmax(cl,-a[i]+b[i]+c[i]-r);
		chkmin(dr,a[i]+b[i]+c[i]+r);
		chkmax(dl,a[i]+b[i]+c[i]-r);
	}
	if(al>ar || bl>br || cl>cr || dl>dr)return 0;
	int l1,r1,l2,r2,l3,r3,l4,r4;
	l1=al,r1=ar,l2=bl,r2=br,l3=cl,r3=cr,l4=dl,r4=dr;
	if(l1&1)++l1;if(r1&1)--r1;
	if(l2&1)++l2;if(r2&1)--r2;
	if(l3&1)++l3;if(r3&1)--r3;
	if(l4&1)++l4;if(r4&1)--r4;
	if(l1<=r1 && l2<=r2 && l3<=r3 && l4<=r4 &&max(l1+l2+l3,l4)<=min(r1+r2+r3,r4))return 1;
	l1=al,r1=ar,l2=bl,r2=br,l3=cl,r3=cr,l4=dl,r4=dr;
	if(~l1&1)++l1;if(~r1&1)--r1;
	if(~l2&1)++l2;if(~r2&1)--r2;
	if(~l3&1)++l3;if(~r3&1)--r3;
	if(~l4&1)++l4;if(~r4&1)--r4;
	if(l1<=r1 && l2<=r2 && l3<=r3 && l4<=r4 &&max(l1+l2+l3,l4)<=min(r1+r2+r3,r4))return 1;
	return 0;
}
bool check(int l1,int r1,int l2,int r2,int l3,int r3,int l4,int r4){
	int X,Y,Z;
	l4-=l1+l2+l3;
	if(l4<0){
		X=Y=Z=0;
	}
	else{
		r1-=l1;r2-=l2;r3-=l3;
		X=min(r1,l4);
		l4-=X;
		Y=min(r2,l4);
		l4-=Y;
		Z=min(r3,l4);
		l4-=Z;
	}
	X+=l1;Y+=l2;Z+=l3;
	bool sign=X&1;
	X>>=1;Y>>=1;Z>>=1;
	write(X+Y+sign,' ',X+Z+sign,' ',Y+Z+sign,'\n');
	return 1;
}
bool make(int r){
	int al=-inf,ar=inf,bl=-inf,br=inf,cl=-inf,cr=inf,dl=-inf,dr=inf;
	for(int i=1;i<=n;++i){
		chkmin(ar,a[i]+b[i]-c[i]+r);
		chkmax(al,a[i]+b[i]-c[i]-r);
		chkmin(br,a[i]-b[i]+c[i]+r);
		chkmax(bl,a[i]-b[i]+c[i]-r);
		chkmin(cr,-a[i]+b[i]+c[i]+r);
		chkmax(cl,-a[i]+b[i]+c[i]-r);
		chkmin(dr,a[i]+b[i]+c[i]+r);
		chkmax(dl,a[i]+b[i]+c[i]-r);
	}
	int l1,r1,l2,r2,l3,r3,l4,r4;
	l1=al,r1=ar,l2=bl,r2=br,l3=cl,r3=cr,l4=dl,r4=dr;
	if(l1&1)++l1;if(r1&1)--r1;
	if(l2&1)++l2;if(r2&1)--r2;
	if(l3&1)++l3;if(r3&1)--r3;
	if(l4&1)++l4;if(r4&1)--r4;
	if(l1<=r1 && l2<=r2 && l3<=r3 && l4<=r4 &&max(l1+l2+l3,l4)<=min(r1+r2+r3,r4))return check(l1,r1,l2,r2,l3,r3,l4,r4);
	l1=al,r1=ar,l2=bl,r2=br,l3=cl,r3=cr,l4=dl,r4=dr;
	if(~l1&1)++l1;if(~r1&1)--r1;
	if(~l2&1)++l2;if(~r2&1)--r2;
	if(~l3&1)++l3;if(~r3&1)--r3;
	if(~l4&1)++l4;if(~r4&1)--r4;
	if(l1<=r1 && l2<=r2 && l3<=r3 && l4<=r4 &&max(l1+l2+l3,l4)<=min(r1+r2+r3,r4))return check(l1,r1,l2,r2,l3,r3,l4,r4);
	return 1;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t){
		read(n);
		for(int i=1;i<=n;++i){
			read(a[i],b[i],c[i]);
		}
		int l=0,r=3000000000000000000ll;
		while(l<=r){
			int mid=(l+r)>>1;
			if(chk(mid))r=mid-1;
			else l=mid+1;
		}
		make(r+1);
//		write(r+1,'\n');
	}
	return 0;
}