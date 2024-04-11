/*
Author: QAQAutomaton
Lang: C++
Code: I.cpp
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
/*
ooo   o     ooo     o     oooo
oo    oo     oo    oo     oooo
o     ooo     o   ooo     oooo

oooooo       ooo   ooo  (s3)
ooooo   ===> ooo + oo 
oooo         ooo   o

oooo         ooo   o    (s2) 
ooooo   ===> ooo + oo 
oooooo       ooo   ooo

 oooooo      ooooooo   o
  ooooo ===> ooooooo - oo
   oooo      ooooooo   ooo

   oooo      ooooooo   ooo
  ooooo ===> ooooooo - oo
 oooooo      ooooooo   o
*/
int tp[100005],x[100005],y[100005],s[100005],w[100005];
int xl[20005],xr[20005];
int ans[100005];
vector<int> Q[100005];
int mxx;
void buildt(int x,int l,int r){
	chkmax(mxx,x);
	xl[x]=l;xr[x]=r;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	buildt(x<<1,l,mid);
	buildt(x<<1|1,mid+1,r);
}
void addx(int x,int l,int r,int id){
	if(l<=xl[x]&&xr[x]<=r){Q[x].push_back(id);return;}
	if(l<=xr[x<<1])addx(x<<1,l,r,id);
	if(xl[x<<1|1]<=r)addx(x<<1|1,l,r,id);
}
void addQ(int r,int x,int id){
	Q[r].push_back(id);
	if(xl[r]==xr[r])return;
	if(x<=xr[r<<1])addQ(r<<1,x,id);
	else addQ(r<<1|1,x,id);
}
int n,q;	
struct bit{
	int s[5005];
	void init(){
		for(int i=1;i<=n+1;++i)s[i]=0;
	}
	void add(int x,int y){for(++x;x<=n+1;x+=x&-x)s[x]+=y;}
	int sum(int x){int y=0;for(++x;x;x^=x&-x)y+=s[x];return y;}
	int sum(int l,int r){chkmax(l,0);return sum(r)-sum(l-1);}
};
bit s1,s2,s3;
int calc(int id,int rt){
	return s1.sum(y[id])+s2.sum(y[id]-(x[id]-xl[rt]),y[id])+s3.sum(y[id]-(xr[rt]-x[id]),y[id]);
}
void update(int id,int rt){
	if(w[id]==1){
		int y0=y[id],yu=(s[id]-(xr[rt]-x[id]))+y[id];
		s1.add(y0,1);
		s1.add(yu,-1);
		s3.add(yu,1);
	}else
	if(w[id]==2){
		int yr=y[id],yl=y[id]-(s[id]-(xl[rt]-x[id]))-1;
		s1.add(yl,1);
		s1.add(yr+1,-1);
		s2.add(yl,-1);
	}else
	if(w[id]==3){
		int y0=y[id],yu=(s[id]-(x[id]-xl[rt]))+y[id];
		s1.add(y0,1);
		s1.add(yu,-1);
		s2.add(yu,1);
	}else{
		int yr=y[id],yl=y[id]-(s[id]-(x[id]-xr[rt]))-1;
		s1.add(yl,1);
		s1.add(yr+1,-1);
		s3.add(yl,-1);
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("I.in","r",stdin);
	freopen("I.out","w",stdout);
#endif
	read(n,q);
	buildt(1,1,n);
	for(int i=1;i<=q;++i){
		read(tp[i]);
		if(tp[i]==1){
			read(w[i],x[i],y[i],s[i]);
			if(w[i]<=2)addx(1,x[i],x[i]+s[i],i);
			else addx(1,x[i]-s[i],x[i],i);
		}
		else{
			read(x[i],y[i]);	
			addQ(1,x[i],i);
		}
	}	
	for(int i=1;i<=mxx;++i){
		int upd=0;
		for(auto j:Q[i])if(tp[j]==1){
			upd=1;
			update(j,i);
		}
		else{
			ans[j]+=calc(j,i);	
		}
		if(upd)s1.init(),s2.init(),s3.init();
	}
	for(int i=1;i<=q;++i)if(tp[i]==2){
		write(ans[i],'\n');
	}
	return 0;
}