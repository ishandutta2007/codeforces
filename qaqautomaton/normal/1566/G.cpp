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
const int inf=0x3f3f3f3f3f3f;
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
map<pii,int> mp;
int xu[200005],xv[200005],xw[200005],xt[200005];
int val[400005],wc;
namespace solver{
	int ans;
	int t;
	int *stk[2000005],rv[2000005];
	int f1[100005],f2[100005];
	void roll(){
		*stk[t]=rv[t];
		--t;
	}
	bool setv(int &x,int y){
		stk[++t]=&x;rv[t]=x;
		x=y;
		return x;
	}
	bool chkmin(int &a,int b){return a>b?setv(a,b),1:0;}
	const int lim=1000000000;
	signed l[12000005],r[12000005],cnt[12000005],tt,nt;
	signed rt[100005];
	bool find(int r1,int r2,int r3,int ls,int rs,int &v){
		if(cnt[r1]==cnt[r2]+cnt[r3]){return 0;}
		if(ls==rs){
			v=ls;return 1;
		}
		int mid=(ls+rs)>>1;
		if(find(r1[l],r2[l],r3[l],ls,mid,v))return 1;
		return find(r1[r],r2[r],r3[r],mid+1,rs,v);
	}
	void add(signed &rt,int ls,int rs,int x,int y){
		if(!rt){rt=++nt;}
		cnt[rt]+=y;
		if(ls!=rs){
			int mid=(ls+rs)>>1;
			if(x<=mid)add(rt[l],ls,mid,x,y);
			else add(rt[r],mid+1,rs,x,y);
		}
	}
	void add(int e){
		int u=xu[e],v=xv[e],w=xw[e];

		//case 1:
		chkmin(ans,f1[u]+f2[u]+w);
		chkmin(ans,f1[v]+f2[v]+w);
		if(w<f1[u]){
			setv(f2[u],f1[u]);
			setv(f1[u],w);
		}
		else chkmin(f2[u],w);

		if(w<f1[v]){
			setv(f2[v],f1[v]);
			setv(f1[v],w);
		}
		else chkmin(f2[v],w);

		//case 2:
		int s;
		if(find(rt[0],rt[u],rt[v],1,wc,s)){chkmin(ans,val[s]+w);};
		int id=lower_bound(val+1,val+wc,w)-val;
		add(rt[0],1,wc,id,1);
		add(rt[u],1,wc,id,1);
		add(rt[v],1,wc,id,1);
	}
	void del(int e){
		int u=xu[e],v=xv[e],w=xw[e];
		int id=lower_bound(val+1,val+wc,w)-val;
		add(rt[0],1,wc,id,-1);
		add(rt[u],1,wc,id,-1);
		add(rt[v],1,wc,id,-1);
	}
}
struct smt{
	int ls,rs;
	vector<int> vt;
	smt *l,*r;
	smt(){}
	smt(int,int);
	void Ins(int la,int ra,int id){
		
		if(la<=ls && rs<=ra){
			vt.emplace_back(id);
			return;
		}
		if(la<=l->rs)l->Ins(la,ra,id);
		if(r->ls<=ra)r->Ins(la,ra,id);
	}
	void solve(){
		int lt=solver::t;
		for(auto i:vt){solver::add(i);}

		if(ls==rs)write(solver::ans,'\n');
		else{l->solve();r->solve();}
		while(solver::t>lt){solver::roll();}

		for(auto i:vt)solver::del(i);

	}
};
smt *rt,node[400005],*at=node;
smt *newsmt(int la,int ra){
	smt *rt=at;++at;
	*rt=smt(la,ra);
	return rt;
}
smt::smt(int la,int ra){
	ls=la;rs=ra;vt.clear();
	if(ls==rs){l=r=0;return;}
	int mid=(ls+rs)>>1;
	l=newsmt(ls,mid);
	r=newsmt(mid+1,rs);
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int n,m;	
	read(n,m);
	for(int i=1;i<=m;++i){
		int u,v,w;
		read(u,v,w);
		sort2(u,v);
		xu[i]=u;xv[i]=v;xw[i]=w;xt[i]=0;
		mp[{u,v}]=i;
	}
	for(int i=1;i<=n;++i)solver::f1[i]=solver::f2[i]=inf;
	solver::ans=inf;
	int q;
	read(q);
	rt=newsmt(0,q);
	for(int id=1;id<=q;++id){
		int tp,u,v,w;
		read(tp,u,v);
		sort2(u,v);
		if(tp==0){
			w=mp[{u,v}];
			mp.erase({u,v});
			rt->Ins(xt[w],id-1,w);
		}
		else{
			read(w);
			int i=++m;
			xu[i]=u;xv[i]=v;xw[i]=w;xt[i]=id;
			mp[{u,v}]=i;
		}
	}
	for(int i=1;i<=m;++i)val[i]=xw[i];
	sort(val+1,val+m+1);
	wc=unique(val+1,val+m+1)-val-1;
	for(auto i:mp){
		rt->Ins(xt[i.y],q,i.y);
	}
	rt->solve();
	return 0;
}