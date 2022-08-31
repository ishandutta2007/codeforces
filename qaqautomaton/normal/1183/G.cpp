/*
Author: QAQ Automaton
LANG: C++
PROG: 1183G.cpp
Mail: lk@qaq-am.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const signed inf=0x3f3f3f3f;
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
	// input a signed integer
	inline bool read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}

	inline bool read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		x=gc();
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
		inline bool read(A &x,B &...y){
			return read(x)&&read(y...);
		}
	// print a signed integer
	inline bool write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}

	inline bool write (long long x) {
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
namespace solver{
	int cnt[200005],c[2][200005],cntt[2];
	int place[200005];
	int x[200005],y[200005];
	vector<pii> a[200005];
	priority_queue<pii> p;
	void main(){
		int n;
		read(n);
		for(int i=1;i<=n;++i){
			a[i].clear();
			cnt[i]=c[0][i]=c[1][i]=0;
			place[i]=0;
		}
		cntt[0]=cntt[1]=0;
		while(!p.empty())p.pop();
		for(int i=1;i<=n;++i){
			read(x[i],y[i]);
			++cnt[x[i]];++c[y[i]][x[i]];
			++cntt[y[i]];
		}
		for(int i=1;i<=n;++i)if(cnt[i]){
			a[cnt[i]].push_back(make_pair(c[1][i],i));	
		}
		int ans1=0,ans2=0;
		for(int i=n;i;--i){
			for(auto j:a[i])p.push(j);	
			if(!p.empty()){
				place[i]=p.top().y;
				ans1+=i;
				ans2+=min(i,p.top().x);
				p.pop();
			}
		}
		write(ans1,' ',ans2,'\n');
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("1183G.in","r",stdin);
	freopen("1183G.out","w",stdout);
#endif
	int q;
	read(q);
	for(;q;--q){
		solver::main();
	}
	return 0;
}