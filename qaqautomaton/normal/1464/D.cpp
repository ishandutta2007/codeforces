/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp
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
const int p=1000000007;
int fpm(int a,int b){
	int c(1);for(;b;b>>=1,a=(ll)a*a%p)if(b&1)c=(ll)c*a%p;
	return c;
}
int a[1000005];
bitset<1000005>v;
int w[1000005],t;
int s[3];
int calc(int x,int y){
	int mn=min(x,y);
	int cnt=mn;
	x-=mn;y-=mn;
	cnt+=x/3*2;
	cnt+=y;
	return cnt;
}
int calc2(int x,int y){
	int mn=inf;
	if(y>=2)chkmin(mn,calc(x,y-2));
	if(y && x>=2)chkmin(mn,calc(x-2,y-1)+1);
	if(x>=4)chkmin(mn,calc(x-4,y)+2);
	return mn;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int T;
	read(T);
	for(;T;--T){
		int n;
		read(n);
		t=0;
		for(int i=1;i<=n;++i){read(a[i]);v[i]=0;}
		for(int i=1;i<=n;++i)if(!v[i]){
			int l=0;
			int j=i;
			while(!v[j]){
				++l;v[j]=1;j=a[j];
			}
			w[++t]=l;
		}
		/*read(t);
		for(int i=1;i<=t;++i)read(w[i]);*/
		s[1]=s[2]=0;
		if(n%3==0){
			write(fpm(3,n/3),' ');
			int cnt=0;
			for(int i=1;i<=t;++i){
				if(w[i]>3)cnt+=(w[i]-1)/3;
				++s[w[i]%3];
			}
			cnt+=calc(s[1],s[2]);
			write(cnt,'\n');
		}
		else if((n%3)==2){
			write(fpm(3,n/3)*2%p,' ');
			int cnt=0;
			for(int i=1;i<=t;++i){
				if(w[i]%3==2){
					swap(w[i],w[t]);
					break;
				}
			}
			for(int i=1;i<=t;++i){
				if(w[i]>3)cnt+=(w[i]-1)/3;
				++s[w[i]%3];
			}
			if(s[2])--s[2];else{s[1]-=2;++cnt;}
			cnt+=calc(s[1],s[2]);
			write(cnt,'\n');
		}
		else{
			write(fpm(3,n/3-1)*4ll%p,' ');
			int cnt=0;
			int hv=0;
			for(int i=1;i<=t;++i){
				if(w[i]>4 && w[i]%3==1){
					++cnt;
					w[i]-=4;w[++t]=4;break;
				}
				else if(w[i]==4){swap(w[i],w[t]);break;}
				
			}
			for(int i=1;i<=t;++i){
				if(w[i]>3)cnt+=(w[i]-1)/3;
				++s[w[i]%3];
				if(w[i]>=3)hv=1;
			}
			
			if(w[t]==4){
				int v=calc2(s[1],s[2]);
				--s[1];
				cnt+=min(v,calc(s[1],s[2])-1);
			}		
			else{
				int v=calc2(s[1],s[2]);
				if(s[1] && hv){
					--s[1];
					chkmin(v,calc(s[1],s[2])+1);
					//s[1]+s[2]-(s[1]+s[2]+s[2])/3+1);
				}
				cnt+=v;
			}
			write(cnt,'\n');
		}
	}
	return 0;

}