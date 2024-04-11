/*
Author: QAQAutoMaton
Lang: C++
Code: G.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
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
int id[19][19];
pii e[405];
int s[19];
namespace flow{
	int to[1000005],lst[1000005],beg[100005],w[1000005],e=1,cur[100005],q[100005],dis[1000005];
	int n,s,t;
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
		return ans;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,m,x,y,w,c=2;
	read(n,m);
	for(int i=1;i<=n;++i){
		id[i][0]=1;
		for(int j=1;j<n;++j)id[i][j]=++c;
		id[i][n]=2;
	}
	flow::n=c;
	flow::s=1;flow::t=2;
	for(int i=1;i<=m;++i){
		read(x,y,w);
		for(int j=0;j<n;++j)flow::add(id[y][j],id[x][j+1],inf);
		e[i]={x,y};
		s[x]+=w;
		s[y]-=w;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(s[i]==0)continue;
		if(s[i]>0){
			for(int j=1;j<=n;++j)flow::add(id[i][j-1],id[i][j],j*s[i]);
		}
		else{
			ans+=n*s[i];
			for(int j=1;j<=n;++j){
				flow::add(id[i][j-1],id[i][j],(j-n)*s[i]);
			}
		}
	}
	flow::calc();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)if(flow::dis[id[i][j-1]]<=c&&flow::dis[id[i][j]]>c){
			write(j,i==n?'\n':' ');
			break;
		}
	}
	return 0;
}