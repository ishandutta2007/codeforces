/*
Author: QAQAutomaton
Lang: C++
Code: F.cpp
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
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
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
int n,m,q;	
vector<int> to[300005];
int dfn[300005],low[300005],t,stk[300005],tp;
int xu[300005],xv[300005],uv[300005];
int col[300005],c;
void dfs_bcc(int x,int f){
	dfn[x]=low[x]=++t;
	stk[++tp]=x;
	for(auto i:to[x])if(i!=f){
		int v=uv[i]^x;
		if(!dfn[v]){dfs_bcc(v,i);chkmin(low[x],low[v]);}
		else if(dfn[v]<dfn[x])chkmin(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		stk[tp+1]=-1;
		++c;
		while(stk[tp+1]!=x){
			col[stk[tp]]=c;
			--tp;
		}
	}
}
int bel[300005];
int fa[19][300005];
int bc,dep[300005];
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[0][x]=f;
	for(int i=1;i<=18;++i){
		fa[i][x]=fa[i-1][fa[i-1][x]];
	}
	bel[x]=bc;
	dfn[x]=++t;
	for(auto i:to[x])if(i!=f)dfs(i,x);
	low[x]=t;
}
int inSub(int x,int y){
	return dfn[x]<=dfn[y] && low[y]<=low[x];
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=18;~i;--i)if(dep[x]-(1<<i)>=dep[y]){
		x=fa[i][x];
	}
	if(x==y)return x;
	for(int i=18;~i;--i)if(fa[i][x] != fa[i][y]){x=fa[i][x];y=fa[i][y];}
	return fa[0][x];
}
int xn;
ll R;
int rotate(int element)
{
   element=(element+R)%xn;

   if (element==0) {
       element=xn;
   }

   return element;
}
namespace query{
	int dfn[300005],low[300005],t,stk[300005],tp,c;
	int col[300005];
	int a[300005];
	int u[300005],v[300005];
	int xu[600005],xv[600005],uv[600005],en;
	int node[900005],l;
	vector<int> to[300005];
	void add(int u,int v){
		++en;
		xu[en]=u;xv[en]=v;uv[en]=u^v;
		to[u].emplace_back(en);
		to[v].emplace_back(en);
	}

	void dfs_bcc(int x,int f){
		dfn[x]=low[x]=++t;
		stk[++tp]=x;
		for(auto i:to[x])if(i!=f){
			int v=uv[i]^x;
			if(!dfn[v]){dfs_bcc(v,i);chkmin(low[x],low[v]);}
			else if(dfn[v]<dfn[x])chkmin(low[x],dfn[v]);
		}
		if(dfn[x]==low[x]){
			stk[tp+1]=-1;
			++c;
			while(stk[tp+1]!=x){
				col[stk[tp]]=x;
				--tp;
			}
		}
	}
	void setnode(int x){
		dfn[x]=low[x]=col[x]=0;
		to[x].clear();
	}
	void build(){
		t=0;
		sort(node+1,node+l+1,[](int x,int y){return ::dfn[x]<::dfn[y];});
		for(int i=1;i<=l;++i){
			if(node[i]==node[i-1])continue;
			setnode(node[i]);
			if(i==1 || ::bel[node[i]]!=::bel[node[i-1]]){
				while(t){
					if(t>1)add(stk[t],stk[t-1]);
					--t;
				}
				stk[++t]=node[i];
			}	
			else{
				int x=node[i];
				if(::inSub(stk[t],x)){stk[++t]=x;continue;}
				while(t>1 && !::inSub(stk[t-1],x)){
					add(stk[t],stk[t-1]);
					--t;
				}
				if(t==1){
					int l=::lca(stk[1],x);
					setnode(l);
					add(stk[1],l);
					stk[1]=l;
					stk[++t]=x;
				}
				else{
					int l=::lca(stk[t],x);
					if(l==stk[t-1]){
						add(stk[t],stk[t-1]);
						stk[t]=x;
					}
					else{
						setnode(l);
						add(stk[t],l);
						stk[t]=l;
						stk[++t]=x;
					}
				}
			}
		}
		while(t){
			if(t>1)add(stk[t],stk[t-1]);
			--t;
		}
	}
	int id=0;
	bool main(){
		++id;
		en=0;
		int n,m;
		read(n,m);
		l=0;
		for(int i=1;i<=n;++i){
			read(a[i]);
			a[i]=rotate(a[i]);
			a[i]=::col[a[i]];
			node[++l]=a[i];
		}
		for(int i=1;i<=m;++i){
			read(u[i],v[i]);
			u[i]=rotate(u[i]);
			v[i]=rotate(v[i]);
			u[i]=::col[u[i]];
			v[i]=::col[v[i]];
			node[++l]=u[i];
			node[++l]=v[i];
		}
		build();
		for(int i=1;i<=m;++i)add(u[i],v[i]);
		dfs_bcc(a[1],0);
		for(int i=2;i<=n;++i)if(col[a[i]]!=col[a[1]]){return write("NO\n");}
		R+=id;
		return write("YES\n");
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	read(n,m,q);
	xn=n;
	for(int i=1;i<=m;++i){
		int &u=xu[i],&v=xv[i];
		read(u,v);
		uv[i]=u^v;
		to[u].emplace_back(i);
		to[v].emplace_back(i);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])dfs_bcc(i,0);
	for(int i=1;i<=n;++i)to[i].clear();
	for(int i=1;i<=m;++i)if(col[xu[i]]!=col[xv[i]]){
		to[col[xu[i]]].emplace_back(col[xv[i]]);	
		to[col[xv[i]]].emplace_back(col[xu[i]]);	
	}
	n=c;
	for(int i=1;i<=n;++i)dfn[i]=0;
	t=0;
	for(int i=1;i<=n;++i)if(!dfn[i]){
		++bc;
		dfs(i,0);
	}
	for(;q;--q){
		query::main();
	}
	return 0;
}