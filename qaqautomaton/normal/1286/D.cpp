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
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
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
const int cy=998244353,i100=828542813;
int a[100005],v[100005],p[100005];
struct matrix{
	int a[2][2];
	int *operator [](int b){return a[b];}
	matrix operator *(matrix b){
		matrix c;
		for(int i=0;i<2;++i)for(int j=0;j<2;++j)c[i][j]=0;
		for(int i=0;i<2;++i)for(int k=0;k<2;++k)for(int j=0;j<2;++j)c[i][j]=(c[i][j]+a[i][k]*b[k][j])%cy;
		return c;
	}
};
matrix w[100005];
struct smt{
	matrix mul;	
	int ls,rs;
	smt *l,*r;
	smt(int la,int ra){
		ls=la;rs=ra;
		if(ls==rs){mul=w[ls];l=r=0;return;}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);
		r=new smt(mid+1,rs);
		mul=r->mul*l->mul;
	}
	void reset(int x){
		if(ls==rs){mul=w[x];return;}
		if(x<=l->rs)l->reset(x);
		else r->reset(x);
		mul=r->mul*l->mul;
	}
};
smt *rt;
int fpm(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*a%cy)if(b&1)c=c*a%cy;
	return c;
}

struct frac{
	int x,y,id;
	frac(int a=0,int b=0,int c=0){
		x=a;y=b;id=c;
	}
	bool operator <(const frac &b)const{
		return x*b.y<y*b.x;
	}
};
frac s[200005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n;
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i],v[i],p[i]);
		p[i]=p[i]*i100%cy;
	}
	int m=0;
	for(int i=2;i<=n;++i){
		s[++m]=frac(a[i]-a[i-1],v[i]+v[i-1],i);
		if(v[i]!=v[i-1])s[++m]=frac(a[i]-a[i-1],abs(v[i]-v[i-1]),-i);
	}
	sort(s+1,s+m+1);
	for(int i=1;i<=n;++i){
		w[i][1][0]=w[i][1][1]=p[i];
		w[i][0][0]=w[i][0][1]=(cy+1-p[i])%cy;
		/* 1 ->
		   <- 0*/
		if(i==1){
			w[i][1][1]=w[i][0][1]=0;
		}
	}
	rt=new smt(1,n);
	int ans=0;
	for(int i=1;i<=m;++i){
		int id=s[i].id,is=id>0;		
		if(!is)id=-id;
		matrix ww=w[id];
		if(is){
			w[id][1][0]=w[id][0][0]=w[id][1][1]=0;
		}
		else if(v[id-1]<v[id]){
			w[id][1][0]=w[id][0][1]=w[id][1][1]=0;
		}
		else{
			w[id][1][0]=w[id][0][1]=w[id][0][0]=0;
		}
		rt->reset(id);
		ans=(ans+s[i].x*fpm(s[i].y,cy-2)%cy*(rt->mul[0][0]+rt->mul[1][0]))%cy;
		w[id]=ww;
		if(is){
			w[id][0][1]=0;
		}
		else{
			if(v[id-1]<v[id]){
				w[id][0][0]=0;
			}
			else{
				w[id][1][1]=0;
			}
		}
		rt->reset(id);
	}
	write(ans,'\n');
	return 0;
}