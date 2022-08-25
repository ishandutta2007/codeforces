/*
Author: QAQAutoMaton
Lang: C++
Code: H.cpp
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
const int N=200005;
int a[N][4],b[N],c[N];
int s1[N];
ll s2[N];
const int B=2500;
const int nB=81;
int ps1[nB][N];
ll ps2[nB][N],pans[nB];
int s[5][nB][N];
const int id[4][4]={
	{0,0,0,0},
{0,0,1,0},
{0,0,2,3},
{0,0,0,4}
};
#define f(l,r) s[id[l][r]]
int blk[N],st[nB],ed[nB];
ll dp[4][4];
int n,q;	
void add(int x,int y){
	for(int i=1;i<=3;++i)for(int j=1;j<=3;++j)dp[i][j]=i==j?y:0;
	for(int i=x-1;i>=st[blk[x]];--i){
		for(int j=1;j<=3;++j)for(int k=j+1;k<=3;++k){
			if(a[i][j]==a[x][k])dp[j][k]+=dp[j+1][k];
		}
	}
	for(int i=blk[x]-1;i;--i){
		for(int r=1;r<=3;++r)for(int l=1;l<r;++l){
			for(int v=l;v<r;++v){
				dp[l][r]+=f(l,v)[i][a[x][r]]*dp[v+1][r];
			}
		}
	}
	for(int i=1;i<=3;++i)dp[i][i]=dp[1][i];
	dp[1][2]=dp[1][3]=dp[2][3]=0;
	for(int i=x+1;i<=ed[blk[x]];++i){
		for(int j=1;j<=3;++j)for(int k=3;k>j;--k){
			if(a[i][k]==a[x][j])dp[j][k]+=dp[j][k-1];
		}
	}
	ps1[blk[x]][a[x][1]]+=dp[1][1];
	for(int i=1;i<=2;++i)ps2[blk[x]][a[x][i]]+=dp[i][2];
	for(int i=1;i<=3;++i)pans[blk[x]]+=dp[i][3];
	for(int b=blk[x]+1;b<=blk[n];++b){
		for(int l=1;l<=3;++l)for(int r=3;r>l;--r){
			for(int v=l+1;v<=r;++v){
				dp[l][r]+=dp[l][v-1]*f(v,r)[b][a[x][l]];
			}
		} 
		ps1[b][a[x][1]]+=dp[1][1];
		for(int i=1;i<=2;++i)ps2[b][a[x][i]]+=dp[i][2];
		for(int i=1;i<=3;++i)pans[b]+=dp[i][3];
	}
}
void rebuild(int x){
	for(int i=st[x];i<=ed[x];++i){
		f(3,3)[x][a[i][3]]+=1;
		f(2,3)[x][a[i][3]]+=f(2,2)[x][a[i][3]];
		f(2,2)[x][a[i][2]]+=1;
		f(1,2)[x][a[i][2]]+=f(1,1)[x][a[i][2]];
		f(1,1)[x][a[i][1]]+=1;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("H.in","r",stdin);
	freopen("H.out","w",stdout);
#endif
	read(n,q);
	for(int i=1;i<=n;++i)read(a[i][2]);
	for(int i=1;i<=n;++i)read(b[i]);
	for(int i=1;i<=n;++i)read(c[i]);
	for(int i=1;i<=n;++i){
		a[i][1]=b[a[i][2]];
		a[i][3]=c[a[i][2]];
		blk[i]=(i-1)/B+1;
		if(blk[i]!=blk[i-1])st[blk[i]]=i;
		ed[blk[i]]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans+=s2[a[i][3]];
		s2[a[i][2]]+=s1[a[i][2]];
		++s1[a[i][1]];
		if(i==ed[blk[i]]){
			pans[blk[i]]=ans;
			for(int j=1;j<=n;++j)ps1[blk[i]][j]=s1[j];
			for(int j=1;j<=n;++j)ps2[blk[i]][j]=s2[j];
		}
	}
	for(int i=1;i<=blk[n];++i)rebuild(i);
	for(;q;--q){
		int tp,x;
		read(tp);
		if(tp==1){
			read(x);
			add(x,-1);
			for(int i=1;i<=3;++i)--f(i,i)[blk[x]][a[x][i]];
			for(int i=st[blk[x]];i<x;++i){
				if(a[i][1]==a[x][2])--f(1,2)[blk[x]][a[x][2]];
				if(a[i][2]==a[x][3])--f(2,3)[blk[x]][a[x][3]];
			}
			for(int i=x+1;i<=ed[blk[x]];++i){
				if(a[i][2]==a[x][1])--f(1,2)[blk[x]][a[x][1]];
				if(a[i][3]==a[x][2])--f(2,3)[blk[x]][a[x][2]];
			}
			read(a[x][2]);
			a[x][1]=b[a[x][2]];
			a[x][3]=c[a[x][2]];
			add(x,1);
			for(int i=1;i<=3;++i)++f(i,i)[blk[x]][a[x][i]];
			for(int i=st[blk[x]];i<x;++i){
				if(a[i][1]==a[x][2])++f(1,2)[blk[x]][a[x][2]];
				if(a[i][2]==a[x][3])++f(2,3)[blk[x]][a[x][3]];
			}
			for(int i=x+1;i<=ed[blk[x]];++i){
				if(a[i][2]==a[x][1])++f(1,2)[blk[x]][a[x][1]];
				if(a[i][3]==a[x][2])++f(2,3)[blk[x]][a[x][2]];
			}
		}
		else{
			read(x);
			int *s1=ps1[blk[x]-1];
			ll *s2=ps2[blk[x]-1];
			ll ans=pans[blk[x]-1];

			for(int i=st[blk[x]];i<=x;++i){
				ans+=s2[a[i][3]];
				s2[a[i][2]]+=s1[a[i][2]];
				++s1[a[i][1]];
			}
			write(ans,'\n');
			for(int i=x;i>=st[blk[x]];--i){
				--s1[a[i][1]];
				s2[a[i][2]]-=s1[a[i][2]];
			}
		}
	}
	return 0;
}

// orz lxl,dllxl