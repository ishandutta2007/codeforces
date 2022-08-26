/*
Author: QAQAutomaton
Lang: C++
Code: G.cpp
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
int a[150005];
int n,q,p;	
struct solver{
	int id[5],cnt[5];
	void clear(){
		for(int i=0;i<p;++i){
			id[i]=cnt[i]=0;
		}
	}
	void insert(int x,int y){
		for(int i=0;i<p;++i)if(id[i]==x){cnt[i]+=y;return;}
		int mn=inf;
		for(int i=0;i<p;++i)chkmin(mn,cnt[i]);
		if(mn>y){
			for(int i=0;i<p;++i)cnt[i]-=y;
		}
		else{
			for(int i=0;i<p;++i){
				cnt[i]-=mn;
			}	
			y-=mn;
			for(int i=0;i<p;++i)if(!cnt[i]){
				id[i]=x;cnt[i]=y;return;
			}
		}
	}
	void merge(solver b){
		for(int i=0;i<p;++i)insert(b.id[i],b.cnt[i]);
	}
	void output(){
		int m=0;
		for(int i=0;i<p;++i)if(id[i])++m;
		write(m);
		for(int i=0;i<p;++i)if(id[i])write(' ',id[i]);
		write('\n');
	}
};
struct smt{
	int ls,rs;
	solver s;
	smt *l,*r;
	int stt;
	smt(int la,int ra){
		ls=la;rs=ra;
		stt=0;
		s.clear();
		if(ls==rs){
			s.insert(a[ls],1);
			l=r=0;
		}
		else{
			int mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
			s=l->s;
			s.merge(r->s);
		}
	}
	void put_tag(int x){
		stt=x;
		s.clear();
		s.insert(x,rs-ls+1);
	}
	void push_down(){
		if(stt){
			l->put_tag(stt);
			r->put_tag(stt);
			stt=0;
			return;
		}
	}
	void set(int la,int ra,int w){
		if(la<=ls && rs<=ra){
			put_tag(w);
			return;
		}
		push_down();
		if(la<=l->rs)l->set(la,ra,w);
		if(r->ls<=ra)r->set(la,ra,w);
		s=l->s;
		s.merge(r->s);
	}
	void query(int la,int ra,solver &ans){
		if(la<=ls && rs<=ra){
			ans.merge(s);
			return;
		}
		push_down();
		if(la<=l->rs)l->query(la,ra,ans);
		if(r->ls<=ra)r->query(la,ra,ans);
	}
};
smt *rt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	read(n,q,p);
	p=100/p;
	for(int i=1;i<=n;++i){
		read(a[i]);
	}
	rt=new smt(1,n);
	int tp,l,r,id;
	for(;q;--q){
		read(tp,l,r);	
		if(tp==1){
			read(id);
			rt->set(l,r,id);
		}
		else{
			solver ans;
			ans.clear();
			rt->query(l,r,ans);
			ans.output();
		}
	}
	return 0;
}