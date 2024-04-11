/*
Author: QAQAutomaton
Lang: C++
Code: G.cpp
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
int a[200005],b[200005],m;
int xl[200005],xr[200005],yl[200005],yr[200005],xyl[200005],xyr[200005];
struct smt{
	pii mx,mn;
	int ls,rs;
	smt *l,*r;
	smt(int la,int ra){
		ls=la;rs=ra;
		if(ls==rs){mx=mn=make_pair(a[ls],ls);l=r=0;return;}
		int mid=(ls+rs)>>1;
		l=new smt(ls,mid);r=new smt(mid+1,rs);
		mx=max(l->mx,r->mx);
		mn=min(l->mn,r->mn);
	}
	void qry(int la,int ra,pii &Mx,pii &Mn){
		if(la<=ls && rs<=ra){chkmax(Mx,mx);chkmin(Mn,mn);return;}
		if(la<=l->rs)l->qry(la,ra,Mx,Mn);
		if(r->ls<=ra)r->qry(la,ra,Mx,Mn);
	}
};
smt *xrt;
struct smt2{
	int ls,rs;
	smt2 *l,*r;
	int mxs,mns;
	smt2(int la,int ra){
		ls=la;rs=ra;
		mxs=mns=0;
		if(ls==rs){l=r=0;return;}
		int mid=(ls+rs)>>1;
		l=new smt2(ls,mid);
		r=new smt2(mid+1,rs);
	}
	void set_mx(int x){
		++mxs;	
		if(ls==rs)return;
		if(x<=l->rs)l->set_mx(x);
		else r->set_mx(x);
	}
	void unset_mx(int x){
		--mxs;	
		if(ls==rs)return;
		if(x<=l->rs)l->unset_mx(x);
		else r->unset_mx(x);
	}

	void set_mn(int x){
		++mns;	
		if(ls==rs)return;
		if(x<=l->rs)l->set_mn(x);
		else r->set_mn(x);
	}
	void unset_mn(int x){
		--mns;	
		if(ls==rs)return;
		if(x<=l->rs)l->unset_mn(x);
		else r->unset_mn(x);
	}
	void fnd(int atl,int hmx,int hmn,int &ans){
		if((hmx?mxs:0)+(hmn?mns:0)==rs-ls+1)return;
		if(rs<atl)return;
		if(ls==rs){ans=ls;return;}
		l->fnd(atl,hmx,hmn,ans);
		if(!ans)r->fnd(atl,hmx,hmn,ans);
	}
};
smt2 *rt;
int mxs[200005],mxat[200005],mxt;
int mns[200005],mnat[200005],mnt;
int smxs[200005],smxat[200005],smxt;
int smns[200005],smnat[200005],smnt;
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,q;
	read(n,q);
	for(int i=1;i<=n;++i){
		read(a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;		
	}
	xrt=new smt(1,n);
	rt=new smt2(1,n);
	xyr[n+1]=xr[n+1]=yr[n+1]=n+1;
	for(int i=n;i;--i){
		while(mxt && a[i]>mxs[mxt]){rt->unset_mx(mxat[mxt]);--mxt;}
		mxs[++mxt]=a[i];mxat[mxt]=i;rt->set_mx(mxat[mxt]);
		while(mnt && a[i]<mns[mnt]){rt->unset_mn(mnat[mnt]);--mnt;}
		mns[++mnt]=a[i];mnat[mnt]=i;rt->set_mn(mnat[mnt]);
		while(smxt && a[i]>=smxs[smxt])--smxt;
		int mxl=smxt?smxat[smxt]:n+1;
		smxs[++smxt]=a[i];smxat[smxt]=i;
		while(smnt && a[i]<=smns[smnt])--smnt;
		int mnl=smnt?smnat[smnt]:n+1;
		smns[++smnt]=a[i];smnat[smnt]=i;
	/*	write(i,':',mxl,' ',mnl,'\n');
		for(int j=1;j<=mxt;++j)write(mxs[j],j==mxt?'\n':' ');
		for(int j=1;j<=mnt;++j)write(mns[j],j==mnt?'\n':' ');*/
		int w;
		w=0;rt->fnd(mxl,1,0,w);
		if(w)xr[i]=w;else xr[i]=n+1;xl[i]=i;

		w=0;rt->fnd(mnl,0,1,w);
		if(w)yr[i]=w;else yr[i]=n+1;yl[i]=i;
		rt->unset_mn(i);
		w=0;rt->fnd(max(mxl,mnl),1,1,w);
		rt->set_mn(i);
		if(w)xyr[i]=w;else xyr[i]=n+1;xyl[i]=i;
		
		if(chkmin(xr[i],xr[i+1]))xl[i]=xl[i+1];
		if(chkmin(yr[i],yr[i+1]))yl[i]=yl[i+1];
		if(chkmin(xyr[i],xyr[i+1]))xyl[i]=xyl[i+1];
	}
	//for(int i=1;i<=n;++i)write(xl[i],' ',xr[i],'|',yl[i],' ',yr[i],'|',xyl[i],' ',xyr[i],'\n');
	//return 0;
	for(;q;--q){
		int l,r;
		read(l,r);
		if(xyr[l]<=r){
			r=xyr[l];
			l=xyl[l];
			pii x=make_pair(-inf,0),y=make_pair(inf,0);
			xrt->qry(l,r,x,y);
			if(x.y>y.y)swap(x.y,y.y);
			write(4,'\n',l,' ',x.y,' ',y.y,' ',r,'\n');
		}
		else if(xr[l]<=r){
			r=xr[l];l=xl[l];	
			pii x=make_pair(-inf,0),y=make_pair(inf,0);
			xrt->qry(l,r,x,y);
			write(3,'\n',l,' ',x.y,' ',r,'\n');
		}
		else if(yr[l]<=r){
			r=yr[l];l=yl[l];	
			pii x=make_pair(-inf,0),y=make_pair(inf,0);
			xrt->qry(l,r,x,y);
			write(3,'\n',l,' ',y.y,' ',r,'\n');
		}
		else write(0,'\n','\n');
	}
	return 0;
}