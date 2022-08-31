/*
Author: CNYALI_LK
LANG: C++
PROG: F.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const signed inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>ll dcmp(T a,T b){return a>b;}
template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
	const ll SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; ll f, qr;
	// getchar
#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// prll the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed lleger
	inline void read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}

	inline void read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	inline void read (char &x) {
		x=gc();
	}
	inline void read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
	}
	template<typename A,typename ...B>
		inline void read(A &x,B &...y){
			read(x);read(y...);
		}
	// prll a signed lleger
	inline void write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}

	inline void write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	inline void write (char x) {
		putc(x);
	}
	inline void write(const char *x){
		while(*x){putc(*x);++x;}
	}
	inline void write(char *x){
		while(*x){putc(*x);++x;}
	}
	template<typename A,typename ...B>
		inline void write(A x,B ...y){
			write(x);write(y...);
		}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
pii f[100005];
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
int main(){
#ifdef cnyali_lk
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	ll n,a=1,b,x=0,t=0;
	read(n);
	b=n;
	for(ll i=2;i*i<=n;++i)if(!(b%i)){
		x=i;
		while(!(b%i)){b/=i;a*=i;++t;}
		break;
	}
	if(!x || b==1)printf("NO\n");
	else{
		printf("YES\n");
		ll x,y;
		exgcd(a,b,x,y);
		x*=n-1;
		y*=n-1;
		y+=x/b*a;
		x%=b;
		x+=y/a*b;
		y%=a;
		t=0;
		while(1){
			if(x>=b){f[++t]=make_pair(b-1,b);x-=b-1;}
			else{f[++t]=make_pair(x,b);break;}
		}
		while(1){
			if(y>=a){f[++t]=make_pair(a-1,a);y-=a-1;}
			else{f[++t]=make_pair(y,a);break;}
		}
		write(t,'\n');
		for(ll i=1;i<=t;++i)write(f[i].x,' ',f[i].y,'\n');
		/*
		 *x/b+y/a=ab-1/ab
		 * */
	}
	return 0;
}