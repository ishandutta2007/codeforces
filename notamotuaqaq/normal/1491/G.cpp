/*
Author: QAQAutoMaton
Lang: C++
Code: G.cpp
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
int a[200005];
bitset<200005>vis;
vector<int> c[200005];
int v1[200005],v2[200005];
int t1=0,t2=0;
vector<pii> ans;
void xswap(int x,int y){
	swap(a[x],a[y]);
	a[x]=-a[x];
	a[y]=-a[y];
	ans.emplace_back(x,y);
}
void solve(){
	swap(v1[1],v2[1]);	
	//swap(v1[t1],v2[t2]);
	for(int i=2;i<=t1;++i){
		xswap(v1[1],v1[i]);
	}
	for(int i=2;i<=t2;++i){
		xswap(v2[1],v2[i]);
	}
	xswap(v1[2],v2[2]);	
	xswap(v1[1],v2[1]);
}
void solve1(){
	if(t1==2){
		int x=1;
		while(x==v1[1] || x==v1[2])++x;
		xswap(x,v1[1]);
		xswap(x,v1[2]);
		xswap(x,v1[1]);
	}
	else{
#define s(x,y) xswap(v1[x],v1[y])
		if(t1==3){
			s(1,3);s(1,2);s(2,3);s(1,3);
		}
		else{
			s(2,3);
			s(3,4);
			for(int i=5;i<=t1;++i){
				s(3,i);
			}
			s(1,4);
			s(2,4);
			s(1,3);
		}
#undef s
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n;	
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
	}
	int t=0;
	for(int i=1;i<=n;++i)if(!vis[i]){
		vis[i]=1;
		if(a[i]!=i){
			++t;
			int j=i;
			do{
				vis[j]=1;
				c[t].emplace_back(j);
				j=a[j];
			}while(j!=i);
		}
	}
	for(int i=2;i<=t;i+=2){
		t1=t2=0;
		for(auto x:c[i-1])v1[++t1]=x;
		for(auto x:c[i])v2[++t2]=x;
		solve();
		//c[i-1],c[i]
	}
	if(t&1){
		t1=0;
		for(auto x:c[t])v1[++t1]=x;
		solve1();
	}
	for(int i=1;i<=n;++i){
		assert(a[i]==i);
	}
	assert(ans.size()<=n+1);
	write(ans.size(),'\n');
	for(auto i:ans)write(i.x,' ',i.y,'\n');
	return 0;
}