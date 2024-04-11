/*
Author: QAQAutomaton
Lang: C++
Code: A.cpp
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
int a[500005];
int f[500005],g[500005];
struct smt{
	int tag;
	int rmx,mx;
	int ls,rs;
	smt(){}
	smt(int,int);
	smt *l,*r;
	void put_tag(){rmx=mx+1;tag=1;}
	void push_down(){
		if(tag){l->put_tag();r->put_tag();tag=0;}
	}
	void query(int ra,int &ans){ 
		if(rs<=ra){chkmax(ans,rmx);return;}
		push_down();
		l->query(ra,ans);
		if(ra>l->rs)r->query(ra,ans);
	}
	void add(int x,int y){
		if(ls==rs){chkmax(mx,y);chkmax(rmx,y);return;}
		push_down();
		if(x<=l->rs)l->add(x,y);else r->add(x,y);
		rmx=max(l->rmx,r->rmx);
		mx=max(l->mx,r->mx);
	}
	void set(int ra){
		if(rs<=ra){put_tag();return;}
		push_down();
		l->set(ra);
		if(ra>l->rs)r->set(ra);
		rmx=max(l->rmx,r->rmx);
		mx=max(l->mx,r->mx);
	}
};
smt *rt,node[1000005],*at=node;
smt *newsmt(int la,int ra){
	smt *rt=++at;
	*rt=smt(la,ra);
	return rt;
}
smt::smt(int la,int ra){
	tag=0;rmx=mx=-inf;
	ls=la;rs=ra;
	if(ls==rs){l=r=0;return;}
	int mid=(ls+rs)>>1;
	l=newsmt(ls,mid);
	r=newsmt(mid+1,rs);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	int t;
	read(t);
	int n;
	for(;t;--t){
		read(n);
		for(int i=1;i<=n;++i)read(a[i]);
		int ans=0;
		int mx=0;
		at=node;
		rt=newsmt(1,n);
		for(int i=1;i<=n;++i){
			f[i]=mx>=a[i];
			bool ok=0;
			rt->query(a[i],f[i]);
			++f[i];
			//chkmax(f[i],rt->query(a[i])+1);
			/*for(int j=i-1;j;--j){
				if(a[j]<=a[i])chkmax(f[i],f[j]+1+ok);
				if(a[j]>=a[i]){chkmax(f[i],2);ok=1;}
			}*/
			//write(i,' ',f[i],'\n');	
			chkmax(ans,f[i]);
			rt->set(a[i]);
			rt->add(a[i],f[i]);
			chkmax(mx,a[i]);
			// fi is next geq i
			// first last can leq i
			//f[i] -> i is min(a[i],a[i+1])
			//g[i] -> i+1 is
		}
		write(ans,'\n');
	}
	return 0;
}