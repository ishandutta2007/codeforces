/*
Author: QAQAutoMaton
Lang: C++
Code: B.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
#include<tr1/unordered_set>
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
int deg[100005];
vector<int> to[100005];
__gnu_pbds::priority_queue<pii,greater<pii> > pq;
__gnu_pbds::priority_queue<pii,greater<pii> >::point_iterator it[100005];
bitset<100005>gg;
tr1::unordered_set<ll> st,xst[100005];
int nd[100005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	int t,n,m,k,u,v;
	read(t);
	for(;t;--t){
		read(n,m,k);
		pq.clear();
		st.swap(xst[t]);
		for(int i=1;i<=n;++i){deg[i]=0;to[i].clear();gg[i]=0;}
		for(int i=1;i<=m;++i){
			read(u,v);
			to[u].emplace_back(v);
			to[v].emplace_back(u);
			st.insert((ll)u*n+v);
			st.insert((ll)v*n+u);
			++deg[u];++deg[v];
		}
		for(int i=1;i<=n;++i){
			it[i]=pq.push({deg[i],i});
		}
		int c=n;
		bool hv=((ll)k*(k-1)>>1 )<=m;
		while(c){
			if(pq.top().x==k)break;
			int x=pq.top().y;
			if(deg[x]==k-1&&hv){
				int c=0;
				for(auto i:to[x])if(!gg[i]){nd[++c]=i;}
				bool gg=0;
				for(int i=1;i<c&&!gg;++i)for(int j=i+1;j<=c;++j)if(!st.count((ll)n*nd[i]+nd[j])){gg=1;break;}
				if(!gg){
					write("2\n",x);
					for(int i=1;i<=c;++i)write(' ',nd[i]);
					putc('\n');
					goto end;
				}
			}
			pq.pop();
			gg[x]=1;
			for(auto i:to[x])if(!gg[i]){
				pq.modify(it[i],{--deg[i],i});
			}
			--c;
		}
		if(c){
			write(1,' ',c,'\n');
			while(!pq.empty()){
				write(pq.top().y,c==1?'\n':' ');
				--c;
				pq.pop();
			}
		}
		else write("-1\n");
		end:;
	}
	return 0;
}