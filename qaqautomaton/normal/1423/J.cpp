/*
Author: QAQAutomaton
Lang: C++
Code: J.cpp
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
const uint p=1000000007;
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

ull f[7],g[7];
ull o[7][7],z[7][7];
void add1(){
	g[0]=(o[0][0]*f[0]+o[0][1]*f[1]+o[0][2]*f[2]+o[0][3]*f[3]+o[0][4]*f[4]+o[0][5]*f[5]+o[0][6]*f[6])%p;
	g[1]=(o[1][0]*f[0]+o[1][1]*f[1]+o[1][2]*f[2]+o[1][3]*f[3]+o[1][4]*f[4]+o[1][5]*f[5]+o[1][6]*f[6])%p;
	g[2]=(o[2][0]*f[0]+o[2][1]*f[1]+o[2][2]*f[2]+o[2][3]*f[3]+o[2][4]*f[4]+o[2][5]*f[5]+o[2][6]*f[6])%p;
	g[3]=(o[3][0]*f[0]+o[3][1]*f[1]+o[3][2]*f[2]+o[3][3]*f[3]+o[3][4]*f[4]+o[3][5]*f[5]+o[3][6]*f[6])%p;
	g[4]=(o[4][0]*f[0]+o[4][1]*f[1]+o[4][2]*f[2]+o[4][3]*f[3]+o[4][4]*f[4]+o[4][5]*f[5]+o[4][6]*f[6])%p;
	g[5]=(o[5][0]*f[0]+o[5][1]*f[1]+o[5][2]*f[2]+o[5][3]*f[3]+o[5][4]*f[4]+o[5][5]*f[5]+o[5][6]*f[6])%p;
	g[6]=(o[6][0]*f[0]+o[6][1]*f[1]+o[6][2]*f[2]+o[6][3]*f[3]+o[6][4]*f[4]+o[6][5]*f[5]+o[6][6]*f[6])%p;
	f[0]=g[0];f[1]=g[1];f[2]=g[2];f[3]=g[3];f[4]=g[4];f[5]=g[5];f[6]=g[6];
}
void add0(){
	g[0]=(z[0][0]*f[0]+z[0][1]*f[1]+z[0][2]*f[2]+z[0][3]*f[3]+z[0][4]*f[4]+z[0][5]*f[5]+z[0][6]*f[6])%p;
	g[1]=(z[1][0]*f[0]+z[1][1]*f[1]+z[1][2]*f[2]+z[1][3]*f[3]+z[1][4]*f[4]+z[1][5]*f[5]+z[1][6]*f[6])%p;
	g[2]=(z[2][0]*f[0]+z[2][1]*f[1]+z[2][2]*f[2]+z[2][3]*f[3]+z[2][4]*f[4]+z[2][5]*f[5]+z[2][6]*f[6])%p;
	g[3]=(z[3][0]*f[0]+z[3][1]*f[1]+z[3][2]*f[2]+z[3][3]*f[3]+z[3][4]*f[4]+z[3][5]*f[5]+z[3][6]*f[6])%p;
	g[4]=(z[4][0]*f[0]+z[4][1]*f[1]+z[4][2]*f[2]+z[4][3]*f[3]+z[4][4]*f[4]+z[4][5]*f[5]+z[4][6]*f[6])%p;
	g[5]=(z[5][0]*f[0]+z[5][1]*f[1]+z[5][2]*f[2]+z[5][3]*f[3]+z[5][4]*f[4]+z[5][5]*f[5]+z[5][6]*f[6])%p;
	g[6]=(z[6][0]*f[0]+z[6][1]*f[1]+z[6][2]*f[2]+z[6][3]*f[3]+z[6][4]*f[4]+z[6][5]*f[5]+z[6][6]*f[6])%p;
	f[0]=g[0];f[1]=g[1];f[2]=g[2];f[3]=g[3];f[4]=g[4];f[5]=g[5];f[6]=g[6];
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("J.in","r",stdin);
	freopen("J.out","w",stdout);
#endif
	int t;
	ll n;
	read(t);
	for(int i=0;i<7;++i){
		for(int j=0;j<=7;++j){
			if((i+j)&1)++o[(i+j)>>1][i];
			else ++z[(i+j)>>1][i];
		}
	}
	for(;t;--t){
		read(n);
		for(int i=1;i<7;++i)f[i]=0;
		f[0]=1;
		for(int i=0;i<=60;++i){
			if((n>>i)&1)add1();
			else add0();
		}
		write(f[0],'\n');
	}
	return 0;
}