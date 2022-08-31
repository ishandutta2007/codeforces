/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp
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
const int cy=1000000007,i2=(cy+1)>>1;
struct Z{
	uint x;
	Z(){}
	Z(uint a){
		x=a;
	}
};
inline uint modp(const uint x){
	return x<cy?x:x-cy;
}
inline Z operator+(const Z x1, const Z x2) { return modp(x1.x+x2.x);}
inline Z operator-(const Z x1, const Z x2) { return modp(x1.x+cy-x2.x);}
inline Z operator-(const Z x) {return x.x?cy-x.x:0;}
inline Z operator*(const Z x1, const Z x2) { return static_cast<ull>(x1.x)*x2.x%cy;}
void exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
inline Z Inv(const Z a){
	int x,y;
	exgcd(cy,a.x,x,y);
	return y<0?y+=cy:y;
}
inline Z operator/(const Z x1, const Z x2) { return x1*Inv(x2);}

inline Z &operator++(Z &x1){x1.x==cy-1?x1.x=0:++x1.x;return x1;} 
inline Z &operator--(Z &x1){x1.x?--x1.x:x1.x=cy-1;return x1;}
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }
inline Z fpm(Z a,int b){Z c(1);for(;b;b>>=1,a*=a)if(b&1)c*=a;return c;}
char s[1005];
int v[1005],a[4005];
int p,k,m,n;
Z f[4005][2][2],g[4005][2][2];
Z sum(int l,int r){
	if(l>r)return 0;
	return Z(l+r)*(r-l+1)*i2;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	read(p,k);
	read(s);
	m=strlen(s);
	if(p==1){
		Z c=0;	
		for(int i=0;i<m;++i)c=c*10+(s[i]-'0');
		write((c+1).x,'\n');
	}
	else{
		for(int i=1;i<=m;++i)v[i]=s[m-i]-'0';
		while(m){
			ll x=0;
			for(int i=m;i;--i){
				x=x*10+v[i];
				v[i]=x/p;
				x%=p;
			}
			a[++n]=x;
			while(m&&!v[m])--m;
		}
		f[0][1][0]=1;
		if(k>n)return write("0\n");
		m=0;
		//for(int i=1;i<=n;++i)write(a[i],i==n?'\n':' ');
		Z s1=sum(1,p),s2=sum(1,p-1);
		for(int i=n;i;--i){
			for(int j=0;j<=m;++j){
				g[j][0][0]+=f[j][0][0]*s1+f[j][0][1]*s2+f[j][1][0]*sum(1,a[i])+f[j][1][1]*sum(p-a[i],p-1);
				g[j+1][0][1]+=f[j][0][0]*s2+f[j][0][1]*s1+f[j][1][0]*sum(1,a[i]-1)+f[j][1][1]*sum(p-a[i]+1,p);

				g[j][1][0]+=f[j][1][0]*(a[i]+1)+f[j][1][1]*(p-a[i]-1);
				g[j+1][1][1]+=f[j][1][0]*a[i]+f[j][1][1]*(p-a[i]);
				/* 
				 * f[j][0][0] -> g[j][0][0] (* sum 1..p)
				 * f[j][0][0] -> g[j+1][0][1] (* sum 0..p-1)
				 
				 * f[j][0][1] -> g[j][0][0] (* sum 0..p-1)
				 * f[j][0][1] -> g[j+1][0][1] (* sum 1..p) 
				 
				 * f[j][1][0] -> g[j][0][0] (* sum 1..a[i])
				 * f[j][1][0] -> g[j+1][0][1] (* sum 0..a[i]-1)
				 * f[j][1][0] -> g[j][1][0] (* a[i]+1)
				 * f[j][1][0] -> g[j+1][1][1] (* a[i])
				 
				 * f[j][1][1] -> g[j][0][0] (* sum p-a[i]..p-1)
				 * f[j][1][1] -> g[j+1][0][1] (* sum p-a[i]+1..p)
				 * f[j][1][1] -> g[j][1][0] (* p-a[i]-1)
				 * f[j][1][1] -> g[j+1][1][1] (* p-a[i])
				 * */
			}	
			++m;
			for(int j=0;j<=m;++j){
				#define mk(x,y) f[j][x][y]=g[j][x][y],g[j][x][y]=0
				mk(0,0),mk(0,1),mk(1,0),mk(1,1);
			//	write(f[j][0][0].x,',',f[j][0][1].x,',',f[j][1][0].x,',',f[j][1][1].x,j==m?'\n':' ');
			}
		}
		Z ans(0);
		for(int i=k;i<=m;++i)ans+=f[i][0][0]+f[i][1][0];
		write(ans.x,'\n');
	}
	return 0;
}