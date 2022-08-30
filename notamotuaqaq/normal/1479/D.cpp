/*
Author: QAQAutoMaton
Lang: C++
Code: D.cpp
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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()/100);
int isp(int x){
	if(x<=1)return 0;
	for(int i=2;i*i<=x;++i)if(!(x%i))return 0;
	return 1;
}
int randp(int l,int r){
	int w=0;
	while(!isp(w=rnd()%(r-l+1)+l));
	return w;
}
const int c=5;
int xp[6],xq[6];
int pw[6][300005];
vector<int> to[300005];
int fa[19][300005],dep[300005];
int a[300005];
int rt[300005];
int n;
struct node{
	int l,r,h[6];
};
node v[20000005];
int t;
int clone(int x){
	++t;
	v[t]=v[x];return t;
}
int xl;
int ans;
#define l(x) v[x].l
#define r(x) v[x].r
#define h(x) v[x].h
int bmod(int x,int p){return x>=p?x-p:x;}
void Ins(int &rt,int ls,int rs,int x){
	rt=clone(rt);
	if(ls==rs){
		if(h(rt)[1])for(int i=1;i<=c;++i)h(rt)[i]=0;else for(int i=1;i<=c;++i)h(rt)[i]=pw[i][x];
		return;
	}
	int mid=(ls+rs)>>1;
	if(x<=mid)Ins(l(rt),ls,mid,x);
	else Ins(r(rt),mid+1,rs,x);
	for(int i=1;i<=c;++i){h(rt)[i]=bmod(h(l(rt))[i]+h(r(rt))[i],xp[i]);}
}
int same(int x,int y){
	for(int i=1;i<=c;++i)if(h(x)[i]!=h(y)[i])return 0;
	return 1;
}
bool Query(int r1,int r2,int ls,int rs,int xl,int xr){
	if(rs<xl||xr<ls)return 0;
	//write(ls,' ',rs,' ',xl,' ',xr,' ',::xl,' ',a[::xl],'\n');
	if(ls==rs){
		if(same(r1,r2)==(ls==a[::xl])){ans=ls;return 1;}
		return 0;
	}
	if(same(r1,r2) && (a[::xl]<ls || rs<a[::xl]))return 0;
	int mid=(ls+rs)>>1;
	return Query(l(r1),l(r2),ls,mid,xl,xr)||Query(r(r1),r(r2),mid+1,rs,xl,xr);
}
#undef l
#undef r
#undef h
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=18;~i;--i)if(dep[x]-(1<<i)>=dep[y])x=fa[i][x];
	if(x==y)return x;
	for(int i=18;~i;--i)if(fa[i][x]!=fa[i][y]){x=fa[i][x];y=fa[i][y];}
	return fa[0][x];
}
void dfs(int x,int f){
	fa[0][x]=f;
	dep[x]=dep[f]+1;
	rt[x]=rt[f];
	Ins(rt[x],1,n,a[x]);
	for(int i=1;i<=18;++i)fa[i][x]=fa[i-1][fa[i-1][x]];
	for(auto i:to[x])if(i!=f){
		dfs(i,x);
	}	
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int q;	
	read(n,q);
	for(int i=1;i<=c;++i){
		xp[i]=randp(900000000,1000000000);
		xq[i]=randp(2,100);
	}	
	for(int j=1;j<=c;++j){
		pw[j][0]=1;
		for(int i=1;i<=n;++i){
			pw[j][i]=(ll)pw[j][i-1]*xq[j]%xp[j];
		}
	}
	for(int i=1;i<=n;++i)read(a[i]);
	int u,v;
	for(int i=1;i<n;++i){
		read(u,v);
		to[u].emplace_back(v);
		to[v].emplace_back(u);
	}
	dfs(1,0);
	for(;q;--q){
		int u,v,l,r;
		read(u,v,l,r);
		xl=lca(u,v);
		ans=-1;
		Query(rt[u],rt[v],1,n,l,r);
		write(ans,'\n');
	}
	return 0;
}