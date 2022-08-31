/*
Author: QAQAutomaton
Lang: C++
Code: F.cpp
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
int a[200005];
mt19937 ran;
vector<int> p;
int isp(int x){
	for(int i=2;i*i<=x;++i)if(!(x%i))return 0;
	return 1;
}
int cnt[20005];
void calc(int &x){
	if(!x)return;
	for(auto i:p){
		if(!(x%i)){
			++cnt[i];
			while(!(x%i))x/=i;
		}
	}
}
int b[600005];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int n,xans;
void test(int x){
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=min((a[i]%x)+(a[i]<x?x:0),x-a[i]%x);	
		if(ans>=xans)return;
	}
	xans=ans;
}

void yf(int &x,int y){
	y=gcd(x,y);
	if(y!=1)x=y;
}
void test2(int x){
	int ans=0;
	for(int i=1;i<=n;++i){
		yf(x,a[i]);
		yf(x,a[i]-1);
		yf(x,a[i]+1);
		int w=min(a[i]%x+(a[i]<x?x:0),x-a[i]%x);	
		ans+=w;
		if(ans>=xans)return;
	}
	xans=ans;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	read(n);
	xans=n;
	ran=mt19937(time(0)^114514);
	for(int i=2;i<=1000;++i)if(isp(i))p.push_back(i);
	for(int i=1;i<=n;++i){
		read(a[i]);
		b[i*3-2]=a[i];
		b[i*3-1]=a[i]-1;
		b[i*3]=a[i]+1;
	}
	for(int i=1;i<=n+n+n;++i)calc(b[i]);
	for(int i=1;i<=1000;++i)if(cnt[i]>=(n+1)>>1)test(i);
	while(clock()<=2*CLOCKS_PER_SEC){
		int x=ran()%(3*n)+1,y=ran()%(3*n)+1;	
		if(x!=y){
			int w=gcd(b[x],b[y]);
			if(w>1000){
				test2(w);		
			}
		}
	}
	write(xans,'\n');
	return 0;
}