/*
Author: QAQ Automaton
LANG: C++
PROG: C.cpp
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
#define up(a,b,c) for (int a(b),end##a(c);a<=end##a;++a)
#define down(a,c,b) for (int a(b),end##a(c);a>=end##a;--a)
#define uup(a,c,b) for (int a(b),end##a(c);a<=end##a;++a)
#define udown(a,b,c) for (int a(b),end##a(c);a>=end##a;--a)
char s[501010];
int sa[501010],rnk[501010],n;
int a[501010],b[501010],aa[501010],ba[501010],ab[501010];
void build_sa(){
	up(i,1,n){
		++a[s[i]-'a'+1];
	}
	up(i,1,26)a[i]+=a[i-1];
	down(i,1,n){
		sa[a[s[i]-'a'+1]]=i;
		--a[s[i]-'a'+1];		
	}
	rnk[sa[1]]=1;
	up(i,2,n){
		if(s[sa[i]]==s[sa[i-1]])rnk[sa[i]]=rnk[sa[i-1]];
		else rnk[sa[i]]=rnk[sa[i-1]]+1;
	}
	int t=1;

	while(rnk[sa[n]]!=n){
		up(i,1,n){
			a[i]=rnk[i];
			b[i]=rnk[i+t];
			aa[i]=ba[i]=0;
		}
		aa[0]=ba[0]=0;
		up(i,1,n){++aa[a[i]];++ba[b[i]];}
		up(i,1,n){aa[i]+=aa[i-1];ba[i]+=ba[i-1];}
		down(i,1,n){
			ab[ba[b[i]]]=i;
			--ba[b[i]];
		}
		down(i,1,n){
			sa[aa[a[ab[i]]]]=ab[i];
			--aa[a[ab[i]]];
		}
		rnk[sa[1]]=1;
		up(i,2,n){
			if(a[sa[i]]==a[sa[i-1]]&&b[sa[i]]==b[sa[i-1]]){
				rnk[sa[i]]=rnk[sa[i-1]];
			}
			else rnk[sa[i]]=rnk[sa[i-1]]+1;
		}
		t<<=1;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	read(s+1);
	n=strlen(s+1);
	char mn='z'+1;
	for(int i=1;i<=n;++i)if(mn>=s[i]){mn=s[i];write("Mike\n");}else write("Ann\n");
	return 0;
}