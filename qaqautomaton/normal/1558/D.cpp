/*
Author: QAQAutoMaton
Lang: C++
Code: D.cpp
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
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
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
int is[200005];
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
namespace treap{
	int w[200005],v[200005],l[200005],r[200005],t,rt=0,siz[200005],c[200005];
	int newNode(int s=1){
		++t;
		w[t]=rnd();
		v[t]=l[t]=r[t]=0;
		siz[t]=c[t]=s;
		return t;
	}
#define push_up(x) siz[x]=siz[l[x]]+siz[r[x]]+c[x]
	int merge(int x,int y){
		if(!x)return y;if(!y)return x;
		if(w[x]>w[y]){r[x]=merge(r[x],y);push_up(x);return x;}
		else {l[y]=merge(x,l[y]);push_up(y);return y;}
	}
	void split(int x,int y,int &u,int &v){ //<=y u >y v
		if(!x){u=v=0;return;}
		if(!y){u=0;v=x;return;}
		if(y==siz[x]){u=x;v=0;return;}
		if(y<=siz[l[x]]){
			v=x;split(x[l],y,u,v[l]);
			push_up(v);
		}
		else{
			y-=siz[l[x]];
			if(y<c[x]){
				assert(1<=y);
				u=newNode(y);
				c[x]-=y;
				v=x;
				u[l]=x[l];x[l]=0;
				push_up(u);push_up(v);
				return;
			}
			y-=c[x];
			u=x;split(x[r],y,u[r],v);
			push_up(u);
		}
	}
}
const int p=998244353;
struct Z{
	uint x;
	Z(){}
	Z(uint a){
		x=a;
	}
};
inline uint modp(const uint x){
	return x<p?x:x-p;
}
inline Z operator+(const Z x1, const Z x2) { return modp(x1.x+x2.x);}
inline Z operator-(const Z x1, const Z x2) { return modp(x1.x+p-x2.x);}
inline Z operator-(const Z x) {return x.x?p-x.x:0;}
inline Z operator*(const Z x1, const Z x2) { return static_cast<ull>(x1.x)*x2.x%p;}
void exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
inline Z Inv(const Z a){
	int x,y;
	exgcd(p,a.x,x,y);
	return y<0?y+=p:y;
}
inline Z operator/(const Z x1, const Z x2) { return x1*Inv(x2);}

inline Z &operator++(Z &x1){x1.x==p-1?x1.x=0:++x1.x;return x1;} 
inline Z &operator--(Z &x1){x1.x?--x1.x:x1.x=p-1;return x1;}
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }
inline Z fpm(Z a,int b){Z c(1);for(;b;b>>=1,a*=a)if(b&1)c*=a;return c;}
Z fac[400005],inv[400005],invf[400005];
namespace run{
	Z C(int a,int b){
		return fac[a]*invf[b]*invf[a-b];
	}
	Z xc(int n,int m){
		return C(n+m-1,m);
	}
	int a[200005],b[200005];
	bool main(){
		int n,m;
		read(n,m);
		int las=0;
		using namespace treap;
		t=0;
		int rt=0;
		for(int i=1;i<=m;++i){
			read(a[i],b[i]);
			if(a[i]>a[i-1]+1)
			rt=merge(rt,newNode(a[i]-a[i-1]-1));
			int l=b[i];
			int x=newNode(1);
			int r1,r2;
			split(rt,l-1,r1,r2);
			if(l!=a[i])v[x]=1;
			int xl=r1;
			while(xl[r])xl=xl[r];
			v[xl]=0;
			rt=merge(r1,merge(x,r2));
		}
		int c=0;
		for(int i=1;i<=t;++i)if(v[i]){
			++c;
		}
		return write(xc(n-c,n).x,'\n');
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int t;
	read(t);
	fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;
	for(int i=2;i<=400000;++i){
		fac[i]=fac[i-1]*i;
		inv[i]=(p-p/i)*inv[p%i];
		invf[i]=inv[i]*invf[i-1];
	}
	for(;t;--t){
		run::main();
	}
	return 0;
}