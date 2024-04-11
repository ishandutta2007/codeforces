/*
Author: QAQAutoMaton
Lang: C++
Code: C.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
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
vector<int> to[200005][2];
int dis[200005];
int n;
typedef pair<pii,int> piii;
__gnu_pbds::priority_queue<piii,greater<piii> >pq;
__gnu_pbds::priority_queue<piii,greater<piii> >::point_iterator it[400005];
vector<int> nd[200005];
void bfs(int v){
	pq.clear();
	for(int i=0;i<=n;++i)nd[i].clear();
	for(int i=1;i<=n;++i)nd[dis[i]].emplace_back(i);
	for(int d=0;d<n;++d)for(auto x:nd[d])if(dis[x]==d){
		for(auto i:to[x][v])if(chkmin(dis[i],dis[x]+1))nd[dis[x]+1].emplace_back(i);
	}
}
pii xdis[400005];
const int p=998244353;
int fpm(int a,int b){
	int c=1;for(;b;b>>=1,a=(ll)a*a%p)if(b&1)c=(ll)c*a%p;
	return c;
}
pii operator +(const pii &a,const pii &b){return {a.x+b.x,a.y+b.y};}
void dij(){
	int m=n<<1|1;
	for(int i=2;i<=m;++i)it[i]=pq.push({xdis[i],i});
	while(!pq.empty()){
		int x=pq.top().y>>1,y=pq.top().y&1,w=pq.top().y;
		pq.pop();
		if(chkmin(xdis[w^1],xdis[w]+pii{1,0}))pq.modify(it[w^1],{xdis[w^1],w^1});
		for(auto i:to[x][y]){
			if(chkmin(xdis[i<<1|y],xdis[w]+pii{0,1}))pq.modify(it[i<<1|y],{xdis[i<<1|y],i<<1|y});
		}
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int m;
	read(n,m);
	for(int i=1;i<=m;++i){
		int u,v;
		read(u,v);
		to[u][0].emplace_back(v);
		to[v][1].emplace_back(u);
	}
	int ans=inf;
	for(int i=1;i<=n;++i)dis[i]=n;
	dis[1]=0;
	for(int i=0;i<30;++i){
		bfs(i&1);
		if(dis[n]!=n)chkmin(ans,(1<<i)-1+dis[n]);
	}
	if(ans!=inf)return write(ans,'\n');
	for(int i=1;i<=n;++i)if(dis[i]!=n){
		xdis[i<<1]={30,dis[i]};
		xdis[i<<1|1]={29,dis[i]};
	}
	else{ 
		xdis[i<<1]=xdis[i<<1|1]={inf,inf};
	}
	dij();
	pii w=min(xdis[n<<1],xdis[n<<1|1]);
	int s=(w.y+fpm(2,w.x))%p;
	if(!s)s=p-1;else --s;
	write(s,'\n');
	return 0;
}