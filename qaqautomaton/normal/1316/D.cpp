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
pii a[1005][1005];
int vis[1005][1005];
char w[1005][1005];
//R->++y
//L->--y
//U->--x
//D->++x
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char ch[4]={'D','U','R','L'};
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;++i){
		if(!vis[x+dx[i]][y+dy[i]] && a[x+dx[i]][y+dy[i]]==a[x][y]){
			w[x+dx[i]][y+dy[i]]=ch[i];
			dfs(x+dx[i],y+dy[i]);
		}
	}
	if(!vis[x-1][y] && a[x-1][y]==a[x][y]){
		w[x-1][y]='D';
		dfs(x-1,y);
	}
	if(!vis[x+1][y] && a[x+1][y]==a[x][y]){
		w[x+1][y]='U';
		dfs(x+1,y);
	}
	if(!vis[x][y-1] && a[x][y-1]==a[x][y]){
		w[x][y-1]='R';
		dfs(x,y-1);
	}
	if(!vis[x][y+1] && a[x][y+1]==a[x][y]){
		w[x][y+1]='L';
		dfs(x,y+1);
	}
}
int fx[1005][1005],fy[1005][1005];
char rev[129];
void dfs2(int x,int y){
	vis[x][y]=2;
	for(int i=0;i<4;++i){
		if(a[x+dx[i]][y+dy[i]]==a[x][y]){
			if(!vis[x+dx[i]][y+dy[i]]){
				w[x+dx[i]][y+dy[i]]=ch[i];
				fx[x+dx[i]][y+dy[i]]=x;
				fy[x+dx[i]][y+dy[i]]=y;
				dfs2(x+dx[i],y+dy[i]);
				if(!fx[x][y]){
					w[x][y]=rev[ch[i]];
				}
			}
		}
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n;
	read(n);
	rev['U']='D';
	rev['D']='U';
	rev['L']='R';
	rev['R']='L';
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			read(a[i][j].x,a[i][j].y);
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(a[i][j]==make_pair(i,j) && !vis[i][j]){
		w[i][j]='X';
		dfs(i,j);
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(!vis[i][j] && a[i][j]!=make_pair(-1,-1))return write("INVALID\n");
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(!vis[i][j]){
		w[i][j]='X';
		dfs2(i,j);
		if(w[i][j]=='X')return write("INVALID\n");
	}
	write("VALID\n");
	for(int i=1;i<=n;++i){
		w[i][n+1]=0;
		write(w[i]+1,'\n');
	}
	return 0;
}