/*
Author: QAQAutomaton
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
vector<int> to[300005];
int dep[300005],fa[300005];
void pdfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x]=f;
	for(auto i:to[x])if(i!=f)pdfs(i,x);
}
vector<pii> ad[300005];
int n;
int rt[300005];
ll ans;
int mn[10000005],l[10000005],r[10000005],t,tag[10000005];
void put_tag(int x,int y){if(!x)return;mn[x]+=y;tag[x]+=y;}
void push_down(int x){if(tag[x]){put_tag(x[l],tag[x]);put_tag(x[r],tag[x]);tag[x]=0;}}
void merge(int &x,int y){
	if(!y)return;
	if(!x){x=y;return;}
	push_down(x);
	push_down(y);
	chkmin(mn[x],mn[y]);
	merge(x[l],y[l]);
	merge(x[r],y[r]);
}
void put(int &rt,int ls,int rs,int x,int y){
	if(!rt){mn[rt=++t]=y;}
	else chkmin(mn[rt],y);
	if(ls==rs)return;
	push_down(rt);
	int mid=(ls+rs)>>1;
	if(x<=mid)put(rt[l],ls,mid,x,y);
	else put(rt[r],mid+1,rs,x,y);
}
int findmn(int rt,int ls,int rs){
	if(ls==rs){return ls;}
	push_down(rt);
	int mid=(ls+rs)>>1;
	if(!rt[l][mn]){rt[r]=0;return findmn(rt[l],ls,mid);}
	return findmn(rt[r],mid+1,rs);
}
void remove(int &rt,int ls,int rs,int x){
	if(!rt)return;
	if(x<=ls){rt=0;return;}
	if(rs<x)return;
	push_down(rt);
	int mid=(ls+rs)>>1;
	if(x<=mid){remove(rt[l],ls,mid,x);rt[r]=0;}
	else remove(rt[r],mid+1,rs,x);
	if(!rt[l] && !rt[r]){rt=0;return;}
	mn[rt]=min(mn[rt[l]],mn[rt[r]]);
}
int dfs(int x,int f){
	int mnd=dep[x];
	for(auto i:to[x])if(i!=f){
		chkmin(mnd,dfs(i,x));
		merge(rt[x],rt[i]);
	}
	for(auto i:ad[x]){
		put(rt[x],1,n,i.x,i.y);
	}
	remove(rt[x],1,n,mnd);
	if(mnd==dep[x]){
		if(x==1)return 0;
		if(!rt[x])exit(write("-1\n"));
		ans+=rt[x][mn];
		put_tag(rt[x],-rt[x][mn]);
		return findmn(rt[x],1,n);
	}
	return mnd;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	mn[0]=inf;
	int m,u,v,c;
	read(n,m);
	for(int i=1;i<n;++i){
		read(u,v);
		to[u].emplace_back(v);
		to[v].emplace_back(u);
	}
	pdfs(1,0);
	for(int i=1;i<=m;++i){
		read(u,v,c);
		if(u==v)continue;
		ad[u].emplace_back(dep[v],c);
	}
	dfs(1,0);
	write(ans,'\n');
	return 0;
}