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
pii mx[10000005];
int l[10000005],r[10000005],t;
int clone(int x){++t;l[t]=l[x];r[t]=r[x];mx[t]=mx[x];return t;}
void qmax(int rt,int ls,int rs,int la,int ra,pii &ans){
	if(!rt)return;
	if(la<=ls && rs<=ra){chkmax(ans,mx[rt]);return;}
	int mid=(ls+rs)>>1;
	if(la<=mid)qmax(rt[l],ls,mid,la,ra,ans);
	if(mid<ra)qmax(rt[r],mid+1,rs,la,ra,ans);
}
void merge(int &x,int y,int ls,int rs){
	if(!y)return;
	if(!x){x=y;return;}
	x=clone(x);
	if(ls==rs){
		x[mx].x+=y[mx].x;
		assert(x[mx].y==-ls);
	}
	else{
		int mid=(ls+rs)>>1;
		merge(x[l],y[l],ls,mid);
		merge(x[r],y[r],mid+1,rs);
		x[mx]=max(x[l][mx],x[r][mx]);
	}
	//write(x[mx].x,' ',x[mx].y,'?','\n');
}
void ins(int &rt,int ls,int rs,int x){
	rt=clone(rt);
	if(!rt[mx].x){rt[mx].y=-ls;}
	if(ls==rs){++mx[rt].x;return;}
	int mid=(ls+rs)>>1;
	if(x<=mid)ins(rt[l],ls,mid,x);
	else ins(rt[r],mid+1,rs,x);
	rt[mx]=max(rt[l][mx],rt[r][mx]);
	//write(rt[mx].x,',',rt[mx].y,'\n');
}
int rt[1300005];
int n;
namespace SAM{
	int to[1300005][27],len[1300005],fail[1300005],t=1;
	int val[1300005];
	int las=1,l=0;
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
		val[nw]=id;
		return las=nw;
	}
	auto *fa=to;
	int cnt[1300005],id[1300005];
	void work(){
		for(int i=1;i<=t;++i)++cnt[len[i]];
		for(int i=1;i<=l;++i)cnt[i]+=cnt[i-1];
		for(int i=1;i<=t;++i){id[cnt[len[i]]]=i;--cnt[len[i]];}
		for(int i=t;i;--i){
			int x=id[i];
			if(val[x])ins(rt[x],1,n,val[x]);
			merge(rt[fail[x]],rt[x],1,n);
		}
		for(int i=1;i<=t;++i)fa[i][0]=fail[i];
		for(int i=1;i<=20;++i)for(int j=1;j<=t;++j)fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	int calc(int id,int l){
		for(int i=20;~i;--i)if(len[fa[id][i]]>=l)id=fa[id][i];
		return id;
	}
}
char s[500005],ss[50005];
int at[500005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(s+1);
	read(n);
	for(int i=1;i<=n;++i){
		read(ss+1);
		int m=strlen(ss+1);
		for(int j=1;j<=m;++j){
			SAM::extend(ss[j]-'a',i);
		}
		SAM::extend(26,0);
	}
	int c=strlen(s+1);
	for(int i=1;i<=c;++i){
		at[i]=SAM::extend(s[i]-'a',0);
	}
	SAM::work();
	int q,l,r,xl,xr;
	read(q);
	for(;q;--q){
		read(l,r,xl,xr);
		pii ans(0,-l);
		qmax(rt[SAM::calc(at[xr],xr-xl+1)],1,n,l,r,ans);
		write(-ans.y,' ',ans.x,'\n');
	}
	return 0;
}