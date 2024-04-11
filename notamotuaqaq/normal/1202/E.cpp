/*
Author: QAQ Automaton
LANG: C++
PROG: E.cpp
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
char s[200005],ss[200005],t[200005];
int to[200005][26];
int cnt[200005],fail[200005],xt=1,su[200005];
void insert(char *s,int at){
	if(!*s){++cnt[at];return;}
	if(!to[at][*s-'a'])to[at][*s-'a']=++xt;
	insert(s+1,to[at][*s-'a']);
}

int rto[200005][26];
int rcnt[200005],rfail[200005],rt=1;
void rinsert(char *s,int at){
	if(!*s){++rcnt[at];return;}
	if(!rto[at][*s-'a'])rto[at][*s-'a']=++rt;
	rinsert(s+1,rto[at][*s-'a']);
}
int q[200005],*l,*r;
void build(){
	l=(r=q)+1;
	for(int i=0;i<26;++i)if(to[1][i]){*(++r)=to[1][i];fail[to[1][i]]=1;}
	fail[1]=0;
	while(l<=r){
		cnt[*l]+=cnt[fail[*l]];
		for(int i=0;i<26;++i)if(to[*l][i]){
			for(int j=fail[*l];1;j=fail[j])if(to[j][i]){fail[to[*l][i]]=to[j][i];break;}
			*(++r)=to[*l][i];
		}
		++l;
	}


	l=(r=q)+1;
	for(int i=0;i<26;++i)if(rto[1][i]){*(++r)=rto[1][i];rfail[rto[1][i]]=1;}
	rfail[1]=0;
	while(l<=r){
		rcnt[*l]+=rcnt[rfail[*l]];
		for(int i=0;i<26;++i)if(rto[*l][i]){
			for(int j=rfail[*l];1;j=rfail[j])if(rto[j][i]){rfail[rto[*l][i]]=rto[j][i];break;}
			*(++r)=rto[*l][i];
		}
		++l;
	}
}
int main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(t+1);
	int l=strlen(t+1);
	int n;
	read(n);
	for(;n;--n){
		read(s);
		insert(s,1);
		int sl=strlen(s);
		for(int i=0;i<sl;++i)ss[sl-i-1]=s[i];
		ss[sl]=0;
		rinsert(ss,1);
	}
	for(int i=0;i<26;++i)to[0][i]=1;
	for(int i=0;i<26;++i)rto[0][i]=1;
	build();
	int at=1;
	for(int i=1;i<=l;++i){
		while(!to[at][t[i]-'a'])at=fail[at];
		at=to[at][t[i]-'a'];
		su[i]=cnt[at];
//		write(at,' ',cnt[at],'\n');
	}

	at=1;
	long long ans=0;
	for(int i=l;i;--i){
		while(!rto[at][t[i]-'a'])at=rfail[at];
		at=rto[at][t[i]-'a'];
		ans=ans+(ll)su[i-1]*rcnt[at];
	}
	write(ans,'\n');
	return 0;
}