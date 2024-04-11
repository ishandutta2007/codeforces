/*
Author: QAQ-Automaton
LANG: C++
PROG: F2.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__) #define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__) #define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define inf 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
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
	// prll a signed lleger
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
const ll p=998244353;
vector<ll> co[300005],to[300005];
ll a[300005],head[300005],inv[300005];
ll fa[19][300005],dep[300005];
void dfs_pre(ll x,ll f){
	dep[x]=dep[f]+1;
	fa[0][x]=f;
	for(ll i=1;i<=18;++i)fa[i][x]=fa[i-1][fa[i-1][x]];
	for(auto i:to[x])if(i!=f)dfs_pre(i,x);	
}
ll lca(ll a,ll b){
	if(dep[a]<dep[b])swap(a,b);
	for(ll i=18;~i;--i)if(dep[a]-(1<<i)>=dep[b])a=fa[i][a];
	for(ll i=18;~i;--i)if(fa[i][a]!=fa[i][b])a=fa[i][a],b=fa[i][b];
	return a==b?a:fa[0][a];
}
ll tag[300005];
vector<ll> qwq[300005];
ll f[300005][2],ans;
ll fpm(ll a,ll b){
	ll c=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
void dfs(ll x){
	if(a[x]){
		tag[x]=-x;
		qwq[x].push_back(-x);
	}
	for(auto i:to[x])if(i!=fa[0][x]){
		dfs(i);
		if(tag[i]){
			qwq[x].push_back(tag[i]);
		}
	}
	ll s=0,gg=0;
	for(auto i:qwq[x]){
		if(i<0){
			if(!s)s=i,++gg;
			else if(a[-s]!=a[-i])exit(write("0\n"));
		}	
		else ++gg;
	}
	if(gg>=2){
		f[x][0]=1;
		ll w=0;
		for(auto i:qwq[x])if(i>0){
			f[i][0]=(f[i][0]+f[i][1]*(dep[i]-dep[x]))%p;
			f[x][0]=f[x][0]*f[i][0]%p;
			w+=fpm(f[i][0],p-2)*f[i][1]%p;	
		}
//		write(w,'\n');
		w%=p;
		f[x][1]=f[x][0]*w%p;
//		write(x,' ',f[x][0],' ',f[x][1],'?',s,'\n');
		if(s){
			ans=ans*f[x][0]%p;
			tag[x]=s;
		}
		else tag[x]=x;
	}
	else {
		qwq[x].push_back(0);
		tag[x]=qwq[x][0];
	}
	if(x==head[a[x]]){
		tag[x]=x;
//		write('!',x,' ',tag[x],"\n");
		f[x][1]=1;f[x][0]=0;
	}
}
int main(){
#ifdef QAQAutoMaton 
	freopen("F2.in","r",stdin);
	freopen("F2.out","w",stdout);
#endif
	ll n,k;
	read(n,k);
	for(ll i=1;i<=n;++i){
		read(a[i]);
		co[a[i]].push_back(i);
	}
	ll u,v;
	for(ll i=1;i<n;++i){
		read(u,v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dfs_pre(1,0);
	for(ll i=1;i<=k;++i){
		head[i]=*co[i].begin();
		for(auto x:co[i])head[i]=lca(head[i],x);
		if(a[head[i]] && a[head[i]]!=i)return write("0\n");
		a[head[i]]=i;
	}
	ans=1;
	dfs(1);
	ans=ans*f[tag[1]][1]%p;
	write(ans,'\n');
	return 0;
}