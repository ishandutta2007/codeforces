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
int s[405][10005];
vector<int> ok;
bool chk(int x){
	while(x){
		if(x%10!=4 && x%10!=7)return 0;
		x/=10;
	}
	return 1;
}
int a[100005];
int S=1000;
int tag[405];
int is[100005];
int blk[100005];
char str[405];
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,q;
	read(n,q);
	for(int i=1;i<=10000;++i)if(chk(i)){is[i]=1;ok.push_back(i);}
	for(int i=1;i<=n;++i){
		read(a[i]);
		blk[i]=(i-1)/S+1;
		++s[blk[i]][a[i]];
	}
	for(;q;--q){
		read(str);			
		if(str[0]=='a'){
			int l,r,w;
			read(l,r,w);
			if(blk[l]==blk[r]){
				for(int i=l;i<=r;++i){
					--s[blk[i]][a[i]];
					++s[blk[i]][a[i]+=w];
				}
			}
			else{
				for(int i=blk[l]+1;i<blk[r];++i)tag[i]+=w;
				for(int i=l;blk[i]==blk[l];++i){
					--s[blk[i]][a[i]];
					++s[blk[i]][a[i]+=w];
				}
				for(int i=r;blk[i]==blk[r];--i){
					--s[blk[i]][a[i]];
					++s[blk[i]][a[i]+=w];
				}
			}
		}
		else{
			int l,r;
			read(l,r);
			int ans=0;
			if(blk[l]==blk[r]){
				for(int i=l;i<=r;++i){
					ans+=is[tag[blk[i]]+a[i]];
				}
			}
			else{
				for(int i=blk[l]+1;i<blk[r];++i)
					for(auto j:ok)if(j>=tag[i])ans+=s[i][j-tag[i]];
				for(int i=l;blk[i]==blk[l];++i){
					ans+=is[tag[blk[i]]+a[i]];
				}
				for(int i=r;blk[i]==blk[r];--i){
					ans+=is[tag[blk[i]]+a[i]];
				}
			}
			write(ans,'\n');
		}
	}
	return 0;
}