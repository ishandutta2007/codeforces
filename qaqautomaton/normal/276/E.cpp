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
vector<int> to[100005];
int vis[100005],siz[100005],sc,rt,rts,mxs[100005];
int dep[100005];
int fa[100005];
void dfs(int x,int f){
	siz[x]=1;
	mxs[x]=0;
	for(auto i:to[x])if(i!=f && !vis[i]){
		dfs(i,x);
		siz[x]+=siz[i];
		chkmax(mxs[x],siz[i]);
	}
}
void dfs1(int x,int f){
	if(chkmin(rts,max(mxs[x],sc-siz[x])))rt=x;
	for(auto i:to[x])if(i!=f && !vis[i]){
		dfs1(i,x);
	}
}
struct smt{
	int ls,rs;
	smt *l,*r;
	int tag;
	smt(int la,int ra){
		ls=la;rs=ra;
		tag=0;
		if(ls==rs){
			l=r=0;return;
		}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
	}
	void add(int la,int ra,int x){
		if(la<=ls && rs<=ra){tag+=x;return;}
		if(la<=l->rs)l->add(la,ra,x);
		if(r->ls<=ra)r->add(la,ra,x);
	}
	int query(int x){
		if(ls==rs)return tag;
		return tag+(x<=l->rs?l->query(x):r->query(x));
	}
};
smt *a[100005],*b[100005];
smt *stk[100005];
int bl,al;
int dis[100005][25],top;
void dfs2(int x,int f,int d,int id){
	dis[x][id]=d;
	chkmax(bl,d);chkmax(al,d);
	for(auto i:to[x])if(i!=f && !vis[i])dfs2(i,x,d+1,id);
}
int build(int x,int d){
	dfs(x,0);	
	sc=siz[x];
	rt=0;rts=sc;
	dfs1(x,0);
	x=rt;
	vis[x]=1;
	al=0;
	int ot=top;
	dis[x][d]=0;
	dep[x]=d;
	for(auto i:to[x])if(!vis[i]){
		bl=0;
		dfs2(i,x,1,d);
		stk[++top]=new smt(0,bl);
	}
	a[x]=new smt(0,al);
	for(auto i:to[x])if(!vis[i]){
		int son=build(i,d+1);
		fa[son]=x;
		b[son]=stk[++ot];
	}
	return x;
}
int query(int x){
	int ans=0;
	for(int y=x;y;y=fa[y]){
		ans+=a[y]->query(dis[x][dep[y]]);
		if(fa[y])ans-=b[y]->query(dis[x][dep[y]-1]);
	}
	return ans;
}
void add(int x,int d,int w){
	for(int y=x;y;y=fa[y]){
		if(dis[x][dep[y]]<=d){
			a[y]->add(0,d-dis[x][dep[y]],w);
		}
		if(fa[y] && dis[x][dep[y]-1]<=d){
			b[y]->add(0,d-dis[x][dep[y]-1],w);
		}
	}
} 
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,q,u,v,tp,x,d;
	read(n,q);
	for(int i=1;i<n;++i){
		read(u,v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	build(1,0);
	for(;q;--q){
		read(tp,u);		
		if(tp==1){
			write(query(u),'\n');
		}
		else{
			read(x,d);
			add(u,d,x);
		}
	}
	return 0;
}