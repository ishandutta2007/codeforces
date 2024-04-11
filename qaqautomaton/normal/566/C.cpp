/*
Author: QAQAutomaton
Lang: C++
Code: C.cpp
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
int a[200005];
vector<pii> to[200005];
double ans=1e20;
int id;
bitset<200005> vis;
int rts,mns,rt;
int siz[200005],mxs[200005];
void dfs1(int x,int f){
	siz[x]=1;
	mxs[x]=0;
	for(auto i:to[x])if(i.x!=f && !vis[i.x]){
		dfs1(i.x,x);
		chkmax(mxs[x],siz[i.x]);
		siz[x]+=siz[i.x];
	}
}
void dfs2(int x,int f){
	if(chkmin(mns,max(mxs[x],rts-siz[x])))rt=x;
	for(auto i:to[x])if(i.x!=f && !vis[i.x]){
		dfs2(i.x,x);
	}
}
double cur,inc,d[200005];
void dfs3(int x,int f,int d,double &dc){
	double a=d*sqrt(d)*::a[x],b=(d+1)*sqrt(d+1)*::a[x],c=(d-1)*sqrt(d-1)*::a[x];
	cur+=a;
	inc+=b-a;
	dc+=b-c;
	for(auto i:to[x])if(i.x!=f){
		dfs3(i.x,x,d+i.y,dc);
	}
}
void solve(int x){
	dfs1(x,0);	
	rts=siz[x];
	mns=rts;
	rt=0;
	dfs2(x,0);	
	x=rt;
	vis[x]=1;
	int t=0;
	cur=0;
	inc=a[x];
	for(auto i:to[x]){
		d[++t]=0;
		dfs3(i.x,x,i.y,d[t]);
	}
	t=0;
	if(chkmin(ans,cur))id=x;
	for(auto i:to[x]){
		if(inc<d[++t] && !vis[i.x]){
			solve(i.x);
			return;
		}
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,u,v,w;
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
	}
	for(int i=1;i<n;++i){
		read(u,v,w);
		to[u].emplace_back(v,w);
		to[v].emplace_back(u,w);
	}
	solve(1);
	printf("%d %.9lf\n",id,ans);
	return 0;
}