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
int a[100005],b[100005],n,c;
int v[100005];
char s[100005];
struct Q{
	int k,m,id;
};
Q ask[100005];
int ans[100005];
int cn;
void Go(int s);
int get(int rk);
void Ins(int x);
int query(int m){
	int l=1,r=min(c,m);
	while(l<=r){
		int mid=(l+r)>>1;
		if(b[mid]<=get(m-mid))l=mid+1;
		else 
		if(b[mid]>get(m-mid+1))r=mid-1;
		else 
		return b[mid]+mid-1;
	}
	l=1,r=min(n,m);
	while(l<=r){
		int mid=(l+r)>>1;
		int w=get(mid);
		if(w<b[m-mid])l=mid+1;
		else
		if(w>=b[m-mid+1])r=mid-1;
		else
		return w+m-mid;
	}
}
int d;
signed main(){
#ifdef QAQAutoMaton 
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
#endif
	int m,q;
	read(m,d,q);
	for(int i=1;i<=m;++i){
		read(v[i]);
	}
	read(s+1);
	for(int i=1;i<=m;++i){
		if(s[i]=='1'){
			a[++n]=v[i]-c;
		}
		else{
			b[c+1]=v[i]-c;
			++c;
		}
	}
	for(int i=c+1;i<=m+1;++i)b[i]=inf;
	for(int i=n+1;i<=m+1;++i)a[i]=inf;
	for(int i=1;i<=q;++i){
		read(ask[i].k,ask[i].m);
		ask[i].id=i;
	}
	sort(ask+1,ask+q+1,[](Q a,Q b){return a.k<b.k;});
	cn=1;
	Ins(a[1]);
	for(int i=1;i<=q;++i){
		Go(ask[i].k-ask[i-1].k);
		ans[ask[i].id]=query(ask[i].m);
	}
	for(int i=1;i<=q;++i)write(ans[i],'\n');
	return 0;
}
namespace fhq{
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	int tag[100005];
	int rt,n;
	int v[100005];
	uint w[100005];
	int l[100005],r[100005];
	int siz[100005];
	void put_tag(int x,int y){
		if(x){
			v[x]+=y;tag[x]+=y;
		}
	}
	void push_down(int x){if(tag[x]){put_tag(l[x],tag[x]);put_tag(r[x],tag[x]);tag[x]=0;}}
	void push_up(int x){siz[x]=siz[l[x]]+siz[r[x]]+1;}
	int merge(int x,int y){
		if(!y)return x;
		if(!x)return y;
		if(w[x]>w[y]){
			push_down(x);
			r[x]=merge(r[x],y);
			push_up(x);
			return x;
		}
		else{
			push_down(y);
			l[y]=merge(x,l[y]);
			push_up(y);
			return y;
		}
	}
	void split(int x,int y,int &r1,int &r2){
		if(!x){r1=r2=0;return;}
		push_down(x);
		if(v[x]<=y){
			r1=x;split(r1[r],y,r1[r],r2);
			push_up(r1);
		}
		else{
			r2=x;split(r2[l],y,r1,r2[l]);
			push_up(r2);
		}
	}
	void ssplit(int x,int y,int &r1,int &r2){
		if(!x){r1=r2=0;return;}
		if(y>=siz[x]){r1=x;r2=0;return;}
		if(!y){r1=0;r2=x;return;}
		push_down(x);
		if(y<=siz[l[x]]){
			r2=x;ssplit(r2[l],y,r1,r2[l]);
			push_up(r2);
		}
		else{
			r1=x;ssplit(r1[r],y-siz[l[x]]-1,r1[r],r2);
			push_up(r1);
		}
	}
	void insert(int x){
		++n;
		v[n]=x;w[n]=rnd();
		siz[n]=1;
		int r1,r2;
		split(rt,x,r1,r2);
		rt=merge(merge(r1,n),r2);
	}
	int get(int rk){
		int x=rt;
		int r1,r2,r3;
		ssplit(rt,rk-1,r1,r2);
		ssplit(r2,1,r2,r3);
		int ret=v[r2];
		rt=merge(merge(r1,r2),r3);
		return ret;

		assert(rk<=siz[rt]);
		while(1){
			push_down(x);
			if(rk<=siz[x[l]])x=x[l];
			else{
				rk-=siz[x[l]];
				if(rk==1)return v[x];
				--rk;x=x[r];
			}
		}
	}
}
void Ins(int x){
	fhq::insert(x);
}
int get(int rk){
	if(rk==0)return 0;
	if(rk<=cn){
		return fhq::get(rk);
	}
	else return a[rk];
}
void Go(int s){
	cerr<<s<<endl;
	if(!n)return;
	while(s){
		if(cn==n){
			fhq::put_tag(fhq::rt,(s/n)*(d+n-1));
			s%=n;
			if(s){
				int r1,r2;
				fhq::ssplit(fhq::rt,s,r1,r2);
				fhq::put_tag(r1,d+n-1);
				fhq::rt=fhq::merge(r2,r1);
			}
			s=0;return;
		}
		int l=(a[cn+1]-fhq::get(cn)-1)/(d+cn-1);
		if(l*cn>=s){
			fhq::put_tag(fhq::rt,(s/cn)*(d+cn-1));
			s%=cn;
			if(s){
				int r1,r2;
				fhq::ssplit(fhq::rt,s,r1,r2);
				fhq::put_tag(r1,d+cn-1);
				fhq::rt=fhq::merge(r2,r1);
			}
			s=0;
			return;
		}
		else{
			fhq::put_tag(fhq::rt,l*(d+cn-1));
			s-=l*cn;
			int r1,r2,r3;
			fhq::split(fhq::rt,a[cn+1]-d-cn,r1,r2);
			if(s<=fhq::siz[r1]){
				fhq::ssplit(r1,s,r1,r3);
				fhq::put_tag(r1,d+cn-1);
				fhq::rt=fhq::merge(r3,fhq::merge(r2,r1));
				s=0;
				return;
			}
			else{
				s-=fhq::siz[r1];
				fhq::put_tag(r1,d+cn-1);
				fhq::rt=fhq::merge(r2,r1);
				fhq::insert(a[++cn]);
				int w=fhq::get(1);
				while(cn<n && w+d+cn-1>=a[cn+1]){
					fhq::insert(a[++cn]);
				}
				fhq::ssplit(fhq::rt,1,r1,r2);
				fhq::put_tag(r1,d+cn-1);;
				fhq::rt=fhq::merge(r2,r1);
				--s;
			}
			// right
		}
		/*	int r1,r2;
			while(cn<n && fhq::get(1)+d+cn-1>=a[cn+1]){
			fhq::insert(a[++cn]);
			}
			write(fhq::rt,'?','\n');
			write(r1,'!',r2,"faq");
			fhq::ssplit(fhq::rt,1,r1,r2);
			fhq::put_tag(r1,d+cn-1);;
			fhq::rt=fhq::merge(r2,r1);
			--s;
			*/
	}	
}