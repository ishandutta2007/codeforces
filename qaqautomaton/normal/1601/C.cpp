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
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
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
namespace run{

	// < : 1
	// > : -1
	// < - > (+>)
	// 0 (+>)
	// => + <
	// < - > < - >
	//
	int f[1000005];	
	int a[1000005],b[1000005];
	int w[1000005];
	int ra[1000005];
	namespace bit{
		int s[1000005];
		int n;
		void init(int m){
			n=m;
			for(int i=1;i<=n;++i)s[i]=0;
		}
		void add(int x,int y){for(;x;x^=x&-x)s[x]+=y;}
		int query(int x){int y=0;for(;x<=n;x+=x&-x)y+=s[x];return y;}
	}
	int calc(int *a,int n){
		for(int i=1;i<=n;++i)w[i]=a[i];
		sort(w+1,w+n+1);
		int m=unique(w+1,w+n+1)-w-1;
		for(int i=1;i<=n;++i)ra[i]=lower_bound(w+1,w+m+1,a[i])-w;
		bit::init(m);
		int s=0;
		for(int i=1;i<=n;++i){
			s+=bit::query(ra[i]+1);
			bit::add(ra[i],1);
		}
		return s;
	}
	struct smt{
		int ls,rs;
		int mx,mxc,tag;
		int s;
		smt *l,*r;
		smt(){}
		smt(int,int);
		void push_up(){
			mx=max(l->mx,r->mx);
			s=l->s+r->s;
			mxc=0;
			if(l->mx==mx)mxc+=l->mxc;
			if(r->mx==mx)mxc+=r->mxc;
		}
		void put_tag(int x){
			mx+=x;
			s+=(rs-ls+1)*x;
			tag+=x;
		}
		void push_down(){
			if(tag){l->put_tag(tag);r->put_tag(tag);tag=0;}
		}
		void add(int la,int ra,int v){
			//cerr<<ls<<' '<<rs<<' '<<la<<' '<<ra<<endl;
			if(la<=ls && rs<=ra){put_tag(v);return;}
			push_down();
			if(la<=l->rs)l->add(la,ra,v);
			if(r->ls<=ra)r->add(la,ra,v);
			push_up();
		}
	};
	smt *rt,node[2000005],*at=node;
	smt *newsmt(int la,int ra){
		smt *rt=at;++at;
		*rt=smt(la,ra);
		return rt;
	}
	smt::smt(int la,int ra){
		ls=la;rs=ra;mx=tag=s=0;
		mxc=rs-ls+1;
		if(ls==rs){l=r=0;return;}
		int mid=(ls+rs)>>1;
		l=newsmt(ls,mid);r=newsmt(mid+1,rs);
	}
	bool main(){
		int n,m;
		read(n,m);
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=1;i<=m;++i)read(b[i]);
		int cnt=calc(a,n);
		sort(b+1,b+m+1);
		f[0]=0;
		for(int i=1;i<=m;++i)f[i]=0;
		rt=newsmt(1,m);
		for(int i=1;i<=n;++i){
			int up=upper_bound(b+1,b+m+1,a[i])-b;
			if(up<=m)
			rt->add(up,m,1);
			//for(int j=up;j<=m;++j)++f[j];
			int lo=lower_bound(b+1,b+m+1,a[i])-b-1;
			cnt+=lo;
			if(lo)
			rt->add(1,lo,-1);
			
			//for(int j=1;j<=lo;++j)--f[j];
			/*for(int j=m;~j;--j){
				f[j]+=c;
				if(b[j]<a[i])++c;
			}*/
			if(rt->mx>0)rt->add(m-rt->mxc+1,m,-1);
		}
		return write(cnt+rt->s,'\n');
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t)run::main();

	return 0;
}