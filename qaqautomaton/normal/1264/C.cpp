/*
Author: QAQAutomaton
LANG: C++
PROG: C.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
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
map<int,int> e;
int inv[105];
const int p=998244353;
int a[200005],ia[200005];
struct smt{
	int k,b,ls,rs;
	smt *l,*r;
	smt(int la,int ra){
		ls=la;rs=ra;
		if(ls==rs){
			k=(p+1-a[ls])*ia[ls]%p;b=ia[ls]%p;
		}
		else{
			int mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
			k=(l->k+r->k*l->k+r->k)%p;
			b=(l->b+r->b+r->k*l->b)%p;
			/*
			 *	(k1x+b1+x)*k2+b2+(k1x+b1+x)-x
			 *	(k1+k2+k1k2)x+(b1+b2+b1k2)
			 *
			 * */
		}
	}
	void getv(int &x,int la,int ra){
		if(la<=ls&&rs<=ra){
			x=(x+x*k+b)%p;
			return;
		}
		if(la<=l->rs)l->getv(x,la,ra);
		if(r->ls<=ra)r->getv(x,la,ra);
	}

};
smt *rt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,q;
	read(n,q);
	inv[1]=1;
	for(int i=2;i<=100;++i)inv[i]=(p-p/i)*inv[p%i]%p;
	int x,w;
	for(int i=1;i<=n;++i){
		read(x);
		a[i]=x*inv[100]%p;
		ia[i]=100*inv[x]%p;
	}
	rt=new smt(1,n);
	rt->getv(w=0,1,n);
	e[1]=w;
	int ans=w;
	e[n+1]=0;
	int cnt=0;
	for(;q;--q){
		read(x);
		if(e.count(x)){
			auto it=e.lower_bound(x),it2=it,it3=it;
			++it2;
			--it3;
			ans=(ans-it->y+p)%p;
			ans=(ans-it3->y+p)%p;
			e.erase(it);
			rt->getv(w=0,it3->x,it2->x-1);
			it3->y=w;
//			-1b[nx-1]*a[it3->x-1]%p;
			ans=(ans+it3->y)%p;
			--cnt;
		}
		else{
			auto it=e.lower_bound(x),it2=it;
			--it2;
			rt->getv(w=0,it2->x,x-1);
			ans=(ans+p-it2->y)%p;
			it2->y=w;
			ans=(ans+it2->y)%p;
			rt->getv(w=0,x,it->x-1);
			ans=(ans+w)%p;
			e[x]=w;
			++cnt;
		}
		write(ans,'\n');
	}
	return 0;
}
/*
fi=(1-p)f1+f(i+1)p+1
fn=(1-p)f1+1
fi->f(i+1)
gi=E(i->i+1)
gi=(1-p)sum(j<=i)gj+1

gi=((1-p)sum(j<i)gj+1)/p
g1=1/p
g2=(1-p2) p2+x
g2=((1-p2)g1)/p2
g1->g2 => 
sum -> 
(1-p) (1-p) (1-p)
2/10 3/10 4/10 5/10
*/