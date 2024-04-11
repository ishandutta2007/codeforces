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
const signed inf=0x3f3f3f3f;
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
pii e[400005],ans[200005];
int fa[200005],cs[200005],ct[200005],qwq[200005],bt,c;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void putans(){
	write("Yes\n");
	for(int i=1;i<=c;++i)write(ans[i].x,' ',ans[i].y,'\n');
}
int main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,m,u,v;
	read(n,m);
	for(int i=1;i<=m;++i){
		read(e[i].x,e[i].y);
	}
	int s,t,ds,dt;
	read(s,t,ds,dt);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		if(e[i].x!=s && e[i].x!=t && e[i].y!=s && e[i].y!=t&& find(e[i].x)!=find(e[i].y)){
			ans[++c]=e[i];
			fa[find(e[i].x)]=find(e[i].y);
		}
	}
	for(int i=1;i<=m;++i){
		if(e[i].y==s)swap(e[i].x,e[i].y);
		if(e[i].x==s)cs[find(e[i].y)]=i;
		if(e[i].y==t)swap(e[i].x,e[i].y);
		if(e[i].x==t)ct[find(e[i].y)]=i;
	}
	for(int i=1;i<=n;++i)if(find(i)==i && i!=s && i!=t){
		if(cs[i]||ct[i]){
			if(cs[i] && ct[i]){
				qwq[++bt]=i;	
			}
			else
			if(cs[i]){ans[++c]=e[cs[i]];--ds;}
			else{ans[++c]=e[ct[i]];--dt;}
		}else return write("No\n");
	}
	if(!bt){
		if(ct[s] && ds>0 && dt>0){
			ans[++c]=e[ct[s]];
			putans();	
			return 0;
		}
		return write("No\n");
	}
	qwq[0]=cs[0];
	if(ds>0 && dt>0 && ds+dt-1>=bt){
		for(int i=1;i<=ds && i<=bt;++i){
			ans[++c]=e[cs[qwq[i]]];
		}
		for(int i=bt;i>=ds || i>=bt;--i){
			ans[++c]=e[ct[qwq[i]]];
		}
		putans();
	}
	else return write("No\n");
	return 0;
}