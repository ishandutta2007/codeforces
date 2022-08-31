/*
Author: QAQ Automaton
LANG: C++
PROG: E1.cpp
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
int a[4][105];
pii b[405];
pii od[5];
bool chk(pii a,pii b,pii c,pii d){
	od[0]=a;od[1]=b;od[2]=c;od[3]=d;
	sort(od,od+4,[](pii a,pii b){return a.y<b.y ||( a.y==b.y && a.x<b.x);});
	return !(
			od[0].y==od[1].y && od[2].y==od[3].y
			&&((od[0].x^od[1].x^od[2].x^od[3].x)&1)
			);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E1.in","r",stdin);
	freopen("E1.out","w",stdout);
#endif
	int n,m;
	int t;
	read(t);
	for(;t;--t){
		read(n,m);
		for(int i=0;i<n;++i)for(int j=1;j<=m;++j)read(a[i][j]);
		int t=0;
		for(int i=0;i<n;++i)for(int j=1;j<=m;++j)b[++t]=make_pair(i,j);
		sort(b+1,b+t+1,[](pii x,pii y){return a[x.x][x.y]>a[y.x][y.y];});
		if(n<4){
			int ans=0;
			for(int i=1;i<=n;++i)ans+=a[b[i].x][b[i].y];
			write(ans,'\n');
			continue;
		}
		int m=min(t,20),ans=0;
		for(int i=1;i<=m;++i)for(int j=i+1;j<=m;++j)for(int k=j+1;k<=m;++k)for(int l=k+1;l<=m;++l){
			if(chk(b[i],b[j],b[k],b[l]))chkmax(ans,
					a[b[i].x][b[i].y]+
					a[b[j].x][b[j].y]+
					a[b[k].x][b[k].y]+
					a[b[l].x][b[l].y]);
		}
		write(ans,'\n');
	}
	return 0;
}