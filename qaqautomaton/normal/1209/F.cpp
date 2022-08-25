/*
Author: QAQ Automaton
LANG: C++
PROG: F.cpp
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
int t;
vector<pii> to[1200005];
const int p=1000000007;
int ans[1200005];
int q[1200005],*l,*r;
int dis[1200005];
void BFS(int x){
	*(l=r=q)=x;
	dis[x]=1;
	while(l<=r){
		for(auto i:to[*l])if(!dis[i.x]){
			dis[i.x]=dis[*l]+1;
			*(++r)=i.x;
		}
		++l;
	}
}
vector<int> s[1200005][10];
int mn[1200005];
bool vis[1200005];
void work(int x,int y){
	for(auto i:s[x][y]){
		for(auto j:to[i])if(dis[j.x]==dis[i]+1&&!vis[j.x])chkmin(mn[j.x],j.y);
	}
	for(auto i:s[x][y]){
		for(auto j:to[i])if(dis[j.x]==dis[i]+1 && !vis[j.x])if(mn[j.x]==j.y){
			ans[j.x]=(ans[i]*10ll+j.y)%p;
			s[x+1][j.y].push_back(j.x);
			vis[j.x]=1;
		}
	}
	for(int i=0;i<10;++i)if(!s[x+1][i].empty())work(x+1,i);
	s[x][y].clear();
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,m,u,v;
	read(n,m);
	int x=0,y=1;
	t=n;
	for(int i=1;i<=m;++i){
		if(i>=y){++x;y*=10;}
		read(u,v);
		int prev=u,w=i;
		for(int i=1;i<x;++i){
			++t;
			to[t].push_back(make_pair(prev,w%10));
			prev=t;
			w/=10;
		}
		to[v].push_back(make_pair(prev,w));
		prev=v,w=i;
		for(int i=1;i<x;++i){
			++t;
			to[t].push_back(make_pair(prev,w%10));
			prev=t;
			w/=10;
		}
		to[u].push_back(make_pair(prev,w));
	}
	BFS(1);
	for(int i=1;i<=t;++i)mn[i]=10;
	s[1][0].push_back(1);
	work(1,0);
	for(int i=2;i<=n;++i)write(ans[i],'\n');
	return 0;
}