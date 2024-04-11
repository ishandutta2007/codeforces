/*
Author: QAQAutoMaton
Lang: C++
Code: D.cpp
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
		fill((unsigned char *)(&inf),(unsigned char *)(&inf)+sizeof(inf),0x3f);
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
namespace run{
	int n,m;
	set<pii,greater<pii> >st;
	set<int> to[500005];
	int deg[500005];
	int a[500005],b[500005];
	bitset<500005>isd;
	void del(int x){
		isd[x]=1;
		st.erase({deg[x],x});
		for(auto i:to[x])if(!isd[i]){
			st.erase({deg[i],i});
			st.insert({--deg[i],i});
		}
	}
	int node[500005],c;
	bool main(){
		read(n,m);
		int u,v;
		for(int i=1;i<=n;++i){deg[i]=0;to[i].clear();isd[i]=0;}
		for(int i=1;i<=m;++i){
			read(u,v);
			to[u].insert(v);
			to[v].insert(u);
			++deg[u];++deg[v];
		}
		st.clear();
		for(int i=1;i<=n;++i)st.insert({deg[i],i});
		int t=n;
		while(!st.empty()){
			if(st.rbegin()->x==0){
				int x=st.rbegin()->y;
				a[x]=t;b[x]=1;
				for(auto i:st)if(i.y!=x){
					b[i.y]=t;
					a[i.y]=--t;
				}
				break;
			}
			if(st.begin()->x==t-1){
				int x=st.begin()->y;
				a[x]=b[x]=t;--t;
				del(x);
			}
			else if(st.begin()->x==t-2){
				int x=st.begin()->y,y=0;
				//write(x,'\n');
				for(auto i:st)if(i.y!=x && !to[x].count(i.y)){
					y=i.y;
					break;
				}
				//write(y,'\n');
				int c=0;
				for(auto i:st)if(i.x!=t-2)break;else{
					if(i.y!=y && !to[y].count(i.y)){node[++c]=i.y;}
				}
				//for(int i=1;i<=c;++i)write(node[i],i==c?'\n':' ');
				b[y]=t;
				for(int i=1;i<=c;++i){
					a[node[i]]=t;b[node[i]]=--t;
				}
				a[y]=t;--t;
				for(int i=1;i<=c;++i){
					del(node[i]);
				}
				del(y);
			}
			else if(st.begin()->x==t-3){
				int x=st.begin()->y;
				c=0;
				for(auto i:st)if(i.y!=x && !to[x].count(i.y)){
					node[++c]=i.y;
				}
				if(deg[node[2]]==t-3 && !to[node[1]].count(node[2])){
					a[x]=t;a[node[1]]=t-1;a[node[2]]=t-2;
					b[x]=t-2;b[node[1]]=t;b[node[2]]=t-1;
					t-=3;
					del(x);del(node[1]);del(node[2]);	
				}
				else{
					a[x]=t;a[node[1]]=t-1;
					b[x]=t-1;b[node[1]]=t;
					t-=2;
					del(x);del(node[1]);
				}
			}
			else{
				int x=st.begin()->y,y=0;
				for(auto i:st)if(i.y!=x && !to[x].count(i.y)){
					y=i.y;
					break;
				}
				a[x]=t;b[x]=t-1;a[y]=t-1;b[y]=t;t-=2;
				del(x);
				del(y);
			}
		}
		for(int i=1;i<=n;++i)write(a[i],i==n?'\n':' ');
		for(int i=1;i<=n;++i)write(b[i],i==n?'\n':' ');
		return 0;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t){
		run::main();
	}
	return 0;
}