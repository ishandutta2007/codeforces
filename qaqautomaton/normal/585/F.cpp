/*
Author: QAQAutomaton
Lang: C++
Code: F.cpp
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
char s[1005],l[55],r[55];
int t=2;
int to[50005][10],fail[50005];
bitset<50005>vis;
int n,m;
void add(char *w){
	int at=1;
	for(int i=1;i<=m;++i,++w){
		if(i==m)to[at][*w^'0']=2;
		else{
			if(!to[at][*w^'0'])to[at][*w^'0']=++t;
			at=to[at][*w^'0'];
		}
	}
}
int q[50005];
void work(){
	vis[1]=vis[2]=1;	
	int *l=q+1,*r=q;
	for(int i=0;i<10;++i)if(to[1][i]){
		fail[*(++r)=to[1][i]]=1;
	}else to[1][i]=1;
	for(;l<=r;++l){
		for(int i=0;i<10;++i)if(to[*l][i]){
			if(to[*l][i]!=2)
			fail[*(++r)=to[*l][i]]=to[fail[*l]][i];
		}else to[*l][i]=to[fail[*l]][i];	
	}
}

int f[55][50005];
const int p=1000000007;
int add(int &a,const int &b){return (a+=b)>=p?a-=p:a;}
int minu(int &a,const int &b){return (a-=b)<0?a+=p:a;}
int dp(char *s,int n){
	int at=1;
	for(int i=0;i<n;++i)for(int j=1;j<=t;++j)f[i][j]=0;
	for(int i=0;i<n;++i){
		for(int j=!i;j<s[i]-'0';++j){
			add(f[i][to[at][j]],1);	
		}
		for(int j=1;j<=t;++j)for(int k=0;k<10;++k)add(f[i+1][to[j][k]],f[i][j]);
		at=to[at][s[i]-'0'];
	}
	if(at==2)add(f[n-1][2],1);
	return f[n-1][2];
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	read(s);	
	read(l);	
	read(r);	
	n=strlen(s);
	m=strlen(l)>>1;
	for(int i=0;i<10;++i)to[2][i]=2;
	for(int i=0;i+m<=n;++i){
		add(s+i);
	}
	work();
	int d=strlen(l);	
	int s=dp(r,d);
	--l[d-1];
	int w=d-1;
	while(l[w]<'0'){l[w]='9';--l[--w];}
	if(l[0]>'0')minu(s,dp(l,d));
	write(s,'\n');
	return 0;
}