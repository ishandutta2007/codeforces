/*
Author: QAQAutoMaton
Lang: C++
Code: D2.cpp
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
int a[200005];
int cnt[200005];
int mx,mid;
int p[200005];
int xmn[400015],*mn=xmn+200005;
const int B=400;
int ps[200015];
vector<int> vt[200015];
struct Max2{
	pii mx,se;
	void add(int x,int y){
		if(y==mx.y)mx.x=x;
		else{
			pii p{x,y};
			if(p>mx){se=mx;mx=p;}
			else chkmax(se,p);
		}
	}
	int q1(){return mx.x;}
	int q2(){return se.x;}
};
Max2 m2[200005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("D2.in","r",stdin);
	freopen("D2.out","w",stdout);
#endif
	int n;	
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		++cnt[a[i]];
	}
	for(int i=1;i<=n;++i)if(chkmax(mx,cnt[i]))mid=i;
	for(int i=1;i<=n;++i)if(mx==cnt[i] && i!=mid){return write(n,'\n');}
	for(int i=1;i<=n;++i)ps[i]=ps[i-1]+(a[i]==mid);
	for(int i=-n;i<=n;++i)mn[i]=inf;
	int ans(0);
	for(int i=1;i<=n;++i)if(i!=mid&&cnt[i]>B){
		for(int j=1;j<=n;++j){
			p[j]=p[j-1];
			if(a[j]==i)++p[j];
			else if(a[j]==mid)--p[j];
		}
		for(int j=0;j<=n;++j){
			if(mn[p[j]]==inf)mn[p[j]]=j;
			else if(ps[j]-ps[mn[p[j]]]>B)chkmax(ans,j-mn[p[j]]);
		}
		for(int j=0;j<=n;++j)mn[p[j]]=inf;
	}
	for(int i=1;i<=n;++i){vt[i].resize(cnt[i]+1);cnt[i]=0;}
	int cmx=0;
	for(int i=1;i<=n;++i){
		int c=a[i];
		for(int j=cnt[c];j;--j)vt[c][j+1]=vt[c][j];
		vt[c][1]=i;
		++cnt[c];
		for(int j=1;j<=cnt[c];++j){
			m2[j].add(vt[c][j],c);
		}
		if(cnt[c]>B)--cnt[c];
		chkmax(cmx,cnt[c]);
		for(int j=1;j<=cmx;++j){
			if(m2[j].q2()>m2[j+1].q1())chkmax(ans,i-m2[j+1].q1());
		}
		//for(int j=1;j<=3;++j){for(int k=1;k<=cnt[j];++k)write(vt[j][k],' ');putc('\n');}
	}
	write(ans,'\n');
	return 0;
}