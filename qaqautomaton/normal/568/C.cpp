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
char s[205],w1[15],w2[15];
int a[27],nex[27][2],l;
vector<int> to[405];
void add(int x,int y){
	to[x].push_back(y);	
}
int stk[405],t;
int n,m;
int ans[405];
bitset<405>vis;
int gg;
void dfs(int x){
	if(vis[x])return;
	if(vis[x^1]){gg=1;return;}
	stk[++t]=x;
	vis[x]=1;
	for(auto i:to[x]){
		dfs(i);
	}
}
void undo(int lst){
	while(t>lst){vis[stk[t]]=0;--t;}
}
int tryput(int x,int y){
	gg=0;	
	dfs(x<<1|y);
	return !gg;
}
int solve(int x,int eq){
	if(x>n)return 1;
	int lim;
	int lst=t;
	if(eq){
		lim=s[x]-'a';
		ans[x]=s[x]-'a';
		if(tryput(x,a[lim])&&solve(x+1,1))return 1;
		undo(lst);
		++lim;
	}
	else
		lim=0;
	int w=0;
	if(nex[lim][0]<nex[lim][1])w=0;
	else w=1;
	ans[x]=lim;
	if(ans[x]<l){
		if(tryput(x,w)&&solve(x+1,0))return 1;
		undo(lst);
	}
	ans[x]=nex[lim][w^1];
	if(ans[x]<l){
		if(tryput(x,w^1)&&solve(x+1,0))return 1;
		undo(lst);
	}
	return 0;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	read(s);
	l=strlen(s);
	for(int i=0;i<l;++i){
		a[i]=s[i]=='C';	
	}
	nex[l][0]=nex[l][1]=l;
	for(int i=l-1;~i;--i){
		nex[i][0]=nex[i+1][0];
		nex[i][1]=nex[i+1][1];
		nex[i][a[i]]=i;
	}
	int u,v;
	read(n,m);
	for(int i=1;i<=m;++i){
		read(u,w1,v,w2);
		u=u<<1|(*w1=='C');
		v=v<<1|(*w2=='C');
		add(u,v);
		add(v^1,u^1);
	}
	for(int i=1;i<=n;++i){
		if(tryput(i,0)){undo(0);continue;}
		undo(0);
		if(tryput(i,1)){undo(0);continue;}
		return write("-1\n");
	}
	read(s+1);
	if(!solve(1,1))return write("-1\n");
	for(int i=1;i<=n;++i)putc(ans[i]+'a');
	putc('\n');
	return 0;
}