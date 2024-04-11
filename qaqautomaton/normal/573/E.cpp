/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
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
int a[100005];
const int B=300;
int xl[1005],xr[1005],blk[100005];
int bc;
struct block{
	int curk,curb;	
	pii a[1005],b[1005];
	bitset<1005>del;
	int aid[1005];
	int id[1005],at,t,xid,m;
	void addk(){
		++curk;
		while(at<t && b[at].x*curk+b[at].y<=b[at+1].x*curk+b[at+1].y)++at;
	}
	void addb(int x){curb+=x;}
	bool check(pii a,pii b,pii c){
		int z1=a.y-b.y,m1=a.x-b.x,z2=a.y-c.y,m2=a.x-c.x;
		int y1=z1/m1,y2=z2/m2;
		z1-=y1*m1;z2-=y2*m2;
		if(z1<0){z1+=m1;--y1;}
		if(z2<0){z2+=m2;--y2;}
		if(y1!=y2)return y1>y2;
		return z1*m2>=z2*m1;
	}
	void build(){
		at=1;t=0;
		for(int i=1;i<=m;++i)if(!del[i]){
			while(t && b[t].y<=a[i].y)--t;
			if(t && a[i].x==b[t].x)continue;
			while(t>1 && check(a[i],b[t],b[t-1]))--t;
			b[++t]=a[i];
			id[t]=i;
		}
		if(!t){++t;b[t].x=0,b[t].y=-inf;}
	}
	pii getmx(){return {curk*b[at].x+curb+b[at].y,id[at]};}
	void init(int x){
		xid=x;
		m=xr[x]-xl[x]+1;
		for(int i=1;i<=m;++i)a[i]={::a[xl[x]+i-1],xl[x]+i-1};
		sort(a+1,a+m+1);
		for(int i=1;i<=m;++i)aid[i]=a[i].y,a[i].y=a[i].x;
		curk=curb=0;
		build();
	}
	void rebuild(int x){
		for(int i=1;i<=m;++i){a[i].y+=curk*a[i].x+curb;}
		curk=curb=0;
		for(int i=1;i<=m;++i)if(aid[i]<aid[x]){a[i].y+=a[x].x;}else a[i].y+=a[i].x;
		del[x]=1;
		build();
	}
};
block b[1005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n;
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		blk[i]=(i-1)/B+1;
		if(!xl[blk[i]])xl[blk[i]]=i;
		xr[blk[i]]=i;
	}
	bc=blk[n];
	for(int i=1;i<=bc;++i){
		b[i].init(i);		
	}
	int ans=0;
	while(1){
		pii mx(0,0);
		int id=0;
		for(int i=1;i<=bc;++i){
			if(chkmax(mx,b[i].getmx()))id=i;
		}
		if(mx.x<=0)break;
		ans+=mx.x;
		for(int i=1;i<id;++i)b[i].addb(b[id].a[mx.y].x);
		for(int i=id+1;i<=bc;++i)b[i].addk();
		b[id].rebuild(mx.y);
	}
	write(ans,'\n');
	return 0;
}