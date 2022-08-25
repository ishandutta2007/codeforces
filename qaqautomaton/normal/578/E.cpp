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
char s[100005];
int w[2][100005],c[2];
int nex[100005];
bitset<100005> in,a;
vector<int> as[2][2];
int las[100005];
void put(int x){
	write(x,' ');
	if(nex[x])put(nex[x]);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n;
	read(s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]=='R';
		w[a[i]][++c[a[i]]]=i;
		if(c[a[i]^1]){nex[w[a[i]^1][c[a[i]^1]]]=i;in[i]=1;--c[a[i]^1];}
	}
	write(c[0]+c[1]-1,'\n');
	for(int i=1;i<=n;++i)if(!in[i]){
		int x=0,y=i;
		while(y){x^=1;las[i]=y;y=nex[y];}
		as[a[i]][x].emplace_back(i);
	}
	if(n&1){
		while(!as[0][1].empty() && !as[1][1].empty()){
			int x=as[0][1].back(),y=as[1][1].back();
			as[0][0].emplace_back(x);
			nex[las[x]]=y;
			as[0][1].pop_back();
			as[1][1].pop_back();
		}
		if(as[0][1].empty()){
			for(auto i:as[1][0])put(i);
			for(auto i:as[1][1])put(i);
			for(auto i:as[0][0])put(i);
		}
		else{
			for(auto i:as[0][0])put(i);
			for(auto i:as[0][1])put(i);
			for(auto i:as[1][0])put(i);
		}
	}
	else{
		if(as[0][1].empty()){
			if(as[0][0].empty()||as[1][0].empty()){
			}
			else{
				int x=as[0][0].back(),y=as[1][0].back();		
				if(x<y){
					int z=nex[x];
					nex[x]=y;
					y=z;
				}
				else{
					int z=nex[y];
					nex[y]=x;
					x=z;
				}
				as[0][1].emplace_back(x);
				as[1][1].emplace_back(y);
				as[0][0].pop_back();
				as[1][0].pop_back();
			}
		}
		else{
			int s=as[0][1].size();
			while(s>1){
				int x=as[0][1].back(),y=as[1][1].back();
				as[0][0].emplace_back(x);
				nex[las[x]]=y;
				as[0][1].pop_back();
				as[1][1].pop_back();
				--s;
			}
		}
		for(auto i:as[0][0])put(i);
		for(auto i:as[0][1])put(i);
		for(auto i:as[1][0])put(i);
		for(auto i:as[1][1])put(i);
	}
	putc('\n');
	return 0;
}