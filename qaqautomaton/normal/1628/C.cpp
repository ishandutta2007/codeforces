/*
Author: QAQAutoMaton
Lang: C++
Code: C.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
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
	int id[1005][1005],t;
	/*vector<int> v[1000005];
	int val[1000005];
	int w;
	bitset<1000005>s;
	int a[1005][1005];
	bitset<1000005>q;*/
	bitset<1005> v[1005],xv[1005];
	/*void make(vector<int> &v1,vector<int> &v2){
		for(auto i:v1){s.flip(i);}
		for(auto i:v2){s.flip(i);}
		for(int i=v1.size()-1;~i;--i)if(!s[v1[i]]){swap(v1[i],v1[v1.size()-1]);v1.pop_back();}
		for(auto i:v2)if(s[i])v1.emplace_back(i);
		for(auto i:v1){s[i]=0;}
		for(auto i:v2){s[i]=0;}
	}*/
	bitset<1005> cur,cv,ask,av;
	void insert(){
		for(int i=t;i;--i)
			if(cur[i]){
				if(v[i][i]){cv^=xv[i];cur^=v[i];}
				else {v[i]=cur;xv[i]=cv;return;}
			}
	}
	int a[1005][1005];
	bitset<1005>ok[1005];
	void solve(int stx,int sty,int n){
#define p(x,y) ok[x+stx][y+sty]
		for(int i=1;i<=n;++i)p(1,i)=p(n-1,i)=1;
		if(n==2)return;
		for(int i=2;i<n;++i)p(2,i)=p(n-2,i)=1;
		for(int i=3;i<n-2;++i){
			if(i&1)p(i,1)=p(i,2)=p(i,n-1)=p(i,n)=1;
			else p(i,2)=p(i,3)=p(i,n-2)=p(i,n-1)=1;
		}
		if(n>8)solve(stx+4,sty+4,n-8);
	}
	bool main(){
		int n;
		read(n);
		t=0;
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)ok[i][j]=0;
		solve(0,0,n);
		//for(int i=1;i<=n;++i)
		//for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)read(a[i][j]);
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				read(a[i][j]);
				if(ok[i][j])ans^=a[i][j];
			}
		return write(ans,'\n');
		/*for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)if(!((i+j)&1)){
				id[i][j]=++t;
				v[t].reset();
				xv[t].reset();
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)if((i+j)&1){
				cur.reset();cv.reset();
				cv[id[i][n-j+1]]=1;	
				if(i>1)cur[id[i-1][j]]=1;
				if(i<n)cur[id[i+1][j]]=1;
				if(j>1)cur[id[i][j-1]]=1;
				if(j<n)cur[id[i][j+1]]=1;
				insert();
			}
		}
		for(int i=1;i<=t;++i)ask[i]=1;
		av.reset();
		int ans=0;
		for(int i=t;i;--i)if(ask[i]){
			ask^=v[i];
			av^=xv[i];
		}
		int out=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				bool ok;
				if(!((i+j)&1))ok=av[id[i][j]];
				else ok=av[id[i][n+1-j]];
				assert(ok==run::ok[i][j]);
				putc(ok+'0');
				if(ok)out^=a[i][j];
			}
			putc('\n');
		}
		return write(out,'\n');*/
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t){
		run::main();
	}
	return 0;
}