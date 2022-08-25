/*
Author: QAQ Automaton
LANG: C++
PROG: E.cpp
Mail: cnyalilk@vip.qq.com
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
int w[200005];
vector<int> to[200005],to2[200005];
int dfn[200005],low[200005],ins[200005],col[200005],t,c;
int stk[200005],top;
int sum[200005],siz[200005];
void dfs(int x,int f){
	dfn[x]=low[x]=++t;
	ins[x]=1;
	stk[++top]=x;
	for(auto i:to[x])if(i!=f){
		if(!dfn[i]){dfs(i,x);chkmin(low[x],low[i]);}
		else if(ins[i])chkmin(low[x],dfn[i]);
	}
	if(dfn[x]==low[x]){
		stk[top+1]=-1;
		++c;
		while(stk[top+1]!=x){
			col[stk[top]]=c;
			sum[c]+=w[stk[top]];
			++siz[c];
			--top;
		}
	}
}
int ans,add[200005],ansad;
bool gg[200005];
void dfs2(int x,int f){
	gg[x]=siz[x]==1;
	for(auto i:to2[x])if(i!=f){
		dfs2(i,x);
		if(!gg[i])gg[x]=0;
	}
	if(f&&gg[x]){
		sum[x]+=add[x];
		chkmax(add[f],sum[x]);
	}
	else {
		chkmax(ansad,add[x]);
		ans+=sum[x];
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,m,u,v,s;
	read(n,m);
	for(int i=1;i<=n;++i)read(w[i]);
	for(int i=1;i<=m;++i){
		read(u,v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	read(s);
	dfs(s,0);
	for(int i=1;i<=n;++i)if(col[i])for(auto j:to[i])if(col[i]!=col[j])to2[col[i]].push_back(col[j]);
	for(int i=1;i<=c;++i){sort(all(to2[i]));to2[i].erase(unique(all(to2[i])),to2[i].end());}
	dfs2(col[s],0);
	write(ans+ansad,'\n');
	return 0;
}