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
int xl[200005],xr[200005],yl[200005],yr[200005];
int v[400005],t;
int yv[400005],yt;
vector<int> ad[400005],dl[400005];
int c;
int ban[800005];
int xv[800005];

struct smt{
	int ls,rs;
	ll cnt;
	int tag;
	smt *l,*r;
	void put_tag(int x){cnt+=x*(rs-ls+1);tag+=x;}
	void push_down(){if(tag){l->put_tag(tag);r->put_tag(tag);tag=0;}}
	void add(int la,int ra,int x){
		if(la<=ls && rs<=ra){put_tag(x);return;}
		push_down();
		if(la<=l->rs)l->add(la,ra,x);
		if(r->ls<=ra)r->add(la,ra,x);
		cnt=l->cnt+r->cnt;	
	}
	bool queryl(int ra,int &res){
		if(!cnt)return 0;
		if(ls==rs){
			res=ls;return 1;
		}
		push_down();
		if(r->ls<=ra)if(r->queryl(ra,res))return 1;
		return l->queryl(ra,res);
	}
	bool queryr(int la,int &res){
		if(!cnt)return 0;
		if(ls==rs){
			res=ls;return 1;
		}
		push_down();
		if(la<=l->rs)if(l->queryr(la,res))return 1;
		return r->queryr(la,res);
	}
	smt(){}
	smt(int,int);
};
smt *R,node[1600005],*at=node;
smt *newsmt(int la,int ra){
	smt *rt=at;++at;
	*rt=smt(la,ra);
	return rt;
}
smt::smt(int la,int ra){ls=la;rs=ra;cnt=tag=0;if(ls==rs){l=r=0;return;}int mid=(ls+rs)>>1;l=newsmt(ls,mid);r=newsmt(mid+1,rs);}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
namespace fhq{
	int t,rt;
	int v[800005],dp[800005],w[800005],las[800005];
	int l[800005],r[800005];
	int tv[800005],tl[800005];
	int mn[800005],mnl[800005],mnr[800005];//mn0=min w,mnl=min w-v (left),mnr=min w+v (right)
	struct _init_{
		_init_(){mn[0]=mnl[0]=mnr[0]=inf;}
	}__initer__;
	void push_up(int x){
		mn[x]=min(dp[x],mn[l[x]],mn[r[x]]);
		mnl[x]=min(dp[x]-v[x],mnl[l[x]],mnl[r[x]]);
		mnr[x]=min(dp[x]+v[x],mnr[l[x]],mnr[r[x]]);
	}
	void put_tagv(int x,int y){if(!x)return;v[x]+=y;tv[x]+=y;mnl[x]-=y;mnr[x]+=y;}
	void put_tagl(int x,int y){if(!x)return;las[x]=tl[x]=y;}
	void push_down(int x){
		if(tv[x]){
			put_tagv(l[x],tv[x]);	
			put_tagv(r[x],tv[x]);	
			tv[x]=0;
		}
		if(~tl[x]){
			put_tagl(l[x],tl[x]);	
			put_tagl(r[x],tl[x]);	
			tl[x]=-1;
		}
	}
	void split(int x,int y,int &r1,int &r2){
		if(!x){r1=r2=0;return;}
		push_down(x);
		if(v[x]<=y){
			r1=x;split(x[r],y,r1[r],r2);
			push_up(r1);
		}
		else{
			r2=x;split(x[l],y,r1,r2[l]);
			push_up(r2);
		}
	}
	int merge(int r1,int r2){
		if(!r1)return r2;
		if(!r2)return r1;
		if(w[r1]<w[r2]){
			push_down(r1);
			r1[r]=merge(r1[r],r2);
			push_up(r1);
			return r1;
		}
		else{
			push_down(r2);
			r2[l]=merge(r1,r2[l]);
			push_up(r2);
			return r2;
		}
	}
	int newNode(int v0,int w0,int l0){
		++t;
		v[t]=v0;dp[t]=w0;las[t]=l0;w[t]=rnd();
		tv[t]=0;tl[t]=-1;
		push_up(t);
		return t;
	}
	void Ins(int v0,int w0,int l0){
		if(!rt){
			rt=newNode(v0,w0,l0);
			return;
		}
		int r1,r2,r3;
		split(rt,v0-1,r1,r2);
		split(r2,v0,r2,r3);
		if(!r2)r2=newNode(v0,w0,l0);
		else {chkmin(r2[dp],w0);push_up(r2);}
		rt=merge(r1,merge(r2,r3));
	}
}
int curt;
bool get(int x,int &l,int &r){
	l=r=-114514;
	x<<=1;
	if(!R->queryl(x,l)){
		l=-inf;
	}
	else{if(l==x){return 0;}++l;l=xv[l];}
	if(!R->queryr(x,r))r=inf;
	else{--r;r=xv[r];}
	return 1;
}
void out(int rt){
	if(!rt)return;
	using namespace fhq;	
	push_down(rt);
	out(rt[l]);
	write(fhq::v[rt],',',dp[rt],' ');
	out(rt[r]);

	
}

void update(int x){
	int lv,rv;	
	if(!get(x,lv,rv))return ;
	using namespace fhq;
	int r1,r2,r3;
	split(rt,lv-1,r1,r2);
	split(r2,rv,r2,r3);
	if(r2[las]!=curt){
		//out(r2);
		put_tagv(r2,curt-r2[las]);
		put_tagl(r2,curt);
		//out(r2);
		int r4,r5;
		split(r2,rv-1,r4,r5);
		if(!r5){
			r2=r4;
		}
		else{
			r5[dp]=r5[mnr]-rv;
			r5[l]=r5[r]=0;
			r5[fhq::v]=rv;
			push_up(r5);
			r2=merge(r4,r5);
		}
		/*putc('|');
		out(r2);
		putc(')');*/
	}
	rt=merge(r1,merge(r2,r3));
}
void adv(int x){
	int lv,rv;	
	if(!get(x,lv,rv))return ;
	using namespace fhq;
	int r1,r2,r3;
	split(rt,lv-1,r1,r2);
	split(r2,rv,r2,r3);
	if(r2){
		int r4,r5,r6;
		split(r2,::v[x],r4,r6);
		int cdp=min(mnl[r4]+::v[x],mnr[r6]-::v[x]);
		split(r4,::v[x]-1,r4,r5);
		if(!r5){r5=newNode(::v[x],cdp,curt);}
		else {chkmin(dp[r5],cdp);push_up(r5);}
		r2=merge(r4,merge(r5,r6));
	}
	rt=merge(r1,merge(r2,r3));
}
void del(int l,int r){
	using namespace fhq;
	int r1,r2,r3;
	split(rt,l,r1,r2);
	split(r2,r-1,r2,r3);
	rt=merge(r1,r3);
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
		//write(xl[i],' ',xr[i],' ',yl[i],' ',yr[i],'\n');
	}
	R=newsmt(1,t<<1|1);
	fhq::Ins(x,0,0);
	/*out(fhq::rt);
	putc('\n');*/
	for(int y=1;y<=yt;++y){
		curt=yv[y];
		for(auto id:dl[y]){
			update(xl[id]);
			update(xr[id]);
		}
		for(auto id:ad[y]){
			update(xl[id]);
			update(xr[id]);
		}
		for(auto id:dl[y])
			R->add(xl[id]<<1|1,(xr[id]<<1)-1,-1);
		for(auto id:ad[y]){
			adv(xl[id]);
			adv(xr[id]);
		}
		for(auto id:ad[y]){
			R->add(xl[id]<<1|1,(xr[id]<<1)-1,1);
			del(v[xl[id]],v[xr[id]]);
		}
	/*	out(fhq::rt);
		putc('\n');*/
	}
	write(fhq::mn[fhq::rt],'\n');
	return 0;
}