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
const int B=500;
int n,m;
namespace bit{
	int s[100005];
	void clear(){for(int i=1;i<=n;++i)s[i]=0;}
	void add(int x,int y){
		for(;x<=n;x+=x&-x)s[x]+=y;
	}
	int sum(int x){int y=0;for(;x;x^=x&-x)y+=s[x];return y;}
	void add(int l,int r,int x){for(int i=l;i<=r;++i)add(i,x);}
}
int l[100005],r[100005];
int ans[50005];
vector<int> vt[50005];
int xl[30000005],xr[30000005],mn[30000005],t;
void Ins(int &rt,int ls,int rs,int x,int y){
	if(!rt){mn[rt=++t]=y;}
	chkmin(mn[rt],y);
	if(ls==rs)return;
	int mid=(ls+rs)>>1;
	if(x<=mid)Ins(rt[xl],ls,mid,x,y);
	else Ins(rt[xr],mid+1,rs,x,y);
}
int query(int rt,int ls,int rs,int la,int ra){
	if(!rt)return inf;
	if(la<=ls && rs<=ra)return mn[rt];
	int ans=inf; 
	int mid=(ls+rs)>>1;
	if(la<=mid)chkmin(ans,query(rt[xl],ls,mid,la,ra));
	if(mid<ra)chkmin(ans,query(rt[xr],mid+1,rs,la,ra));
	return ans;
}
struct smt{
	int ls,rs;
	int xrt;
	smt *l,*r;
	smt(){}
	smt(int,int);
	void add(int x,int y,int z){
		Ins(xrt,1,n,y,z);
		if(ls==rs)return;
		if(x<=l->rs)l->add(x,y,z);
		else r->add(x,y,z);
	}
	int query(int la,int ra,int lb,int rb){
		if(la<=ls && rs<=ra){return ::query(xrt,1,n,lb,rb);}
		int ans=inf;
		if(la<=l->rs)chkmin(ans,l->query(la,ra,lb,rb));
		if(r->ls<=ra)chkmin(ans,r->query(la,ra,lb,rb));
		return ans;
	}
};
smt *rt,node[100005],*at=node;
smt *newsmt(int la,int ra){
	smt *rt=at;++at;
	*rt=smt(la,ra);
	return rt;
}
smt::smt(int la,int ra){ls=la;rs=ra;xrt=0;if(ls==rs){l=r=0;return;}int mid=(ls+rs)>>1;l=newsmt(ls,mid);r=newsmt(mid+1,rs);}
int query(int l,int r){
	if(l>r)return inf;
	return rt->query(l,r,l,r);
}
priority_queue<int,vector<int>,greater<int> >pq;
set<int> sl,sr;
int solve(){
	int s=0;
	while(!pq.empty())pq.pop();
	pq.push(query(1,n));
	sl.clear();
	sr.clear();
	sl.insert(n+1);
	sr.insert(0);
	while(!pq.empty()){
		int x=pq.top();
		if(x==inf)return s;
		pq.pop();
		s+=r[x]-l[x]+1;
		auto v=sl.lower_bound(r[x]);
		pq.push(query(r[x]+1,*v-1));
		v=sr.lower_bound(l[x]);
		--v;
		pq.push(query(*v+1,l[x]-1));
		sr.insert(r[x]);
		sl.insert(l[x]);
	}
	return s;	
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	read(n,m);
	for(int i=1;i<=m;++i){
		read(l[i],r[i]);
		vt[r[i]-l[i]+1].emplace_back(i);
	}
	for(int i=1;i<=B;++i){
		bit::clear();
		int s=0;
		for(int j=1;j<=m;++j){
			if(r[j]-l[j]+1>=i && bit::sum(r[j])==bit::sum(l[j]-1)){
				bit::add(l[j],r[j],1);
				s+=r[j]-l[j]+1;
			}
		}
		ans[i]=s;
	}
	rt=newsmt(1,n);
	for(int _=n;_>B;--_){
		for(auto i:vt[_])rt->add(l[i],r[i],i);
		ans[_]=solve();
	}
	for(int i=1;i<=n;++i)write(ans[i],'\n');
	return 0;
}