/*
Author: QAQAutoMaton
Lang: C++
Code: G.cpp
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
namespace run{
	vector<int> fr2[150005],fr[150005];
	vector<int> to[150005],bk[150005];
	int tr[150005];
	bitset<150005>s;
	int f[150005],g[150005];
	bitset<150005> s1[2],s2[2];
	// f: -1,i
	// g: i,-1
	int a[2][2],b[2][2];
	void dfs(int x,int y){
		if(s1[y][x])return;
		s1[y][x]=1;
		for(auto i:bk[x])dfs(i,!y);
	}
	void dfs2(int x,int y){
		if(s2[y][x])return;
		s2[y][x]=1;
		for(auto i:to[x])dfs2(i,!y);
	}
	bool main(){
		int n,m;
		read(n,m);
		s1[0].reset();s1[1].reset();
		s2[0].reset();s2[1].reset();
		s.reset();
		for(int i=1;i<=n;++i){
			f[i]=g[i]=0;
			fr2[i].clear();fr[i].clear();
			to[i].clear();
			bk[i].clear();
		}
		for(int i=1;i<=m;++i){
			int u,v;
			read(u,v);
			fr2[n-u+1].emplace_back(n-v+1);
			fr[v].emplace_back(u);
			if(u+1==v)s[u]=1;
		}
		for(int i=n;i;--i){
			tr[i]=s[i]?tr[i+1]:i;
		}
		int l=tr[1],r=n;
		if(l==n){
			return write(n*(n-1)>>1,'\n');
		}
		while(s[r-1])--r;
		int ans=0;
		for(int i=2;i<=n;++i)for(auto j:fr[i])if(j<i-1 && tr[j+1]>=i-1){
			//write(j+1,' ',i,'!');
			to[j+1].emplace_back(i);
			bk[i].emplace_back(j+1);
		}
		dfs(l+1,0);
		dfs2(l+1,0);
		a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
		b[0][0]=b[0][1]=b[1][0]=b[1][1]=0;
		for(int i=2;i<=l+1;++i){
			a[s1[0][i]][s1[1][i]]+=1;
		}

		for(int i=r;i<=n;++i){
			b[s2[0][i]][s2[1][i]]+=1;
		}
		/*write(a[0][0],' ',a[0][1],' ',a[1][0],' ',a[1][1],'!');
		write(b[0][0],' ',b[0][1],' ',b[1][0],' ',b[1][1],'!');*/
		for(int i=0;i<2;++i)for(int j=0;j<2;++j)for(int k=0;k<2;++k)for(int l=0;l<2;++l){
			if((i&&k) || (j&&l))ans+=a[i][j]*b[k][l];
		}
		if(l+1==r)--ans;
		//write(ans,'?','\n');
		int at=0;
		for(int i=1;i<=n;++i)f[i]=g[i]=0;
		for(int i=2;i<=n;++i){
			for(auto j:fr[i])if(j!=i-1){
				if(j<at)f[j]=g[j]=0;
				f[i-1]+=g[j];
				g[i-1]+=f[j];
			}
			if(!s[i-1]){
				at=i-1;
			}
 
			if(i>=r){
				if(f[i-1])++ans;
			}
			if(i<=l+1){
				++g[i-1];	
			}
			/*for(int j=1;j<i;++j)write(f[j],j==i-1?'\n':' ');
			for(int j=1;j<i;++j)write(g[j],j==i-1?'\n':' ');*/
			if(i==n){
				for(int j=at;j<i;++j)if(g[j]){++ans;break;}
			}
		}
		at=0;
		for(int i=1;i<=n;++i)f[i]=g[i]=0;
		for(int i=1;i<n;++i)if(i<(n-i)){
			int a=s[i],b=s[n-i];
			s[i]=b;s[n-i]=a;
		}
		l=n-l+1,r=n-r+1;
		swap(l,r);
		/*write(ans,'\n');
		//write(l,' ',r,'!','\n');
		for(int i=1;i<n;++i)write((int)s[i]);
		putc('\n');*/
		for(int i=2;i<=n;++i){
			for(auto j:fr2[i])if(j!=i-1){
				//write(j,' ',i,'\n');
				if(j<at)f[j]=g[j]=0;
				f[i-1]+=g[j];
				g[i-1]+=f[j];
			}
			if(!s[i-1]){
				at=i-1;
			}
			/*for(int j=1;j<i;++j)write(f[j],j==i-1?'\n':' ');
			for(int j=1;j<i;++j)write(g[j],j==i-1?'\n':' ');*/
			if(i>=r){
				if(f[i-1])++ans;
			}
			if(i<=l+1){
				++g[i-1];	
			}
			/*if(i==n){
				for(int j=1;j<i;++j)if(g[j]){++ans;break;}
			}*/
		}
		write(ans,'\n');
		return 0;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t){
		run::main();
	}
	return 0;
}