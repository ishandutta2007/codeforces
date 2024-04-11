/*
Author: QAQAutoMaton
Lang: C++
Code: G.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/

_/_/_/_/    _/_/_/_/_/  _/_/_/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/  _/  _/
_/      _/  _/  _/    _/    _/_/
_/_/_/_/      _/_/     _/_/_/_/_/

_/_/_/_/    _/    _/  _/      _/
_/      _/   _/  _/   _/_/  _/_/
_/      _/    _/_/    _/ _/_/ _/
_/      _/     _/     _/  _/  _/
_/      _/    _/_/    _/      _/
_/      _/   _/  _/   _/      _/
_/_/_/_/    _/    _/  _/      _/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
*/

#include<bits/stdc++.h>
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
		fill((unsigned char *)(&inf),(unsigned char *)(&inf)+sizeof(inf),0x3f);
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
char s[600005];
int to[600005][27],t=1,fail[600005];
int id[600005],val[600005];
int mx[600005];
multiset<int> st[600005];
int a[600005];
int ins(char *s){
	int at=1;
	while(*s){
		if(!to[at][*s-'a'])val[to[at][*s-'a']=++t]=-inf;
		at=to[at][*s-'a'];
		++s;
	}
	val[at]=0;
	st[at].insert(0);
	return at;
}
int q[600005],*l,*r;
vector<int> nxt[600005];
int siz[600005],hvy[600005],mxs[600005];
void dfs(int x){
	siz[x]=1;	
	for(auto i:nxt[x]){
		dfs(i);
		siz[x]+=siz[i];
		if(chkmax(mxs[x],siz[i]))hvy[x]=i;
	}
}
int c;
int top[600005],xid[600005],ct,dfn[600005];
int mxdp[600005];
int dep[600005];
int fa[600005];
int ls[600005],rs[600005],rt[600005],xsiz[600005],li[600005];
int build(int l,int r){
	if(l>r)return 0;
	if(l==r){mx[li[l]]=val[li[l]];return li[l];}
	int mid;
	int xl=l,xr=r;
	mid=(xl+xr)>>1;
	/*while(xl<=xr){
		mid=(xl+xr)>>1;
		if((xsiz[mid]-xsiz[r])<<1>=xsiz[l]-xsiz[r])xl=mid+1;
		else xr=mid-1;
	}	
	mid=xl-1;*/
	int x=li[mid];
	fa[ls[x]=build(l,mid-1)]=x;
	fa[rs[x]=build(mid+1,r)]=x;
	mx[x]=max(val[x],max(mx[ls[x]],mx[rs[x]]));
	return x;
}
int dfs2(int x){
	if(!top[x]){
		top[x]=x;
	}
	xid[++ct]=x;
	dfn[x]=ct;
	chkmax(mxdp[top[x]],dep[x]);
	if(hvy[x]){
		top[hvy[x]]=top[x];
		dep[hvy[x]]=dep[x]+1;
		dfs2(hvy[x]);
		for(auto i:nxt[x])if(i!=hvy[x]){
			dep[i]=dep[x]+1;
			fa[dfs2(i)]=x;
		}
	}
	if(top[x]==x){
		c=mxdp[x]-dep[x]+1;
		for(int i=0;i<c;++i){
			li[i+1]=xid[dfn[x]+i];
			xsiz[i+1]=siz[li[i+1]];
		}
		int y=build(1,c);
		rt[y]=1;
		return y;
	}
	else return 0;
}
void build(){
	l=q+1;r=q;
	fail[1]=1;
	for(int i=0;i<26;++i)if(!to[1][i])to[1][i]=1;else {fail[to[1][i]]=1;*(++r)=to[1][i];}
	for(;l<=r;++l){
		for(int i=0;i<26;++i)if(!to[*l][i]){to[*l][i]=to[fail[*l]][i];}else fail[*(++r)=to[*l][i]]=to[fail[*l]][i];
	}
	for(int i=2;i<=t;++i)nxt[fail[i]].emplace_back(i);
	mx[0]=-inf;
	mx[1]=val[1]=-inf;
	dfs(1);
	dfs2(1);
}
void upd(int x,int y,int id){
	st[x].erase(st[x].lower_bound(a[id]));
	st[x].insert(a[id]=y);
	if(val[x]!=*st[x].rbegin()){
		val[x]=*st[x].rbegin();
		while(1){
			mx[x]=max(val[x],max(mx[ls[x]],mx[rs[x]]));
			if(rt[x])return;
			x=fa[x];
		}
	}
}
 
int query(int x){
	int y=max(val[x],mx[ls[x]]);
	while(fa[x]){
		if(x!=ls[fa[x]]){
			chkmax(y,mx[ls[fa[x]]]);
			chkmax(y,val[fa[x]]);
		}
		x=fa[x];
	}
	return y;
}
int query(char *s){
	int at=1;
	int ans=-1;
	while(*s){
		at=to[at][*s-'a'];
		chkmax(ans,query(at));
		++s;
	}
	return ans;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,q;
	read(n,q);
	for(int i=1;i<=n;++i){
		read(s);
		id[i]=ins(s);
	}
	build();
	fa[0]=0;
	for(;q;--q){
		int tp,x,y;
		read(tp);
		if(tp==1){
			read(x,y);
			upd(id[x],y,x);
		}
		else{
			read(s);
			write(query(s),'\n');
		}
	}
	return 0;
}