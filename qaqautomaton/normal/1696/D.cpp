/*
Author: QAQAutoMaton
Lang: C++
Code: D.cpp
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
	int rt[250005];
	int l[40000005],r[40000005],t;
	bitset<40000005>ban;	
	int newNode(){
		++t;
		l[t]=r[t]=ban[t]=0;
		return t;
	}
	int v[250005];
	int a[250005];
	int su[250005],sd[250005],tu,td;
	int lrt[250005],rrt[250005];
	int ll[250005],rl[250005];
	int lr[250005],rr[250005];
	int clone(int x){
		++t;
		l[t]=l[x];r[t]=r[x];ban[t]=ban[x];
		return t;
	}
	void Ins(int &rt,int ls,int rs,int x,int y){
		if(ls==rs){
			rt=v[y];
			return;
		}
		if(!rt){
			rt=newNode();
		}
		else{
			rt=clone(rt);
		}
		int mid=(ls+rs)>>1;
		if(x<=mid)
			Ins(rt[l],ls,mid,x,y);
		else 
			Ins(rt[r],mid+1,rs,x,y);
	}
	int q[250005],*ql,*qr,d[250005];
	void inQ(int x,int y){
		*(++qr)=x;
		d[x]=y;
		ban[v[x]]=1;
	}
	int n;
	void find(int rt,int ls,int rs,int xl,int xr,int v){
		if(ban[rt])return;
		if(ls==rs){
			inQ(rt,v);
			return;
		}
		int mid=(ls+rs)>>1;
		if(xl<=mid)find(rt[l],ls,mid,xl,xr,v);
		if(mid<xr)find(rt[r],mid+1,rs,xl,xr,v);
		if(ban[rt[l]] && ban[rt[r]])ban[rt]=1;
	} 
	void work(int x){
		find(lrt[x],1,n,ll[x],lr[x],d[x]+1);
		find(rrt[x],1,n,rl[x],rr[x],d[x]+1);
	} 
	bool main(){
		t=0;
		read(n);
		ban[0]=1;
		for(int i=1;i<=n;++i)v[i]=newNode();
		for(int i=1;i<=n;++i){
			read(a[i]);
		}
		tu=td=0;
		int rt1=0,rt2=0;
		lrt[1]=ll[1]=lr[1]=0;
		rrt[n]=rl[n]=rr[n]=0;
		for(int i=1;i<=n;++i){
			while(tu&&a[su[tu]]<a[i]){
				--tu;
			}
			while(td&&a[sd[td]]>a[i]){
				--td;
			}
			if(i>1){
				if(su[tu]<sd[td]){
					int at=lower_bound(sd+1,sd+td+1,su[tu])-sd;
					lrt[i]=rt2;
					ll[i]=at;lr[i]=td;
					//at,td
				}
				else{
					int at=lower_bound(su+1,su+tu+1,sd[td])-su;
					lrt[i]=rt1;
					ll[i]=at;lr[i]=tu;
				}
			}
			su[++tu]=i;
			sd[++td]=i;
			Ins(rt1,1,n,tu,i);
			Ins(rt2,1,n,td,i);
		}
		rt1=0;rt2=0;
		tu=td=n+1;
		su[n+1]=sd[n+1]=n+1;
		for(int i=n;i;--i){
			while(tu<=n&&a[su[tu]]<a[i]){
				++tu;
			}
			while(td<=n&&a[sd[td]]>a[i]){
				++td;
			}
			if(i<n){
				if(su[tu]>sd[td]){
					int at=lower_bound(sd+td,sd+n+1,su[tu])-sd-1;
					rrt[i]=rt2;
					rl[i]=td;rr[i]=at;
					//at,td
				}
				else{
					int at=lower_bound(su+tu,su+n+1,sd[td])-su-1;
					rrt[i]=rt1;
					rl[i]=tu;rr[i]=at;
				}
			}
			su[--tu]=i;
			sd[--td]=i;
			Ins(rt1,1,n,tu,i);
			Ins(rt2,1,n,td,i);
		}
		d[*(ql=qr=q)=1]=0;
		for(int i=2;i<=n;++i)d[i]=inf;
		while(ql<=qr){
			work(*ql);
			++ql;
		}
		write(d[n],'\n');
		return 0;
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t)run::main();
	return 0;
}