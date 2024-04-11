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
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef std::complex<double> cp;
typedef std::pair<int,int> pii;
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
		memset(&inf,0x3f,sizeof(inf));
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

const int p=1000000007;
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
Z pr,fac[100005],inv[100005],invf[100005];
Z pw1[100005],pw2[100005],w[100005],ws[100005];
Z f[1505][1505],g[1505][1505];
Z fs1[1505][1505],fs2[1505][1505],fs3[1505][1505],gs[1505][1505];
//f[i][j] ai=j,ai-1<=ai
//g[i][j] ai=j,ai-1>ai>ai+1
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,m,a,b,k;
	read(n,m,a,b,k);
	pr=a/Z(b);
	fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;
	for(int i=2;i<=k;++i){fac[i]=fac[i-1]*i;inv[i]=(p-p/i)*inv[p%i];invf[i]=inv[i]*invf[i-1];}
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=k;++i){
		pw1[i]=pw1[i-1]*pr;
		pw2[i]=pw2[i-1]*(1-pr);
	}
	for(int i=0;i<=k;++i)w[i]=pw1[i]*pw2[k-i]*fac[k]*invf[i]*invf[k-i];
	ws[0]=w[0];
	for(int i=1;i<=m;++i)ws[i]=ws[i-1]+w[i];
	--m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			fs2[i][j]+=fs2[i][j-1];
			fs3[i][j]+=fs3[i][j-1];
			gs[i][j]+=gs[i][j-1];
		}
		if(i>1)for(int j=0;j<=m;++j)f[i][j]=fs2[i][j]*ws[m-j]+fs3[i][j]*ws[j];
		else for(int j=0;j<=m;++j)f[i][j]=1;
		for(int j=0;j<=m;++j)g[i][j]=gs[i][j];
		for(int j=0;j<=m;++j){
			f[i][j]*=w[j];	
			g[i][j]*=w[j];
			//ai+1>=ai
			fs2[i+1][j]+=f[i][j];
			//ai>ai+1>ai+2
			Z s=f[i][j]*ws[m-j]*ws[m-j]+g[i][j]*ws[m-j];
			gs[i+1][0]+=s;
			gs[i+1][j]-=s;
			//ai>ai+1<=ai+2
			if(j){
				Z s(f[i][j]*ws[m-j]*ws[m-j]+g[i][j]*ws[m-j]);
				fs3[i+2][0]+=s;fs3[i+2][j]-=s;
				s=f[i][j]*ws[m-j]*ws[j-1]+g[i][j]*ws[j-1];
				fs2[i+2][j]+=s;
			}
		}
	}
	Z ans(0);
	for(int j=0;j<=m;++j){
		ans+=f[n][j]*ws[m-j];
		ans+=g[n][j];
	}
	write(ans.x,'\n');
	return 0;
}

/*
1000
1000
1
2
100000
112428641
 * */