/*
Author: CNYALI_LK
LANG: C++
PROG: D.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int,int> pii;
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
    inline void read (int &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
    }
    inline void read (char &x) {
        x=gc();
    }
    inline void read(char *x){
        while((*x=gc())=='\n' || *x==' '||*x=='\r');
        while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
    }
    template<typename A,typename ...B>
    inline void read(A &x,B &...y){
        read(x);read(y...);
    }
    // print a signed integer
    inline void write (int x) {
        if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
        while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
        while (qr) putc (qu[qr --]);
    }
    inline void write (char x) {
        putc(x);
    }
    inline void write(const char *x){
        while(*x){putc(*x);++x;}
    }
    inline void write(char *x){
        while(*x){putc(*x);++x;}
    }
    template<typename A,typename ...B>
    inline void write(A x,B ...y){
        write(x);write(y...);
    }
    //no need to call flush at the end manually!
    struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
int fa[200005],ans[200005],w[200005];
struct edg{
	int u,v,w;
}e[200005];
int cmp(edg a,edg b){return a.w<b.w;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
#ifdef cnyali_lk
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n,m,k,x;	
	read(n,m,k);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=k;++i){read(x);w[x]=1;}
	for(int i=1;i<=m;++i){
		read(e[i].u,e[i].v,e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	int t=n,u,v;
	for(int i=1;i<=m;++i)if(find(e[i].u)!=find(e[i].v)){
		u=find(e[i].u);v=find(e[i].v);	
		w[u]+=w[v];
		fa[v]=u;
		if(w[u]==k){for(int j=1;j<=k;++j)printf("%d%c",e[i].w,j==k?'\n':' ');return 0;}
	}
	return 0;
}