/*
Author: QAQAutoMaton
Lang: C++
Code: E.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
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
int inf=1000000000000000000ll;
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
namespace run{
	int n,c,q;
	int a[30005];
	int f[150055];
	int id[30005][5];
	int wx[150055],wy[150055];
	int l;
	pii w[7];
	vector<int> to[150055];
	int fa[21][150055],sf[21][150055];
	bool main(){
		read(n,c,q);
		l=0;
		for(int i=1;i<=n+1;++i)for(int j=0;j<=c;++j){
			id[i][j]=++l;
			to[l].clear();
			wx[l]=i;wy[l]=j;
		}
		for(int i=1;i<=n;++i){
			read(a[i]);
		}
		for(int i=0;i<=c;++i)f[id[n+1][i]]=1;
		for(int i=n;i;--i){
			for(int j=0;j<=c;++j){
				int &xf=f[id[i][j]];
				xf=0;
				int l=min(n-i,j)+1;
				for(int k=0;k<=j && i+k<=n;++k){
					xf+=f[id[i+k+1][j-k]];
					w[k+1]={a[i+k],k};
				}
				chkmin(xf,inf);
				sort(w+1,w+l+1);
				for(int k=1;k<=l;++k)to[id[i][j]].emplace_back(id[i+w[k].y+1][j-w[k].y]);
			}
		}
		for(int i=1;i<=l;++i){
			int mx=inf;
			int s=0;
			fa[0][i]=0;sf[0][i]=inf;
			for(auto x:to[i]){
				if(chkmin(mx,x))fa[0][i]=x,sf[0][i]=s;
				chkmin(s+=f[x],inf);
			}
		}
		for(int i=1;i<=14;++i)for(int j=1;j<=l;++j){fa[i][j]=fa[i-1][fa[i-1][j]];sf[i][j]=min(sf[i-1][j]+sf[i-1][fa[i-1][j]],inf);}
		for(;q;--q){
			int s,y;
			int lim;
			read(y,s);
			lim=y*(c+1);
			int x=c+1;
			if(s>f[x]){write("-1\n");continue;}
			while(1){
				int i=0;
				while(fa[i][x]<=lim && sf[i][x]<s && s<=sf[i][x]+f[fa[i][x]]){
					s-=sf[i][x];	
					x=fa[i][x];
					++i;
				}
				while(i){
					--i;
					if(fa[i][x]<=lim && sf[i][x]<s && s<=sf[i][x]+f[fa[i][x]]){
						s-=sf[i][x];	
						x=fa[i][x];
					}
				}
				for(auto i:to[x]){
					if(s>f[i]){s-=f[i];}
					else{
						if(i>lim){
							int l=wx[x],r=wx[i]-1;
							//write(x,' ',i,' ',l,' ',r,' ',y,'\n');
							write(a[l+r-y],'\n');
							goto _end;
						}
						else{x=i;break;}
					}
				}	
			}
			_end:;
		}
		return 0;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t){
		run::main();
	}
	return 0;
}