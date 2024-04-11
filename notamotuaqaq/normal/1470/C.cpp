/*
Author: QAQAutoMaton
Lang: C++
Code: C.cpp
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
#ifdef QAQAutoMaton
int cnt=0;
int a[100005],n,k,p,na[100005];
int query(int x){
	++cnt;
	assert(cnt<=1000);
	int ret=a[x];
	//for(int i=1;i<=n;++i)cout<<a[i]<<(i==n?'\n':' ');
	for(int i=1;i<=n;++i){
		if(i==p){na[i+1]+=a[i];}
		else{
			na[i-1]+=a[i]>>1;
			na[i+1]+=a[i]-(a[i]>>1);
		}
	}
	for(int i=1;i<=n;++i)a[i]=na[i];
	a[n]+=na[0];a[1]+=na[n+1];
	//for(int i=1;i<=n;++i)cout<<a[i]<<(i==n?'\n':' ');
	for(int i=0;i<=n+1;++i)na[i]=0;
	return ret;
}
#else
int query(int x){
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}
#endif
int bound(int l,int r,int n,int k){
	//cout<<query(l)<<' '<<query(r)<<endl;
	while(l<r){
		int mid=(l+r)>>1;
		int f=query(((mid-1)%n+n)%n+1);
		if(f<k)l=mid+1;
		else if(f>k)r=mid-1;
		else return ((mid-1)%n+n)%n+1;
	}
	return ((l-1)%n+n)%n+1;
}
int ask(int n,int k){
	if(n<=1990){
		int x=1;
		query(1);
		for(int i=1;i<=n>>1;++i){
			int v=query(1);
			if(v<k){return i%n+1;}
			else if(v>k)return (n-i)%n+1;
		}
		if(!(n&1)){
			if(query(2)<k)return (n>>1)+1;
			else return 1;
		}
		else return 1;
	}
	else{
		int B=400;
		for(int i=1;i<=B;++i)query(1);
		for(int i=1;i*B<=n;++i){
			int x=query(i*B);
			if(x>k){
				return bound(i*B - (i+B-1),i*B-1,n,k);
			}
			else if(x<k)
				return bound(i*B+1,i*B+(i+B-1),n,k);
			
		}
	}
	return -1;
}
signed main(){
#ifdef QAQAutoMaton
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()/100);
	n=10001;k=1000000000;p=n;//rnd()%n+1;
	//n=100000;k=((rnd()%1000)+1)<<1;
	//p=rnd()%n+1;
	//cin>>n>>k>>p;
	//k=(k>>1)<<1;
	for(int i=1;i<=n;++i)a[i]=k;
	//p=rnd()%n+1;
	cout<<p<<endl;
	int ans=ask(n,k);
	cout<<ans<<endl;
	assert(ans==p);
	cout<<cnt<<endl;
	cout<<"good job\n"<<endl;
#else
	int n,k;
	cin>>n>>k;
	int ans=ask(n,k);
	cout<<"! "<<ans<<endl;
#endif
	return 0;
}