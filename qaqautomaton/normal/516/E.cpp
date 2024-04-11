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
void exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
vector<int> a[200005],b[200005];
int n,m;
int imn,inm; // imn = m^-1 mod n
vector<pii> ar,br;
pii w[400005];
set<int> ax,bx;
int solve(vector<int> &a,vector<int> &b){
	ar.clear();
	br.clear();
	ax.clear();bx.clear();
	for(auto i:a){
		ax.insert(i*imn%n);
		ar.emplace_back(i*imn%n,i);
		br.emplace_back(i*inm%m,i);
	}
	for(auto i:b){
		bx.insert(i*inm%m);
		ar.emplace_back(i*imn%n,i);
		br.emplace_back(i*inm%m,i);
	}
	sort(all(ar));
	sort(all(br));
	int t=0;
	for(auto i:ar)w[++t]=i;
	int ht=t;
	for(auto i:ar){w[++t]=i;w[t].x+=n;}
	int mn=inf;
	int ans=0;
	for(int i=1;i<t;++i){
		mn=min(mn+(w[i].x-w[i-1].x)*m,w[i].y);
		if(i>=ht && w[i].x!=w[i+1].x&&!(w[i].x+1==w[i+1].x && ax.count(w[i].x%n)))chkmax(ans,(w[i+1].x-w[i].x-1)*m+mn);
	}
	t=0;
	for(auto i:br)w[++t]=i;
	ht=t;
	for(auto i:br){w[++t]=i;w[t].x+=m;}
	mn=inf;
	for(int i=1;i<t;++i){
		mn=min(mn+(w[i].x-w[i-1].x)*n,w[i].y);
		if(i>=ht && w[i].x!=w[i+1].x&&!(w[i].x+1==w[i+1].x && bx.count(w[i].x%m)))chkmax(ans,(w[i+1].x-w[i].x-1)*n+mn);
	}
	return ans;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(n,m);
	int g=__gcd(n,m);
	if(g>200000){
		return write("-1\n");
	}
	int c,x;
	n/=g;m/=g;
	exgcd(n,m,inm,imn);
	inm=(inm%m+m)%m;
	imn=(imn%n+n)%n;
	read(c);for(int i=1;i<=c;++i){read(x);a[x%g].emplace_back(x/g);}
	read(c);for(int i=1;i<=c;++i){read(x);b[x%g].emplace_back(x/g);}
	int ans=0;
	for(int i=0;i<g;++i){
		if(a[i].empty()&&b[i].empty())return write("-1\n");
		if(a[i].size()!=n || b[i].size()!=m)chkmax(ans,solve(a[i],b[i])*g+i);
	}
	write(ans,'\n');
	return 0;
}