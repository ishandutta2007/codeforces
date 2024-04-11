/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
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
map<int,int> mp;
pii s[105][10005]; 
int x[105],isx[105];
int n,m;
// \prod p[j]^(s[i][j].x*x[i]+s[i][j].y)
// x[i]=a[i]w+b[i]

int p[105],q[105];
void exgcd(int a,int b,int &d,int &x,int &y){
	if(!b){d=a;x=1;y=0;return;}
	exgcd(b,a%b,d,y,x);
	y-=(a/b)*x;
}
int a[105],b[105];
void solvew(int id){
	for(int i=1;i<=n;++i){
		p[i]=s[i][id].x;
		q[i]=s[i][id].y%s[i][id].x;
	}
	int xp=p[1],xq=q[1];
	/*
	 * p1x1+q1=p2x2+q2	
	 * p1x1-p2x2=q2-q1
	 * */
	int x,y,d;
	for(int i=2;i<=n;++i){
		exgcd(xp,p[i],d,x,y);
		if((q[i]-xq)%d)exit(write("-1\n"));
		x*=(q[i]-xq)/d;
		int np=xp/d*p[i];
		xq=((x%p[i]*xp%np+xq)%np+np)%np;
		xp=np;
	}
	for(int i=1;i<=n;++i){
		while(xq<s[i][id].y)xq+=xp;
	}
	for(int i=1;i<=n;++i){
		a[i]=xp/s[i][id].x;
		b[i]=(xq-s[i][id].y)/s[i][id].x;
	}
}
int d,isset;
void calc(int x,int y){
	if(!x){
		if(y)exit(write("-1\n"));
	}
	else{
		if(y%x)exit(write("-1\n"));
		if(y/x<0)exit(write("-1\n"));
		if(!isset){isset=1;d=y/x;}
		else if(d!=y/x)exit(write("-1\n"));
	}
}
int xp[10005];
const int cy=1e9+7;
int fpm(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*a%cy)if(b&1)c=c*a%cy;
	return c;
}
void calc(int tp){
	if(tp){
		int ans=1;
		for(int i=1;i<=m;++i){
			ans=ans*fpm(xp[i],(a[1]*d%(cy-1)+b[1])*s[1][i].x%(cy-1)+s[1][i].y)%cy;
		}
		write(ans,'\n');
	}
	else{
		int ans=1;
		for(int i=1;i<=m;++i){
			ans=ans*fpm(xp[i],x[1]*s[1][i].x%(cy-1)+s[1][i].y)%cy;
		}
		write(ans,'\n');

	}

}
void solvex(int j){
	int stx=0,wx=0;
	for(int i=1;i<=n;++i){
		if(!s[i][j].x){
			if(!stx){stx=1;wx=s[i][j].y;}
			else if(wx!=s[i][j].y)exit(write("-1\n"));
		}
	}
	for(int i=1;i<=n;++i){
		if(s[i][j].x){
			if((wx-s[i][j].y)%s[i][j].x)exit(write("-1\n"));
			if((wx-s[i][j].y)/s[i][j].x<0)exit(write("-1\n"));
			if(!isx[i]){isx[i]=1;x[i]=(wx-s[i][j].y)/s[i][j].x;}
			else if(x[i]!=(wx-s[i][j].y)/s[i][j].x)exit(write("-1\n"));
		}
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(n);
	int x,y;
	for(int j=1;j<=n;++j){
		read(x,y);
		for(int i=2;i*i<=x;++i){
			if(!(x%i)){
				if(!mp.count(i))xp[mp[i]=++m]=i;
				int id=mp[i];
				while(!(x%i)){
					x/=i;++s[j][id].y;
				}
			}
		}
		if(x>1){
			if(!mp.count(x))xp[mp[x]=++m]=x;
			int id=mp[x];
			++s[j][id].y;
		}
		for(int i=2;i*i<=y;++i){
			if(!(y%i)){
				if(!mp.count(i))xp[mp[i]=++m]=i;
				int id=mp[i];
				while(!(y%i)){
					y/=i;++s[j][id].x;
				}
			}
		}
		if(y>1){
			if(!mp.count(y))xp[mp[y]=++m]=y;
			int id=mp[y];
			++s[j][id].x;
		}
	}
	if(!m)return write("1\n");
//	for(int i=0;i<=n;++i)for(int j=1;j<=m;++j)write(s[i][j].x,',',s[i][j].y,j==m?'\n':' ');
	int sel=0;
	for(int j=1;j<=m;++j){
		bool ok=1;
		for(int i=1;i<=n;++i)if(!s[i][j].x){ok=0;break;}
		if(ok){sel=j;break;}
	}
	if(sel){
		solvew(sel);
		for(int i=1;i<n;++i){
			for(int j=1;j<=m;++j){
	//			let s[i][j].x*(a[i]*d+b[i])+s[i][j].y == s[i+1][j].x*(a[i+1]*d+b[i+1])+s[i+1][j].y
	//			let s[i][j].x*a[i]*d+s[i][j].x*b[i]+s[i][j].y == s[i+1][j].x*a[i+1]*d+s[i+1][j].x*b[i+1]+s[i+1][j].y
				calc(s[i][j].x*a[i]-s[i+1][j].x*a[i+1],s[i+1][j].x*b[i+1]+s[i+1][j].y-s[i][j].x*b[i]-s[i][j].y);
			}
		}
		calc(1);
	}
	else{
		for(int j=1;j<=m;++j){
			solvex(j);
		}
		calc(0);
	}
	return 0;
}