/*
Author: QAQAutoMaton
Lang: C++
Code: E.cpp
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
int l[10000005],r[10000005],cnt[10000005],trash[10000005],top,t;
void del(int &x){
	l[x]=r[x]=cnt[x]=0;
	trash[++top]=x;
	x=0;
}
int New(){
	if(top){
		--top;
		return trash[top+1];
	}
	return ++t;
}
void Ins(int &rt,int ls,int rs,int x){
	if(!rt)rt=New();
	++cnt[rt];
	if(ls==rs)return;
	int mid=(ls+rs)>>1;
	if(x<=mid)Ins(rt[l],ls,mid,x);
	else Ins(rt[r],mid+1,rs,x);
}
void merge(int &rt,int rt2){
	if(!rt2)return;
	if(!rt){rt=rt2;return;}
	cnt[rt]+=cnt[rt2];
	merge(rt[l],rt2[l]);	
	merge(rt[r],rt2[r]);	
	del(rt2);
}
void split(int rt,int ls,int rs,int val,int &t1,int &t2){
	if(!rt){
		t1=t2=0;return;
	}
	if(val<ls){
		t2=rt;t1=0;return;
	}
	if(rs<=val){
		t1=rt;t2=0;return;
	}
	int mid=(ls+rs)>>1;
	t1=rt;
	t2=New();
	split(rt[l],ls,mid,val,t1[l],t2[l]);
	split(rt[r],mid+1,rs,val,t1[r],t2[r]);
	cnt[t1]=cnt[t1[l]]+cnt[t1[r]];
	cnt[t2]=cnt[t2[l]]+cnt[t2[r]];
	if(!cnt[t1])del(t1);
	if(!cnt[t2])del(t2);
}
int a[200005],xl[200005],xr[200005];
int rt[200005],prt,srt;
int occ[200005],pre[200005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n;
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		if(!xl[a[i]])xl[a[i]]=i;
		xr[a[i]]=i;
		occ[a[i]]=1;
		Ins(rt[a[i]],1,n,i);
	}
	int las=0;
	for(int i=1;i<=n+1;++i){
		pre[i]=las;
		if(occ[i])las=i;
	}
	xl[0]=0;xr[0]=n+1;
	ll ans=0;
	for(int i=las;i;i=pre[i]){
		int t1,t2,t3;

		split(prt,1,n,xl[i],prt,t1);
		merge(rt[i],t1);
		split(srt,1,n,xr[i],t1,srt);
		merge(rt[i],t1);
		
		ans+=cnt[rt[i]];
	
		split(rt[i],1,n,xl[pre[i]],t1,t2);
		split(t2,1,n,xr[pre[i]],t2,t3);

		merge(prt,t1);
		merge(srt,t3);
		merge(rt[pre[i]],t2);
	}
	write(ans,'\n');
	return 0;
}