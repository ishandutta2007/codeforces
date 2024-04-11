/*
Author: QAQAutoMaton
Lang: C++
Code: H.cpp
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
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
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
char s[1000005];
int n;
int v[1000005];
int to[1000005][26],fail[1000005],len[1000005],t;
int f1[19][1000005],f[19][1000005],f2[19][1000005];
void init(){
	s[0]=-1;
	for(int i=0;i<=18;++i)f[i][1]=f[i][2]=1;
	t=2;v[0]=1;
	len[1]=-1;len[2]=0;fail[2]=1;
	fail[1]=1;
}
int Ins(int x,char ch){
	while(x!=1 && s[n-len[x]-1]!=ch)x=fail[x];
	if(!to[x][ch]){
		int nx=++t;
		to[x][ch]=nx;
		len[nx]=len[x]+2;
		if(x==1){fail[nx]=2;}
		else{
			for(x=fail[x];s[n-len[x]-1]!=ch||!to[x][ch];x=fail[x]);	
			fail[nx]=to[x][ch];
		}
		return nx;
	}
	x=to[x][ch];
	return x;
}
void push(char c){
	s[++n]=c;
	v[n]=Ins(v[n-1],c);
}
char op[1005],c;
int Op[1000005];
int pre[1000005],suf[1000005];
int query(int x,int l){
	if(len[x]<=l)return x;
	for(int i=18;~i;--i)if(len[f[i][x]]>l)x=f[i][x];
	//write(x,' ',fail[x],'?');
	return fail[x];
}
vector<int> son[1000005];
int dfn[1000005],low[1000005],dc;
void dfs(int x){
	dfn[x]=++dc;
	for(auto i:son[x])dfs(i);
	low[x]=dc;
}
namespace zkw{
	int w[1<<22|5];
	int N;
	void init(int n){
		N=1;
		while(N<=n)N<<=1;
	}
	void set(int x,int y){
		x+=N;
		for(;x;x>>=1)w[x]=y;
	}
	int query(int l,int r){
		l+=N;r+=N;
		int mx=0;
		while(l<=r){
			if(l&1){chkmax(mx,w[l]);++l;}
			if(!(r&1)){chkmax(mx,w[r]);--r;}
			if(l>r)break;
			l>>=1;r>>=1;
		}
		return mx;
	}
}

int cnt=0;
int l,r;
void Add(int x){
	//write("Add", x,' ',len[x],'\n');
	int h=zkw::query(dfn[x],low[x]);
	//write(h,'?','\n');
	if(h<l+len[x]-1)++cnt;
}
void Del(int x){

	//write("Del", x,' ',len[x],'\n');
	int h=zkw::query(dfn[x],low[x]);
	if(h==l+len[x]-1)--cnt;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("H.in","r",stdin);
	freopen("H.out","w",stdout);
#endif
	int q;
	read(q);
	v[1]=1;
	init();
	for(int i=1;i<=q;++i){
		read(op);
		if(op[1]=='u'){
			Op[i]=1;
			read(c);
			push(c-'a');
			pre[n]=v[n];
		}
		else{
			
		}
	}
	reverse(s+1,s+n+1);
	int m=n;
	n=0;
	for(int i=1;i<=m;++i){
		++n;
		suf[m-i+1]=v[n]=Ins(v[n-1],s[i]);
	}
	for(int i=1;i<=t;++i){
		f[0][i]=fail[i];
	}
	for(int i=1;i<=18;++i)for(int j=1;j<=t;++j)f[i][j]=f[i-1][f[i-1][j]];
	for(int i=2;i<=t;++i){
		son[fail[i]].emplace_back(i);	
	}

	dfs(1);
	zkw::init(t);
	l=1,r=0;
	for(int i=1;i<=q;++i){
		if(Op[i]){
			++r;
			//write('+',r,'!');
			Add(query(pre[r],r-l+1));
			zkw::set(dfn[pre[r]],r);
		}			
		else{
			Del(query(suf[l],r-l+1));
			++l;
		}
		write(cnt,'\n');
	}

	return 0;
}