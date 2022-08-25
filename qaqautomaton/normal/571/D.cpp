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
int n,q;
struct Tree{
	int t;
	int fa[1000005];
	vector<int> to[1000005];
	int dfn[1000005],low[1000005],c;
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){
		++t;
		x=find(x),y=find(y);
		fa[x]=fa[y]=fa[t]=t;
		to[t].emplace_back(x);to[t].emplace_back(y);
	} 
	void dfs(int x){
		dfn[x]=c+1;	
		if(x<=n)++c;
		for(auto i:to[x])dfs(i);
		low[x]=c;
	}
	void make(){
		for(int i=1;i<=t;++i)if(fa[i]==i){fa[i]=t+1;to[t+1].emplace_back(i);}
		++t;
		dfs(t);
	}
}t1,t2;
int id[500005];
struct query{
	int tp,x,t;
};
query ask[500005];
ll ans[500005];
set<pair<pii,int> >st;
vector<pii> q1[500005],q2[500005];
namespace bit{
	ll s[500005];
	void add(int x,int y){for(;x<=n;x+=x&-x)s[x]+=y;}
	ll sum(int x){ll y=0;for(;x;x^=x&-x)y+=s[x];return y;}
}
void split(int x){
	auto it=st.lower_bound({{x,0},0});
	if(it->x.y<x){
		int l=it->x.y,r=it->x.x,v=it->y;	
		st.erase(it);
		st.insert({{r,x},v});
		st.insert({{x-1,l},v});
	}
}
void put(int l,int r,int x){
	split(l);
	if(r!=n)split(r+1);
	auto it=st.lower_bound({{l,0},0});
	while(it!=st.end() && it->x.x<=r){
		auto od=it;
		++it;
		st.erase(od);
	}
	st.insert({{r,l},x});
}
int getval(int x){
	return st.lower_bound({{x,0},0})->y;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	read(n,q);
	t1.t=t2.t=n;
	for(int i=1;i<=n;++i){
		t1.fa[i]=t2.fa[i]=i;
	}
	int m1=0,m=0;
	for(;q;--q){
		char tp;
		int x,y;
		read(tp,x);
		switch(tp){
			case 'U': read(y);t1.merge(x,y);break;
			case 'M': read(y);t2.merge(x,y);break;
			case 'A': id[++m1]=t1.find(x);break;
			case 'Z': ask[++m]={1,t2.find(x),m1};break;
			case 'Q': ask[++m]={2,x,m1};break;
		}
	}
	t1.make();t2.make();
	st.insert({{n,1},0});
	for(int i=1;i<=m;++i){
		if(ask[i].tp==1){
			put(t2.dfn[ask[i].x],t2.low[ask[i].x],ask[i].t);	
		}
		else{
			int xt=getval(t2.dfn[ask[i].x]);
			q1[ask[i].t].emplace_back(t1.dfn[ask[i].x],i);
			q2[xt].emplace_back(t1.dfn[ask[i].x],i);
		}
	}
	for(int i=1;i<=m1;++i){
		int l=t1.dfn[id[i]],r=t1.low[id[i]];
		bit::add(l,r-l+1);
		bit::add(r+1,l-r-1);
		for(auto x:q1[i])ans[x.y]+=bit::sum(x.x);
		for(auto x:q2[i])ans[x.y]-=bit::sum(x.x);
	}
	for(int i=1;i<=m;++i)if(ask[i].tp==2)write(ans[i],'\n');
	return 0;
}