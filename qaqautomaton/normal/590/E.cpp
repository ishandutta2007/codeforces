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
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
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
char str[10000005],*s[755];
int to[10000005][2],id[10000005],las[10000005],fail[10000005],t=1;
int q[10000005],*l,*r;
bitset<755> a[755];
int sx[755],sy[755];
namespace match{
	int xn;
	int beg[1505],to[1919810],lst[1919810],w[1919810],e=1;
	void add(int u,int v,int c){
		to[++e]=v;lst[e]=beg[u];beg[u]=e;w[e]=c;
		to[++e]=u;lst[e]=beg[v];beg[v]=e;w[e]=0;
	}
	int q[1505],*l,*r;
	int dis[1505],vis[1505],cur[1505];
	bool bfs(int s,int t){
		for(int i=1;i<=xn;++i){
			dis[i]=114514;
			cur[i]=beg[i];
		}
		dis[s]=0;
		*(l=r=q)=s;
		while(l<=r){
			for(int i=beg[*l];i;i=lst[i])if(w[i]){
				if(chkmin(dis[to[i]],dis[*l]+1))
					*(++r)=to[i];
			}
			++l;
		}
		return dis[t]!=114514;
	}
	int dfs(int s,int t,int flw){
		if(s==t)return flw;	
		for(int &i=cur[s];i;i=lst[i])if(w[i] && dis[to[i]]==dis[s]+1){
			int mx=dfs(to[i],t,min(flw,w[i]));
			if(mx){
				w[i]-=mx;w[i^1]+=mx;
				return mx;
			}
		}
		return 0;
	}
	int dinic(int s,int t){
		int ans=0,flow;
		while(bfs(s,t)){
			while(flow=dfs(s,t,114514))ans+=flow;	
		}	
		return ans;
	}
	void dfs(int s){
		if(vis[s])return;
		vis[s]=1;
		for(int i=beg[s];i;i=lst[i])if(w[i]){
			dfs(to[i]);
		}
	}
	void match(int n){
		xn=n*2+2;
		for(int i=1;i<=n;++i)add(1,i+2,1);
		for(int i=1;i<=n;++i)add(i+2+n,2,1);
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(a[i][j])add(i+2,j+n+2,114514);
		write(n-dinic(1,2),'\n');
		dfs(1);
		for(int i=1;i<=n;++i)if(vis[i+2])sx[i]=1;
		for(int i=1;i<=n;++i)if(!vis[i+2+n])sy[i]=1;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n;
	read(n);
	s[1]=str;
	for(int i=1;i<=n;++i){
		read(s[i]);
		s[i+1]=s[i]+strlen(s[i]);
		for(char *j=s[i];j<s[i+1];++j)*j-='a';
	}
	for(int i=1;i<=n;++i){
		int at=1;
		for(char *j=s[i];j<s[i+1];++j){
			if(!to[at][*j])to[at][*j]=++t;
			at=to[at][*j];
		}
		id[at]=i;
	}
	fail[*(l=r=q)=1]=1;
	while(l<=r){
		las[*l]=id[fail[*l]];
		if(!id[*l])id[*l]=las[*l];
		for(int j=0;j<2;++j)if(to[*l][j]){
			*(++r)=to[*l][j];
			if(*l==1)fail[*r]=1;
			else{
				int x=fail[*l];
				while(x!=1 && !to[x][j])x=fail[x];
				if(to[x][j])fail[*r]=to[x][j];
				else fail[*r]=1;
			}
		}
		++l;
	}

	for(int i=1;i<=n;++i){
		int at=1;
		for(char *j=s[i];j<s[i+1];++j){
			at=to[at][*j];
			if(id[at]!=i)a[i][id[at]]=1;
			else a[i][las[at]]=1;
		}
	}
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)if(a[i][k])a[i]|=a[k];
	match::match(n);	
	for(int i=1;i<=n;++i)if(sx[i]&&sy[i])write(i,' ');
	putc('\n');
	return 0;
}