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
int l[200005],r[200005];
vector<pii> to[200005];
priority_queue<pii,vector<pii>,greater<pii> >pq;
int n;
int a[200005],ins[400005],ym[200005];
int stk[400005],t,vis[400005];
set<int> ya,yb;
int w[400005];
void find_cir(int x,int y){
	write("NO\n");	
	for(int i=1;i<=n;++i)write(a[i],i==n?'\n':' ');
	stk[++t]=y;
	int m;
	for(int i=t;i;--i)if(stk[i]==x){
		for(int j=i;j<=t;++j)w[j-i]=stk[j];
		m=t-i+1;
	}	
	for(int i=0;i<m;++i)if(w[i]<=n){
		a[w[i]]^=(w[(i+1)%m]-n)^(w[(i+m-1)%m]-n);
	}
	for(int i=1;i<=n;++i)write(a[i],i==n?'\n':' ');
	exit(0);
}
void dfs(int x){
	if(x<=n){
		auto it=yb.lower_bound(l[x]);
		while(it!=yb.end() && *it<=r[x]){
			if(*it==a[x]){++it;}
			else {
				find_cir(*it+n,x);
			}
		}
		vis[x]=1;
		ins[x]=1;
		stk[++t]=x;
		while(1){
			it=ya.lower_bound(l[x]);
			if(it!=ya.end() && *it==a[x])++it;
			if(it!=ya.end()&&*it<=r[x])dfs(*it+n);
			else break;
		}
		ins[x]=0;
		--t;
	}
	else{
		if(ins[ym[x-n]]){
			find_cir(ym[x-n],x);
		}	
		else{
			stk[++t]=x;
			ins[x]=1;
			vis[x]=1;
			ya.erase(x-n);
			yb.insert(x-n);
			dfs(ym[x-n]);
			yb.erase(x-n);
			ins[x]=0;
			--t;
		}
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	read(n);
	for(int i=1;i<=n;++i){
		read(l[i],r[i]);
		to[l[i]].push_back(make_pair(r[i],i));
	}
	for(int i=1;i<=n;++i){
		for(auto j:to[i])pq.push(j);
		a[pq.top().y]=i;
		ym[i]=pq.top().y;
		pq.pop();
	}
	for(int i=1;i<=n;++i)ya.insert(i);
	for(int i=1;i<=n;++i)if(!vis[i])dfs(i);
	write("YES\n");
	for(int i=1;i<=n;++i)write(a[i],i==n?'\n':' ');
	return 0;
}