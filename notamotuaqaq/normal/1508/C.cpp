/*
Author: QAQAutoMaton
Lang: C++
Code: C.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
#define debug(qaq...) fprintf(stderr,qaq)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())
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
int xu[200005],xv[200005],xw[200005];
vector<int> to[200005];
set<int> ts[200005],st;
int fa[200005];
int q[200005],*l,*r;
void bfs(int v){
	*(l=r=q)=v;
	st.erase(v);
	fa[v]=v;
	for(;l<=r;++l){
		int x=*l;
		for(set<int>::iterator it=st.begin();it!=st.end();){
			if(ts[x].count(*it)){++it;continue;}
			else{
				auto nw=it;++nw;
				*(++r)=*it;
				fa[*it]=v;
				st.erase(it);
				it=nw;
			}
		}
	}
}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
struct edge{
	int u,v,w;
};
edge e[200005];
bool operator<(const edge &a,const edge &b){return a.w<b.w;}
pii xe[200005];
int c;
int merge(int x,int y,int w){
	if(find(x)!=find(y)){fa[find(y)]=find(x);return w;}
	return 0;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,m;	
	read(n,m);
	int rem=n>=1000?inf:n*(n-1)/2-m;
	int s=0;
	for(int i=1;i<=m;++i){
		read(e[i].u,e[i].v,e[i].w);
		s^=e[i].w;
		int u=e[i].u,v=e[i].v;
		to[u].emplace_back(v);
		to[v].emplace_back(u);
		ts[u].insert(v);ts[v].insert(u);
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;++i)st.insert(i);
	int l=n;
	for(int i=1;i<=n;++i){
		if(st.count(i)){
			bfs(i);
			--l;
		}
	}
	int sa=0;
	for(int i=1;i<=m;++i){
		if(find(e[i].u)!=find(e[i].v)){
			sa+=e[i].w;
			fa[find(e[i].v)]=find(e[i].u);
		}
	}
	//write(xs,' ',s,' ',sa,' ',l,' ',rem,'\n');
	if(l<rem)return write(sa,'\n');
	int ans=sa+s;
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(!ts[i].count(j)){
		xe[++c]={i,j};
	}
	int v=0;
	for(int i=1;i<=m;++i)if(e[i].w<=s){v=i;}
	else break;
	for(int i=1;i<=c;++i){
		for(int j=1;j<=n;++j)fa[j]=j;
		int cnt=0;
		for(int j=1;j<=c;++j)if(i!=j)merge(xe[j].x,xe[j].y,0);
		for(int j=1;j<=v;++j){
			cnt+=merge(e[j].u,e[j].v,e[j].w);
		}
		cnt+=merge(xe[i].x,xe[i].y,s);
		for(int j=v+1;j<=m;++j)
			cnt+=merge(e[j].u,e[j].v,e[j].w);
		chkmin(ans,cnt);
	}
	write(ans,'\n');
	return 0;
}