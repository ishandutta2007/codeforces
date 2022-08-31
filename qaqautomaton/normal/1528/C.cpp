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
	int fa[300005],fb[300005];
	vector<int> to[300005],tb[300005];
	int dfn[300005],low[300005],t;
	void dfsb(int x){
		dfn[x]=++t;
		for(auto i:tb[x])dfsb(i);
		low[x]=t;
	}
	int ans;
	int cnt;
	set<pii> st;
	pii rm[300005];
	bool tryput(int x){
		/*write("Ins",x,'\n') ; 
		write(dfn[x],' ',low[x],'\n');*/
		auto it=st.lower_bound({dfn[x],-inf});
		//if(it!=st.end())write('x',it->y,',',it->x,'\n');
		if(it==st.end()||it->y>low[x]){st.insert({low[x],dfn[x]});rm[x]={0,0};++cnt;return 1;}
		if(it->y>=dfn[x])return 0;
		//write("/yiw\n");
		rm[x]=*it;
		st.erase(it);
		st.insert({low[x],dfn[x]});
		return 1;
	}
	void dfs(int x){
		bool is=tryput(x);
		chkmax(ans,cnt);
		//write(cnt,' ',ans,'\n');
		for(auto i:to[x]){
			dfs(i);
		}
		if(is){
			st.erase({low[x],dfn[x]});
			if(rm[x].x){
				st.insert(rm[x]);	
			}
			else --cnt;
		}
	}
	bool main(){
		int n;
		read(n);
		for(int i=1;i<=n;++i)to[i].clear();
		for(int i=1;i<=n;++i)tb[i].clear();
		for(int i=2;i<=n;++i){
			read(fa[i]);
			to[fa[i]].emplace_back(i);
		}
		for(int i=2;i<=n;++i){
			read(fb[i]);
			tb[fb[i]].emplace_back(i);
		}
		dfsb(1);
		ans=0;
		dfs(1);
		write(ans,'\n');
		return 0;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t)run::main();
	return 0;
}