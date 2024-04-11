/*
Author: QAQAutoMaton
Lang: C++
Code: E.cpp
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
vector<int> dd[200005];
int a[200005],at[200005];
int mx[19][200005],_lg[200005];
int qmax(int l,int r){
	int h=_lg[r-l+1];
	return max(mx[h][l],mx[h][r-(1<<h)+1]);
}
vector<pii> ad[200005],dl[200005],qry[200005];
void addm(int xl,int xr,int yl,int yr){
	if(xl>xr || yl>yr)return;
	ad[yl].emplace_back(xl,xr);
	dl[yr+1].emplace_back(xl,xr);
}
void solve(int l,int r){
	if(l>r)return;
	int mx=qmax(l,r),id=at[mx];
	for(auto i:dd[mx]){
		if(l<=at[i] && at[i]<=r && l<=at[mx/i] && at[mx/i]<=r){
			int lr=id,rl=id;
			chkmin(lr,at[i]);
			chkmin(lr,at[mx/i]);
			chkmax(rl,at[i]);
			chkmax(rl,at[mx/i]);
			addm(l,lr,rl,r);
		}
	}
	solve(l,id-1);
	solve(id+1,r);
}

struct smt{
	int ls,rs;
	int mn,tag,sum,tag2,mnc;
	smt *l,*r;
	smt(){}
	smt(int,int);
	void put_tag(int x){
		tag+=x;mn+=x;
	}
	void put_tag2(int x){
		tag2+=x;
		sum+=mnc*x;
	}
	void push_up(){
		sum=l->sum+r->sum;
		mn=min(l->mn,r->mn);
		mnc=0;
		if(l->mn==mn)mnc+=l->mnc;
		if(r->mn==mn)mnc+=r->mnc;
	}
	void push_down(){
		if(tag){
			l->put_tag(tag);
			r->put_tag(tag);
			tag=0;
		}
		if(tag2){
			if(l->mn==mn)l->put_tag2(tag2);
			if(r->mn==mn)r->put_tag2(tag2);
			tag2=0;
		}
	}
	void add(int la,int ra,int t){
		if(la<=ls && rs<=ra){
			put_tag(t);
			return;
		}
		push_down();
		if(la<=l->rs)l->add(la,ra,t);
		if(r->ls<=ra)r->add(la,ra,t);
		push_up();
	}
	void add0(int la,int ra){
		if(mn)return;
		if(la<=ls && rs<=ra){put_tag2(1);return;}
		push_down();
		if(la<=l->rs)l->add0(la,ra);
		if(r->ls<=ra)r->add0(la,ra);
		push_up();
	}
	int qsum(int la,int ra){
		if(la<=ls && rs<=ra)return sum;
		push_down();
		int ans=0;
		if(la<=l->rs)ans+=l->qsum(la,ra);
		if(r->ls<=ra)ans+=r->qsum(la,ra);
		return ans;
	}
};
smt *rt,node[400005],*curv=node;
smt *newsmt(int la,int ra){
	smt *rt=curv;
	++curv;
	*rt=smt(la,ra);
	return rt;
}
smt::smt(int la,int ra){
	ls=la;rs=ra;
	mn=0,tag=0,mnc=rs-ls+1;
	sum=0,tag2=0;
	if(ls==rs){
		l=r=0;
		return;
	}
	int mid=(ls+rs)>>1;
	l=newsmt(ls,mid);
	r=newsmt(mid+1,rs);
}
int S(int x){
	return x*(x+1)>>1;
}
int ans[1000005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n,q;
	read(n,q);
	for(int i=1;i<=n;++i){read(a[i]);at[a[i]]=i;mx[0][i]=a[i];}
	_lg[1]=0;
	for(int i=2;i<=n;++i)_lg[i]=_lg[i>>1]+1;
	for(int i=1;i<=_lg[n];++i){
		for(int j=1;j+(1<<i)-1<=n;++j){
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
		}	
	}
	for(int i=1;i<=n;++i)for(int j=1;j<i && j*i<=n;++j)dd[i*j].emplace_back(i);

	addm(1,at[1],at[1],n);
	solve(1,at[1]-1);
	solve(at[1]+1,n);
	for(int i=1;i<=q;++i){
		int l,r;
		read(l,r);
		qry[r].emplace_back(l,i);
	}
	rt=newsmt(1,n);
	for(int i=1;i<=n;++i){
		for(auto j:ad[i]){
			rt->add(j.x,j.y,1);
		}
		for(auto j:dl[i]){
			rt->add(j.x,j.y,-1);
		}
		if(i>1)
		rt->add0(1,i-1);
		for(auto v:qry[i]){
			ans[v.y]=S(i-v.x)-rt->qsum(v.x,i);
		}
	}
	for(int i=1;i<=q;++i)write(ans[i],'\n');
	return 0;
}