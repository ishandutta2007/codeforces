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
int ans[500005];
namespace SAM{
	int to[1000005][27],len[1000005],fail[1000005],t=1;
	int las=1,l=0;
	vector<int> node[1000005],son[1000005];
	vector<pair<int,pii> >ask[1000005];
	int extend(int ch,int id){
		int nw=++t;
		len[nw]=++l;
		int at;
		for(at=las;at && !to[at][ch];at=fail[at]){to[at][ch]=nw;}
		if(!at){fail[nw]=1;}
		else{
			if(len[to[at][ch]]==len[at]+1)fail[nw]=to[at][ch];	
			else{
				int nx=++t,old=to[at][ch];
				len[nx]=len[at]+1;
				for(int i=0;i<=26;++i)to[nx][i]=to[old][i];
				fail[nx]=fail[old];
				fail[old]=fail[nw]=nx;
				for(;at && to[at][ch]==old;at=fail[at])to[at][ch]=nx;
			}
		}
		node[nw].emplace_back(id);
		return las=nw;
	}
	auto *fa=to;
	void work(){
		for(int i=2;i<=t;++i)son[fail[i]].emplace_back(i);
		for(int i=1;i<=t;++i)fa[i][0]=fail[i];
		for(int i=1;i<=19;++i)for(int j=1;j<=t;++j)fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	int calc(int id,int l){
		for(int i=19;~i;--i)if(len[fa[id][i]]>=l)id=fa[id][i];
		return id;
	}
	namespace BIT{
		int s[1000005];
		void add(int x,int y){for(;x<=t;x+=x&-x)s[x]+=y;}
		int sum(int x){int y=0;for(;x;x^=x&-x)y+=s[x];return y;}
	}
	void dfs(int x){
		for(auto i:ask[x])ans[i.x]-=BIT::sum(i.y.y)-BIT::sum(i.y.x);
		for(auto i:node[x])BIT::add(i,1);
		for(auto i:son[x])dfs(i);
		for(auto i:ask[x])ans[i.x]+=BIT::sum(i.y.y)-BIT::sum(i.y.x);
	}
}
char s[1000005];
int id[200005],len[200005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,q;	
	read(n,q);
	for(int i=1;i<=n;++i){
		read(s);
		int m=strlen(s);
		int las=0;
		for(int j=0;j<m;++j){
			las=SAM::extend(s[j]-'a',i);
		}
		id[i]=las;
		len[i]=m;
		SAM::extend(26,i);
	}
	SAM::work();
	for(int i=1;i<=n;++i){
		id[i]=SAM::calc(id[i],len[i]);
	}
	for(int i=1;i<=q;++i){
		int l,r,x;
		read(l,r,x);
		SAM::ask[id[x]].emplace_back(i,make_pair(l-1,r));
	}
	SAM::dfs(1);
	for(int i=1;i<=q;++i)write(ans[i],'\n');
	return 0;
}