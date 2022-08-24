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

int a[300005];
struct smt{
	int ls,rs;
	int mn;
	smt *l,*r;
	smt(){}
	smt(int,int);
	int query(int la,int ra){
		//cerr<<ls<<' '<<rs<<' '<<la<<' '<<ra<<endl;
		if(la<=ls && rs<=ra)return mn;
		int rt=inf;
		if(la<=l->rs)chkmin(rt,l->query(la,ra));
		if(r->ls<=ra)chkmin(rt,r->query(la,ra));
		return rt;
	}
};
smt *rt,node[600005],*at=node;
smt *newsmt(int la,int ra){
	smt *rt=at;++at;
	*rt=smt(la,ra);
	return rt;
}
smt::smt(int la,int ra){
	ls=la;rs=ra;mn=inf;
	if(ls==rs){l=r=0;mn=a[ls];return;}
	int mid=(ls+rs)>>1;
	l=newsmt(ls,mid);r=newsmt(mid+1,rs);
	mn=min(l->mn,r->mn);
}
int n,q,k;
vector<pii> ask[300005];
int ans[300005];

/*const int B=600;
namespace bigk{
	int blk[300005],st[300005],ed[300005];
	int pre[300005],suf[300005];
	int mn[300005];
	bool main(){
		int bs;
		for(int i=1;i<=n;++i){
			blk[i]=(i-1)/B+1;
			ed[blk[i]]=i;
		}
		for(int i=n;i;--i)st[blk[i]]=i;
		bs=blk[n];
		for(int i=1;i<=bs;++i){
			mn[i]=inf;
			for(int j=st[i];j<=ed[i];++j){
				chkmin(mn[i],a[j]);
				pre[j]=mn[i];
			}
			mn[i]=inf;
			for(int j=ed[i];j>=st[i];--j){
				chkmin(mn[i],a[j]);
				suf[j]=mn[i];
			}
		}
		for(int l=1;l<=n;++l){
			for(auto _q:ask[l]){
				int &xa=ans[_q.x];
				int mn=suf[l];
				xa=a[l];
				int r=l;
				int rb=blk[l]+1;
				for(int i=1;i<=_q.y;++i){
					r+=k;
					while(rb<blk[r]){chkmin(mn,bigk::mn[rb]);++rb;}
					xa+=min(mn,pre[r]);
				}
			}
		}
		return 0;
	}
}
*/
namespace smallk{
	struct xstk{
		int stk[300005];
		int at[300005];
		int pre[300005];
		int t;
		void clear(){t=0;}
		void add(int x,int y){
			while(t && stk[t]>=x)--t;
			stk[++t]=x;
			at[t]=y;
			pre[t]=pre[t-1]+(at[t-1]-at[t])*stk[t];
		}
		int query(int l,int r){
			if(l==r)return stk[t];
			/*int ans=0;
			for(int i=l,j=t;i<=r;++i){
				while(i>=at[j-1])--j;
				ans+=stk[j];
			}
			return ans;*/
			int ls=1,rs=t;
			while(ls<=rs){
				int mid=(ls+rs)>>1;
				if(at[mid]>r)ls=mid+1;
				else rs=mid-1;
			}
			return pre[t]-pre[ls]+(r-at[ls]+1)*stk[ls];
		}
	};
	xstk stk;
	bool main(){
		rt=newsmt(1,n);
		for(int mo=1;mo<=k;++mo){
			stk.clear();
			stk.at[0]=n+5;
			for(int l=(n-mo)/k*k+mo;l>=mo;l-=k){
				stk.add(a[l],(l-mo)/k);
				for(auto j:ask[l]){
					ans[j.x]=stk.query((l-mo)/k,(l-mo)/k+j.y);
				}
				if(l>mo){
					stk.add(rt->query(l-k+1,l),(l-mo)/k);
				}
			}
		}
		return 0;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(n,q,k);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=q;++i){
		int l,r;
		read(l,r);
		ask[l].emplace_back(i,(r-l)/k);
	}
	smallk::main();
	for(int i=1;i<=q;++i)write(ans[i],'\n');
	return 0;
}