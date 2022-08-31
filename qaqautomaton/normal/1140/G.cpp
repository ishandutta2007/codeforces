/*
Author: QAQ-Automaton
LANG: C++
PROG: G.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
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
ll a[300005];
vector<pair<ll,pii> >to[300005];
__gnu_pbds::priority_queue<pii,greater<pii> >p;
__gnu_pbds::priority_queue<pii,greater<pii> >::point_iterator it[300005];
ll siz[300005],mxs[300005],hvy[300005],dfn[300005],t,top[300005];
ll dep[300005],fa[300005];
void dfs1(ll x,ll f){
	siz[x]=1;
	fa[x]=f;
	for(auto i:to[x])if(i.x!=f){
		dep[i.x]=dep[x];
		dfs1(i.x,x);
		siz[x]+=siz[i.x];
		if(chkmax(mxs[x],siz[i.x]))hvy[x]=i.x;	
	}
}
struct mat{
	ll a[2][2];
	ll *operator [](ll x){return a[x];}
	mat operator *(mat b){
		mat c;	
		for(ll i=0;i<2;++i)for(ll j=0;j<2;++j){
			c[i][j]=inf;
			for(ll k=0;k<2;++k)chkmin(c[i][j],a[i][k]+b[k][j]);
		}
		return c;
	}
};
mat up[300005],down[300005],mt;
struct smt{
	mat us,ds;
	ll ls,rs;
	smt *l,*r;
	smt(ll la,ll ra){
		ls=la;rs=ra;
		if(la==ra){us=up[ls];ds=down[rs];l=r=0;return;}
		ll mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
		us=l->us*r->us;
		ds=r->ds*l->ds;
	}
	mat um(ll la,ll ra){
		if(la<=ls && rs<=ra)return us;
		return la<=l->rs && r->ls<=ra?l->um(la,ra)*r->um(la,ra):(la<=l->rs?l->um(la,ra):r->um(la,ra));
	}
	mat dm(ll la,ll ra){
		if(la<=ls && rs<=ra)return ds;
		return la<=l->rs && r->ls<=ra?r->dm(la,ra)*l->dm(la,ra):(la<=l->rs?l->dm(la,ra):r->dm(la,ra));
	}
};
smt *rt;
void dfs2(ll x,ll f){
	dfn[x]=++t;		
	top[hvy[x]]=top[x];
	if(hvy[x])
	dfs2(hvy[x],x);
	for(auto i:to[x])if(i.x!=f && i.x!=hvy[x]){
		top[i.x]=i.x;
		dfs2(i.x,x);
	}
	for(auto i:to[x])if(i.x!=f){
		up[dfn[i.x]][0][0]=i.y.x;
		down[dfn[i.x]][0][0]=i.y.x;
		up[dfn[i.x]][0][1]=i.y.y+a[x];
		down[dfn[i.x]][0][1]=i.y.y+a[i.x];
		up[dfn[i.x]][1][0]=i.y.x+a[x];
		up[dfn[i.x]][1][1]=i.y.y;
		down[dfn[i.x]][1][0]=i.y.x+a[i.x];
		down[dfn[i.x]][1][1]=i.y.y;
	}
}
mat calc(ll u,ll v){
	mat su,sv;
	su[0][0]=su[1][1]=0;
	su[0][1]=su[1][0]=inf;
	sv=su;
	while(top[u]!=top[v]){
		if(dfn[top[u]]<dfn[top[v]]){
			sv=sv*rt->dm(dfn[top[v]],dfn[v]);
			v=fa[top[v]];
		}	
		else{
			su=rt->um(dfn[top[u]],dfn[u])*su;
			u=fa[top[u]];
		}
	}
	if(u==v){return sv*su;}
	if(dfn[u]<dfn[v])return sv*rt->dm(dfn[u]+1,dfn[v])*su;
	return sv*rt->um(dfn[v]+1,dfn[u])*su;
}
int main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif 
	ll n,u,v,x,y;
	read(n);
	for(ll i=1;i<=n;++i){
		read(a[i]);
		it[i]=p.push(make_pair(a[i],i));
	}
	for(ll i=1;i<n;++i){
		read(u,v,x,y);
		to[u].push_back(make_pair(v,make_pair(x,y)));
		to[v].push_back(make_pair(u,make_pair(x,y)));
	}
	while(!p.empty()){
		ll u=p.top().y;
		p.pop();
		for(auto v:to[u])if(chkmin(a[v.x],a[u]+v.y.x+v.y.y))p.modify(it[v.x],make_pair(a[v.x],v.x));
	}
	dfs1(1,0);
	top[1]=1;
	dfs2(1,0);
	rt=new smt(2,n);
	ll q;
	read(q);
	for(;q;--q){
		read(u,v);
		x=(u-1)%2;
		u=(u-1)/2+1;
		y=(v-1)%2;
		v=(v-1)/2+1;
		mt[x][0]=0;
		mt[x^1][0]=a[u];
		write((calc(u,v)*mt)[y][0],'\n');
	}
	return 0;
}