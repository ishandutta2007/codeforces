/*
Author: QAQ-Automaton
LANG: C++
PROG: F.cpp
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
const ll inf=1e18;
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
struct smt{
	ll ls,rs,tag,mn;
	smt *l,*r;
	smt(ll la,ll ra){
		ls=la;rs=ra;
		tag=mn=0;
		if(ls==rs){l=r=0;}
		else{
			ll mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
		}
	}
	void push_up(){
		mn=min(l->mn,r->mn);
	}
	void put_tag(ll x){
		tag+=x;mn+=x;
	}
	void push_down(){
		l->put_tag(tag);
		r->put_tag(tag);
		tag=0;
	}
	void add(ll la,ll ra,ll w){
		if(la<=ls && rs<=ra){put_tag(w);return;}	
		push_down();
		if(la<=l->rs)l->add(la,ra,w);
		if(r->ls<=ra)r->add(la,ra,w);
		push_up();
	}
	ll qmin(ll la,ll ra){
		if(la<=ls && rs<=ra)return mn;
		push_down();
		ll ans=inf;
		if(la<=l->rs)chkmin(ans,l->qmin(la,ra));
		if(r->ls<=ra)chkmin(ans,r->qmin(la,ra));
		return ans;
	}
};
smt *rt;
vector<pii> son[500005];
vector<pair<ll,pii> > asks[500005];
ll dis[500005],ans[500005],l[500005],r[500005],c;
void dfs1(ll x){
	rt->add(x,x,son[x].size()?inf:dis[x]);
	l[x]=++c;
	for(auto i:son[x]){
		dis[i.x]=dis[x]+i.y;
		dfs1(i.x);	
	}
	r[x]=c;
}
void dfs2(ll x){
	for(auto i:asks[x]){
		ans[i.x]=rt->qmin(i.y.x,i.y.y)+dis[x];	
	}
	for(auto i:son[x]){
		rt->add(l[i.x],r[i.x],-2*i.y);	dfs2(i.x); rt->add(l[i.x],r[i.x],2*i.y);	
	}
}
int main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	ll n,q,x,l,r;
	read(n,q);
	for(ll i=2;i<=n;++i){
		ll f,w;
		read(f,w);
		son[f].push_back(make_pair(i,w));
	}
	rt=new smt(1,n);
	dfs1(1);
	for(ll i=1;i<=q;++i){
		read(x,l,r);
		asks[x].push_back(make_pair(i,make_pair(l,r)));
	}
	dfs2(1);
	for(ll i=1;i<=q;++i)write(ans[i],'\n');
	return 0;
}