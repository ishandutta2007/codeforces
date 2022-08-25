/*
Author: CNYALI_LK
LANG: C++
PROG: D.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const signed inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>ll dcmp(T a,T b){return a>b;}
template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
	const ll SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; ll f, qr;
	// getchar
#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// prll the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed lleger
	inline void read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}

	inline void read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	inline void read (char &x) {
		x=gc();
	}
	inline void read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
	}
	template<typename A,typename ...B>
		inline void read(A &x,B &...y){
			read(x);read(y...);
		}
	// prll a signed lleger
	inline void write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}

	inline void write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	inline void write (char x) {
		putc(x);
	}
	inline void write(const char *x){
		while(*x){putc(*x);++x;}
	}
	inline void write(char *x){
		while(*x){putc(*x);++x;}
	}
	template<typename A,typename ...B>
		inline void write(A x,B ...y){
			write(x);write(y...);
		}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
ll ans,beg[100005],to[200005],lst[200005],e,deg[100005],cnt[2],col[100005];
void add(ll u,ll v){to[++e]=v;lst[e]=beg[u];beg[u]=e;}
void dfs(ll x,ll Cl){
	if(~col[x]){if(Cl!=col[x]){printf("0 1\n");exit(0);}return;}
	col[x]=Cl;
	ans+=cnt[Cl];
	++cnt[Cl];
	for(ll i=beg[x];i;i=lst[i])dfs(to[i],Cl^1);
}
int main(){
#ifdef cnyali_lk
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	ll n,m,u,v;
	read(n,m);
	for(ll i=1;i<=m;++i){
		read(u,v);
		add(u,v);
		add(v,u);
		++deg[u];
		++deg[v];
	}

	if(!m){
		printf("3 %lld\n",n*(n-1)*(n-2)/6);	
	}
	else{
		ll hv2=0;
		for(ll i=1;i<=n;++i){
			if(deg[i]>=2)hv2=1;
		}
		if(!hv2){
			printf("2 %lld\n",(n-2)*m);
		}
		else{
			for(ll i=1;i<=n;++i){col[i]=-1;}
			ans=0;
			for(ll i=1;i<=n;++i)if(!~col[i]){
				cnt[0]=cnt[1]=0;
				dfs(i,1);
			}
			printf("1 %lld\n",ans);
		}
	}
	return 0;
}