/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
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
vector<int> to[200005];
int dfn[200005],c,dep[200005];
pii w[19][400005];
int lg[400005];
void dfs(int x,int f){
	dfn[x]=++c;	
	dep[x]=dep[f]+1;
	w[0][c]=make_pair(dep[x],x);
	for(auto i:to[x])if(i!=f){
		dfs(i,x);
		w[0][++c]=make_pair(dep[x],x);
	}
}
int a[200005],s[200005],b[200005],id[200005],is[200005];
int nd[400005];
int dis[200005];
int stk[200005],t;
vector<int> xto[200005];
int vis[200005],tod[200005],cd,fa[200005];
int make(int x){if(!vis[x]){vis[x]=1;tod[++cd]=x;}return x;}
pii query(int l,int r){
	if(l>r)swap(l,r);
	return min(w[lg[r-l+1]][l],w[lg[r-l+1]][r+1-(1<<(lg[r-l+1]))]);
}
int lca(int a,int b){return query(dfn[a],dfn[b]).y;}
int mn[200005],d[200005],at[200005],del[200005];
__gnu_pbds::priority_queue<pii,greater<pii> > pq;
__gnu_pbds::priority_queue<pii,greater<pii> >::point_iterator it[200005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,q,u,v,m,k;
	read(n);
	for(int i=1;i<n;++i){
		read(u,v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dfs(1,0);
	for(int i=2;i<=c;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=18;++i)for(int j=1;j+(1<<i)-1<=c;++j)w[i][j]=min(w[i-1][j],w[i-1][j+(1<<(i-1))]);
	read(q);
	for(;q;--q){
		read(m,k);
		for(int i=1;i<=m;++i){
			read(a[i]);
			read(s[a[i]]);
			nd[i]=a[i];
			id[a[i]]=i;
		}
		for(int i=1;i<=k;++i){read(b[i]);nd[i+m]=b[i];}
		int mk=m+k;
		sort(nd+1,nd+mk+1,cmp_a<dfn>);
		mk=unique(nd+1,nd+mk+1)-nd-1;
		t=0;
		stk[++t]=make(1);
		for(int i=1;i<=mk;++i){
			if(nd[i]==1)continue;
			int ot=t;
			while(dep[lca(nd[i],stk[t])]<dep[stk[t]])--t;
			if(t<ot && lca(stk[t+1],nd[i])!=stk[t]){
				int nw=lca(stk[t+1],nd[i]);
				fa[stk[t+1]]=nw;
				fa[nw]=stk[t];
				stk[++t]=make(nw);
			}
			fa[nd[i]]=stk[t];
			stk[++t]=make(nd[i]);
		}
		for(int i=2;i<=cd;++i){
			xto[tod[i]].push_back(fa[tod[i]]);
			xto[fa[tod[i]]].push_back(tod[i]);
		}
		for(int i=1;i<=cd;++i)mn[tod[i]]=d[tod[i]]=inf;
		for(int i=1;i<=m;++i){
			at[a[i]]=a[i];	
			d[a[i]]=0;
			mn[a[i]]=0;
		}
		for(int i=1;i<=cd;++i){
			it[tod[i]]=pq.push(make_pair(mn[tod[i]],tod[i]));
		}
		while(!pq.empty()){
			int x=pq.top().y;
			del[x]=1;
			pq.pop();
			for(auto i:xto[x]){
				int w=d[x]+abs(dep[x]-dep[i]),xw=((w-1)/s[at[x]])*n+id[at[x]];
				if(!del[i] && chkmin(mn[i],xw)){d[i]=w;pq.modify(it[i],make_pair(mn[i],i));at[i]=at[x];}
			}
		}
		for(int i=1;i<=k;++i)write(id[at[b[i]]],i==k?'\n':' ');
		for(int i=1;i<=m;++i)s[a[i]]=id[a[i]]=0;
		while(cd){
			fa[tod[cd]]=vis[tod[cd]]=0;
			del[tod[cd]]=0;
			xto[tod[cd]].clear();
			--cd;
		}
	}
	return 0;
}