/*
Author: QAQAutomaton
Lang: C++
Code: G.cpp
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
const double inf=1e10,winf=1e9;
int a[200005],b[200005];
int at[200005];
double cur[200005],nex[200005];
typedef pair<double,int> pfi;
__gnu_pbds::priority_queue<pfi>pnex;
__gnu_pbds::priority_queue<pfi,greater<pfi> >pcur;
__gnu_pbds::priority_queue<pfi>::point_iterator itnex[200005];
__gnu_pbds::priority_queue<pfi,greater<pfi> >::point_iterator itcur[200005];
int n,t,q,cnt;
double ans;
double w(int i,int j){return j*1./(i+j)-(j-1)*1./(i+j-1);}
void clear(int x){
	ans-=a[x]*at[x]*1./(at[x]+b[x]);
}
void recalc(int x){
	if(!at[x])cur[x]=inf;
	else cur[x]=a[x]*w(b[x],at[x]);
	if(at[x]==b[x])nex[x]=-inf;
	else nex[x]=a[x]*w(b[x],at[x]+1);
	ans+=a[x]*at[x]*1./(at[x]+b[x]);
	pcur.modify(itcur[x],make_pair(cur[x],x));
	pnex.modify(itnex[x],make_pair(nex[x],x));
}
void maintain(){
	while(cnt<t&&pnex.top().x>-winf){
		++cnt;
		clear(pnex.top().y);
		++at[pnex.top().y];
		recalc(pnex.top().y);
	}	
	while(pnex.top().x>pcur.top().x+eps){
		int u=pnex.top().y,v=pcur.top().y;
		clear(u);clear(v);
		++at[u];--at[v];
		recalc(u);recalc(v);
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	read(n,t,q);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i){
		read(b[i]);
		at[i]=0;
		cur[i]=inf;
		nex[i]=a[i]*w(b[i],1);
		itcur[i]=pcur.push(make_pair(cur[i],i));
		itnex[i]=pnex.push(make_pair(nex[i],i));
	}
	maintain();
	for(;q;--q){
		int tp,x;	
		read(tp,x);
		clear(x);
		if(tp==1){
			++b[x];
		}
		else{
			if(at[x]==b[x]){--cnt;--at[x];}
			--b[x];
		}
		recalc(x);	
		maintain();
/*		double w=0;
		for(int i=1;i<=n;++i)printf("%d|%d|%d|%lf,%lf\n",a[i],b[i],at[i],cur[i],nex[i]);
		for(int i=1;i<=n;++i)w+=a[i]*at[i]*1./(b[i]+at[i]);
		printf("%.9lf ",w);*/
		printf("%.9lf\n",ans);
	}
	return 0;
}