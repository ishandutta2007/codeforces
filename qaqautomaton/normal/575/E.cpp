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
typedef unsigned uint;
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
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
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
const int N=100000;
pii a[1000005];
int n;
void make(){
	int x,y,r;
	read(x,y,r);
	if(x>=r){
		a[++n]={x-r,y};
	}
	else{
		a[++n]={0,min(y+r-x,N)};
		a[++n]={0,max(y-r+x,0)};
	}
	if(y>=r){
		a[++n]={x,y-r};
	}
	else{
		a[++n]={max(x-(r-y),0),0};
		a[++n]={min(x+(r-y),N),0};
	}
	if(x+r<=N){
		a[++n]={x+r,y};
	}
	else{
		a[++n]={N,min(y+(r-(N-x)),N)};
		a[++n]={N,max(y-(r-(N-x)),0)};
	}

	if(y+r<=N){
		a[++n]={x,y+r};
	}
	else{
		a[++n]={min(x+(r-(N-y)),N),N};
		a[++n]={max(x-(r-(N-y)),0),N};
	}
}
pii b[1000005];
int t;
int c;
pii stk[1000005];
void build(){
	t=0;
	for(int i=1;i<=n;++i){
		while(t>1 && (ll)(a[i].y-stk[t].y)*(a[i].x-stk[t-1].x)<=(ll)(a[i].y-stk[t-1].y)*(a[i].x-stk[t].x))--t;
		stk[++t]=a[i];
	}
	for(int i=1;i<=t;++i)b[++c]=stk[i];
	t=0;
	for(int i=1;i<=n;++i){
		while(t>1 && (ll)(a[i].y-stk[t].y)*(a[i].x-stk[t-1].x)>=(ll)(a[i].y-stk[t-1].y)*(a[i].x-stk[t].x))--t;
		stk[++t]=a[i];
	}
	while(t&&stk[t]==b[c])--t;
	while(t>1){b[++c]=stk[t];--t;}
	t=c;
}
double calc(pii a,pii b,pii c){
	double A,B,C,D,E,F;
	A=2*(a.x-b.x);
	B=2*(a.y-b.y);
	C=(sqr(double(a.x))+sqr(double(a.y)))-(sqr(double(b.x))+sqr(double(b.y)));
	D=2*(a.x-c.x);
	E=2*(a.y-c.y);
	F=(sqr(double(a.x))+sqr(double(a.y)))-(sqr(double(c.x))+sqr(double(c.y)));

	double x,y;
	y=(C*D-A*F)/(B*D-A*E);
	x=(C*E-B*F)/(A*E-B*D);
	return sqr(x-a.x)+sqr(y-a.y);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int m;
	read(m);
	for(int i=1;i<=m;++i){
		make();
	}
	sort(a+1,a+n+1);
	build();
	b[t+1]=b[1];b[t+2]=b[2];
	double ans=0;
	pii x,y,z;
	for(int i=1;i<=t;++i){
		if(chkmax(ans,calc(b[i],b[i+1],b[i+2]))){x=b[i];y=b[i+1];z=b[i+2];}
	}
	write(x.x,' ',x.y,'\n');
	write(y.x,' ',y.y,'\n');
	write(z.x,' ',z.y,'\n');
	return 0;
}