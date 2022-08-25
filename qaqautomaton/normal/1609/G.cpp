/*
Author: QAQAutoMaton
Lang: C++
Code: G.cpp
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
int a[105],b[100005];
struct smt{
	int ls,rs;
	int mx,tag,sum;
	smt *l,*r;
	smt(){}
	smt(int,int);
	void push_up(){
		mx=max(l->mx,r->mx);
		sum=l->sum+r->sum;
	}
	void put_tag(int x){
		tag+=x;
		mx+=x;
		sum+=(rs-ls+1)*x;
	}
	void push_down(){
		if(tag){
			l->put_tag(tag);r->put_tag(tag);
			tag=0;
		}
	}
	void add(int la,int ra,int w){
		if(la<=ls && rs<=ra){put_tag(w);return;}
		push_down();
		if(la<=l->rs)l->add(la,ra,w);
		if(r->ls<=ra)r->add(la,ra,w);
		push_up();
	}
	int qsum(int la,int ra){
		if(la<=ls && rs<=ra)return sum;
		push_down();
		int ans=0;
		if(la<=l->rs)ans+=l->qsum(la,ra);
		if(r->ls<=ra)ans+=r->qsum(la,ra);
		return ans;
	}
	int lb(int w){
		if(ls==rs)return ls;
		push_down();
		if(l->mx<w)return r->lb(w);
		else return l->lb(w);
	}
};
smt *rt;
smt node[2000005],*at=node;
smt *newsmt(int la,int ra){
	smt *rt=at;++at;
	*rt=smt(la,ra);return rt;
}
smt::smt(int la,int ra){
	ls=la;rs=ra;
	tag=0;
	if(ls==rs){
		l=r=0;
		mx=sum=b[ls];
	}
	else{
		int mid=(ls+rs)>>1;
		l=newsmt(ls,mid);
		r=newsmt(mid+1,rs);
		push_up();
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,m,q;	
	read(n,m,q);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=m;++i)read(b[i]);
	for(int i=n;i;--i)a[i]-=a[i-1];
	for(int i=m;i;--i)b[i]-=b[i-1];
	rt=newsmt(2,m);
	ll sta=0;
	for(int i=2;i<=m;++i)sta+=b[i]*(m-i+1);
	for(;q;--q){
		int tp,x,y;
		read(tp,x,y);
		if(tp==1){for(int i=0;i<x;++i)a[n-i]+=y;}
		else {if(x==m){b[1]+=y;--x;}rt->add(m-x+1,m,y);sta+=(x*(x+1)>>1)*y;}
		int i=1,j=1;
		ll ans=(a[1]+b[1])*(n+m-1)+sta;
		int at=n+m-1;
		for(int i=2;i<=n;++i){
			int l=2,r=m;
			int v;
			if(rt->mx<a[i])v=m+1;
			else v=rt->lb(a[i]);
			if(v>2)ans+=rt->qsum(2,v-1);
			ans+=(n-i+m-v+2)*a[i];
		}
		/*while(i<n && j<m){
			if(a[i+1]<b[j+1]){
				++i;
				ans+=a[i]*(--at);
			}
			else{
				++j;
				ans+=b[j]*(--at);
			}
		}
		while(i<n){
			++i;
			ans+=a[i]*(--at);
		}
		while(j<m){
			++j;
			ans+=b[j]*(--at);
		}
		*/
		write(ans,'\n');
	}
	return 0;
}