/*
Author: QAQ Automaton
Lang: C++
Prog: C.cpp
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
char s[15];
int a[15][83][83],w[83][83][83];
int mp[128];
const int p=998244353;

int n,t;
vector<int> ok;
int orz[8];
int qaq(int len){
	for(int i=1;i<=t;++i)for(int j=i;j<=t;++j)for(int k=j;k<=t;++k){
		w[i][j][k]=0;
	}
	for(int l=1;l<=t;++l){
		for(int i=1;i<=t;++i)for(int j=i;j<=t;++j)for(int k=i;k<=t;++k)
			w[i][j][k]=(w[i][j][k]+a[len][i][l]*a[len][j][l]%p*a[len][k][l])%p;
	}
	int ans=0;
	for(int i=1;i<=t;++i)for(int j=i;j<=t;++j){
		for(int k=j;k<=t;++k)
			for(int l=k;l<=t;++l)
				ans=(ans+w[i][j][k]*w[i][k][l]%p*w[i][j][l]%p*w[j][k][l]%p*
					orz[(j==i)|((j==k)<<1)|((k==l)<<2)])%p;
	}
	return ans;
}
int neq(char *a){
	int s=strlen(a)-1;
	for(int i=0;i<=s;++i)if(a[i]!=a[s-i])return 1;
	return 0;
}
set<unsigned long long> st[11];
int l;
unsigned long long hsh(char *s){
	unsigned long long w=0;
	for(char *i=s;*i;++i)w=w*t+mp[*i]-1;
	return w;
}
void reverse(char *s){
	for(int i=0,j=strlen(s)-1;i<j;++i,--j)swap(s[i],s[j]);
	
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	read(n);

	/*for(int i='a';i<='p';++i)mp[i]=++t;
	for(int i='A';i<='P';++i)mp[i]=++t;*/
	for(int i='a';i<='z';++i)mp[i]=++t;
	for(int i='A';i<='Z';++i)mp[i]=++t;
	for(int i='0';i<='9';++i)mp[i]=++t;
	for(int i=1;i<=n;++i){
		read(s);
		l=strlen(s);
		int x=mp[s[0]],y=mp[s[l-1]];
		unsigned long long w;
		if(!st[l].count(w=hsh(s))){
			st[l].insert(w);
			++a[strlen(s)][x][y];
		}
		reverse(s);
		if(!st[l].count(w=hsh(s))){
			st[l].insert(w);
			++a[strlen(s)][y][x];
		}
	}
	int ans=0;
	orz[0]=24;
	orz[1]=orz[2]=orz[4]=12;
	orz[3]=orz[6]=4;
	orz[5]=6;
	orz[7]=1;
	for(int len=3;len<=10;++len){
		ans=(ans+qaq(len))%p;
	}
	write(ans,'\n');
	return 0;
}