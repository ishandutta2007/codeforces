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
namespace run{
	map<int,int> mp;
	int a[200005];
	set<int> st[200005];
	int pre[200005],nex[200005];
	int mn[19][200005],mx[19][200005],_lg[200005];
	int las[200005];
	int n,m,c;
	int mxr[200005];
	int qmax(int l,int r){
		int h=_lg[r-l+1];
		return max(mx[h][l],mx[h][r-(1<<h)+1]);
	}
	int qmin(int l,int r){
		int h=_lg[r-l+1];
		return min(mn[h][l],mn[h][r-(1<<h)+1]);
	}
	int Q1(int l,int r){
		int xl=l,xr=r;
		while(l<=r){
			int mid=(l+r)>>1;
			if(qmax(xl,mid)>=xl){
				r=mid-1;
			}
			else l=mid+1;
		}
		return r+1;
	}

	int Q2(int l,int r){
		int xl=l,xr=r;
		while(l<=r){
			int mid=(l+r)>>1;
			if(qmin(mid,xr)<=xr){
				l=mid+1;
			}
			else r=mid-1;
		}
		return l-1;
	}
	bool main(){
		read(n,m);
		c=0;
		mp.clear();
		for(int i=1;i<=n;++i){
			mxr[i]=0;
			read(a[i]);
			if(!mp.count(a[i])){mp[a[i]]=++c;a[i]=c;st[c].clear();las[c]=0;}
			else a[i]=mp[a[i]];
			st[a[i]].insert(i);
			pre[i]=las[a[i]];
			las[a[i]]=i;
			nex[i]=n+1;
			if(pre[i])nex[pre[i]]=i;
		}
		for(int i=2;i<=n;++i)_lg[i]=_lg[i>>1]+1;
		for(int i=1;i<=n;++i){
			mx[0][i]=pre[i];
			mn[0][i]=nex[i];
		}
		for(int i=1;i<=_lg[n];++i){
			for(int j=1;j+(1<<i)-1<=n;++j){
				mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
				mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
			}
		}
		int lmx=n+1,rmn=0;
		for(int i=1;i<=m;++i){
			int l,r;	
			read(l,r);
			if(qmax(l,r)<l)continue;
			int v1=Q1(l,r),v2=Q2(l,r);
			chkmin(lmx,v1);
			chkmax(rmn,v2);
			chkmax(mxr[l],r);
		}
		if(lmx>n)return write(0,'\n');
		int ans=rmn;
		for(int i=1;i<lmx;++i){
			chkmax(mxr[i],mxr[i-1]);
			chkmax(mxr[i],i);
			// i,mxr[i]
			chkmax(rmn,i);
			auto it=st[a[i]].upper_bound(mxr[i]);
			--it;
			chkmax(rmn,*it);
			chkmin(ans,rmn-i);
		}
		return write(ans,'\n');
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