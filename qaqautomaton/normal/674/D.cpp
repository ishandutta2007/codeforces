/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp
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
int s[100005],to[100005],cnt[100005],w[100005],mx[100005],mn[100005],tag[100005];
multiset<int> ss[100005],smx,smn;
#define erasex(a,b) a.erase(a.lower_bound(b))
#define ix(a,b) a.insert(b)
void updw(int x,int y){
	erasex(smx,*ss[to[x]].rbegin()+tag[to[x]]);
	erasex(smn,*ss[to[x]].begin()+tag[to[x]]);
	erasex(ss[to[x]],w[x]);
	w[x]=y;
	ix(ss[to[x]],w[x]);
	ix(smx,*ss[to[x]].rbegin()+tag[to[x]]);
	ix(smn,*ss[to[x]].begin()+tag[to[x]]);
}

void del(int x,int y){
	int ot=tag[x],os=s[x]%(cnt[x]+2)+tag[x];
	erasex(smx,*ss[x].rbegin()+tag[x]);
	erasex(smn,*ss[x].begin()+tag[x]);
	--cnt[x];
	erasex(ss[x],w[y]);
	tag[x]=s[x]/(cnt[x]+2);
	if(ss[x].size()){
		ix(smx,*ss[x].rbegin()+tag[x]);
		ix(smn,*ss[x].begin()+tag[x]);
	}
	updw(to[x],w[to[x]]+tag[x]-ot);
	updw(x,w[x]+(tag[x]+s[x]%(cnt[x]+2))-os);
}
void add(int x,int y){
	int ot=tag[x],os=s[x]%(cnt[x]+2)+tag[x];
	if(ss[x].size()){
		erasex(smx,*ss[x].rbegin()+tag[x]);
		erasex(smn,*ss[x].begin()+tag[x]);
	}
	++cnt[x];
	ix(ss[x],w[y]);
	tag[x]=s[x]/(cnt[x]+2);
	if(ss[x].size()){
		ix(smx,*ss[x].rbegin()+tag[x]);
		ix(smn,*ss[x].begin()+tag[x]);
	}
	updw(to[x],w[to[x]]+tag[x]-ot);
	updw(x,w[x]+(tag[x]+s[x]%(cnt[x]+2))-os);
}
void upd(int x,int y){
	updw(to[x],w[to[x]]-tag[x]);	
	del(to[x],x);
	to[x]=y;
	updw(to[x],w[to[x]]+tag[x]);	
	add(to[x],x);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n,q;
	read(n,q);
	for(int i=1;i<=n;++i){
		read(s[i]);
	}
	for(int i=1;i<=n;++i){
		read(to[i]);
		++cnt[to[i]];
	}
	for(int i=1;i<=n;++i){
		w[to[i]]+=tag[i]=s[i]/(cnt[i]+2);
		w[i]+=s[i]/(cnt[i]+2)+s[i]%(cnt[i]+2);
	}
	for(int i=1;i<=n;++i){
		ss[to[i]].insert(w[i]);		
	}
	for(int i=1;i<=n;++i)if(!ss[i].empty()){
		smn.insert(*ss[i].begin()+tag[i]);
		smx.insert(*ss[i].rbegin()+tag[i]);
	}
	int tp,x,y;
	for(;q;--q){
		read(tp);
		if(tp==1){
			read(x,y);
			upd(x,y);
		}
		else if(tp==2){
			read(x);
			write(w[x]+tag[to[x]],'\n');
		}
		else{
			write(*smn.begin(),' ',*smx.rbegin(),'\n');
		}
	}
	return 0;
}