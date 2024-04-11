/*
Author: QAQAutomaton
Lang: C++
Code: G.cpp
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
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char *)(&inf),(unsigned char *)(&inf)+sizeof(inf),0x3f);
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
const uint p=1000000007,i2=(p+1)>>1;
struct Z{
	uint x;
	Z(){}
	Z(uint a){x=a;}
    Z& operator++(){x=x==p-1?0:x+1;return *this;}
    Z& operator--(){x=x?x-1:p-1;return *this;}
};
inline uint modp(const uint x){
	return x<p?x:x-p;
}
inline Z operator+(const Z x1, const Z x2) { return modp(x1.x+x2.x);}
inline Z operator-(const Z x1, const Z x2) { return modp(x1.x+p-x2.x);}
inline Z operator-(const Z x) {return x.x?p-x.x:0;}
inline Z operator*(const Z x1, const Z x2) { return static_cast<ull>(x1.x)*x2.x%p;}
void exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return;}	
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
inline Z Inv(const Z x){
	int a,b;
	exgcd(p,x.x,a,b);
	return b<0?b+p:b;
}
inline Z operator/(const Z x1,const Z x2){return x1*Inv(x2);}
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()/100);
int isp(int x){
	if(x<=1)return 0;
	for(int i=2;i*i<=x;++i)if(!(x%i))return 0;
	return 1;
}
int rndp(int l,int r){
	int w=0;
	while(!isp(w=rnd()%(r-l+1)+l));
	return w;
}
const int c=3;
int xp[3],xq[3];

char s[2000005],t[100005];
int len[100005];
char asks[2000005];
char *ask[100005];
int al[100005];
int pre[3][2000005],suf[3][2000005];
int xpre[3][1000005],xsuf[3][1000005];
vector<int> xask[25];
Z cnt[100005][26];
int xpw[3][1000005];
Z pw[100005],ipw[100005];
Z reqpw[100005];
Z ans[100005];
int at[100005];
namespace trie{
	int to[1000005][26],t;	
	int q[1000005],*l,*r;
	int fail[1000005],f[1000005];
	void clear(){ 
		while(t){
			for(int i=0;i<26;++i)to[t][i]=0;
			f[t]=fail[t]=0;
			--t;
		}
	}
	int ins(char *s,int l){
		int at=1;
		for(int i=1;i<=l;++i){
			if(!to[at][s[i]]){to[at][s[i]]=++t;}
			at=to[at][s[i]];
		}
		return at;
	}
	void init(){
		l=q+1;r=q;	
		fail[1]=1;
		for(int i=0;i<26;++i)if(to[1][i])fail[*(++r)=to[1][i]]=1;else to[1][i]=1;
		for(;l<=r;++l){
			for(int i=0;i<26;++i)if(to[*l][i])fail[*(++r)=to[*l][i]]=to[fail[*l]][i];else to[*l][i]=to[fail[*l]][i];
		}
	}
	void walk(char *s,int l){
		int at=1;
		for(int i=1;i<=l;++i)++f[at=to[at][s[i]]];
		for(int *i=r;i>q;--i)f[fail[*i]]+=f[*i];
	} 
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,q;	
	read(n,q);
	read(s+1);
	pw[0]=ipw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=pw[i-1]+pw[i-1];
	for(int i=1;i<=n;++i)ipw[i]=ipw[i-1]*i2;
	len[0]=strlen(s+1);

	for(int i=0;i<c;++i){
		xp[i]=rndp(900000000,1000000000);
		xq[i]=rndp(100,10000);
		xpw[i][0]=1;
		for(int j=1;j<=1000000;++j)xpw[i][j]=(ll)xpw[i][j-1]*xq[i]%xp[i];
	}
	int l=0;
	read(t+1);
	while(l<n && len[l]<1000000){
		int m=len[l];
		s[m+1]=t[l+1];
		for(int i=1;i<=m;++i)s[i+m+1]=s[i];
		++l;
		len[l]=len[l-1]<<1|1;
	}
	for(int i=l+1;i<=n;++i){
		for(int j=0;j<26;++j)cnt[i][j]=cnt[i-1][j];
		cnt[i][t[i]-'a']+=ipw[i];
	}
	int m=len[l];
	for(int i=1;i<=m;++i)s[i]-='a';
	for(int x=0;x<3;++x)for(int i=1;i<=m;++i)pre[x][i]=((ll)pre[x][i-1]*xq[x]+s[i])%xp[x];
	for(int x=0;x<3;++x)for(int i=m;i;--i)suf[x][i]=((ll)suf[x][i+1]*xq[x]+s[i])%xp[x];
	ask[1]=asks;
	for(int id=1;id<=q;++id){
		int k;
		read(k);
		char *at=ask[id];
		read(at+1);
		int xl=al[id]=strlen(at+1);
		for(int j=1;j<=xl;++j)at[j]-='a';
		xask[min(l,k)].emplace_back(id);
		reqpw[id]=pw[k-min(l,k)];
		ask[id+1]=at+(xl+2);
		if(k>l){
			for(int x=0;x<3;++x)for(int i=1;i<=xl;++i)xpre[x][i]=(xpre[x][i-1]+(ll)xpw[x][i-1]*at[i])%xp[x];
			for(int x=0;x<3;++x){xsuf[x][xl+1]=0;for(int i=xl;i;--i)xsuf[x][i]=(xsuf[x][i+1]+(ll)xpw[x][xl-i]*at[i])%xp[x];}
			for(int i=1;i<=xl;++i){
				bool gg=0;
				for(int x=0;x<3;++x)if(xpre[x][i-1]!=suf[x][m-(i-1)+1]){gg=1;break;}
				for(int x=0;x<3;++x)if(xsuf[x][i+1]!=pre[x][xl-i]){gg=1;break;}
				if(!gg){
					//for(int j=l+1;j<=k;++j)if(t[j]-'a'==at[i])ans[id]+=pw[k-j];
					ans[id]+=cnt[k][at[i]]*pw[k];
					//printf("%d:ok\n",i);
				}
			}
		}
	}
	for(int i=0;i<=l;++i){
		trie::clear();
		if(!xask[i].empty()){
			trie::t=1;
			for(auto x:xask[i])at[x]=trie::ins(ask[x],al[x]);
			trie::init();
			trie::walk(s,len[i]);
			for(auto x:xask[i]){
				ans[x]+=trie::f[at[x]]*reqpw[x];
			}
		}
	}
	for(int i=1;i<=q;++i)write(ans[i].x,'\n');
	return 0;
}