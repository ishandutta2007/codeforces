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
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int p=1000000007;
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
inline Z operator*(const Z x1, const Z x2) { return static_cast<ull>(x1.x)*x2.x%p;}
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

inline Z &operator++(Z &x1){x1.x==p-1?x1.x=0:++x1.x;return x1;} 
inline Z &operator--(Z &x1){x1.x?--x1.x:x1.x=p-1;return x1;}
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }
inline Z fpm(Z a,int b){Z c(1);for(;b;b>>=1,a*=a)if(b&1)c*=a;return c;}
Z ans;
int n,m;
char s0[2005],s1[2005],t[2005];
const int c=3;
int xp[c],xq[c];
ll pw[c][4005],s0p[c][2005],s0s[c][2005],s1p[c][2005],s1s[c][2005],tp[c][2005],ts[c][2005];
int isp(int x){
	if(x==1)return 0;
	for(int i=2;i*i<=x;++i)if(!(x%i))return 0;
	return 1;
}
int getp(int l,int r){
	int w;
	while(!isp(w=rnd()%(r-l)+l));
	return w;
}
void init(){
	for(int i=0;i<c;++i){
		xp[i]=getp(900000000,1000000000);
		xq[i]=getp(1,1000);
	}
	for(int i=0;i<c;++i){
		ll p=xp[i],q=xq[i];
		for(int j=1;j<=n;++j){
			s0p[i][j]=(s0p[i][j-1]*q+(s0[j]-'a'))%p;
			s1p[i][j]=(s1p[i][j-1]*q+(s1[j]-'a'))%p;
		}
		for(int j=1;j<=m;++j){
			tp[i][j]=(tp[i][j-1]*q+(t[j]-'a'))%p;
		}
		for(int j=n;j;--j){
			s0s[i][j]=(s0s[i][j+1]*q+(s0[j]-'a'))%p;
			s1s[i][j]=(s1s[i][j+1]*q+(s1[j]-'a'))%p;
		}
		for(int j=m;j;--j){
			ts[i][j]=(ts[i][j+1]*q+(t[j]-'a'))%p;
		}
		pw[i][0]=1;
		for(int j=1;j<=n+n;++j)pw[i][j]=pw[i][j-1]*q%p;
	}
}

//AB
//CD
bool chkst0(int l,int r){//D->C->B->A
	int L=r-l+1;
	for(int i=0;i<c;++i){
		ll p=xp[i];
		if((s0p[i][r]+(s1s[i][l]-s0p[i][l-1])*pw[i][L]-s1s[i][r+1]*pw[i][L<<1]-tp[i][L<<1])%p)return 0;
	}
	return 1;
}
bool chkst1(int l,int r){//B->A->C->D
	int L=r-l+1;
	for(int i=0;i<c;++i){
		ll p=xp[i];
		if((s1p[i][r]+(s0s[i][l]-s1p[i][l-1])*pw[i][L]-s0s[i][r+1]*pw[i][L<<1]-tp[i][L<<1])%p)return 0;
	}
	return 1;
}
bool chked0(int l,int r){//A->B->D->C
	int L=r-l+1;
//	(s0s[l]-s0s[r+1]*pw[i][L])+
//	(s1p[r]-s1p[l-1]*pw[i][L])*pw[i][L]
//	s0s[l]+(s1p[r]-s0s[r+1])*pw[i][L]-s1p[l-1]*pw[i][2L]
	for(int i=0;i<c;++i){
		ll p=xp[i];
		if((s0s[i][l]+(s1p[i][r]-s0s[i][r+1])*pw[i][L]-s1p[i][l-1]*pw[i][L<<1]-ts[i][m-(L<<1)+1])%p)return 0;
	}
	return 1;
}
bool chked1(int l,int r){//C->D->B->A
	int L=r-l+1;
	for(int i=0;i<c;++i){
		ll p=xp[i];
		if((s1s[i][l]+(s0p[i][r]-s1s[i][r+1])*pw[i][L]-s0p[i][l-1]*pw[i][L<<1]-ts[i][m-(L<<1)+1])%p)return 0;
	}
	return 1;
}
Z f[2005][2005][2];
void solve(){
	int k=(m-1)>>1;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)f[i][j][0]=f[i][j][1]=0;
	for(int i=0;i<=n;++i){
		++f[i][0][0];
		++f[i][0][1];
		for(int j=2;j<=i && j<=k;++j){
			f[i][j<<1][0]+=chkst0(i-j+1,i);
			f[i][j<<1][1]+=chkst1(i-j+1,i);
		}
		ans+=f[i][m][0]+f[i][m][1];
		for(int j=2;j<=k&&i+j<=n;++j){
			if(chked0(i+1,i+j))ans+=f[i][m-(j<<1)][0];
			if(chked1(i+1,i+j))ans+=f[i][m-(j<<1)][1];
		}
		for(int j=0;j<m;++j){
			if(t[j+1]==s0[i+1])f[i+1][j+1][0]+=f[i][j][0];
			if(t[j+1]==s1[i+1])f[i+1][j+1][1]+=f[i][j][1];
			if(t[j+1]==s0[i+1] && t[j+2]==s1[i+1])f[i+1][j+2][1]+=f[i][j][0];
			if(t[j+1]==s1[i+1] && t[j+2]==s0[i+1])f[i+1][j+2][0]+=f[i][j][1];
		}
	}
/*	for(int i=0;i<=n;++i)for(int j=0;j<=m;++j){
		if(f[i][j][0].x || f[i][j][1].x)write(i,',',j,':',f[i][j][0].x,',',f[i][j][1].x,'\n');
	}
	write("==============================",ans.x,' ',(ans+ans).x,'\n');*/
} 
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(s0+1);
	read(s1+1);
	n=strlen(s0+1);
	read(t+1);
	m=strlen(t+1);
	if(m>n+n)return write("0");
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;++i){ans+=t[1]==s0[i];ans+=t[1]==s1[i];}
		return write(ans,'\n');
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;++i){
			ans+=(t[1]==s0[i]&&t[2]==s1[i]);
			ans+=(t[1]==s1[i]&&t[2]==s0[i]);
			ans+=(t[1]==s0[i]&&t[2]==s0[i-1]);
			ans+=(t[1]==s1[i]&&t[2]==s1[i-1]);
			ans+=(t[1]==s0[i]&&t[2]==s0[i+1]);
			ans+=(t[1]==s1[i]&&t[2]==s1[i+1]);
		}
		return write(ans,'\n');
	}
	init();
	if(!(m&1)){
		int k=m>>1;
		for(int i=1;i+k-1<=n;++i){
			ans+=chkst0(i,i+k-1);
			ans+=chkst1(i,i+k-1);
			ans+=chked0(i,i+k-1);
			ans+=chked1(i,i+k-1);
		}
	}
	solve();
	reverse(s0+1,s0+n+1);
	reverse(s1+1,s1+n+1);
	init();
	solve();
	write(ans.x,'\n');

	return 0;
}