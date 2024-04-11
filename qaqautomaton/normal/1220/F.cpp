/*
Author: QAQ Automaton
LANG: C++
PROG: F.cpp
Mail: cnyalilk@vip.qq.com
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
	// input a signed integer
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
	// print a signed integer
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
	int ls,rs;
	int mx;
	int tag;
	smt *l,*r;
	smt(int la,int ra){
		ls=la;rs=ra;
		mx=tag=0;
		if(ls==rs){
			l=r=0;return;
		}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
	}
	void put_tag(int x){mx+=x;tag+=x;}
	void push_down(){
		l->put_tag(tag);
		r->put_tag(tag);
		tag=0;
	}
 
	void update(int la,int ra,int x){
		if(la<=ls && rs<=ra){put_tag(x);return;}	
		push_down();
		if(la<=l->rs)l->update(la,ra,x);
		if(r->ls<=ra)r->update(la,ra,x);
		mx=max(l->mx,r->mx);
	}
	int query(int la,int ra){
		if(la<=ls && rs<=ra)return mx;
		push_down();
		int mx=0;
		if(la<=l->rs)chkmax(mx,l->query(la,ra));
		if(r->ls<=ra)chkmax(mx,r->query(la,ra));
		return mx;
	}
};
smt *rt;
vector<pair<pii,int> >v[200005];
int a[400005],b[400005],t;
int ls[400005],rs[400005];
int n;
void work(int x){
	v[1].push_back(make_pair(make_pair(x-2-ls[x+n],x-2+rs[x]),1));
	v[n-x+2].push_back(make_pair(make_pair(x-2-ls[x+n],x-2+rs[x]),-1));
	if(x>1){
 
		v[n-x+2].push_back(make_pair(make_pair(x-1-ls[x+n]-n-1,x-1+rs[x]-n-1),1));
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		a[n+i]=a[i];
	}
	t=0;
	for(int i=1;i<=n+n;++i){
		while(t && a[b[t]]>a[i])--t;
		if(t)ls[i]=i-b[t]-1;
		else ls[i]=n;
		b[++t]=i;
	}
	t=0;
	for(int i=n+n;i;--i){
		while(t && a[b[t]]>a[i])--t;
		if(t)rs[i]=b[t]-i-1;
		else rs[i]=n;
		b[++t]=i;
	}
	for(int i=1;i<=n;++i)work(i);
	rt=new smt(-n,n);
	int id=0,ans=n+5;
	for(int i=1;i<=n;++i){
		for(auto j:v[i]){
			rt->update(j.x.x,j.x.y,j.y);
		}
		if(chkmin(ans,rt->query(-i,n-i-1)))id=(n+1-i)%n;
	}
	write(ans,' ',id,'\n');
	return 0;
}