/*
Author: QAQAutomaton
Lang: C++
Code: G.cpp
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
struct poi{
	int at,x,y,s;	
	poi(int a=0,int b=0,int c=0,int d=0){
		at=a;x=b;y=c;s=d;
	}
	bool operator <(const poi &b)const{
		return at<b.at;
	}
};
vector<poi>w;
int n,l,x,y,t,f;
int frac(int a,int b,int tp){
	if(!(a%b))return a/b;
	if(a<0)return a/b-(tp?1:0);
	else return a/b+(tp?0:1);
}
int axl,axr,ayl,ayr;
void add_q(poi a,poi b){
	int sx=b.s-a.s;
	int xx=b.x-a.x;
	int yx=b.y-a.y;
	int atx=b.at-a.at;
	if(sx==0){
		if(abs(xx)+abs(yx)>atx || ((abs(xx)+abs(yx))^atx)&1)exit(write("NO\n"));
	}
	else {
		if(sx<0)sx=-sx;
		else {xx=-xx;yx=-yx;}
		if(((abs(xx)+abs(yx)+sx*l)^atx)&1)exit(write("NO\n"));
		int xl=frac(xx+yx-atx,sx,0);
		int xr=frac(xx+yx+atx,sx,1);
		int yl=frac(xx-yx-atx,sx,0);
		int yr=frac(xx-yx+atx,sx,1);
		if(!f){f=1;axl=xl;axr=xr;ayl=yl;ayr=yr;}
		else{
			chkmax(axl,xl);
			chkmin(axr,xr);
			chkmax(ayl,yl);
			chkmin(ayr,yr);
			if(axl>axr)exit(write("NO\n"));
			if(ayl>ayr)exit(write("NO\n"));
		}
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	read(n,l);
	w.push_back(poi());
	w.push_back(poi(l,0,0,1));
	for(int i=1;i<=n;++i){
		read(t,x,y);
		w.push_back(poi(t%l,x,y,-t/l));
	}
	sort(all(w));
	int m=w.size();
	for(int i=1;i<m;++i){
		add_q(w[i-1],w[i]);
	}
	int ok=0,sx,sy;
	for(int i=0;i<4;++i)for(int j=0;j<4;++j){
		if(axl+i<=axr && ayl+j<=ayr && 
				!((axl+ayl+i+j)&1) 
				&& !((axl+i+l)&1)
				){
			x=axl+i;y=ayl+j;
			sx=(x+y)>>1;
			sy=(x-y)>>1;
			ok=1;break;
		}
	}
	if(!ok)return write("NO\n");
	int las=0,atx=0,aty=0;
	for(int i=0;i<m;++i){
		w[i].x+=w[i].s*sx;
		w[i].y+=w[i].s*sy;
		while(las<w[i].at){
			++las;
			if(atx<w[i].x){
				putc('R');
				++atx;
			}
			else if(atx>w[i].x){
				putc('L');
				--atx;
			}
			else if(aty<w[i].y){
				putc('U');
				++aty;
			}
			else {
				putc('D');
				--aty;
			}
		}
	}
	putc('\n');
	return 0;
}