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
namespace bit{
	int a[400005];
	int n=400000,y;
	void add(int x,int y){if(x)for(;x<=n;x+=x&-x)a[x]+=y;}
	int sum(int x){for(y=0;x;x^=x&-x)y+=a[x];return y;}
}
namespace lct{
	int fa[200005],son[200005][2],t;
	int siz[200005],rev[200005],col[200005];
	void push_up(int x){siz[x]=1+siz[son[x][0]]+siz[son[x][1]];}	
	void put_rev(int x){rev[x]^=1;swap(son[x][0],son[x][1]);}
	void rotate(int x){
		int f=fa[x],g=fa[f],slr=son[f][1]==x;
		fa[f]=x;fa[x]=g;
		if(son[g][1]==f)son[g][1]=x;
		if(son[g][0]==f)son[g][0]=x;
		fa[son[f][slr]=son[x][slr^1]]=f;
		son[x][slr^1]=f;
		push_up(f);
		push_up(x);
	}
#define ntr(x) (fa[x] && (son[fa[x]][1]==x||son[fa[x]][0]==x))
	void push_tag(int x){
		if(ntr(x))push_tag(fa[x]);
		if(rev[x]){put_rev(son[x][0]);put_rev(son[x][1]);rev[x]=0;}
		col[son[x][0]]=col[x];
		col[son[x][1]]=col[x];
	}
	void splay(int x){
		push_tag(x);
		while(ntr(x)){
			int f=fa[x];
			if(ntr(f)){
				if((son[f][1]==x)==(son[fa[f]][1]==f))rotate(f);
				else rotate(x);
			}
			rotate(x);
		}
	}
	void access(int x,int c=0){
		int y=0;
		for(;x;y=x,x=fa[x]){
			splay(x);
			son[x][1]=0;
			push_up(x);
			bit::add(col[x],-siz[x]);
			son[x][1]=y;
			push_up(x);
		}	
		col[y]=c;
		bit::add(c,siz[y]);
	}
	void mtr(int x){
		access(x,t);
		splay(x);
		put_rev(x);
		access(x,++t);
	}
	void link(int x,int y){
		mtr(x);
		fa[x]=y;
	}
	int ask(int x){
		splay(x);
		return bit::sum(col[x])-siz[son[x][0]];
	}
}
char s[15];
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,q,u,v;
	read(n,q);
	for(int i=1;i<n;++i){
		read(u,v);
		lct::link(u,v);
	}
	lct::t=0;
//	for(int i=1;i<=n;++i){bit::add(lct::col[i],-1);lct::col[i]=0;lct::rev[i]=0;}
	for(int i=1;i<=n;++i)lct::mtr(i);
	for(;q;--q){
		read(s);
		read(u);
		if(*s=='u'){lct::mtr(u);}
		else if(*s=='w'){write(lct::ask(u),'\n');}
		else{read(v); write(lct::ask(u)<lct::ask(v)?u:v,'\n');}
	}
	return 0;
}