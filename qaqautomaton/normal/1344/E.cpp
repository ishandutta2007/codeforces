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
vector<pii> to[100005];
int las[100005];
vector<int> hv[100005];
int t[100005],col[100005];
set<int> st[100005];
multiset<pii> mt;
priority_queue<int,vector<int>,greater<int> > pq;
void put_ans(int cur){
	write(cur,' ');
	int ans=0;
	for(auto i:mt)if(i.y<cur)++ans;
	write(ans,'\n');
	exit(0);
}
int dep[100005],ndep;
void add(int x,int y){
	if(col[x]!=col[y]){
		mt.insert(make_pair(t[x]+ndep+1,t[y]+ndep));
	}
}
void del(int x,int y){
	if(col[x]!=col[y]){
		mt.erase(mt.lower_bound(make_pair(t[x]+ndep+1,t[y]+ndep)));
	}
}
void dfs(int x){
	for(auto i:to[x]){
		dep[i.x]=dep[x]+i.y;
		dfs(i.x);
	}
	t[0]=-dep[x];	
	st[las[x]].insert(0);
	for(auto i:to[x]){
		if(st[x].size()<st[i.x].size()){
			swap(st[x],st[i.x]);
		}
	}
	int c=0;
	ndep=dep[x];
	for(auto i:to[x]){
		++c;	
		for(auto j:st[i.x]){
			col[j]=c;
			auto it=st[x].lower_bound(j);
			if(it==st[x].end()){
				--it;
				add(*it,j);
			}
			else if(it==st[x].begin()){
				add(j,*it);
			}
			else{
				auto it2=it;
				--it2;
				del(*it2,*it);
				add(*it2,j);
				add(j,*it);
			}
			st[x].insert(j);
		}
	}
	c=0;
	for(auto i:to[x]){
		++c;	
		for(auto j:st[i.x]){
			col[j]=0;
		}
		st[i.x].clear();
	}
	st[x].erase(0);
	for(auto i:hv[x])st[x].insert(i);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,m,u,v,c;
	read(n,m);
	for(int i=1;i<n;++i){
		read(u,v,c);
		to[u].push_back(make_pair(v,c));
		las[u]=v;
	}
	for(int i=1;i<=m;++i){
		int x;
		read(x,t[i]);
		hv[x].push_back(i);
	}
	dfs(1);
	int cur=0;
	auto it=mt.begin();
//	for(auto i:mt)write(i.x,' ',i.y,'\n');
	while(1){
		++cur;
		if(pq.empty()){
			if(it==mt.end())break;
			cur=it->x;
		}
		while(it!=mt.end()&&it->x==cur){
			pq.push(it->y);
			++it;	
		}
		if(pq.top()<cur){
			put_ans(pq.top());
		}
		pq.pop();
	}
	write(-1,' ',mt.size(),'\n');
	return 0;
}