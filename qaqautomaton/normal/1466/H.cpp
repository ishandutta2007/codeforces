/*
Author: QAQAutoMaton
Lang: C++
Code: H.cpp
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
const int p=1000000007;
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
Z f[45][45];
int s[5005];
bitset<45> v;
int c;
int pw;
int a[45],b[45];
int cur[45],nx[45],af[5005][45];
Z C[45][45];
int c1[5005];
Z dp[5005];
void chai(int x){
	int y=x;
	s[x]=0;
	c1[x]=0;
	for(int i=c;i;--i){
		cur[i]=af[x][i]=y%a[i];
		s[x]+=cur[i]*b[i];
		c1[x]^=cur[i]&1;
		y/=a[i];
	}
}
int get(){
	int w=0;
	for(int i=1;i<=c;++i)w=w*a[i]+nx[i];
	return w;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("H.in","r",stdin);
	freopen("H.out","w",stdout);
#endif
	int n;	
	read(n);
	for(int i=0;i<n;++i){
		f[i][0]=1;
		f[i][1]=1;
		for(int j=1;j<=n;++j)if(j+i!=n)f[i][1]*=j;
		//write(f[i][1].x,i==n-1?'\n':' ');
		for(int j=2;j<=n;++j)f[i][j]=f[i][j-1]*f[i][1];
	}
	for(int i=0;i<=n;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	for(int i=1;i<=n;++i){read(a[i]);}
	for(int i=1;i<=n;++i)if(!v[i]){
		int l=0,j=i;
		while(!v[j]){++l;v[j]=1;j=a[j];}
		++s[l];
	}
	int w(1);
	for(int i=1;i<=n;++i){
		if(s[i]){
			++c;
			a[c]=s[i]+1;
			w*=a[c];
			b[c]=i;
		}	
	}
	dp[0]=1;
	for(int i=1;i<w;++i){
		chai(i);
		//for(int j=1;j<=c;++j)write(cur[j],j==c?'\n':' ');
		for(int j=1;j<=c;++j)nx[j]=0;
		while(1){
			//for(int j=1;j<=c;++j)debug("%d %d\n",cur[j],nx[j]);
			int j=get();
			if(i==j)break;
			Z S(1);
			//for(int j=1;j<=c;++j)assert(nx[j]<=cur[j]);
			for(int j=1;j<=c;++j)S*=C[cur[j]][nx[j]];
			//write(i,' ',j,' ',s[j],' ',s[i]-s[j],' ',f[s[j]][s[i]-s[j]].x,'\n');
			dp[i]+=dp[j]*(c1[i]^c1[j]?1:p-1)*f[s[j]][s[i]-s[j]]*S;
			++nx[1];
			j=1;
			while(j<c && nx[j]>cur[j]){nx[j]=0;++nx[++j];}
		}
		//write(i,':',dp[i].x,'\n');
	}
	write(dp[w-1].x,'\n');
	return 0;
}