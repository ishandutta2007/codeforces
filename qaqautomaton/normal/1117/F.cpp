/*
Author: QAQ-Automaton
LANG: C++
PROG: F.cpp
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
int a[100005],ok[18][18],fnd[18],qwq[18][18],gg[17][17][1<<17],f[1<<17],hv[18][18];
char s[100005];
int main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,p;
	read(n,p);
	read(s+1);
	for(int i=1;i<=n;++i)a[i]=s[i]-'a';
	for(int i=0;i<p;++i)for(int j=0;j<p;++j)read(ok[i][j]);
	for(int i=n;i;--i){
		for(int j=0;j<p;++j)if(!ok[a[i]][j] && hv[a[i]][j]){
			gg[a[i]][j][qwq[a[i]][j]]=1;
		}		
		for(int j=0;j<p;++j)for(int k=0;k<p;++k){
			qwq[j][k]|=1<<a[i];
		}
		for(int j=0;j<p;++j){
			qwq[j][a[i]]=qwq[a[i]][j]=0;
			hv[a[i]][j]=0;
		}
		for(int j=0;j<p;++j)hv[j][a[i]]=1;
		++fnd[a[i]];
	}
	int w1=(1<<p)-1,w2,w3,w;

	for(int i=0;i<p;++i){
		for(int j=0;j<p;++j){
			w2=w1^((1<<i) | (1<<j));
			for(int x=w2;x;x&=x-1){
				w3=x&-x;
				for(int y=w2^w3;y;y=(y-1)&(w2^w3)){
					gg[i][j][y|w3]|=gg[i][j][y];
				}
			}
			for(int k=w2;k;k=(k-1)&w2){
				f[k]|=gg[i][j][k];
			}
		}
	}	
	int ans=n;
	
	for(int i=1;i<=w1;++i){
		if(!f[i]){
			f[i]=1;
			for(int j=0;j<p;++j)if(i&(1<<j) && !f[i^(1<<j)])f[i]=0;
			if(!f[i]){
				int cnt=n;
				for(int j=0;j<p;++j)if(i&(1<<j))cnt-=fnd[j];
				chkmin(ans,cnt);
			}
		}
	}
	write(ans,'\n');
	return 0;
}