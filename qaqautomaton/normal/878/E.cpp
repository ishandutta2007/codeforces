/*
Author: QAQ Automaton
Lang: C++
Prog: border.cpp
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
const int p=1000000007,i2=(p+1)>>1;
int a[500005];
int pw[500005],ipw[500005];
int t,ans[500005];
int b[500005],c[500005],siz[500005],w[500005],r[500005],s[500005];
vector<pii> ask[500005];
void append(int x,int id){
	++t;
	siz[t]=(t!=1);
	b[t]=x*pw[siz[t]];
	c[t]=(x*pw[siz[t]]%p+p)%p;
	while(t>1 && b[t]>=0){
		c[t-1]=(c[t-1]+c[t]*pw[siz[t-1]])%p;
		if(b[t]){
			if(((inf>>(siz[t-1]))/b[t])){
				b[t-1]=min(b[t-1]+(b[t]<<(siz[t-1])),inf);
			}
			else b[t-1]=inf;
		}
		siz[t-1]+=siz[t];
		--t;
	}
	r[t]=id;
	s[t]=(s[t-1]+c[t])%p;
}
signed main(){
	int n,q;
	read(n,q);
	pw[0]=ipw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=(pw[i-1]<<1)%p;
	for(int i=1;i<=n;++i)ipw[i]=(ipw[i-1]*i2)%p;
	for(int i=1;i<=n;++i){
		read(a[i]);
		w[i]=((w[i-1]+a[i]*pw[i])%p+p)%p;
	}
	for(int i=1;i<=q;++i){
		int l,r;
		read(l,r);
		ask[r].push_back(make_pair(l,i));
	}
	for(int i=1;i<=n;++i){
		append(a[i],i);	
		for(auto j:ask[i]){
			int x=lower_bound(r+1,r+t+1,j.x)-r;
			ans[j.y]=((s[t]-s[x]+(w[r[x]]-w[j.x-1])*ipw[j.x])%p+p)%p;
		}
	}
	for(int i=1;i<=q;++i)write(ans[i],'\n');
	return 0;
}