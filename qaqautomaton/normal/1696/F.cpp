/*
Author: QAQAutoMaton
Lang: C++
Code: F.cpp
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
#define forall(a,b) for(int a=b._Find_first();a!=b.size();a=b._Find_next(a))
namespace run{
	bitset<105>ok2[105][105],ok[105][105];
	bitset<105>e[105],cur,d[105];
	int dis[105][105];
	// ok: i,x->j ok2 i,j->x
	char s[105];
	int n;
	void dfs(int x,int f,int *d,int dp){
		d[x]=dp;
		forall(i,e[x]){
			if(i!=f)dfs(i,x,d,dp+1);
		}
	}
	bool judge(){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(e[i][j] || e[j][i]){
					e[i][j]=e[j][i]=1;
				}
			}
		}
		for(int i=1;i<=n;++i){
			dfs(i,0,dis[i],0);
		}
		for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)for(int k=1;k<=n;++k)if((dis[i][k]==dis[j][k])!=ok2[i][j][k])return 0;
		write("Yes\n");
		for(int i=1;i<n;++i)for(int j=i+1;j<=n;++j)if(e[i][j])write(i,' ',j,'\n');
		return 1;
	}
	bool work(int x){
		d[0].reset();
		d[0][1]=1;
		e[1]=ok[x][1];
		d[1]=e[1];
		cur=e[1];
		cur[1]=1;
		for(int i=1;;++i){
			int ls=cur.count();
			if(ls==n)break;
			d[i+1].reset();
			forall(x,d[i-1]){
				forall(y,e[x]){
					e[y]=ok[x][y];
					e[y][x]=0;
					d[i+1]|=e[y];
					if((cur&e[y]).any())return 0;
					cur|=e[y];
				}
			}	
			if((uint)ls==cur.count())return 0;
		}
		return judge();
	}
	bool main(){
		read(n);
		for(int i=1;i<=n;++i){
			ok2[i][i].reset();
			for(int j=1;j<=n;++j)ok2[i][i][j]=1;
		}
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				read(s+1);
				ok2[i][j].reset();
				for(int k=1;k<=n;++k){
					ok2[i][j][k]=s[k]=='1';
				}
				ok2[j][i]=ok2[i][j];
			}	
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				ok[i][j].reset();
				for(int x=1;x<=n;++x){
					ok[i][j][x]=ok2[i][x][j];
				}
			}
		}
		/*for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
			write('(',i,' ',j,')');
			for(int k=1;k<=n;++k)putc(ok[i][j][k]+'0');
			putc('\n');
		}*/
		for(int v=2;v<=n;++v){
			for(int i=1;i<=n;++i){
				e[i].reset();
				for(int j=1;j<=n;++j){
					e[i][j]=0;
				}
			}
			if(work(v))return 0;
		}
		return write("No\n");
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t)run::main();
	return 0;
}