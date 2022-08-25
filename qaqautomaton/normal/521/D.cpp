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
bitset<100005>sel;
vector<pii> va[100005],vm[100005];
int a[100005],tp[100005],id[100005],w[100005];
int xw[100005];
struct frac{
	int x,y,c;
	frac(){}
	frac(int x){c=x;x=0;y=1;}
	frac(int a,int b):x(a),y(b){
		c=a/b;	
		x%=y;
	}
	bool operator <(const frac &b)const{
		if(c!=b.c)return c<b.c;
		return x*b.y<=b.x*y;
	}
	bool operator ==(const frac &b)const{
		return c==b.c && x*b.y==b.x*y;
	}
	//c+x/y x\lt y
};
pii ck[100005];
priority_queue<pair<frac,int> >pq;
void makea(int x){
	if(va[x].empty())return;
	pii b=va[x].back();
	va[x].pop_back();
	pq.push(make_pair(frac(a[x]+b.x,a[x]),b.y));
	a[x]+=b.x;
}
void makem(int x){
	if(vm[x].empty())return;
	pii b=vm[x].back();
	vm[x].pop_back();
	pq.push(make_pair(frac(b.x),b.y));
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int k,m,n;	
	read(k,n,m);
	for(int i=1;i<=k;++i)read(a[i]);
	for(int i=1;i<=n;++i){
		read(tp[i],id[i],w[i]);
		xw[i]=i;
		if(tp[i]==1){
			chkmax(ck[id[i]],make_pair(w[i],i));
		}
		else if(tp[i]==2){
			va[id[i]].emplace_back(w[i],i);
		}
		else{
			vm[id[i]].emplace_back(w[i],i);
		}
	}
	sort(xw+1,xw+n+1,[](int x,int y){return tp[x]<tp[y];});
	for(int i=1;i<=k;++i){
		if(ck[i].x>a[i]){
			va[i].emplace_back(ck[i].x-a[i],ck[i].y);
		}
		sort(all(va[i]));
		sort(all(vm[i]));
		makea(i);
		makem(i);
	}
	while(m && !pq.empty()){
		--m;
		int x=pq.top().y;
		pq.pop();
		sel[x]=1;
		if(tp[x]==3)makem(id[x]);
		else makea(id[x]);
	}
	write(sel.count(),'\n');
	for(int i=1;i<=n;++i)if(sel[xw[i]])write(xw[i],' ');
	putc('\n');
	return 0;
}