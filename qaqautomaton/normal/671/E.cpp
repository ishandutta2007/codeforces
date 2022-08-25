/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
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
int a[100005],b[100005],f[100005],g[100005];
int s[100005],t;
int n,k;
struct smt{
	int amn,bmn,atg;	
	int ls,rs;
	smt *l,*r;
	smt(int la,int ra){
		amn=inf;bmn=-inf;
		atg=0;
		ls=la;rs=ra;
		if(ls==rs){
			l=r=0;
		}
		else{
			int mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
		}
	}
	void setg(int x){
		if(ls==rs){
			amn=bmn=g[x];	
			return;
		}
		if(x<=l->rs)l->setg(x);
		else r->setg(x);
		amn=min(l->amn,r->amn);
		bmn=min(l->bmn,r->bmn);
	}
	void push_down(){
		l->atg+=atg;
		l->amn+=atg;
		r->atg+=atg;
		r->amn+=atg;
		atg=0;
	}
	void add(int la,int ra,int w){
		if(la<=ls && rs<=ra){
			atg+=w;amn+=w;
			return;
		}
		push_down();
		if(la<=l->rs)l->add(la,ra,w);
		if(ra>=r->ls)r->add(la,ra,w);
		amn=min(l->amn,r->amn);
	}
	int query(int x,int rm){
		if(ls>rm)return 0;
		if(bmn-k>x)return 0;
		if(ls==rs)return ls;
		push_down();
		if(min(x,l->amn)>=r->bmn-k){
			int ans=r->query(min(x,l->amn),rm);
			if(ans)return ans;
		}
		return l->query(x,rm);
	}
};
smt *rt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(n,k);
	rt=new smt(1,n);
	for(int i=1;i<n;++i)read(b[i]);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i){
		f[i]=f[i-1]+a[i-1]-b[i-1];
	}
	for(int i=1;i<=n;++i){
		g[i]=g[i-1]+b[i-1]-a[i];
	}
	int ans=0;
	for(int i=n;i;--i){
		rt->setg(i);
		while(t && f[s[t]]>=f[i]){
			if(t>1){
				rt->add(s[t-1]-1,n,f[s[t]]-f[s[t-1]]);
			}
			--t;
		}
		s[++t]=i;
		if(t>1)assert(f[s[t]]>=f[s[t-1]]);
		if(t>1){
			rt->add(s[t-1]-1,n,f[s[t-1]]-f[s[t]]);
		}

		s[0]=n+1;

		int l=1,r=t,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(f[i]-f[s[mid]]<=k)r=mid-1;
			else l=mid+1;
		}
		chkmax(ans,rt->query(inf,s[r]-1)-i+1);
	}
	write(ans,'\n');
	return 0;
}