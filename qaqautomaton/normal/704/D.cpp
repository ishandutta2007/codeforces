/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp
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

int x[1000005],y[1000005];
map<int,int> xs,ys;
int xt,yt;
int cntx[1000005],cnty[1000005];
int limx[1000005],limy[1000005];
void make(int v,int s,int &l,int &r){
	//x-(s-x)<=v
	//s-2x<=v
	//2x<=v+s
	//2x<=v+s
	//2x>=s-v
	r=(v+s)>>1;
	l=(s-v+1)>>1;
}
namespace flow{
	namespace dinic{
		int to[1000005],lst[1000005],beg[1000005],w[1000005],e=1;
		int n,s,t;
		void add(int u,int v,int fl){
			//	write(u,' ',v,' ',fl,'\n');
			to[++e]=v;lst[e]=beg[u];beg[u]=e;w[e]=fl;
			to[++e]=u;lst[e]=beg[v];beg[v]=e;w[e]=0;
		}
		int q[1000005],*l,*r;
		int d[1000005],cur[1000005];
		bool bfs(){
			for(int i=1;i<=n;++i){d[i]=inf;cur[i]=beg[i];}
			d[*(l=r=q)=s]=0;
			while(l<=r){
				for(int i=beg[*l];i;i=lst[i])if(w[i]&&chkmin(d[to[i]],d[*l]+1))*(++r)=to[i];
				++l;
			}	
			return d[t]!=inf;
		}
		int dfs(int x,int f){
			if(x==t)return f;
			for(int &i=cur[x];i;i=lst[i])if(w[i] && d[x]+1==d[to[i]]){
				int g=dfs(to[i],min(f,w[i]));
				if(g){w[i]-=g;w[i^1]+=g;return g;}
			}
			return 0;
		}
		int dinic(){
			int ans=0,fl;
			while(bfs()){
				while((fl=dfs(s,inf)))ans+=fl;
			}
			return ans;
		}
	}
	int n;
	int cnt[1000005];
	void add(int u,int v,int l,int r){
		if(l>r){exit(write("-1\n"));}
		dinic::add(u,v,r-l);
		cnt[u]+=l;
		cnt[v]-=l;
	}
	void solve(int s,int t){
		dinic::n=n+2;
		int cure=dinic::e+1;
		dinic::add(t,s,inf);
		for(int i=1;i<=n;++i)if(cnt[i]>0)dinic::add(i,n+2,cnt[i]);
		else dinic::add(n+1,i,-cnt[i]);
		dinic::s=n+1;dinic::t=n+2;
		dinic::dinic();
		for(int i=cure+2;i<=dinic::e;i+=2)if(dinic::w[i])exit(write("-1\n"));
		for(int i=cure;i<=dinic::e;++i)dinic::w[i]=0;
		dinic::s=s;dinic::t=t;
		dinic::dinic();
	}
}
bitset<100005>cnt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n,m,r,b;	
	read(n,m,r,b);
	bool rev=0;
	if(r<b){swap(r,b);rev=1;}
	int ans=r*n;
	b-=r;
	for(int i=1;i<=n;++i){
		read(x[i],y[i]);
		if(xs.count(x[i]))x[i]=xs[x[i]];
		else {xs[x[i]]=++xt;x[i]=xt;}
		++cntx[x[i]];
		if(ys.count(y[i]))y[i]=ys[y[i]];
		else {ys[y[i]]=++yt;y[i]=yt;}
		++cnty[y[i]];
	}
	for(int i=1;i<=xt;++i)limx[i]=cntx[i];
	for(int i=1;i<=yt;++i)limy[i]=cnty[i];
	for(int i=1;i<=m;++i){
		int tp,x,y;
		read(tp,x,y);
		if(tp==1){
			chkmin(limx[xs[x]],y);
		}
		else{
			chkmin(limy[ys[x]],y);
		}
	}
	flow::n=xt+yt+2;
	for(int i=1;i<=n;++i){
		flow::add(x[i],y[i]+xt,0,1);
	}
	for(int i=1;i<=xt;++i){
		int &l=limx[i],&r=cntx[i];
		make(l,r,l,r);
		flow::add(xt+yt+1,i,l,r);
	}
	for(int i=1;i<=yt;++i){
		int &l=limy[i],&r=cnty[i];
		make(l,r,l,r);
		flow::add(i+xt,xt+yt+2,l,r);
	}
	flow::solve(xt+yt+1,xt+yt+2);
	for(int i=1;i<=n;++i)cnt[i]=!flow::dinic::w[i<<1];
	write(ans+b*cnt.count(),'\n');
	for(int i=1;i<=n;++i)putc((cnt[i]^rev)?'b':'r');
	putc('\n');
	return 0;
}