/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp
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
char s[200005];
int a[200005],b[200005],c[200005];
int p[8],q[8];
int pw[8][200005],ipw[8][200005];
int h[8][200005];
int p1,p2,q1,q2;
const int m=5;
mt19937 ran;
int is_prime(int p){
	for(int i=2;i*i<=p;++i)if(!(p%i))return 0;
	return 1;
}
int rand_p(int l,int r){
	int p=ran()%(r-l+1)+l;
	while(!is_prime(p))
		p=ran()%(r-l+1)+l;
	return p;
}
int fpm(int a,int b,int p){
	int c=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
int cnt[200005];
int hsh(int id,int l,int s){
	int r=l+s;
	if(!b[r]||!a[r-1])return ((h[id][l]-h[id][r]*pw[id][cnt[r-1]-cnt[l-1]])%p[id]+p[id])%p[id];
	else{
		int w=(h[id][l]-(h[id][r]-1)*pw[id][cnt[r-1]-cnt[l-1]])%p[id];
		if(c[r-1]^(cnt[r-1]==cnt[l-1]?c[l-1]:0))
			w+=pw[id][cnt[r-1]-cnt[l-1]];
		else 
			w-=pw[id][cnt[r-1]-cnt[l-1]];
		return (w%p[id]+p[id])%p[id];
	}
}

signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	ran=mt19937(time(0)^114514);
	int n;
	read(n);
	for(int i=1;i<=m;++i){
		p[i]=rand_p(900000000,1000000000);
		q[i]=rand_p(1,100);
		int iq=fpm(q[i],p[i]-2,p[i]);
		pw[i][0]=ipw[i][0]=1;
		for(int j=1;j<=n;++j){
			pw[i][j]=pw[i][j-1]*q[i]%p[i];
			ipw[i][j]=ipw[i][j-1]*iq%p[i];
		}
	}
	read(s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'0';	
		cnt[i]=cnt[i-1]+(!a[i]);
	}
	for(int i=1;i<=n;++i)if(a[i]){c[i]=c[i-1]^1;}
	for(int i=n;i;--i){
		if(!a[i]){
			for(int j=1;j<=m;++j){
				h[j][i]=h[j][i+1]*q[j]%p[j];
			}
		}
		else{
			if(b[i+1]){
				for(int j=1;j<=m;++j){
					h[j][i]=(h[j][i+1]-1)%p[j];
				}		
			}
			else{
				b[i]=1;
				for(int j=1;j<=m;++j){
					h[j][i]=(h[j][i+1]+1)%p[j];
				}		
			}
		}
	}
	int q;
	read(q);
	for(;q;--q){
		int l,r,s;		
		read(l,r,s);
		int ok=1;
		if(cnt[r+s-1]-cnt[r-1]!=cnt[l+s-1]-cnt[l-1])ok=0;
		else
		for(int i=1;i<=m;++i)if(hsh(i,l,s)!=hsh(i,r,s)){ok=0;break;}
		if(ok)write("Yes\n");
		else write("No\n");
	}
	return 0;
}