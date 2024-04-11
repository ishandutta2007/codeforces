/*
Author: QAQAutoMaton
Lang: C++
Code: E.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
#define debug(qaq...) fprintf(stderr,qaq)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())
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
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
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
namespace run{
	int a[100005],c[100005],s[100005];
	vector<int> b[100005];
	int id[100005],rql[100005],okr[100005];
	int req[100005];
	int lsp[100005],rk[100005];
	bool main(){
		int n,m;
		read(n,m);
		for(int i=1;i<=n;++i){
			read(a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=m;++i){
			read(c[i]);
			b[i].resize(c[i]);s[i]=0;
			for(int j=0;j<c[i];++j){read(b[i][j]);s[i]+=b[i][j];}
			id[i]=i;
		}
		sort(id+1,id+m+1,[](int x,int y){return s[x]*c[y]<s[y]*c[x];});
		for(int i=1;i<=m;++i)rk[id[i]]=i;
		int j=1;
		rql[id[1]]=0;
		lsp[id[1]]=0;
		int lp=0;
		for(int i=1;i<m;++i){
			int x=id[i];
			while(j<=n && a[j]*c[x]<s[x]){
				lp=j;
				++j;
			}
			rql[id[i+1]]=j;
			lsp[id[i+1]]=lp;
			++j;
		}
		int cur=n;
		for(int i=1;i<=m;++i)okr[i]=0;
		okr[id[m]]=n;
		for(int i=m;i>1;--i){
			int x=id[i];
			if(a[n-m+i-1]*c[x]<s[x]){
				if(a[n-m+i]*c[x]<s[x]){break;}
				cur=n-m+i-1;
			}
			okr[id[i-1]]=cur;
		}
		for(int i=1;i<=m;++i){
			if(rql[i]+(m-rk[i])<=n && okr[i] && ((okr[i]>rql[i] && rql[i]+(m-rk[i]+1)<=n) || lsp[i])){
				int v=(okr[i]>rql[i] && rql[i]+(m-rk[i]+1)<=n)?okr[i]:lsp[i];
				for(int j=0;j<c[i];++j){
					putc(((s[i]-b[i][j])<=a[v]*(c[i]-1))+'0');
				}
			}	
			else{
				for(int j=1;j<=c[i];++j)putc('0');
			}
		}
		putc('\n');
		return 0;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t){
		run::main();
	}
	return 0;
}