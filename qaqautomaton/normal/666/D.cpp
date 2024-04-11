/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp
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
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
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
pii a[5],ap[5],po[5];
int b[5],ans,c[5],d[5];
int query(pii a,pii b,int id){
	if(id==2){
		if(a.y!=b.y)return inf;
		return abs(b.x-a.x); 
	}
	else{
		if(a.x!=b.x)return inf;
		return abs(b.y-a.y); 
	}
}
void chk(int x1,int x2,int y1,int y2){
	po[1]=make_pair(x1,y1);
	po[2]=make_pair(x2,y1);
	po[3]=make_pair(x1,y2);
	po[4]=make_pair(x2,y2);
	d[1]=1;d[2]=2;d[3]=3;d[4]=4;
	do{
		int mx=0;
		for(int i=1;i<=4;++i)chkmax(mx,query(a[i],po[d[i]],c[i]));
		if(chkmin(ans,mx)){
			for(int i=1;i<=4;++i)ap[i]=po[d[i]];
		};
	}while(next_permutation(d+1,d+5));
}
vector<int> xx,yy;
vector<int> v1,v2;
void calc(){
	xx.clear();yy.clear();
	for(int i=1;i<=4;++i)if(c[i]==1)xx.push_back(a[i].x);
	else yy.push_back(a[i].y);
	sort(all(xx));
	xx.erase(unique(all(xx)),xx.end());
	sort(all(yy));
	yy.erase(unique(all(yy)),yy.end());
	if(xx.size()>2 || yy.size()>2)return;
	if(xx.size()<=1 && yy.size()<=1)return;
	if(xx.size()==2 && yy.size()==2){
		if(xx[1]-xx[0]==yy[1]-yy[0])
		chk(xx[0],xx[1],yy[0],yy[1]);
	}
	else if(xx.size()==2){
		int r=xx[1]-xx[0];
		if(yy.size()==1){
			chk(xx[0],xx[1],yy[0]-r,yy[0]);
			chk(xx[0],xx[1],yy[0],yy[0]+r);
		}
		else{
			v1.clear();v2.clear();
			for(int i=1;i<=4;++i)if(a[i].x==xx[0]){
				v1.push_back(a[i].y);	
			}
			else v2.push_back(a[i].y);
			if(v1.size()!=2)return;
			sort(all(v1));
			sort(all(v2));
			v1[1]-=r;
			v2[1]-=r;
			v1.push_back(v2[0]);
			v1.push_back(v2[1]);
			sort(all(v1));
			int mid=(v1[3]+v1[0])>>1;
			chk(xx[0],xx[1],mid,mid+r);
		}
	}
	else {
		int r=yy[1]-yy[0];
		if(xx.size()==1){
			chk(xx[0]-r,xx[0],yy[0],yy[1]);
			chk(xx[0],xx[0]+r,yy[0],yy[1]);
		}
		else{
			v1.clear();v2.clear();
			for(int i=1;i<=4;++i)if(a[i].y==yy[0]){
				v1.push_back(a[i].x);	
			}
			else v2.push_back(a[i].x);
			if(v1.size()!=2)return;
			sort(all(v1));
			sort(all(v2));
			v1[1]-=r;
			v2[1]-=r;
			v1.push_back(v2[0]);
			v1.push_back(v2[1]);
			sort(all(v1));
			int mid=(v1[3]+v1[0])>>1;
			chk(mid,mid+r,yy[0],yy[1]);
		}
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int t;
	read(t);
	for(;t;--t){
		for(int i=1;i<=4;++i){
			read(a[i].x,a[i].y);
		}
		ans=inf;
		for(int i=0;i<16;++i){
			for(int j=1;j<=4;++j)c[j]=(i&(1<<(j-1)))?1:2;
			calc();
		}
		if(ans==inf){
			write("-1\n");
		}
		else{
			write(ans,'\n');
			for(int i=1;i<=4;++i)write(ap[i].x,' ',ap[i].y,'\n');
		}
	}
	return 0;
}