/*
Author: QAQ Automaton
Lang: C++
Prog: E.cpp
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
typedef long long ll;
typedef pair<int,int> pii;
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
	// input a signed integer
	inline bool read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}

	inline bool read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		x=gc();
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'||*x==EOF))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	// print a signed integer
	inline bool write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}

	inline bool write (long long x) {
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
int inf;
struct _init_{
    _init_(){
        memset(&inf,0x3f,sizeof(inf));
    }
};
_init_ ___INIT__;
int a[20005],b[20005];
int f[40005],beg[20005];
vector<int> poly[40005];
int t;
const int p=998244353,g=3;
int rev[1<<18];
int fpm(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
void NTT(vector<int> &a,int n,int flg){
	for(int i=0;i<n;++i){
		rev[i]=(rev[i>>1]>>1)|((i&1)*(n>>1));
		if(i<rev[i])swap(a[i],a[rev[i]]);
	}
	for(int i=1;i<n;i<<=1){
		int ww=fpm(g,(p-1)/i/2*(flg+p-1)),w;
		for(int j=0;j<n;j+=i+i){
			w=1;
			for(int k=0;k<i;++k){
				int u=a[j+k],v=a[j+k+i]*w%p;
				a[j+k]=(u+v)%p;
				a[j+k+i]=(u-v+p)%p;
				w=w*ww%p;
			}
		}
	}
	if(flg==-1){
		int in=fpm(n,p-2);
		for(int i=0;i<n;++i)a[i]=a[i]*in%p;
	}
}
void Prod(vector<int> &a,vector<int> &b,vector<int> &c){
	int x=a.size()+b.size(),n=1;
	while(n<x)n<<=1;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	NTT(a,n,1);
	NTT(b,n,1);
	for(int i=0;i<n;++i)c[i]=a[i]*b[i]%p;
	NTT(c,n,-1);
	c.resize(x-1);
	a.clear();b.clear();	

}
int query(int k){
	int l=1;
	while(l<t){
		Prod(poly[l],poly[l+1],poly[++t]);
		l+=2;
	}
	return poly[t][k];
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,k;
	read(n,k);
	for(int i=1;i<=n;++i)read(a[i]);
	int q;
	int tp,x,l,r,d;
	read(q);
	for(;q;--q){
		read(tp,x,l);		
		if(tp==1){
			read(d);
			for(int i=1;i<=n;++i){
				poly[i].clear();
				poly[i].push_back(1);
				poly[i].push_back((x-(i==l?d:a[i])+2*p)%p);
			}
		}
		else{
			read(r,d);
			for(int i=1;i<=n;++i){
				poly[i].clear();
				poly[i].push_back(1);
				poly[i].push_back((x-a[i]+2*p)%p);
			}
			for(int i=l;i<=r;++i)poly[i][1]=(poly[i][1]+2*p-d)%p;
		}
		t=n;
		write(query(k),'\n');
	}
	return 0;
}