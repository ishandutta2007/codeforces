/*
Author: QAQ-Automaton
LANG: C++
PROG: E.cpp
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
#define inf 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>bool chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>bool chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>bool dcmp(T a,T b){return a>b;}
template<int *a>bool cmp_a(bool x,bool y){return a[x]<a[y];}
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
bool query(int u,int v){
	printf("? %d %d\n",u,v);
	fflush(stdout);
	scanf("%d",&u);
	return u;
}
int n,m;
vector<int> to[100005],xto[100005];
int dfn[100005],low[100005],stk[100005],top,t,c;
int col[100005],in[100005];
vector<int> p[100005];
void dfs(int x){
	dfn[x]=low[x]=++t;
	stk[++top]=x;
	for(auto i:to[x])if(!dfn[i]){dfs(i);chkmin(low[x],low[i]);}
	else if(!col[i])chkmin(low[x],dfn[i]);
	if(dfn[x]==low[x]){
		++c;
		for(stk[top+1]=-1;stk[top+1]!=x;--top){
			p[col[stk[top]]=c].push_back(stk[top]);
		}
	}
}
int q[100005],*l,*r;
void rebuild(){
	for(int i=1;i<=n;++i)for(auto j:to[i])if(col[i]!=col[j]){
		xto[col[i]].push_back(col[j]);
		++in[col[j]];
	}
	l=q+1;r=q;
	for(int i=1;i<=c;++i)if(!in[i])*(++r)=i;
}
void merge(int &x,int &y){
	while(!p[x].empty() && !p[y].empty()){
		if(query(p[x].back(),p[y].back()))p[y].pop_back();
		else p[x].pop_back();
	}
	if(p[y].empty())swap(x,y);
	for(auto i:xto[x])if(!--in[i])*(++r)=i;
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		to[u].push_back(v);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])dfs(i);
	rebuild();
	while(l<r){
		merge(*l,*(l+1));
		++l;
	}
	printf("! %d\n",p[*l].back());
	fflush(stdout);
	return 0;
}