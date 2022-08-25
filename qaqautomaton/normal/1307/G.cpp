/*
Author: QAQAutomaton
Lang: C++
Code: G.cpp
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
namespace flow{
	int beg[55],to[10005],lst[10005],w[10005],c[10005],e=1;
	void add(int u,int v,int fl,int co){
		to[++e]=v;lst[e]=beg[u];beg[u]=e;w[e]=fl;c[e]=co;
		to[++e]=u;lst[e]=beg[v];beg[v]=e;w[e]=0;c[e]=-co;
	}
	int dis[55],inq[55],las[55],mnw[55];
	int q[55],*l,*r,*rs=q+54;
	int next(int n){
		for(int i=1;i<=n;++i){dis[i]=inf;las[i]=0;inq[i]=0;mnw[i]=0;}
		mnw[1]=inf;
		dis[1]=0;
		*(l=r=q)=1;
		while(l!=(r==rs?q:r+1)){
			inq[*l]=0;
			for(int i=beg[*l];i;i=lst[i])if(w[i] && chkmin(dis[to[i]],dis[*l]+c[i])){
				if(!inq[to[i]]){*(r==rs?r=q:++r)=to[i];inq[to[i]]=1;}
				las[to[i]]=i;
				mnw[to[i]]=min(mnw[*l],w[i]);
			}	
			l==rs?l=q:++l;
		}
		if(dis[n]==inf)return inf;
		int flow=mnw[n];
		for(int i=n;i!=1;i=to[las[i]^1]){
			w[las[i]]-=flow;w[las[i]^1]+=flow;
		}
		return dis[n];
	}
}
int x[1000005];
double ans[1000005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,m,u,v,c;	
	read(n,m);
	for(int i=1;i<=m;++i){
		read(u,v,c);
		flow::add(u,v,1,c);
	}
	int q;
	read(q);
	for(int i=1;i<=q;++i){
		read(x[i]);
		ans[i]=1e10;
	}
	int sumF=0,sumC=0;
	while(1){
		int w=flow::next(n);		
		if(w==inf){break;}
		sumC+=w;
		++sumF;
		for(int i=1;i<=q;++i)chkmin(ans[i],(sumC+x[i])*1./sumF);
	}
	for(int i=1;i<=q;++i)printf("%.12lf\n",ans[i]);
	return 0;
}