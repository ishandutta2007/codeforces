/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
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
vector<pii> xto[200005];
vector<int> to[200005];
int dfn[200005],low[200005],t;
int fa[200005],fid[200005];
vector<pair<int,pii> >eg,xe;
int cnt[200005];
void dfs(int x,int f){
	dfn[x]=++t;
	for(auto i:xto[x])if(i.y!=f){
		if(!dfn[i.x]){
			fa[i.x]=x;
			fid[i.x]=i.y;
			dfs(i.x,i.y);
			to[x].emplace_back(i.x);
		}
		else{
			if(dfn[i.x]<dfn[x]){
				eg.emplace_back(i.y,make_pair(x,i.x));
			}
		}
	}
	low[x]=t;
}
void dfs(int x){
	for(auto i:to[x]){dfs(i);cnt[x]+=cnt[i];}
}
bool in(int x,int y){return dfn[y]<=dfn[x] && dfn[x]<=low[y];}
vector<int> ans;
void putpath(int x){
	write(ans.size()+1,' ',x);
	for(auto i:ans)write(' ',i);
	putc('\n');
	ans.clear();
}
void getx(int x,int y){
	while(x!=y){
//		debug("(%d)",x);
		x=fa[x];
		ans.emplace_back(x);
	}

}
void put_ans(int s){
	pair<int,pii> x=xe[0],y=xe[1];
	if(dfn[x.y.y]<dfn[y.y.y])swap(x,y);
	int t=x.y.y;
	ans.emplace_back(s);
	getx(s,t);
	ans.pop_back();
	reverse(all(ans));
	putpath(t);
	ans.emplace_back(x.y.x);
	getx(x.y.x,s);
	putpath(t);
	getx(t,y.y.y);
	ans.emplace_back(y.y.x);
	getx(y.y.x,s);
	putpath(t);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,m,u,v;
	read(n,m);
	for(int i=1;i<=m;++i){
		read(u,v);
		xto[u].emplace_back(v,i);
		xto[v].emplace_back(u,i);
	}
	for(int i=1;i<=n;++i)if(!dfn[i]){
		dfs(i,0);
		to[0].emplace_back(i);
	}
	for(auto i:eg){
		++cnt[i.y.x];--cnt[i.y.y];
	}
	dfs(0);
	int em=0,id;
	for(int i=1;i<=n;++i)if(cnt[i]>=2)if(chkmax(em,dfn[i]))id=i;
	if(!em)return write("NO\n");
	else{
		write("YES\n");
		for(auto i:eg){
			if(in(i.y.x,id) && !in(i.y.y,id)){
				xe.emplace_back(i);
				if(xe.size()==2){
					put_ans(id);
					return 0;
				}
			}
//			if(in(i.x,))
		}
	}
	return 0;
}