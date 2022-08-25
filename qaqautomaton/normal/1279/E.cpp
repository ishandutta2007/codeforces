/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp 
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
		while(!(*x=='\n'||*x=='\r'))*(++x)=gc();
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
const int inf=1e18+1;
int mul(int a,int b){
	if(!a)return 0;
	return inf/a<=b?inf:a*b;
}
int sum(int a,int b){
	return min(a+b,inf);
}
int fac[55],f[55],hv[55],p[55],fa[55];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int Qc(int x){return x?fac[x-1]:1;}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int t,n=50,k;
	read(t);
	fac[0]=fac[1]=1;
	for(int i=2;i<=n;++i)
		fac[i]=mul(fac[i-1],i);
	f[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			f[i]=sum(f[i],mul(f[i-j],Qc(j-1)));
		}
	}
	for(;t;--t){
		read(n,k);	
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<=n;++i)hv[i]=p[i]=0;
		for(int at=0;at<n;){
			int j;
			for(j=at+1;j<=n;++j)if(mul(Qc(j-at-1),f[n-j])>=k){
				fa[j]=at+1;
				p[at+1]=j;
				hv[j]=1;
				for(int i=at+2;i<=j;++i){
					int w=mul(Qc(j-i),f[n-j]);
					for(int l=at+1;l<=j;++l)if(!hv[l] && (i==j||l!=find(i))){
						if(w<k){k-=w;}	
						else{p[i]=l;fa[find(l)]=find(i);hv[l]=1;break;}
					}
				}
				break;		
			}else k-=mul(Qc(j-at-1),f[n-j]);
			if(j>n){k=-1;break;}
			at=j;
		}
		if(~k)
		for(int i=1;i<=n;++i)write(p[i],i==n?'\n':' ');
		else write("-1\n");
	}
	return 0;
}