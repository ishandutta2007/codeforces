/*
Author: QAQAutoMaton
Lang: C++
Code: D.cpp
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
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
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
int a[300005],gg[300005],pre[300005],suf[300005];
int stk[300005],t;
set<int> st[300005];
void chk(int x,int y){
	if(st[x].count(y)){++gg[x];--gg[x+1];}else {st[x].insert(y);return;}
}
vector<int> v[300005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int T;
	read(T);
	for(;T;--T){
		int n;
		read(n);
		for(int i=1;i<=n;++i){read(a[i]);gg[i]=0;}
		a[n+1]=0;
		stk[t=0]=0;
		for(int i=0;i<=n;++i){
			while(a[stk[t]]>a[i])--t;
			pre[i]=stk[t];stk[++t]=i;
			st[i].clear();
		}
		stk[t=0]=n+1;
		for(int i=n;i;--i){
			while(a[stk[t]]>=a[i])--t;
			suf[i]=stk[t];stk[++t]=i;
		}
		for(int i=1;i<=n;++i){
			if(pre[i]!=i-1 && suf[i]!=i+1){
				++gg[2];--gg[suf[i]-pre[i]-1];
			}
			chk(1,a[i]);
			if(suf[i]-pre[i]!=2)chk(suf[i]-pre[i]-1,a[i]);
		}
		for(int i=1;i<=n;++i)v[i].clear();
		for(int i=1;i<=n;++i)v[a[i]].emplace_back(i);
		for(int i=1;i<=n;++i){
			int mx=0,se=0;
			for(auto x:v[i]){
				int s=suf[x]-pre[x]-1;
				if(mx<s){se=mx;mx=s;}
				else chkmax(se,s);
			}
			if(n-i+2<=mx){++gg[n-i+2];--gg[mx+1];}
			++gg[1];--gg[se+1];
		}
		for(int i=1;i<=n;++i){gg[i]+=gg[i-1];putc(gg[i]?'0':'1');}
		putc('\n');
	}
	return 0;
}