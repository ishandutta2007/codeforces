/*
Author: QAQ-Automaton
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
#define inf 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>bool chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>bool chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>bool dcmp(T a,T b){return a>b;}
template<int *a>bool cmp_a(bool x,bool y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
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
int l[100005],r[100005],w[100005],t,x[100005],y[100005];
pair<pii,pii> qwq[500005];
struct smt{
	int sum;
	int ls,rs;
	smt *lf,*rf;
	smt(int la,int ra){sum=0;ls=la;rs=ra;lf=rf=0;}
	#define l (lf?lf:(lf=new smt(ls,(ls+rs)>>1)))
	#define r (rf?rf:(rf=new smt(((ls+rs)>>1)+1,rs)))
	void add(int x,int y){
		if(ls==rs){sum+=y;return;}
		if(x<=l->rs)l->add(x,y);
		else r->add(x,y);
		sum=l->sum+r->sum;
	}	
	int query(int la){
		if(ls==la)return sum;
		if(r->ls<=la)return r->query(la);
		return l->query(la)+r->sum;
	}
	#undef l
	#undef r
};
smt *a,*b;
int ans[100005],w1[300005],w2[300005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,m,s=0,s1=0,s2=0;
	read(n,m);
	for(int i=1;i<=n;++i){
		read(l[i]);
	}
	for(int i=1;i<=n;++i){
		read(r[i]);
	}
	for(int i=1;i<=n;++i){
		read(w[i]);
	}
	for(int i=1;i<=n;++i){
		qwq[++t]=make_pair(make_pair(l[i],1),make_pair(w[i]-l[i],1));
		qwq[++t]=make_pair(make_pair(r[i]+1,1),make_pair(w[i]-l[i],-1));
		qwq[++t]=make_pair(make_pair(l[i],2),make_pair(l[i]+w[i]-1,-1));
		qwq[++t]=make_pair(make_pair(r[i]+1,2),make_pair(l[i]+w[i]-1,1));
		w1[++s]=w[i]-l[i];
		w2[s]=l[i]+w[i]-1;
	}
	for(int i=1;i<=m;++i){
		read(x[i]);
	}
	for(int i=1;i<=m;++i){
		read(y[i]);
		qwq[++t]=make_pair(make_pair(x[i],3),make_pair(y[i],i));
		w1[++s]=y[i]-x[i];
		w2[s]=x[i]+y[i];
	}
	sort(w1+1,w1+s+1);
	s1=unique(w1+1,w1+s+1)-w1-1;
	sort(w2+1,w2+s+1);
	s2=unique(w2+1,w2+s+1)-w2-1;
	sort(qwq+1,qwq+t+1);
	a=new smt(1,s1);
	b=new smt(1,s2);
	for(int i=1;i<=t;++i){
		if(qwq[i].x.y==1)a->add(lower_bound(w1+1,w1+s1+1,qwq[i].y.x)-w1,qwq[i].y.y);
		else if(qwq[i].x.y==2)b->add(lower_bound(w2+1,w2+s2+1,qwq[i].y.x)-w2,qwq[i].y.y);
		else{
			ans[qwq[i].y.y]=a->query(lower_bound(w1+1,w1+s1+1,qwq[i].y.x-qwq[i].x.x)-w1)+
				b->query(lower_bound(w2+1,w2+s2+1,qwq[i].y.x+qwq[i].x.x)-w2);
		}
	}	
	for(int i=1;i<=m;++i)write(ans[i],i==m?'\n':' ');
		
	return 0;
}