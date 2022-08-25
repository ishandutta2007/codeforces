/*
Author: QAQAutomaton
Lang: C++
Code: A.cpp
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
uint p;
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
struct matrix{
	Z a[2][2];
	Z *operator [](const int &b){return a[b];}
	const Z *operator [](const int &b)const{return a[b];}
	matrix(){}
	matrix(Z b){
		a[0][1]=1;a[1][0]=a[1][1]=b;a[0][0]=0;
	}
	matrix(Z x,Z y){
		a[0][0]=x;a[1][0]=y;a[0][1]=a[1][1]=0;
	}
};
matrix operator *(const matrix &a,const matrix &b){
	matrix c;
	c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];
	return c;
}
int vis[1000005];
Z w[50005];
Z a[50005];
pii u[50005];

struct smt{
	matrix s;
	int ls,rs;
	smt *l,*r;
	smt(int la,int ra){
		ls=la;rs=ra;
		if(ls==rs){s=a[ls];return;}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
		s=r->s*l->s;
	}
	void mul(int la,int ra,matrix &cur){
		if(la<=ls && rs<=ra){cur=s*cur;return;}
		if(la<=l->rs)l->mul(la,ra,cur);
		if(r->ls<=ra)r->mul(la,ra,cur);
	}
};
smt *rt;
matrix fpm(matrix a,int b){
	matrix c;
	c[0][0]=c[1][1]=1;c[0][1]=c[1][0]=0;
	for(;b;b>>=1,a=a*a)if(b&1)c=c*a;
	return c;
} 
signed main(){
#ifdef QAQAutoMaton 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	int l;	
	read(l,p);
	int n;
	read(n);
	for(int i=0;i<n;++i){
		read(a[i].x);a[i].x%=p;
	}
	if(!l)return write(0,'\n');
	else if(l==1)return write(a[1%n].x,'\n');
	int m;
	read(m);
	rt=new smt(0,n-1);
	for(int i=1;i<=m;++i){
		read(u[i].x,u[i].y);
		u[i].y%=p;
	}
	sort(u+1,u+m+1);
	matrix f(0,u[1].x==1?u[1].y:a[1%n]);
	int cur=1;
	for(int i=1+(u[1].x==1);i<=m;++i){
		if(u[i].x>=l)break;
		int x=cur/n,y=cur%n,bx=u[i].x/n,by=u[i].x%n;
		if(x==bx){
			if(y+1<by)rt->mul(y+1,by-1,f);
		}
		else{
			if(y<n-1)rt->mul(y+1,n-1,f);
			++x;
			if(x<bx)f=fpm(rt->s,bx-x)*f;
			x=bx;
			if(by)rt->mul(0,by-1,f);
		}
		f=Z(u[i].y)*f;
		cur=u[i].x;
	}
	if(cur<l-1){
		int x=cur/n,y=cur%n,bx=l/n,by=l%n;
		if(x==bx){
			if(y+1<by)rt->mul(y+1,by-1,f);
		}
		else{
			if(y<n-1)rt->mul(y+1,n-1,f);
			++x;
			if(x<bx)f=fpm(rt->s,bx-x)*f;
			x=bx;
			if(by)rt->mul(0,by-1,f);
		}
		cur=l-1;
	}
	write((f[0][0]+f[1][0]).x,'\n');
	return 0;
}