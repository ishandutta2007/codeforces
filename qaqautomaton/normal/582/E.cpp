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
char s[505];
//a 0/1 b 1/2 c 2/4 d 3/8
int x[17],y[17];
Z f[505][1<<16|5];
Z a[1<<16|5],b[1<<16|5],c[1<<16|5];
int t=0;
int w[8];
void fmt_and(Z *a){
	for(int i=0;i<16;++i)for(int j=0;j<1<<16;++j)if(!(j&(1<<i)))a[j]+=a[j|1<<i];
}
void fmt_or(Z *a){
	for(int i=0;i<16;++i)for(int j=0;j<1<<16;++j)if(!(j&(1<<i)))a[j|1<<i]+=a[j];
}
void ifmt_and(Z *a){
	for(int i=0;i<16;++i)for(int j=0;j<1<<16;++j)if(!(j&(1<<i)))a[j]-=a[j|1<<i];
}
void ifmt_or(Z *a){
	for(int i=0;i<16;++i)for(int j=0;j<1<<16;++j)if(!(j&(1<<i)))a[j|1<<i]-=a[j];
}
int dfs(int l,int r){
	int id=++t;
	if(l==r){
		if(s[l]=='?'){
			for(int i=0;i<8;++i)w[i]=0;
			for(int i=0;i<16;++i){
				for(int j=0;j<8;++j){
					w[j]|=(((i>>(j>>1))&1)^(j&1))<<i;
				}
			}
			for(int i=0;i<8;++i)++f[id][w[i]];
		}
		else{
			int x=0;
			for(int i=0;i<16;++i){
				int a=i&1,b=(i>>1)&1,c=(i>>2)&1,d=i>>3;
				if(s[l]=='A')x|=a<<i;else 
				if(s[l]=='a')x|=(!a)<<i;else
				if(s[l]=='B')x|=b<<i;else 
				if(s[l]=='b')x|=(!b)<<i;else
				if(s[l]=='C')x|=c<<i;else 
				if(s[l]=='c')x|=(!c)<<i;else
				if(s[l]=='D')x|=d<<i;else 
				             x|=(!d)<<i;
			}
			f[id][x]=1;
		}
	}
	else{
		int w=0,mid=-1;
		for(int i=l;i<=r;++i){
			if(s[i]=='(')++w;
			if(s[i]==')'){
				--w;
				if(!w){
					mid=i+1;
					break;
				}
			}
		}
		int u=dfs(l+1,mid-2),v=dfs(mid+2,r-1);
		if(s[mid]!='|'){
			for(int i=0;i<65536;++i)a[i]=f[u][i];
			for(int i=0;i<65536;++i)b[i]=f[v][i];
			fmt_and(a);
			fmt_and(b);
			for(int i=0;i<65536;++i)a[i]*=b[i];
			ifmt_and(a);
			for(int i=0;i<65536;++i)f[id][i]+=a[i];
		}
		if(s[mid]!='&'){
			for(int i=0;i<65536;++i)a[i]=f[u][i];
			for(int i=0;i<65536;++i)b[i]=f[v][i];
			fmt_or(a);
			fmt_or(b);
			for(int i=0;i<65536;++i)a[i]*=b[i];
			ifmt_or(a);
			for(int i=0;i<65536;++i)f[id][i]+=a[i];
		}
	}
	return id;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(s+1);
	int n=strlen(s+1);
	dfs(1,n);
	int m;
	read(m);
	for(int i=1;i<=m;++i){
		int a,b,c,d;
		read(a,b,c,d);
		x[i]=a|b<<1|c<<2|d<<3;
		read(y[i]);
	}
	Z ans(0);
	for(int i=0;i<1<<16;++i){
		int ok=1;
		for(int j=1;j<=m;++j)if(!!(i&(1<<x[j]))!=y[j]){ok=0;break;}
		if(ok)ans+=f[1][i];	
	}
	write(ans.x,'\n');
	return 0;


}