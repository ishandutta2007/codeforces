/*
Author: QAQAutoMaton
Lang: C++
Code: H.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
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
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
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
int a[1005],b[1005],m;
namespace flow{
	const int N=1000005;
	const int M=2000005;
	int to[M],lst[M],beg[N],w[M],e=1,cur[N],q[N],dis[M];
	bitset<N>vis;
	int n,s,t;
	void init(int xn,int xs,int xt){
		n=xn;s=xs;t=xt;
		e=1;
		for(int i=1;i<=n;++i)beg[i]=0;
	}
	void add(int u,int v,int c){
		to[++e]=v;lst[e]=beg[u];beg[u]=e;w[e]=c;
		to[++e]=u;lst[e]=beg[v];beg[v]=e;w[e]=0;
	}
	bool bfs(){
		for(int i=1;i<=n;++i){cur[i]=beg[i];dis[i]=n+1;}
		dis[s]=0;
		int *l=q,*r=q;
		*(l=r=q)=s;
		while(l<=r){
			for(int i=beg[*l];i;i=lst[i])if(w[i]&&chkmin(dis[to[i]],dis[*l]+1))*(++r)=to[i];
			++l;
		}
		return dis[t]<n;
	}
	int dfs(int s,int t,int fl){
		if(s==t)return fl;
		for(int &i=cur[s];i;i=lst[i])if(w[i]&&dis[s]+1==dis[to[i]]){
			int v=dfs(to[i],t,min(fl,w[i]));
			if(v){w[i]-=v;w[i^1]+=v;return v;}
		}
		return 0;
	}
	int calc(){
		int flow;
		int ans=0;
		while(bfs()){
			while((flow=dfs(s,t,0x7fffffff)))ans+=flow;
		}
		for(int i=1;i<=n;++i)vis[i]=(dis[i]<=n);
		return ans;
	}
}
int id[1005];
int u[1005],v[1005];
int ans[1005];
int mn[1005],mx[1005];
int n,se;
void solve(int l,int r){
	if(l==r)return;
	int c=2;
	int s=1,t=2;
	int mid=(l+r)>>1;
	for(int i=1;i<=n;++i)if(mn[i]==l){
		id[i]=++c;
	}
	else id[i]=0;
	flow::init(c,s,t);
	for(int i=1;i<=n;++i)if(id[i]){
		flow::add(s,id[i],(abs(b[mid]-a[i])));
		flow::add(id[i],t,(abs(b[mid+1]-a[i])));
	}
	for(int i=1;i<=se;++i)if(id[u[i]] && id[v[i]]){
		flow::add(id[u[i]],id[v[i]],inf);
	}
	flow::calc();
	for(int i=1;i<=n;++i)if(id[i]){
		if(flow::vis[id[i]]){
			mn[i]=mid+1;
		}
		else mx[i]=mid;
	}
	solve(l,mid);
	solve(mid+1,r);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("H.in","r",stdin);
	freopen("H.out","w",stdout);
#endif
	read(n,se);
	for(int i=1;i<=n;++i){
		read(a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=se;++i)read(u[i],v[i]);
	for(int i=1;i<=n;++i)mn[i]=1,mx[i]=m;
	solve(1,m);
	for(int i=1;i<=n;++i)write(b[mn[i]],i==n?'\n':' ');
	return 0;
}