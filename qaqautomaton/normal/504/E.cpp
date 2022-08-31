/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int isp(int x){
	if(x==1)return 0;
	for(int i=2;i*i<=x;++i)if(!(x%i))return 0;
	return 1;
}
int getp(int l,int r){
	int w;
	while(!isp(w=rnd()%(r-l)+l));
	return w;
}
const int c=3;
ll h[c][600005],pw[c][600005];
ll xp[c],xq[c];
int n,u,v;
vector<int> to[300005];
char s[300005],s1[600005];
int siz[300005],mxs[300005],hvy[300005];
int dfn[300005],xdfn[300005],t;
int top[300005],tdp[300005],fa[300005];
void initHash(){
	for(int i=0;i<c;++i){
		ll &p=xp[i],&q=xq[i];
		p=getp(900000000,1000000000);
		q=getp(1,1000);
		pw[i][0]=1;
		for(int j=1;j<=t;++j){
			pw[i][j]=pw[i][j-1]*q%p;
			h[i][j]=(h[i][j-1]*q+s1[j]-'a')%p;
		}
	}
}
int match(int x,int y,int t){
	for(int i=0;i<c;++i){
		if(((h[i][x+t]-h[i][y+t])+(h[i][y]-h[i][x])*pw[i][t])%xp[i])return 0;
	}
	return 1;
}
void dfs(int x,int f){
	siz[x]=1;for(auto i:to[x])if(i!=f){dfs(i,x);siz[x]+=siz[i];if(chkmax(mxs[x],siz[i]))hvy[x]=i;}
}
void dfs2(int x,int f){
	fa[x]=f;
	if(!top[x]){top[x]=x;tdp[x]=tdp[f]+1;}
	dfn[x]=++t;
	xdfn[x]=n+n-t+1;
	s1[dfn[x]]=s1[xdfn[x]]=s[x];
	if(hvy[x]){
		tdp[hvy[x]]=tdp[x];top[hvy[x]]=top[x];dfs2(hvy[x],x);
		for(auto i:to[x])if(i!=f && i!=hvy[x])dfs2(i,x);
	}
}
int l1[600005],r1[600005],t1;
int l2[600005],r2[600005],t2;
int xl[600005],xr[600005],xt;
void make(int x,int y,int *l,int *r,int &t){
	xt=t=0;
	while(top[x]!=top[y]){
		if(tdp[x]<tdp[y]){
			l[++t]=dfn[top[y]]-1;			
			r[t]=dfn[y];
			y=fa[top[y]];
		}
		else{
			xl[++xt]=xdfn[x]-1;
			xr[xt]=xdfn[top[x]];
			x=fa[top[x]];
		}
	}
	if(dfn[x]<=dfn[y]){
		l[++t]=dfn[x]-1;r[t]=dfn[y];
	}
	else{
		l[++t]=xdfn[x]-1;
		r[t]=xdfn[y];
	}
	while(xt){
		l[++t]=xl[xt];
		r[t]=xr[xt];
		--xt;
	}
}
int query(){
	int ans=0;
	while(t1&&t2){
		int &x=l1[t1],&y=l2[t2];
		int s=min(r1[t1]-l1[t1],r2[t2]-l2[t2]);
		if(match(x,y,s)){ans+=s;x+=s;y+=s;}
		else{
			int l=1,r=s;
			while(l<=r){
				int mid=(l+r)>>1;
				if(match(x,y,mid))l=mid+1;
				else r=mid-1;
			}
			ans+=l-1;
			break;
		}
		if(x==r1[t1])--t1;
		if(y==r2[t2])--t2;
	}
	return ans;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(n);
	read(s+1);
	for(int i=1;i<n;++i){
		read(u,v);
		to[u].emplace_back(v);to[v].emplace_back(u);
	}
	dfs(1,0);
	dfs2(1,0);
	t<<=1;
	initHash();
	int q;
	read(q);
	for(;q;--q){
		int a,b,c,d;
		read(a,b,c,d);
		make(a,b,l1,r1,t1);
		make(c,d,l2,r2,t2);
		write(query(),'\n');
	}
	return 0;
}