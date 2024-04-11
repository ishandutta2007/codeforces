/*
Author: QAQAutoMaton
Lang: C++
Code: A2.cpp
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
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
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
const int w[16][3]={
	{0,1,2},{0,1,3},{0,2,3},{1,2,3},{2,3,4},{2,3,5},{2,4,5},{3,4,5},
	{6,1,7},{6,1,3},{6,7,3},{1,7,3},{7,3,8},{7,3,5},{7,8,5},{3,8,5}
};
int mn[1<<6|5];
int ck[1<<6|5];
int mn2[1<<4|5];
int ck2[1<<4|5];
int mn3[1<<9|5];
int ck3[1<<9|5];
int a[105][105];
vector<vector<pii> >ans;
void mk2(vector<pii> vt){
	int v=0;
	for(int i=0;i<4;++i)v|=a[vt[i].x][vt[i].y]<<i;
	for(int i=0;i<4;++i)if(ck2[v]&(1<<i)){
		ans.emplace_back(vector<pii>{vt[w[i][0]],vt[w[i][1]],vt[w[i][2]]});
	}
	for(auto i:vt)a[i.x][i.y]=0;
}
void mk3(vector<pii> vt){
	int v=0;
	for(int i=0;i<6;++i)v|=a[vt[i].x][vt[i].y]<<i;
	for(int i=0;i<8;++i)if(ck[v]&(1<<i)){
		ans.emplace_back(vector<pii>{vt[w[i][0]],vt[w[i][1]],vt[w[i][2]]});
	}
	for(auto i:vt)a[i.x][i.y]=0;
}
void mk33(vector<pii> vt){
	int v=0;
	for(int i=0;i<9;++i)v|=a[vt[i].x][vt[i].y]<<i;
	for(int i=0;i<16;++i)if(ck3[v]&(1<<i)){
		ans.emplace_back(vector<pii>{vt[w[i][0]],vt[w[i][1]],vt[w[i][2]]});
	}
	for(auto i:vt)a[i.x][i.y]=0;
}
char s[105];
signed main(){
#ifdef QAQAutoMaton 
	freopen("A2.in","r",stdin);
	freopen("A2.out","w",stdout);
#endif
	for(int i=0;i<(1<<6);++i)mn[i]=inf;
	for(int i=0;i<(1<<9);++i)mn3[i]=inf;
	for(int i=0;i<(1<<4);++i)mn2[i]=inf;
	for(int i=0;i<(1<<16);++i){
		int s=0;
		for(int j=0;j<16;++j)if(i&(1<<j)){
			for(int k=0;k<3;++k)s^=1<<w[j][k];
		}
		if(chkmin(mn3[s],__builtin_popcount(i)))ck3[s]=i;
	}
	for(int i=0;i<(1<<8);++i){
		int s=0;
		for(int j=0;j<8;++j)if(i&(1<<j)){
			for(int k=0;k<3;++k)s^=1<<w[j][k];
		}
		if(chkmin(mn[s],__builtin_popcount(i)))ck[s]=i;
	}
	for(int i=0;i<(1<<4);++i){
		int s=0;
		for(int j=0;j<4;++j)if(i&(1<<j)){
			for(int k=0;k<3;++k)s^=1<<w[j][k];
		}
		if(chkmin(mn2[s],__builtin_popcount(i)))ck2[s]=i;
	}
	int t;
	read(t);
	for(;t;--t){
		int n,m;
		read(n,m);
		for(int i=1;i<=n;++i){
			read(s+1);
			for(int j=1;j<=m;++j)a[i][j]=s[j]-'0';
		}
		ans.clear();
		for(int i=n;i>1;i-=2){
			if(i!=3)
			for(int j=m;j>1;j-=2){
				if(j==3){
					mk3({{i,j},{i-1,j},{i,j-1},{i-1,j-1},{i,j-2},{i-1,j-2}});
				}
				else{
					mk2({{i,j},{i-1,j},{i,j-1},{i-1,j-1}});
				}
			}
			else
			for(int j=m;j>1;j-=2){
				if(j==3){
					mk33({{i,j},{i-1,j},{i,j-1},{i-1,j-1},{i,j-2},{i-1,j-2},{i-2,j},{i-2,j-1},{i-2,j-2}});
				}
				else{
					mk3({{i,j},{i,j-1},{i-1,j},{i-1,j-1},{i-2,j},{i-2,j-1}});
				}
			}

		}
		write(ans.size(),'\n');
		for(auto i:ans){write(i[0].x,' ',i[0].y,' ',i[1].x,' ',i[1].y,' ',i[2].x,' ',i[2].y,'\n');}
	}
	return 0;
}