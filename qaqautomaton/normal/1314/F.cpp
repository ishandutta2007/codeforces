/*
Author: QAQAutomaton
Lang: C++
Code: F.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
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

/*
int mxv[127];
ull multiply(ull,ull);
ull multiply_powers_of_2(int,int);
int vis[127][127];
ull v[127][127]; 
ull multiply_powers_of_2(int a, int b) {
	if(!a||!b)return 1ull<<(a+b);
	if(vis[a][b])return v[a][b];
	vis[a][b]=1;
    int power = mxv[max(a,b)];
    if (a >= power && b >= power) {
        return v[a][b]=multiply(3ull<<(power-1), multiply_powers_of_2(a - power, b - power));
    } else if (a >= power) {
        return v[a][b]=multiply_powers_of_2(a - power, b) << power;
    } else {
        return v[a][b]=multiply_powers_of_2(a, b - power) << power;
    }
}
ull multiply(ull a,ull b) {
   ull ans = 0;
   for(int p1=0;p1<64;++p1)if(a&(1ull<<p1)){
   	for(int p2=0;p2<64;++p2)if(b&(1ull<<p2)){
          ans = ans^multiply_powers_of_2(p1,p2);
	}
   }
   return ans;
}
*/

int vis[257][257];
ull v[257][257]; 
ull xexp[1<<17|5],xln[65537];
ull mulx(ull x,ull y,int n=64){
	if(x<=1||y<=1)return x*y;
/*	if(x<65536 && y<65536){
		return xexp[xln[x]+xln[y]];
	}*/
	n>>=1;
	//
	ull a=x&((1ull<<n)-1),b=x>>n;
	ull c=y&((1ull<<n)-1),d=y>>n;
	ull ac=mulx(a,c,n),bd=mulx(mulx(b,d,n),1ull<<(n-1),n),abcd=mulx(a^b,c^d,n);
	return ac^bd^((abcd^ac)<<n);
	/*
	 * M=1<<n 
	 * (a+bM)(c+dM)=ac+Mbc+Mad+M^2bd
	 * =ac+M(bc+ad+bd)+M/2 bd
	 * =ac+M((a+b)(c+d)-ac)+M/2 bd
	 * */
}

ull mul(ull x,ull y,int n=64){
	if(x<=1||y<=1)return x*y;
	if(x<65536 && y<65536){
		return xexp[xln[x]+xln[y]];
	}
	n>>=1;
	//
	ull a=x&((1ull<<n)-1),b=x>>n;
	ull c=y&((1ull<<n)-1),d=y>>n;
	ull ac=mul(a,c,n),bd=mul(mul(b,d,n),1ull<<(n-1),n),abcd=mul(a^b,c^d,n);
	return ac^bd^((abcd^ac)<<n);
	/*
	 *M=1<<n 
	 * (a+bM)(c+dM)=ac+Mbc+Mad+M^2bd
	 * =ac+M(bc+ad+bd)+M/2 bd
	 * =ac+M((a+b)(c+d)-ac)+M/2 bd
	 * */
}
ull fpm(ull a,ull b){
	ull c=1;
	for(;b;b>>=1,a=mul(a,a,64))if(b&1)c=mul(c,a,64);
	return c;
}
/*
65536 -> 258
2^64->4294967302
*/
const ull w[]={3,5,17,257,641,65537,6700417};
const ull g=4294967302;
const ull cy=-1ull;
tr1::unordered_map<ull,int> gt;
ull g3k;
ull calc(ull a){
	ull c=cy;	
	ull b=0;
	ull xg=g,x=1;
	for(int i=0;i<6;++i){
	//	debug("%d\n",i);
		c/=w[i];
		ull ng=fpm(a,c),wg=fpm(g,cy/w[i]);
		while(ng!=1){
			a=mul(a,xg);	
			ng=mul(ng,wg);
			b+=x;
		}
		x*=w[i];
		xg=fpm(xg,w[i]);
	}
	for(int i=1;i<=3000;++i){
		b+=3000*x;	
		a=mul(a,g3k);
		if(gt.count(a)){b-=x*gt[a];break;}
	}
	return cy-b;
}
void init(){
	for(int w=1,i=0;!(i&&(w==1));++i,w=mulx(w,258,16)){
		xexp[i]=xexp[i+65535]=w;xln[w]=i;
	}
	ull xg=g;
	for(int i=0;i<6;++i)xg=fpm(xg,w[i]);
	ull w=1;
	for(int i=0;i<=2999;++i){
		gt[w]=i;w=mul(w,xg);
	}
	g3k=w;
}
//#define __float128 __int128
void exgcd(ull a,ull b,ull &d,__float128 &x,__float128 &y){
	if(!b){d=a;x=1;y=0;return;}
	exgcd(b,a%b,d,y,x);
	y-=(a/b)*x;
}
__float128 &add(__float128 &a,__float128 b,ull p){
	a+=b;
	if(a>=p)return a-=p;
	return a;
}
void calc(ull a,ull p,ull b){
	ull d;
	__float128 x,y;
	exgcd(a,p,d,x,y);
	a/=d;p/=d;
	if(b%d){write("-1\n");return;}
	b/=d;
	if(x<eps)x+=p;
	y=0;
	for(;b;b>>=1,add(x,x,p))if(b&1)add(y,x,p);
	write((ull)(y+0.5),'\n');
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int t;
	read(t);
	init();
	ull a,b,c,d;
	for(;t;--t){
		read(a,b);
		c=calc(a);
		d=calc(b);
		if(!d)write(0,'\n');
		else{
			if(!c)write("-1\n");
			else{	
				calc(c,cy,d);
			}
		}
	}
/*	ull x=1ull<<32,w=-1ull;
	while(1){
		debug("%llu\n",x);
		if(fpm(x,w/3)==1 || fpm(x,w/5)==1 || fpm(x,w/17)==1 ||fpm(x,w/257)==1 
			|| fpm(x,w/641)==1||fpm(x,w/65537)==1||fpm(x,w/6700417)==1)++x;
		else break;
	}
	write(x,'\n');*/
	return 0;
}