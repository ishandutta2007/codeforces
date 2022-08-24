/*
Author: QAQAutoMaton
Lang: C++
Code: G.cpp
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
const int p=998244353;
struct Z{
	uint x;
	Z(){}
	Z(uint a){
		x=a;
	}
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
inline Z Inv(const Z a){
	int x,y;
	exgcd(p,a.x,x,y);
	return y<0?y+=p:y;
}
inline Z operator/(const Z x1, const Z x2) { return x1*Inv(x2);}

inline Z &operator++(Z &x1){x1.x==p-1?x1.x=0:++x1.x;return x1;} 
inline Z &operator--(Z &x1){x1.x?--x1.x:x1.x=p-1;return x1;}
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }
inline Z fpm(Z a,int b){Z c(1);for(;b;b>>=1,a*=a)if(b&1)c*=a;return c;}
char s[2005][2005];
int a[2005][2005];
int cnt[2005],ss[2005];
int cx[2005],cy[2005];
vector<int> hx[2005],hy[2005];
int n,m;
bool ok1,ok2;
void dfsx(int x);
void dfsy(int y);
void dfsx(int x){
	int s=0;
	for(int i=1;i<=m;++i)s^=a[x][i];
	s&=1;
	if(cx[x]==0){
		if(s)ok1=0;
		cx[x]=inf;
		return;
	}
	cx[x]=inf;
	for(auto y:hx[x])if(a[x][y]==2){
		a[x][y]=s;
		if((--cy[y])<=1)dfsy(y);
		break;
	}
}
void dfsy(int y){
	int s=0;
	for(int x=1;x<=n;++x)s^=a[x][y];

	s&=1;
	if(cy[y]==0){
		if(s)ok1=0;
		cy[y]=inf;
		return;
	}
	cy[y]=inf;
	for(auto x:hy[y])if(a[x][y]==2){
		a[x][y]=s;
		if((--cx[x])<=1)dfsx(x);
		break;
	}
}
void Dfsx(int x);
void Dfsy(int y);
void Dfsx(int x){
	int s=1;
	for(int i=1;i<=m;++i)s^=a[x][i];
	s&=1;
	if(cx[x]==0){
		if(s)ok2=0;
		cx[x]=inf;
		return;
	}
	cx[x]=inf;
	for(auto y:hx[x])if(a[x][y]==2){
		a[x][y]=s;
		if((--cy[y])<=1)Dfsy(y);
		break;
	}
}
void Dfsy(int y){
	int s=1;
	for(int x=1;x<=n;++x)s^=a[x][y];
	s&=1;
	if(cy[y]==0){
		if(s)ok2=0;
		cy[y]=inf;
		return;
	}
	cy[y]=inf;
	for(auto x:hy[y])if(a[x][y]==2){
		a[x][y]=s;
		if((--cx[x])<=1)Dfsx(x);
		break;
	}
}
int fa[40005];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	read(n,m);
	for(int i=1;i<=n;++i)read(s[i]+1);
	int k=0;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]=='?')++k;
	if(!(n&1) && !(m&1)){
		return write(fpm(2,k).x,'\n');
	}
	if((n&1) && (m&1)){
		ok1=ok2=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=s[i][j]=='?'?2:s[i][j]-'0';
				if(a[i][j]==2){
					++cx[i];
					hx[i].emplace_back(j);
					++cy[j];
					hy[j].emplace_back(i);
				}
			}
		}
		for(int i=1;i<=n;++i)
			if(cx[i]<=1)dfsx(i);
		for(int i=1;i<=m;++i)
			if(cy[i]<=1)dfsy(i);
		int cnt=0;
		for(int i=1;i<=n+m;++i)fa[i]=i;
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(a[i][j]==2){
			++cnt;
			if(find(i)!=find(j+n)){
				--cnt;
				fa[find(i)]=find(j+n);
			}
			else {a[i][j]=0;--cx[i];--cy[j];}
		}

		for(int i=1;i<=n;++i)
			if(cx[i]<=1)dfsx(i);
		for(int i=1;i<=m;++i)
			if(cy[i]<=1)dfsy(i);
		Z ans=ok1?fpm(2,cnt):0;
		for(int i=1;i<=n;++i)cx[i]=0,hx[i].clear();
		for(int i=1;i<=m;++i)cy[i]=0,hy[i].clear();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=s[i][j]=='?'?2:s[i][j]-'0';
				if(a[i][j]==2){
					++cx[i];
					hx[i].emplace_back(j);
					++cy[j];
					hy[j].emplace_back(i);
				}
			}
		}
		for(int i=1;i<=n;++i)
			if(cx[i]<=1)Dfsx(i);
		for(int i=1;i<=m;++i)
			if(cy[i]<=1)Dfsy(i);
		cnt=0;
		for(int i=1;i<=n+m;++i)fa[i]=i;

		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(a[i][j]==2){
			++cnt;
			if(find(i)!=find(j+n)){
				--cnt;
				fa[find(i)]=find(j+n);
			}
			else {a[i][j]=0;--cx[i];--cy[j];}
		}

		for(int i=1;i<=n;++i)
			if(cx[i]<=1)Dfsx(i);
		for(int i=1;i<=m;++i)
			if(cy[i]<=1)Dfsy(i);
		ans+=ok2?fpm(2,cnt):0;
		write(ans.x,'\n');
	}
	else{
		if(n&1){
			for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]=s[i][j]=='?'?2:s[i][j]-'0';
		}
		else{
			for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[j][i]=s[i][j]=='?'?2:s[i][j]-'0';
			swap(n,m);
		}

		// m=2k
		// n=2u+1
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				ss[j]^=a[i][j];
				cnt[j]+=a[i][j]==2;
			}
		}
		int hv=0;
		Z ans=1;
		//for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)write(a[i][j],j==m?'\n':' ');
		for(int i=1;i<=m;++i)if(!cnt[i]){
			hv|=1<<ss[i];
		}
		else{
			ans*=fpm(2,cnt[i]-1);
		}
		ans*=2-__builtin_popcount(hv);
		return write(ans.x,'\n');
	}
	return 0;
}