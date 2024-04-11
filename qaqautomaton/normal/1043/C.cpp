/*
Author: CNYALI_LK
LANG: C++
PROG: 1043C.cpp
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
		*x=0;
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
char mxs[1023],mns[1023];
char s1[1023],s2[1023],s3[1023],s4[1023];
int mnf[1023],mxf[1023],f1[1023],f2[1023];

int main(){
#ifdef cnyali_lk
	freopen("1043C.in","r",stdin);
	freopen("1043C.out","w",stdout);
#endif
	int n;
	read(mxs+1);
	n=strlen(mxs+1);
	for(int i=1;i<=n;++i)mns[i]=mxs[i];
	for(int i=2;i<=n;++i){
		for(int j=1;j<=i;++j){
			s1[j]=mns[j];	
			s2[i-j+1]=mxs[j];
			s3[j]=mxs[j];	
			s4[i-j+1]=mns[j];
			f1[j]=mnf[j];f2[j]=mxf[j];
		}
		s1[i+1]=s2[i+1]=s3[i+1]=s4[i+1]=0;
		if(strcmp(s1+1,s2+1)<=0){for(int j=1;j<=i;++j)mns[j]=s1[j];}
		else{for(int j=1;j<=i;++j){mns[j]=s2[j];mnf[j]=f2[j];}mnf[i]=1;}
		if(strcmp(s3+1,s4+1)>=0){for(int j=1;j<=i;++j)mxs[j]=s3[j];}
		else{for(int j=1;j<=i;++j){mxs[j]=s4[j];mxf[j]=f1[j];}mxf[i]=1;}
	}
	for(int i=1;i<=n;++i)printf("%d%c",mnf[i],i==n?'\n':' ');
	return 0;
}