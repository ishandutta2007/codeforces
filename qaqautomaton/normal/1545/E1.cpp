/*
Author: QAQAutoMaton
Lang: C++
Code: G.cpp
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
int xl[200005],xr[200005],yl[200005],yr[200005];
int v[400005],t;
int yv[400005],yt;
vector<int> ad[400005],dl[400005];
pii dp[800005];
int c;
int ban[800005];
int xv[800005];
void adv(int x){
	int l=x<<1,r=x<<1;
	while(l>1 && !ban[l-1])--l;
	while(r<=(t<<1) && !ban[r+1])++r;
	int mn=inf;
	for(int j=1;j<=c;++j)if(xv[l]<=dp[j].x && dp[j].x<=xv[r]){
		chkmin(mn,dp[j].y+abs(dp[j].x-v[x]));
	}
	if(mn<inf){
		dp[++c]={v[x],mn};
		for(int i=c;i>1;--i)if(dp[i].x>dp[i-1].x)swap(dp[i],dp[i-1]);else break;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,x;	
	read(n);
	read(x);
	for(int i=1;i<=n;++i){
		read(yl[i],yr[i],xl[i],xr[i]);
		--xl[i];
		++xr[i];
		--yl[i];++yr[i];
		v[++t]=xl[i];v[++t]=xr[i];
		yv[++yt]=yl[i];
		yv[++yt]=yr[i];
	}
	sort(v+1,v+t+1);
	t=unique(v+1,v+t+1)-v-1;
	sort(yv+1,yv+yt+1);
	yt=unique(yv+1,yv+yt+1)-yv-1;
	for(int i=1;i<=t;++i)xv[i<<1]=v[i];
	xv[1]=-inf;
	xv[t<<1|1]=inf;
	for(int i=1;i<=n;++i){
		xl[i]=lower_bound(v+1,v+t+1,xl[i])-v;
		xr[i]=lower_bound(v+1,v+t+1,xr[i])-v;
		yl[i]=lower_bound(yv+1,yv+yt+1,yl[i])-yv;
		yr[i]=lower_bound(yv+1,yv+yt+1,yr[i])-yv;
		ad[yl[i]].emplace_back(i);
		dl[yr[i]].emplace_back(i);
	}
	dp[c=1]={x,0};
	for(int y=1;y<=yt;++y){
		int las=inf;
		int j=1;
		for(int i=t;i;--i){
			while(j<=c && dp[j].x>v[i]){
				dp[j].x+=yv[y]-yv[y-1];
				if(dp[j].x>las){
					dp[j].y+=dp[j].x-las;
					dp[j].x=las;
				}
				++j;
			}
			if(!ban[i<<1] && ban[i<<1|1])las=v[i];
		}
		while(j<=c){
			dp[j].x+=yv[y]-yv[y-1];
			if(dp[j].x>las){
				dp[j].y+=dp[j].x-las;
				dp[j].x=las;
			}
			++j;
		}
		for(auto id:dl[y]){
			for(int j=xl[id]<<1|1;j<(xr[id]<<1);++j)--ban[j];
		}
		for(auto id:ad[y]){
			if(!ban[xl[id]<<1]){
				adv(xl[id]);
			}		
			if(!ban[xr[id]<<1]){
				adv(xr[id]);
			}
		}
		int nc=0;
		dp[0]={-inf,-inf};
		for(int j=1;j<=c;++j)if(dp[j].x!=dp[nc].x)dp[++nc]=dp[j];
		else chkmin(dp[nc].y,dp[j].y);
		c=nc;
		for(auto id:ad[y]){
			for(int j=xl[id]<<1|1;j<(xr[id]<<1);++j)++ban[j];
			nc=0;
			for(int j=1;j<=c;++j)if(v[xl[id]]<dp[j].x && dp[j].x<v[xr[id]]){
				continue;	
			}
			else dp[++nc]=dp[j];
			c=nc;
		}
	}
	int ans=inf;
	for(int i=1;i<=c;++i)chkmin(ans,dp[i].y);
	write(ans,'\n');
	return 0;
}