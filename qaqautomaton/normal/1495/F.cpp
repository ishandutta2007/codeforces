/*
Author: QAQAutoMaton
Lang: C++
Code: F.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
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
int p[200005];
int a[200005],b[200005];
int to[200005],mn[200005];
int fa[19][200005],f[19][200005];
int stk[200005],cnt[200005];
int query(int l,int r){
	if(l==r)return 0;
	int ans=0;
	for(int i=18;~i;--i)if(fa[i][l]<=r){
		ans+=f[i][l];l=fa[i][l];
	}
	return ans;
}
int ans[200005];
vector<pii> xa[200005],xd[200005];
void add(int l,int r,int id){
	xa[r].emplace_back(l,id);
}
void del(int l,int r,int id){
	xd[r].emplace_back(l,id);
}
set<int> st;
bitset<200005>cur;
int t;
int ask(int x){
	int v=lower_bound(stk+1,stk+t+1,x)-stk;
	return cnt[t]-cnt[v]+query(x,stk[v]);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,q;	
	read(n,q);
	for(int i=1;i<=n;++i)read(p[i]);
	p[n+1]=n+1;
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]);
	stk[0]=n+1;
	for(int i=0;i<=18;++i){
		fa[i][n+1]=n+1;f[i][n+1]=0;
	}
	for(int i=n;i;--i){
		while(p[stk[t]]<p[i])--t;
		int j=stk[t];
		stk[++t]=i;
		to[i]=j;
		mn[i]=min(b[i],a[i]+query(i+1,j));
		f[0][i]=mn[i];fa[0][i]=to[i];
		//write(i,' ',to[i],' ',mn[i],'\n');
		for(int j=1;j<=18;++j){fa[j][i]=fa[j-1][fa[j-1][i]];f[j][i]=f[j-1][i]+f[j-1][fa[j-1][i]];}
	}
	st.insert(1);st.insert(n+1);
	add(1,n+1,0);
	for(int i=1;i<=q;++i){
		int x;
		read(x);
		if(x==1)continue;
		if(cur[x]){
			auto it=st.lower_bound(x);
			auto l=it,r=it;
			--l;++r;
			add(*l,*r,i);
			del(*l,x,i);
			del(x,*r,i);
			st.erase(it);
			cur[x]=0;
		}
		else{
			cur[x]=1;
			auto r=st.lower_bound(x);
			auto l=r;
			--l;
			del(*l,*r,i);
			add(*l,x,i);
			add(x,*r,i);
			st.insert(x);
		}
	}
	stk[t=0]=0;
	p[0]=n+2;
	for(int i=1;i<=n+1;++i){
		while(p[stk[t]]<p[i]){
			--t;	
		}
		stk[++t]=i;
		cnt[t]=cnt[t-1]+(a[stk[t-1]]+query(stk[t-1]+1,stk[t]));
		for(auto x:xa[i]){ans[x.y]+=ask(x.x);}
		for(auto x:xd[i]){ans[x.y]-=ask(x.x);}
	}
	for(int i=1;i<=q;++i){
		ans[i]+=ans[i-1];
		write(ans[i],'\n');
	}
	return 0;
}