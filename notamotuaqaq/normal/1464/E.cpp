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
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char *)(&inf),(unsigned char *)(&inf)+sizeof(inf),0x3f);
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

const uint p=998244353;
struct Z{
	uint x;
	Z(){}
	Z(uint a){x=a;}
    Z& operator++(){x=x==p-1?0:x+1;return *this;}
    Z& operator--(){x=x?x-1:p-1;return *this;}
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
inline Z Inv(const Z x){
	int a,b;
	exgcd(p,x.x,a,b);
	return b<0?b+p:b;
}
inline Z operator/(const Z x1,const Z x2){return x1*Inv(x2);}
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }

vector<int> to[100005];
vector<int> fr[100005];
int ind[100005];
int f[100005];
int c[100005];
Z w[1<<17|5];
void dfs(int x){
	--ind[x];
	for(auto i:to[x])++c[f[i]];
	while(c[f[x]])++f[x];
	for(auto i:to[x])--c[f[i]];
	for(auto i:fr[x])if(!--ind[i])dfs(i);
	++w[f[x]];
}
int l,s;
void fwt(Z *a){
	for(int i=1;i<s;i<<=1)for(int j=0;j<s;j+=i+i)for(int k=0;k<i;++k){
		Z u=a[j+k],v=a[i+j+k];
		a[j+k]=u+v;a[j+k+i]=u-v;
	}
}
void ifwt(Z *a){
	for(int i=1;i<s;i<<=1)for(int j=0;j<s;j+=i+i)for(int k=0;k<i;++k){
		Z u=a[j+k],v=a[i+j+k];
		a[j+k]=u+v;a[j+k+i]=u-v;
	}
	Z iw=Inv(s);
	for(int i=0;i<s;++i)a[i]*=iw;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,m,u,v;
	read(n,m);
	for(int i=1;i<=m;++i){
		read(u,v);
		to[u].emplace_back(v);
		fr[v].emplace_back(u);
		++ind[u];
	}
	for(int i=1;i<=n;++i)if(!ind[i])dfs(i);
	l=0;
	while((1<<l)<n)++l;
	s=1<<l;
	fwt(w);
	for(int i=0;i<(1<<l);++i){
		w[i]=Inv(n+1-w[i]);
		/*x=1/(1-w[i]*x)/(n+1)
		w[i]x^2-x+1=0*/
	}
	ifwt(w);
	Z ans(0);
	for(int i=1;i<(1<<l);++i)ans+=w[i];
	write(ans.x,'\n');
	//write((ans+w[0]).x,'\n');
	return 0;
}