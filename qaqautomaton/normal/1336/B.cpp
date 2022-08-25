/*
Author: QAQAutomaton
Lang: C++
Code: C.cpp
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
int a[100005],b[100005],c[100005];
int calc(int a,int b,int c){
//	write(a,' ',b,' ',c,'\n');
	return sqr(a-b)+sqr(a-c)+sqr(b-c);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t){
	int n,m,k;
	read(n,m,k);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=m;++i)read(b[i]);
	for(int i=1;i<=k;++i)read(c[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	sort(c+1,c+k+1);
	int ans=inf;
	for(int i=1;i<=n;++i){
		int w1=lower_bound(b+1,b+m+1,a[i])-b,w2=w1-1,w3=w1;
		if(b[w1]==a[i])++w3;
		int w4=lower_bound(c+1,c+k+1,a[i])-c,w5=w4-1,w6=w4;
		if(c[w4]==a[i])++w6;
		if(w1<=m){
			if(w4<=k)chkmin(ans,calc(a[i],b[w1],c[w4]));
			if(w5>=1)chkmin(ans,calc(a[i],b[w1],c[w5]));
			if(w6<=k)chkmin(ans,calc(a[i],b[w1],c[w6]));
		}
		if(w2>=1){
			if(w4<=k)chkmin(ans,calc(a[i],b[w2],c[w4]));
			if(w5>=1)chkmin(ans,calc(a[i],b[w2],c[w5]));
			if(w6<=k)chkmin(ans,calc(a[i],b[w2],c[w6]));
		}
		if(w3<=m){
			if(w4<=k)chkmin(ans,calc(a[i],b[w3],c[w4]));
			if(w5>=1)chkmin(ans,calc(a[i],b[w3],c[w5]));
			if(w6<=k)chkmin(ans,calc(a[i],b[w3],c[w6]));
		}
	}
	for(int i=1;i<=n||i<=m;++i)swap(a[i],b[i]);
	swap(n,m);
	for(int i=1;i<=n;++i){
		int w1=lower_bound(b+1,b+m+1,a[i])-b,w2=w1-1,w3=w1;
		if(b[w1]==a[i])++w3;
		int w4=lower_bound(c+1,c+k+1,a[i])-c,w5=w4-1,w6=w4;
		if(c[w4]==a[i])++w6;
		if(w1<=m){
			if(w4<=k)chkmin(ans,calc(a[i],b[w1],c[w4]));
			if(w5>=1)chkmin(ans,calc(a[i],b[w1],c[w5]));
			if(w6<=k)chkmin(ans,calc(a[i],b[w1],c[w6]));
		}
		if(w2>=1){
			if(w4<=k)chkmin(ans,calc(a[i],b[w2],c[w4]));
			if(w5>=1)chkmin(ans,calc(a[i],b[w2],c[w5]));
			if(w6<=k)chkmin(ans,calc(a[i],b[w2],c[w6]));
		}
		if(w3<=m){
			if(w4<=k)chkmin(ans,calc(a[i],b[w3],c[w4]));
			if(w5>=1)chkmin(ans,calc(a[i],b[w3],c[w5]));
			if(w6<=k)chkmin(ans,calc(a[i],b[w3],c[w6]));
		}
	}

	for(int i=1;i<=n||i<=k;++i)swap(a[i],c[i]);
	swap(n,k);

	for(int i=1;i<=n;++i){
		int w1=lower_bound(b+1,b+m+1,a[i])-b,w2=w1-1,w3=w1;
		if(b[w1]==a[i])++w3;
		int w4=lower_bound(c+1,c+k+1,a[i])-c,w5=w4-1,w6=w4;
		if(c[w4]==a[i])++w6;
		if(w1<=m){
			if(w4<=k)chkmin(ans,calc(a[i],b[w1],c[w4]));
			if(w5>=1)chkmin(ans,calc(a[i],b[w1],c[w5]));
			if(w6<=k)chkmin(ans,calc(a[i],b[w1],c[w6]));
		}
		if(w2>=1){
			if(w4<=k)chkmin(ans,calc(a[i],b[w2],c[w4]));
			if(w5>=1)chkmin(ans,calc(a[i],b[w2],c[w5]));
			if(w6<=k)chkmin(ans,calc(a[i],b[w2],c[w6]));
		}
		if(w3<=m){
			if(w4<=k)chkmin(ans,calc(a[i],b[w3],c[w4]));
			if(w5>=1)chkmin(ans,calc(a[i],b[w3],c[w5]));
			if(w6<=k)chkmin(ans,calc(a[i],b[w3],c[w6]));
		}
	}
	write(ans,'\n');
	}
	return 0;
}