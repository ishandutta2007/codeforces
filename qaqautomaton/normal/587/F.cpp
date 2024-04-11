/*
Author: QAQAutomaton
Lang: C++
Code: F.cpp
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
typedef long long ll;
typedef pair<int,int> pii;
int inf;
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
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
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
char strs[1000005];
char *s[100005];
int to[100005][26],t=1,fail[100005];
int c[100005];
int ed[100005];
int q[100005],*l,*r;
int cnt[201][100005];
int is[100005];
int ans[100005];
vector<pii> ask[100005];
const int S=500;
int dfn[100005],low[100005],su[100005];
int cl;
void add(int x,int y){
	for(;x<=cl;x+=x&-x)su[x]+=y;
}
int sum(int x){
	int y=0;for(;x;x^=x&-x)y+=su[x];
	return y;
}
vector<int> son[100005];
void dfs(int x){
	dfn[x]=++cl;
	for(auto i:son[x])dfs(i);
	low[x]=cl;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,m;
	read(n,m);
	s[1]=strs;
	for(int i=1;i<=n;++i){
		read(s[i]);
		s[i+1]=s[i]+strlen(s[i]);
		int at=1;
		for(char *j=s[i];j<s[i+1];++j){
			if(!to[at][*j-'a'])to[at][*j-'a']=++t;
			at=to[at][*j-'a'];
		}
		ed[i]=at;
	}
	*(l=r=q)=1;
	fail[1]=1;
	while(l<=r){
		for(int i=0;i<26;++i)if(to[*l][i]){
			*(++r)=to[*l][i];
			if(*l==1){
				fail[*r]=1;	
			}
			else{
				int at=fail[*l];
				while(at!=1 && !to[at][i])at=fail[at];
				if(to[at][i])fail[*r]=to[at][i];
				else fail[*r]=1;
			}
			son[fail[*r]].push_back(*r);
		}	
		++l;
	}
	l=q;
	while(l<=r){
		for(int i=0;i<26;++i)if(!to[*l][i]){
			if(*l==1)to[*l][i]=1;
			else to[*l][i]=to[fail[*l]][i];
		}
		++l;
	}
	int ct=0;
	for(int i=1;i<=n;++i){
		if(s[i+1]-s[i]>S){
			is[i]=++ct;
			int at=1;
			for(char *j=s[i];j<s[i+1];++j){
				at=to[at][*j-'a'];
				++c[at];
			}
			for(int *j=r;;--j){
				c[fail[*j]]+=c[*j];
				if(j==q)break;
			}
			for(int j=1;j<=n;++j)cnt[ct][j]=cnt[ct][j-1]+c[ed[j]];
			for(int j=1;j<=t;++j)c[j]=0;
		}
	}
	for(int i=1;i<=m;++i){
		int l,r,k;
		read(l,r,k);
		if(s[k+1]-s[k]>S){
			ans[i]=cnt[is[k]][r]-cnt[is[k]][l-1];
		}
		else{
			ask[r].push_back(make_pair(k,i));
			ask[l-1].push_back(make_pair(k,-i));
		}
	}
	dfs(1);
	for(int i=1;i<=n;++i){
		add(dfn[ed[i]],1);
		add(low[ed[i]]+1,-1);
		for(auto j:ask[i]){
			int aid=j.y,tp=1;
			if(aid<0){aid=-aid;tp=-1;}
			int at=1;
			for(char *l=s[j.x];l<s[j.x+1];++l){
				at=to[at][*l-'a'];
				ans[aid]+=tp*sum(dfn[at]);
			}
		}
	}
	for(int i=1;i<=m;++i)write(ans[i],'\n');
	return 0;
}