/*
Author: QAQAutoMaton
Lang: C++
Code: E.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(qaq...) fprintf(stderr,qaq)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())
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
const int p=1000000007,_g=3;
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
inline Z Inv(const Z x){
	int a,b;
	exgcd(p,x.x,a,b);
	return b<0?b+p:b;
}
inline Z operator/(const Z x1,const Z x2){return x1*Inv(x2);}
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }
namespace polynomial{
	Z fpm(Z a,int b){
		Z c(1);
		for(;b;b>>=1,a*=a)if(b&1)c*=a;
		return c;
	}
	const int mxl=18;
	const int mxs=1<<mxl;
	Z _w[mxs<<1|5];
	int curn=1,rev[mxs|5],N;
	Z iN;
	void setn(int n){
		for(int i=1;i<n;++i)rev[i]=rev[i>>1]>>1|((i&1)*(n>>1));	
		N=n;
		iN=Inv(N);
		while(curn<n){
			Z w0=fpm(_g,(p-1)/(curn<<1)),w(1);
			for(int i=0;i<curn;++i){_w[i+curn]=w;w*=w0;}
			curn<<=1;
		}
	}
	void dft(Z *a){
		static ull t[mxs|5];
		for(int i=0;i<N;++i){
			t[i]=a[rev[i]].x;
		}
		for(int i=1;i<N;i<<=1){
			if(i==1048576)for(int j=0;j<N;++j)t[j]%=p;
			for(int j=0;j<N;j+=i+i){
				for(int k=0;k<i;++k){
					const ull x=t[j+k+i]*_w[i+k].x%p;
					t[j+k+i]=t[j+k]+p-x;t[j+k]+=x;
				}
			}
		}
		for(int i=0;i<N;++i)a[i]=t[i]%p;
	}
	void idft(Z *a){
		reverse(a+1,a+N);
		dft(a);
		for(int i=0;i<N;++i)a[i]*=iN;
	}
	void mul(Z *f,int n,Z *g,int m,Z *h){
		static Z w1[mxs|5],w2[mxs|5];	
		if(n<=100&&m<=100){
			for(int i=0;i<=n+m;++i)h[i]=0;
			for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)h[i+j]+=f[i]*g[j];
			return;
		}
		int N=1;
		while(N<=n+m){
			N<<=1;
		}
		for(int i=0;i<=n;++i)w1[i]=f[i];
		for(int i=0;i<=m;++i)w2[i]=g[i];
		for(int i=n+1;i<N;++i)w1[i]=0;
		for(int i=m+1;i<N;++i)w2[i]=0;
		setn(N);
		dft(w1);dft(w2);for(int i=0;i<N;++i)w1[i]*=w2[i];
		idft(w1);
		for(int i=0;i<=n+m;++i)h[i]=w1[i];

	}
	Z w1[mxs|5],w2[mxs|5],w3[mxs|5],w4[mxs|5],w5[mxs|5];
	void inv(int n,Z *f,Z *g){//make g=1/f (mod x^n)
		g[0]=Inv(f[0]);
		int m=1;
		while(m<n){
			for(int i=0;i<m;++i)g[i+m]=0;
			int nm=m<<1;
			setn(nm);
			for(int i=0;i<m;++i)w1[i]=g[i];
			for(int i=m;i<nm;++i)w1[i]=0;
			dft(w1);
			for(int i=0;i<nm;++i)w2[i]=f[i];
			dft(w2);
			for(int i=0;i<nm;++i)w2[i]*=w1[i];
			idft(w2);
			for(int i=0;i<m;++i)w2[i]=w2[i+m];
			for(int i=m;i<m+m;++i)w2[i]=0;
			dft(w2);
			for(int i=0;i<nm;++i)w1[i]=w1[i]*w2[i];
			idft(w1);
			for(int i=0;i<m;++i)g[i+m]=-w1[i];
			m<<=1;
		}
		for(int i=n;i<m;++i)g[i]=0;
	}
	void Deriv(int n,Z *f){
		for(int i=0;i<n;++i)f[i]=f[i+1]*(i+1);
		f[n]=0;
	}
	void Integ(int n,Z *f){
		static Z inv[mxs|5];
		static int cnn=0; 
		if(cnn==0)inv[++cnn]=1;
		while(cnn<=n){++cnn;inv[cnn]=(p-p/cnn)*inv[p%cnn];}
		for(int i=n;~i;--i)f[i+1]=f[i]*inv[i+1];
		f[0]=0;
	}
	void frac(int n,Z *f,Z *g,Z *h){//h=f/g mod x^n
		inv(n,g,w5);
		int N=1;
		while(N<=(n+n-2))N<<=1;
		setn(N);
		for(int i=0;i<n;++i)w1[i]=f[i];
		for(int i=n;i<N;++i)w1[i]=w5[i]=0;
		dft(w1);
		dft(w5);
		for(int i=0;i<N;++i)w1[i]*=w5[i];
		idft(w1);
		for(int i=0;i<n;++i)h[i]=w1[i];
	}
	void ln(int n,Z *f,Z *g){
		for(int i=1;i<n;++i)w3[i-1]=f[i]*i;
		w3[n-1]=0;
		frac(n,w3,f,g);
		Integ(n-1,g);
	}
	Z _inv[mxs|5];
	const int b=16;
	Z xh[mxs<<2|5],xw[mxs<<2|5];
	Z *h[b][105];
	Z *w[b][105];
	int pw[105],cur[105],cn[105];
	void cdq_exp(Z *f,Z *g,int l,int r,int cp){
		if(r-l+1<=128){
			for(int i=l;i<=r;++i){
				if(!i)g[i]=1;
				else g[i]*=_inv[i];
				for(int j=i+1;j<=r;++j){
					g[j]+=g[i]*f[j-i];
				}
			}
			return;
		}
		while(r-l+1<=pw[cp])--cp;
		int nd=(r-l)/pw[cp],d=pw[cp];
		int xn=cn[cp];
		for(int i=0;i<=nd;++i){
			int xl=l+i*d,xr=i==nd?r:xl+d-1;
			if(i){
				setn(xn);
				for(int k=0;k<xn;++k)w1[k]=0;
				for(int j=1;j<=i;++j){
					for(int k=0;k<xn;++k)w1[k]+=w[i-j][cp][k]*h[j][cp][k];
				}
				idft(w1);
				for(int j=xl;j<=xr;++j)g[j]+=w1[j-xl+d];
			}
			cdq_exp(f,g,xl,xr,cp-1);
			if(i<nd){
				setn(xn);
				for(int j=0;j<xn;++j)w[i][cp][j]=0;
				for(int j=xl;j<=xr;++j)w[i][cp][j-xl]=g[j];
				dft(w[i][cp]);
			}
		}
	}
	void exp(int n,Z *f,Z *g){
		_inv[1]=1;
		for(int i=2;i<=n;++i)_inv[i]=(p-p/i)*_inv[p%i];
		for(int i=1;i<n;++i)f[i]*=i;
		for(int i=0;i<n;++i)g[i]=0;
		if(n<=128){
			g[0]=1;
			for(int i=1;i<n;++i){
				for(int j=1;j<=i;++j){
					g[i]+=g[i-j]*f[j];
				}
				g[i]*=_inv[i];
			}
			return;
		}
		int cnt=0;
		while((1<<(cnt+4))<n)++cnt;
		int cc=cnt>>2,xn;
		for(int i=1;i<=cc;++i)pw[i]=1;
		for(int c=cc;cnt>=4;--c){
			pw[c]=1<<cnt;
			cn[c]=xn=pw[c]<<1;
			cnt-=4;
			int d=pw[c];
			setn(xn);
			for(int j=1;j<b;++j){
				int l=d*(j-1)+1,r=min(n-1,d*(j+1)-1);
				if(l>r)break;
				h[j][c]=xh+(j*xn);
				w[j-1][c]=xw+(j*xn);
				for(int i=0;i<xn;++i)h[j][c][i]=0;
				for(int i=l;i<=r;++i)h[j][c][i-(j-1)*d]=f[i];
				dft(h[j][c]);
			}
		}
		cdq_exp(f,g,0,n-1,cc);
		for(int i=1;i<n;++i)f[i]*=_inv[i];
	}
}
using polynomial::setn;
using polynomial::dft;
using polynomial::idft;
using polynomial::mul;
using polynomial::inv;
using polynomial::ln;
using polynomial::exp;
namespace run{
	/*Z f[100005],g[100005],h[200005];
	Z fac[100005],inv[100005],invf[100005];*/
	Z f[1005][1005];
	Z invf[100005],inv[100005];
	Z fac[100005];
	Z C(int a,int b){return fac[a]*invf[b]*invf[a-b];}
	bool main(){
		int n,k;
		read(n,k);
		fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;
		for(int i=2;i<=n;++i){fac[i]=fac[i-1]*i;inv[i]=(p-p/i)*inv[p%i];invf[i]=inv[i]*invf[i-1];}
		f[0][0]=1;
		Z ans(1);
		int l=n;
		for(int i=1;l>=i;++i){
			ans+=C(l,i)*fac[i]*fac[n-i]*invf[n];
			l-=k-1;
		}
		return write(ans.x,'\n');
		/*for(int i=0;i<=n+1;++i)g[i]=0;
		for(int i=1;i<=k;++i)g[i]=1;
		fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;
		for(int i=2;i<=n;++i){
			fac[i]=fac[i-1]*i;
			inv[i]=(p-p/i)*inv[p%i];
			invf[i]=inv[i]*invf[i-1];
		}
		for(int i=1;i<=n+1;++i)f[i]=invf[n]*fac[i-1];
		exp(n+2,f,g);
		Z ans(0);
		for(int i=0;i<=n+1;++i)ans+=f[i]*g[n+1-i];*/
		return write(ans.x,'\n');
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t)run::main();
	return 0;
}