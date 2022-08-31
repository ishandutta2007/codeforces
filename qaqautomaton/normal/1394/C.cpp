/*
Author: QAQAutomaton
Lang: C++
Code: C.cpp
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
char s[300005];
int x[300005],y[300005];
multiset<int> l1,l2,r1,r2;
int n;
vector<pii> vt[1000005];
bool chk(int w){
	int yl=0,yr=inf;

	for(int i=1;i<=n;++i){
		int xl=x[i]-w,xr=x[i]+w;
		chkmax(yl,xl);chkmin(yr,xr);
	}
	if(yl>yr)return 0;
	for(int i=yl;i<=yr;++i)vt[i].clear();
	for(int i=1;i<=n;++i){
		int xl=max(x[i]-w,0),xm=x[i],xr=x[i]+w;
		if(chkmax(xm,yl)){
			chkmin(xr,yr);
			++xr;
			vt[xm].emplace_back(5,max(y[i]+w,0));
			vt[xm].emplace_back(7,y[i]-x[i]-w);
			if(xr<=yr){
				vt[xr].emplace_back(6,max(y[i]+w,0));
				vt[xr].emplace_back(8,y[i]-x[i]-w);
			}
			continue;
		}
		if(chkmin(xm,yr)){
			chkmax(xl,yl);
			++xm;
			vt[xl].emplace_back(1,max(y[i]-w,0));
			vt[xl].emplace_back(3,y[i]-x[i]+w);
			continue;
		}
		chkmax(xl,yl);
		chkmin(xr,yr);
		if(xl<xm){
			vt[xl].emplace_back(1,max(y[i]-w,0));
			vt[xm].emplace_back(2,max(y[i]-w,0));
			vt[xl].emplace_back(3,y[i]-x[i]+w);
			vt[xm].emplace_back(4,y[i]-x[i]+w);
		}
		++xr;
		vt[xm].emplace_back(5,max(y[i]+w,0));
		vt[xm].emplace_back(7,y[i]-x[i]-w);
		if(xr<=yr){
			vt[xr].emplace_back(6,max(y[i]+w,0));
			vt[xr].emplace_back(8,y[i]-x[i]-w);
		}
	}
	l1.clear();l2.clear();r1.clear();r2.clear();
	for(int i=yl;i<=yr;++i){
		for(auto p:vt[i]){
			int x=p.y;
			switch(p.x){
				case 1:	l1.insert(x);break;
				case 2:	l1.erase(l1.lower_bound(x));break;
				case 3:	r2.insert(x);break;
				case 4:	r2.erase(r2.lower_bound(x));break;
				case 5:	r1.insert(x);break;
				case 6:	r1.erase(r1.lower_bound(x));break;
				case 7:	l2.insert(x);break;
				case 8:	l2.erase(l2.lower_bound(x));break;
			}
		}	
		if(i>=yl){
			int l=max(l1.empty()?-1:*l1.rbegin(),l2.empty()?-inf:*l2.rbegin()+i);
			if(i==0)chkmax(l,1);
			int r=min(r1.empty()?inf:*r1.begin(),r2.empty()?inf:*r2.begin()+i);
			if(l<=r)return 1;
		}
	}
	return 0;
}
pii get(int w){
	int yl=0,yr=inf;

	for(int i=1;i<=n;++i){
		int xl=x[i]-w,xr=x[i]+w;
		chkmax(yl,xl);chkmin(yr,xr);
	}
	for(int i=yl;i<=yr;++i)vt[i].clear();
	for(int i=1;i<=n;++i){
		int xl=max(x[i]-w,0),xm=x[i],xr=x[i]+w;
		if(chkmax(xm,yl)){
			chkmin(xr,yr);
			++xr;
			vt[xm].emplace_back(5,max(y[i]+w,0));
			vt[xm].emplace_back(7,y[i]-x[i]-w);
			if(xr<=yr){
				vt[xr].emplace_back(6,max(y[i]+w,0));
				vt[xr].emplace_back(8,y[i]-x[i]-w);
			}
			continue;
		}
		if(chkmin(xm,yr)){
			chkmax(xl,yl);
			++xm;
			vt[xl].emplace_back(1,max(y[i]-w,0));
			vt[xl].emplace_back(3,y[i]-x[i]+w);
			continue;
		}
		chkmax(xl,yl);
		chkmin(xr,yr);
		if(xl<xm){
			vt[xl].emplace_back(1,max(y[i]-w,0));
			vt[xm].emplace_back(2,max(y[i]-w,0));
			vt[xl].emplace_back(3,y[i]-x[i]+w);
			vt[xm].emplace_back(4,y[i]-x[i]+w);
		}
		++xr;
		vt[xm].emplace_back(5,max(y[i]+w,0));
		vt[xm].emplace_back(7,y[i]-x[i]-w);
		if(xr<=yr){
			vt[xr].emplace_back(6,max(y[i]+w,0));
			vt[xr].emplace_back(8,y[i]-x[i]-w);
		}
		//x[i]-w..x[i]   [y-x<=r] [y>=l]
		//x[i]..x[i]+w   [y-x>=r] [y<=l]

		//		x[i]-,y[i]+
	}
	l1.clear();l2.clear();r1.clear();r2.clear();
	for(int i=yl;i<=yr;++i){
		for(auto p:vt[i]){
		//	write('=',p.x,' ',p.y,'\n');
			int x=p.y;
			switch(p.x){
				case 1:	l1.insert(x);break;
				case 2:	l1.erase(l1.lower_bound(x));break;
				case 3:	r2.insert(x);break;
				case 4:	r2.erase(r2.lower_bound(x));break;
				case 5:	r1.insert(x);break;
				case 6:	r1.erase(r1.lower_bound(x));break;
				case 7:	l2.insert(x);break;
				case 8:	l2.erase(l2.lower_bound(x));break;
			}
		}	
		if(i>=yl){
			int l=max(l1.empty()?0:*l1.rbegin(),l2.empty()?-inf:*l2.rbegin()+i);
			int r=min(r1.empty()?inf:*r1.begin(),r2.empty()?inf:*r2.begin()+i);
			if(i==0)chkmax(l,1);
			if(l<=r)return make_pair(i,l);
		}
	}
	return make_pair(0,0);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	read(n);
	for(int i=1;i<=n;++i){
		read(s);
		int l=strlen(s);
		for(int j=0;j<l;++j){
			x[i]+=s[j]=='B';
		}
		y[i]=l-x[i];
	//	write(x[i],' ',y[i],'\n');
	}
	int l=0,r=500000;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid))r=mid-1;
		else l=mid+1;
	}
	write(r+1,'\n');
	pii w=get(r+1);
	for(int i=0;i<w.x;++i)putc('B');
	for(int i=0;i<w.y;++i)putc('N');
	putc('\n');
	return 0;
}