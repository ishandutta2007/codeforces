/*
Author: QAQAutomaton
Lang: C++
Code: C.cpp
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
bitset<205>ok[205];
pii a[205];
int operator *(pii a,pii b){return a.x*b.y-a.y*b.x;}
pii operator -(pii a,pii b){return make_pair(a.x-b.x,a.y-b.y);}
int qwq(int a,int b){
	a=a>0?1:a<0?-1:0;
	b=b>0?1:b<0?-1:0;
	return a*b<0;
}
bool in(pii a,pii b,pii c){
	if(c==a||c==b)return 0;
	if((c.x>a.x && c.x>b.x)||(c.x<a.x&&c.x<b.x))return 0;
	if((c.y>a.y && c.y>b.y)||(c.y<a.y&&c.y<b.y))return 0;
	return (c.x-a.x)*(c.y-b.y)==(c.y-a.y)*(c.x-b.x);
}
bool cross(pii a,pii b,pii c,pii d){
	return qwq((c-a)*(b-a),(d-a)*(b-a))&&qwq((c-b)*(a-b),(d-b)*(a-b))&&qwq((a-c)*(d-c),(b-c)*(d-c))&&qwq((a-d)*(c-d),(b-d)*(c-d));
}
const int p=1000000007;
int f[205][205];
signed main(){
#ifdef QAQAutoMaton 
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n;
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i].x,a[i].y);
	}
	int s=0;
	for(int i=1;i<=n;++i){
		s+=a[i]*a[i%n+1];	
	}
	if(s<0)s=-s;
	for(int i=1;i<=n;++i)ok[i][i%n+1]=ok[i%n+1][i]=1;
	for(int i=1;i<=n;++i){
		for(int j=i+2;j<=(i==1?n-1:n);++j){
			ok[i][j]=1;
			for(int k=1;k<=n;++k){
				if(in(a[i],a[j],a[k])){ok[i][j]=0;break;}	
			}
			if(ok[i][j])
			for(int k=1;k<=n;++k){
				if(cross(a[i],a[j],a[k],a[k%n+1])){ok[i][j]=0;break;}
			}
			if(ok[i][j]){
				int x=a[i]*a[j],y=-x;
				for(int k=1;k<=n;++k)
					if(i<=k && k<j)
						y+=a[k]*a[k+1];
					else x+=a[k]*a[k%n+1];
				if(abs(x)+abs(y)!=s)ok[i][j]=0;
			}
			ok[j][i]=ok[i][j];
		}
	}
//	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)write((bool)ok[i][j],j==n?'\n':' ');
	for(int i=n;i;--i){
		f[i][i+2]=ok[i][i+2];
		f[i][i+1]=1;
		for(int j=i+3;j<=n;++j){
			f[i][j]=f[i+1][j]*ok[i+1][j];
			for(int k=i+2;k<j;++k){
				f[i][j]=(f[i][j]+ok[i][k]*ok[k][j]*f[k][j]*f[i][k])%p;
			}
		}
	}
	write(f[1][n],'\n');
	return 0;
}