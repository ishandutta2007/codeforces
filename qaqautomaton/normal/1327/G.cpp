/*
Author: QAQAutomaton
Lang: C++
Code: G.cpp
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
template<class T,class T2>int chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int chkmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
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
int f[16385][1005];
char s[400005];
int v[1005];
int to[1005][15],t=1,fail[1005],w[1005],*l,*r,q[1005];
int s1[15][1005],at1[15][1005];
void add(char *s,int x){
	int at=1;
	while(*s){
		if(!to[at][*s-'a']){
			to[at][*s-'a']=++t;
		//	write(at,' ',*s-'a',' ',t,'\n');
		}
		at=to[at][*s-'a'];
		++s;
	}
	w[at]+=x;
}
void build(){
	l=q+1;r=q;
	fail[1]=1;
	for(int i=0;i<14;++i)if(to[1][i]){
		fail[to[1][i]]=1;
		*(++r)=to[1][i];
	}else to[1][i]=1;
	while(l<=r){
		w[*l]+=w[fail[*l]];
		for(int i=0;i<14;++i)if(to[*l][i]){
			fail[to[*l][i]]=to[fail[*l]][i];
			*(++r)=to[*l][i];
		}
		else to[*l][i]=to[fail[*l]][i];
		++l;
	}
/*	for(int i=1;i<=t;++i)for(int j=0;j<14;++j)write(to[i][j],j==13?'\n':' ');
	for(int i=1;i<=t;++i)write(w[i],i==t?'\n':' ');*/
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int m,x;
	read(m);
	for(int i=0;i<m;++i){
		read(s);read(x);
		add(s,x);
	}
	memset(f,-inf,sizeof(f));
	build();
	read(s+1);
	int  n=strlen(s+1);
	int c=0;
	for(int i=0;i<=n;++i){
		int j=i+1;while(j<=n && s[j]!='?')++j;
		for(int beg=1;beg<=t;++beg){
			s1[c][beg]=0;int at=beg;
			for(int l=i+1;l<j;++l){
				at=to[at][s[l]-'a'];
				s1[c][beg]+=w[at];
			}
			at1[c][beg]=at;
		}
		i=j-1;
		++c;
	}
/*	if(s[n]=='?'){
		for(int i=0;
	}*/
	--c;
//	for(int i=0;i<=c;++i)for(int j=1;j<=t;++j)write(at1[i][j],',',s1[i][j],j==t?'\n':' ');
	f[0][at1[0][1]]=s1[0][1];
	int ans=-inf;
	for(int i=0;i<1<<14;++i){
		int s=__builtin_popcount(i);
		if(s<c){
			for(int j=1;j<=t;++j){
				for(int k=0;k<14;++k)if(!(i&(1<<k))){
					chkmax(f[i|(1<<k)][at1[s+1][to[j][k]]],f[i][j]+w[to[j][k]]+s1[s+1][to[j][k]]);
				}
			}
		}else{
			for(int j=1;j<=t;++j)chkmax(ans,f[i][j]);
		}
	}
	write(ans,'\n');
	return 0;
}