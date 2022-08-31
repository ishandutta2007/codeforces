/*
Author: QAQAutomaton
Lang: C++
Code: C.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
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
int a[100005];
vector<int>c[100005];
int ans[100005];
__gnu_pbds::priority_queue<pii>pq;
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int t,n,x,y;
	read(t);
	for(;t;--t){
		read(n,x,y);
		for(int i=1;i<=n+1;++i)c[i].clear();
		for(int i=1;i<=n;++i){read(a[i]);c[a[i]].emplace_back(i);}
		int gg=0;
		for(int i=1;i<=n+1;++i)if(c[i].empty())gg=i;
		for(int i=1;i<=n;++i)ans[i]=gg;
		pq.clear();
		for(int i=1;i<=n+1;++i)if(!c[i].empty())pq.push(make_pair(c[i].size(),i));
		y-=x;
		int m=n;
		for(;x;--x){
			pii p=pq.top();pq.pop();
			ans[c[p.y].back()]=p.y;
			c[p.y].pop_back();
			if(--p.x)pq.push(p);
			--m;
		}
		bool ok=1;
		if(y==m&&(m&1)){
			if(pq.top().x>=((y+1)>>1)){ok=0;}
			else{
				while(y>3){
					pii a=pq.top();pq.pop();
					if(pq.empty()){ok=0;break;}
					pii b=pq.top();pq.pop();
					ans[c[a.y].back()]=b.y;
					if(--y){
						ans[c[b.y].back()]=a.y;
						if(--y){
							c[a.y].pop_back();
							c[b.y].pop_back();
							if(--a.x)pq.push(a);
							if(--b.x)pq.push(b);
						}
					}
				}
				pii a=pq.top();pq.pop();
				pii b=pq.top();pq.pop();
				pii d=pq.top();pq.pop();
				ans[c[a.y].back()]=b.y;
				ans[c[b.y].back()]=d.y;
				ans[c[d.y].back()]=a.y;
			}
		}
		else{
			while(y){
				assert(!pq.empty());
				pii a=pq.top();pq.pop();
				if(pq.empty()){ok=0;break;}
				pii b=pq.top();pq.pop();
				ans[c[a.y].back()]=b.y;
				if(--y){
					ans[c[b.y].back()]=a.y;
					if(--y){
						c[a.y].pop_back();
						c[b.y].pop_back();
						if(--a.x)pq.push(a);
						if(--b.x)pq.push(b);
					}
				}
			}
		}
		if(ok){
			write("YES\n");
			for(int i=1;i<=n;++i)write(ans[i],i==n?'\n':' ');
		}
		else write("NO\n");
	}
	return 0;
}