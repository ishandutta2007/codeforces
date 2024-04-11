/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
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
const int li[]={1, 42, 1764, 74088, 3111696, 130691232, 5489031744, 230539333248, 9682651996416, 406671383849472};
//len -> 10
int a[100005];
bool ok;
struct smt{
	int ls,rs;
	smt *l,*r;
	int val,mn,tag;
	smt(){}
	smt(int,int);
	void put(int x){
		val=0;
		while(li[val]<x)++val;
		mn=li[val]-x;
	}
	void push_down(){
		if(tag){
			l->tag+=tag;r->tag+=tag;
			l->mn+=tag;r->mn+=tag;
			tag=0;
		}
	}
	int query(int x){
		if(ls==rs){return li[val]-mn;}
		push_down();
		return (x<=l->rs?l:r)->query(x);
	}
	void set(int x,int y){
		if(ls==rs){put(y);return;}
		push_down();
		(x<=l->rs?l:r)->set(x,y);
		mn=min(l->mn,r->mn);
	}
	void solve(int x){
		if(ls==rs){
			while(mn<=0){
				if(mn==0)ok=0;
				mn+=li[val+1]-li[val];
				++val;
			}
		}
		else{
			push_down();
			if(l->mn<=0)l->solve(x);
			if(r->mn<=0)r->solve(x);
			mn=min(l->mn,r->mn);
		}
	}
	void add(int la,int ra,int w){
		if(la<=ls && rs<=ra){
			tag-=w;mn-=w;
			if(mn<=0)solve(w);
			return;
		}
		push_down();
		if(la<=l->rs)l->add(la,ra,w);
		if(r->ls<=ra)r->add(la,ra,w);
		mn=min(l->mn,r->mn);
	}
};
smt *rt,node[200005],*at=node;
smt *newsmt(int la,int ra){
	smt *rt=at;++at;
	*rt=smt(la,ra);
	return rt;
}
smt::smt(int la,int ra){
	ls=la;rs=ra;	
	tag=0;
	if(ls==rs){
		l=r=0;
		put(a[ls]);
		return;
	}
	int mid=(ls+rs)>>1;
	l=newsmt(ls,mid);
	r=newsmt(mid+1,rs);
	mn=min(l->mn,r->mn);
}
int n,q;
set<pii> st;
int ls[100005];
void split(int x){
	set<pii>::iterator it=st.lower_bound(make_pair(x,0));
	if(it->y<x){
		int l=it->y,r=it->x;
		rt->set(x-1,rt->query(r));
		st.erase(it);
		st.insert(make_pair(x-1,l));
		st.insert(make_pair(r,x));
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	read(n,q);
	for(int i=1;i<=n;++i){
		read(a[i]);
		st.insert(make_pair(i,i));
	}
	rt=newsmt(1,n);
	for(;q;--q){
		int tp,l,r,x;
		read(tp);
		if(tp==1){
			read(x);
			write(rt->query(st.lower_bound(make_pair(x,0))->x),'\n');
		}
		else{
			read(l,r,x);
			split(l);
			if(r!=n)split(r+1);
			if(tp==2){
				set<pii>::iterator it=st.lower_bound(make_pair(l,0)),td;
				while(it!=st.end()&&it->x<=r){
					td=it;
					rt->set(it->x,-inf);
					++it;
					st.erase(td);
				}
				st.insert(make_pair(r,l));
				rt->set(r,x);
			}
			else{
				do{
					ok=1;
					rt->add(l,r,x);
				}while(!ok);
			}
		}
	}
	return 0;
}