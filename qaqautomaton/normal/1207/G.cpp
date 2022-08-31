/*
Author: QAQ Automaton
Lang: C++
Prog: G.cpp
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
typedef long long ll;
typedef pair<int,int> pii;
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
		while((x=gc())=='\n' || x==' '||x=='\r')if(x==EOF)return 0;
		return 1;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'||*x==EOF))*(++x)=gc();
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
int inf;
struct _init_{
    _init_(){
        memset(&inf,0x3f,sizeof(inf));
    }
};
_init_ ___INIT__;
int to[400005][26],is[400005],t=1;
char s[400005];
vector<pii> q[400005];
int to2[400005][26],fail[400005],tt=1;
vector<int> son[400005];
int ans[400005];
bool hv[400005];
int insert(char *s){
	int at=1;
	while(*s){
		if(!to2[at][*s-'a'])to2[at][*s-'a']=++tt;
		at=to2[at][*s-'a'];
		++s;
	}
	hv[at]=1;
	return at;
}
int qu[400005],*l,*r;
int sum[400005];
int dfn[400005],clk,low[400005];
void Add(int x,int y){
	for(;x<=tt;x+=x&-x)sum[x]+=y;
}
int Sum(int x){
	int y=0;
	for(;x;x^=x&-x)y+=sum[x];
	return y;
}
void dfs(int x){
	dfn[x]=clk;
	++clk;
	for(auto i:son[x])dfs(i);
	low[x]=clk;
}
void Draw_ACAM(int x,int id){
	s[id]=0;
	for(int i=0;i<26;++i)if(to2[x][i]){s[id]=i+'a';Draw_ACAM(to2[x][i],id+1);}

}
void Build_ACAM(){
	l=(r=qu)+1;
	for(int i=0;i<26;++i)if(to2[1][i]){
		*(++r)=to2[1][i];	
		fail[to2[1][i]]=1;
	}	
	for(;l<=r;++l){
		int cnt=0;
		for(int j=0;j<26;++j)if(to2[*l][j])++cnt;
		for(int i=fail[*l];i &&cnt;i=fail[i]){
			for(int j=0;j<26;++j)if(to2[i][j] && !fail[to2[*l][j]] && to2[*l][j]){
				--cnt;
				fail[to2[*l][j]]=to2[i][j];
			}
		}
		for(int j=0;j<26;++j)if(to2[*l][j] && !fail[to2[*l][j]])fail[to2[*l][j]]=1;
		for(int j=0;j<26;++j)if(to2[*l][j])*(++r)=to2[*l][j];
	}
	for(int i=0;i<26;++i)if(!to2[1][i])to2[1][i]=1;
	for(l=qu+1;l<=r;++l){
		son[fail[*l]].push_back(*l);
		for(int i=0;i<26;++i)if(!to2[*l][i])to2[*l][i]=to2[fail[*l]][i];
		hv[*l]|=hv[fail[*l]];
	}
	dfs(1);
}
int at=1;
void Solve(int x){
	for(auto i:q[x])ans[i.y]=Sum(low[i.x])-Sum(dfn[i.x]);
	for(int i=0;i<26;++i)if(to[x][i]){
		int oat=at;
		at=to2[at][i];
		if(hv[at])
		Add(dfn[at]+1,1);
		Solve(to[x][i]);
		if(hv[at])
		Add(dfn[at]+1,-1);
		at=oat;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,tp,m;
	char c;
	read(n);
	is[0]=1;
	for(int i=1;i<=n;++i){
		read(tp);
		int fa=0;
		if(tp==2)read(fa);
		read(c);
		if(!to[is[fa]][c-'a'])to[is[fa]][c-'a']=++t;
		is[i]=to[is[fa]][c-'a'];
	}
	read(m);
	int id;
	for(int i=1;i<=m;++i){
		read(id,s);
		q[is[id]].push_back(make_pair(insert(s),i));
	}
	Build_ACAM();
	Solve(1);
	for(int i=1;i<=m;++i)write(ans[i],'\n');

	return 0;
}