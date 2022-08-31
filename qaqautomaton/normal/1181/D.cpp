/*
Author: QAQ Automaton
Lang: C++
Prog: D.cpp
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
#define inf 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
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
pii s[500005],ask[500005];
int ans[500005];
struct smt{
	int cnt;
	int ls,rs;
	smt *l,*r;	
	smt(int la,int ra){
		ls=la;rs=ra;
		cnt=0;
		if(ls==rs){l=r=0;return;}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
	}
	void add(int x){
		++cnt;
		if(ls==rs)return;
		x<=l->rs?l->add(x):r->add(x);
	}
	int kth(int x){
		if(ls==rs)return ls;
		return x<=l->cnt?l->kth(x):r->kth(x-l->cnt);
	}
};
smt *rt;
int at[500005],bt[500005],t;
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n,m,q,x;	
	read(n,m,q); for(int i=1;i<=m;++i)s[i].y=i;
	rt=new smt(1,m);
	for(int i=1;i<=n;++i){
		read(x);
		++s[x].x;
	}
	sort(s+1,s+m+1);
	for(int i=1;i<=q;++i){
		read(ask[i].x);
		ask[i].x-=n;
		ask[i].y=i;
	}
	for(int i=1;i<=m;++i){
		if(s[i].x!=s[i+1].x||i==m){
			at[++t]=i;
			bt[t]=bt[t-1]+(s[i+1].x-s[i].x)*i;
		}
	}
	bt[t]=inf;
	sort(ask+1,ask+q+1);
	int cur=0;
	for(int i=1;i<=q;++i){
		while(bt[cur]<ask[i].x){
			for(int j=at[cur]+1;j<=at[cur+1];++j){
				rt->add(s[j].y);
			}
			++cur;
		}
		ans[ask[i].y]=rt->kth((ask[i].x-bt[cur-1]-1)%at[cur]+1);
	}
	for(int i=1;i<=q;++i)write(ans[i],'\n');	
	return 0;
}