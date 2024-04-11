/*
Author: QAQAutomaton
Lang: C++
Code: F.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
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
const char c[]=".RYB";
int v[129];
int x[1005],y[1005];
bitset<2005> a[2005];
bitset<2005>ans;
char s[129];
int xid[2005];
void Gauss(int n,int m){
	int i=1;
	for(int at=1;at<=m;++at){
		for(int j=i;j<=n;++j)if(a[j][at]){
			swap(a[j],a[i]);break;
		}	
		if(a[i][at]){
			xid[i]=at;
			for(int j=i+1;j<=n;++j)if(a[j][at])a[j]^=a[i];
			++i;
		}
	}
	for(int j=i;j<=n;++j)if(a[j][m+1])exit(write("NO\n"));
	for(;i;--i){
		ans[xid[i]]=a[i][m+1];
		for(int j=i-1;j;--j)if(a[j][xid[i]])a[j]^=a[i];
	}
}
signed main(){

#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	for(int i=0;i<4;++i)v[c[i]]=i;
	int n,q;
	read(n,q);
	int m=0;
	for(int i=1;i<=n;++i){x[i]=2;y[i]=1;}
	for(;q;--q){
		read(s);
		if(!strcmp(s,"RY")){
			int k,id;
			read(k);
			for(;k;--k){
				read(id);
				swap(x[id],y[id]);
			}
		}
		else if(!strcmp(s,"RB")){
			int k,id;
			read(k);
			for(;k;--k){
				read(id);
				x[id]^=y[id];
			}
		}
		else if(!strcmp(s,"YB")){
			int k,id;
			read(k);
			for(;k;--k){
				read(id);
				y[id]^=x[id];
			}
		}
		else{
			int k,id;
			read(k);
			for(;k;--k){
				read(id);
				a[m+1][id*2-1]=x[id]&2;
				a[m+1][id*2]=x[id]&1;
				a[m+2][id*2-1]=y[id]&2;
				a[m+2][id*2]=y[id]&1;
			}
			char ch;
			read(ch);
			a[m+1][n*2+1]=v[ch]&2;
			a[m+2][n*2+1]=v[ch]&1;
			m+=2;
		}
	}
	Gauss(m,n+n);
	write("YES\n");
	for(int i=1;i<=n;++i)putc(c[ans[i*2-1]<<1|ans[i*2]]);
	putc('\n');
	return 0;
}