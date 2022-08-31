/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
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
char s[205];
const int p=10007;
struct Z{
	uint x;
	Z(){}
	Z(uint a){
		x=a;
	}
};
inline uint modp(const uint x){
	return x<p?x:x-p;
}
inline Z operator+(const Z x1, const Z x2) { return modp(x1.x+x2.x);}
inline Z operator-(const Z x1, const Z x2) { return modp(x1.x+p-x2.x);}
inline Z operator-(const Z x) {return x.x?p-x.x:0;}
inline Z operator*(const Z x1, const Z x2) { return x1.x*x2.x%p;}
void exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
inline Z Inv(const Z a){
	int x,y;
	exgcd(p,a.x,x,y);
	return y<0?y+=p:y;
}
inline Z operator/(const Z x1, const Z x2) { return x1*Inv(x2);}

inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }
const int N=805;
Z f[N],g[N],ans[N];
int l;
Z dp[205][205][N];
void solve(int n,int m,Z *f,Z *g){
	dp[0][n+1][0]=1;
	for(int i=0;i<=n;++i)for(int j=n+1;j>i;--j){
		if(i+1==j){
			for(int k=1;k<=m;++k)dp[i][j][k]+=dp[i][j][k-1]*26;
			for(int k=0;k<=m;++k)f[k]+=dp[i][j][k];
		}
		else if(i+2==j){
			for(int k=1;k<=m;++k)dp[i][j][k]+=dp[i][j][k-1]*25;
			for(int k=1;k<=m;++k)dp[i+1][j][k]+=dp[i][j][k-1];
			for(int k=0;k<=m;++k)g[k]+=dp[i][j][k];
		}
		else{
			if(s[i+1]==s[j-1]){
				for(int k=1;k<=m;++k)dp[i][j][k]+=dp[i][j][k-1]*25;
				for(int k=1;k<=m;++k)dp[i+1][j-1][k]+=dp[i][j][k-1];
			}
			else{
				for(int k=1;k<=m;++k)dp[i][j][k]+=dp[i][j][k-1]*24;
				for(int k=1;k<=m;++k){
					dp[i][j-1][k]+=dp[i][j][k-1];
					dp[i+1][j][k]+=dp[i][j][k-1];
				}
			}
		}
	}
}
void BM(Z *a,int n,Z *ans,int &l){
	static Z las[10005],nex[10005],c;
	static int p,mn,ll,nl;
	l=0;
	ans[0]=1;
	for(int i=0;i<=n;++i){
		Z s(0);
		for(int j=0;j<=l;++j)s+=a[i-j]*ans[j];
		if(!s.x)continue;
		if(!l){
			l=i+1;
			for(int j=1;j<=i;++j)ans[j]=0;
			p=i;
			c=s;
			ll=0;
			las[0]=1;
			mn=ll-i;
		}
		else{
			Z cd=s/c;
			nl=max(mn+i,l);
			for(int j=0;j<=nl;++j)nex[j]=0;
			for(int j=0;j<=ll;++j)nex[j+i-p]-=las[j]*cd;
			for(int j=0;j<=l;++j)nex[j]+=ans[j];
			if(mn>=l-i){
				mn=l-i;
				p=i;c=s;
				ll=l;
				for(int j=0;j<=ll;++j)las[j]=ans[j];
			}
			l=nl;
			for(int j=0;j<=nl;++j){
				ans[j]=nex[j];	
			}	
		}
	}
}
Z poly[N],np[N];
void fpm(int n){
	if(n==1){
		for(int i=0;i<l;++i)poly[i]=0;
		poly[1]=1;
		if(l==1){
			poly[0]=-ans[1];
			poly[1]=0;
		}
		return;
	}
	fpm(n>>1);
	for(int i=0;i<l+l;++i)np[i]=0;
	for(int i=0;i<l;++i)for(int j=0;j<l;++j)np[i+j]+=poly[i]*poly[j];
	for(int i=l+l-2;i>=l;--i){
		Z s=np[i];
		for(int j=0;j<=l;++j)np[i-j]-=s*ans[j];
	}
	if(n&1){
		for(int i=l;i;--i)np[i]=np[i-1];
		np[0]=0;
		Z s=np[l];
		for(int j=0;j<=l;++j)np[l-j]-=s*ans[j];
	}
	for(int i=0;i<=l;++i)poly[i]=np[i];
}
Z calc(int n,Z *f){
	fpm(n);
	Z ans(0);
	for(int i=0;i<l;++i)ans+=f[i]*poly[i];
	return ans;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(s+1);	
	int n=strlen(s+1),m;
	read(m);
	m+=n;
	int w=n<<2;
	solve(n,w,f,g);
	BM(f,w,ans,l);
	Z xf=calc(m>>1,f);
	if(m&1){
		BM(g,w,ans,l);
		Z xg=calc(m>>1,g);
		write((xf*26+xg).x,'\n');
	}
	else{
		write(xf.x,'\n');
	}
	return 0;
}