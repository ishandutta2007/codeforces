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
int to[5000005][2],t=1;
int cnt[5000005];
void Ins(int x){
	int at=1;
	++cnt[at];
	for(int i=29;~i;--i){
		int c=(x>>i)&1;
		if(!to[at][c])to[at][c]=++t;
		at=to[at][c];
		++cnt[at];
	}
}
int n,s;
Z pw[5000005];
struct xans{
	Z f[2][2];
	xans(){}
	xans(Z a,Z b=0,Z c=0,Z d=0){f[0][0]=a;f[0][1]=b;f[1][0]=c;f[1][1]=d;}
	Z *operator [](const int b){return f[b];}
	const Z *operator [](const int b)const{return f[b];}
	void de(){
		f[0][1]-=f[1][1];f[1][0]-=f[1][1];
		f[0][0]-=f[0][1];f[0][0]-=f[1][0];f[0][0]-=f[1][1];
	}

	void en(){
		f[0][0]+=f[0][1];f[0][0]+=f[1][0];f[0][0]+=f[1][1];
		f[0][1]+=f[1][1];f[1][0]+=f[1][1];
	}
	// atl1 all0
};
xans operator +(const xans &a,const xans &b){
	return {a[0][0]+b[0][0]-1,a[0][1]+b[0][1],a[1][0]+b[1][0],a[1][1]+b[1][1]};
}
xans operator *(xans a,xans b){
	a.de();
	b.de();
	xans res(0,0,0,0);
	for(int i=0;i<2;++i)for(int j=0;j<2;++j)
		for(int k=0;k<2;++k)for(int l=0;l<2;++l)
			res[max(i,k)][max(j,l)]+=a[i][j]*b[k][l];
	res.en();
	return res;
}
xans solve(int x,int y,int c){
	if(!x && !y){
		return {1,0,0,0};
	}
	if(!y){
		return xans{pw[cnt[x]],pw[cnt[x]]-1,0,0};
	}
	if(!x){
		return xans{pw[cnt[y]],0,pw[cnt[y]]-1,0};
	}
	if(c<0){
		return {pw[cnt[x]]*pw[cnt[y]],(pw[cnt[x]]-1)*pw[cnt[y]],pw[cnt[x]]*(pw[cnt[y]]-1),(pw[cnt[x]]-1)*(pw[cnt[y]]-1)};
	}
	if((s>>c)&1){
		xans w=solve(to[x][0],to[y][1],c-1)*solve(to[x][1],to[y][0],c-1);	
		w.de();

		w[0][0]=1;w[0][1]=pw[cnt[x]]-1;w[1][0]=pw[cnt[y]]-1;
		w.en();
		return w;
	}
	else{
		xans a=solve(to[x][0],to[y][0],c-1),b=solve(to[x][1],to[y][1],c-1);

		xans c(0);
		c[1][1]=a[1][1]+b[1][1];
		c[0][0]=1;c[0][1]=pw[cnt[x]]-1;c[1][0]=pw[cnt[y]]-1;
		c.en();
		return c;
	}
}
Z solve(int x,int y){
	if(!x)return 0;
	if(y<0){
		//write(cnt[x],'x');
		return pw[cnt[x]]-1;
	}
	if((s>>y)&1){
		return solve(to[x][0],to[x][1],y-1)[1][1]+(pw[cnt[to[x][0]]]-1)+(pw[cnt[to[x][1]]]-1);
	}
	else{
		return solve(to[x][0],y-1)+solve(to[x][1],y-1);
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("H.in","r",stdin);
	freopen("H.out","w",stdout);
#endif
	read(n,s);
	for(int i=1;i<=n;++i){
		int y;
		read(y);
		Ins(y);
	}
	pw[0]=1;
	for(int i=1;i<=n;++i){pw[i]=pw[i-1]+pw[i-1];}
	write(solve(1,29).x,'\n');
	return 0;
}