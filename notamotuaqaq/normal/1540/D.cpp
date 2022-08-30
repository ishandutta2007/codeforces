/*
Author: QAQAutoMaton
Lang: C++
Code: D.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
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
int b[100005];
const int B=200;
int blk[100005];
int st[100005],ed[100005];
vector<int> xblk[100005];
int w[100005];
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
namespace fhq{
	int ls[200005],rs[200005],v[200005],w[200005],tag[200005];
	int rv[200005];
	int t,rt;
	int stk[200005],tp;
	bitset<200005>del;
	int newNode(int x){
		++t;
		ls[t]=rs[t]=0;
		v[t]=x;w[t]=rnd();
		return t;
	}
	void put_tag(int x,int y){
		if(x){v[x]+=y;tag[x]+=y;}
		
	}
	void push_down(int x){
		if(tag[x]){
			put_tag(ls[x],tag[x]);put_tag(rs[x],tag[x]);
			tag[x]=0;
		}
	}
	void split(int rt,int w,int &r1,int &r2){
		if(!rt){r1=r2=0;return;}
		push_down(rt);
		if(v[rt]<=w){
			r1=rt;
			split(rt[rs],w,r1[rs],r2);
		}
		else{
			r2=rt;
			split(rt[ls],w,r1,r2[ls]);
		}
	}
	int merge(int r1,int r2){
		if(!r2)return r1;
		if(!r1)return r2;
		if(w[r1]<w[r2]){
			push_down(r1);
			r1[rs]=merge(r1[rs],r2);
			return r1;
		}
		else{
			push_down(r2);
			r2[ls]=merge(r1,r2[ls]);
			return r2;
		}
	}
	void output(int x,vector<int> &out,int &cur){
		push_down(x);
		if(ls[x])output(ls[x],out,cur);
		out[cur]=v[x];++cur;
		if(rs[x])output(rs[x],out,cur);
	}	
}
void build(int x){
	int l=st[x],r=ed[x];
	fhq::t=0;fhq::rt=fhq::newNode(b[r]);
	int c=1;
	int r1,r2;
	for(int i=r-1;i>=l;--i){
		fhq::split(fhq::rt,b[i],r1,r2);
		int v=fhq::newNode(b[i]);
		fhq::put_tag(r2,-1);
		fhq::rt=fhq::merge(r1,fhq::merge(v,r2));
	}
	int cur=0;
	xblk[x].resize(fhq::t);
	fhq::output(fhq::rt,xblk[x],cur);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n;	
	read(n);
	for(int i=1;i<=n;++i){
		read(b[i]);
		b[i]=i-b[i];
		blk[i]=(i-1)/B+1;
		ed[blk[i]]=i;
		if(!st[blk[i]])st[blk[i]]=i;
	}
	for(int i=1;i<=blk[n];++i)build(i);
	int q;
	read(q);
	for(;q;--q){
		int tp,x,y;
		read(tp,x);
		if(tp==1){
			read(b[x]);b[x]=x-b[x];
			build(blk[x]);
		}
		else{
			int y=b[x];
			if(x<n){
				for(int i=x+1;i<=ed[blk[x+1]];++i)if(y>=b[i])++y;
				for(int i=blk[x+1]+1;i<=blk[n];++i)y+=upper_bound(all(xblk[i]),y)-xblk[i].begin();
			}
			write(y,'\n');
		}
	}
	return 0;
}