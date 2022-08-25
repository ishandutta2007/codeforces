/*
Author: QAQ-Automaton
LANG: C++
PROG: A.cpp
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
typedef long long ll;
typedef pair<int,int> pii;
#define inf 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
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
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
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
int f[205][205][4][4],lsx[205][205][4][4],lsy[205][205][4][4];
void putans(int a,int b,int c,int d){
	if(c||d){
		putans(a-lsx[a][b][c][d],b-lsy[a][b][c][d],c>=d?c-1:c,c>=d?d:d-1);
		write(lsx[a][b][c][d],':',lsy[a][b][c][d],c+d==1?'\n':' ');
	}
} 
int main(){
#ifdef QAQAutoMaton 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	int t,a,b;
	read(t);
	f[0][0][0][0]=1;
	int mx;
	for(int i=0;i<=200;++i)for(int j=0;j<=200;++j){
		for(int k=0;k<=3;++k)for(int l=0;l<=3;++l){
			if((k==3&&l==3) || (!k && !l))continue;
			if(k>=l){
				if(k==3 && l==2)mx=15;
				else mx=25;
				if(i<mx)continue;
				for(int w=0;w<=mx-2;++w)if(j>=w && f[i-mx][j-w][k-1][l]){
					lsx[i][j][k][l]=mx;
					lsy[i][j][k][l]=w;
					f[i][j][k][l]=1;
				}
				for(int w=mx+1;w<=i;++w)if(j>=w-2 && f[i-w][j-w+2][k-1][l]){
					lsx[i][j][k][l]=w;
					lsy[i][j][k][l]=w-2;
					f[i][j][k][l]=1;
				}
			}			
			else{
				if(k==2 && l==3)mx=15;
				else mx=25;
				if(j<mx)continue;
				for(int w=0;w<=mx-2;++w)if(i>=w && f[i-w][j-mx][k][l-1]){
					lsx[i][j][k][l]=w;
					lsy[i][j][k][l]=mx;
					f[i][j][k][l]=1;
				}
				for(int w=mx+1;w<=j;++w)if(i>=w-2 && f[i-w+2][j-w][k][l-1]){
					lsx[i][j][k][l]=w-2;
					lsy[i][j][k][l]=w;
					f[i][j][k][l]=1;
				}
		
			}
		}	
	}
	for(;t;--t){
		read(a,b);
		bool gg=1;
		for(int i=0;i<=2&&gg;++i){
			if(f[a][b][3][i]){
				write(3,':',i,'\n');
				putans(a,b,3,i);
				gg=0;
			}	
		}
		for(int i=2;i>=0&&gg;--i){
			if(f[a][b][i][3]){
				write(i,':',3,'\n');
				putans(a,b,i,3);
				gg=0;
			}
		}
		if(gg)write("Impossible\n");
	}
	return 0;
}