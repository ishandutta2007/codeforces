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
map<int,int> cm; 
int cntc;
int getw(int x){
	if(cm.count(x))return cm[x];
	else return cm[x]=++cntc;
}
vector<int> xe[50005][2],ans;
int xn[50005][2],m;
int tp[50005],ux[50005],vx[50005];
vector<int> to[50005],eg[50005];
int xu[50005],xv[50005],uv[50005],w[50005];
int cntv,nd[50005];
int vis[50005],xt;
int mn;
void add(int e){
	if(to[xu[e]].empty())nd[++cntv]=xu[e];
	if(to[xv[e]].empty())nd[++cntv]=xv[e];
	to[xu[e]].emplace_back(e);
	to[xv[e]].emplace_back(e);
}
int vn[50005],vid[50005],t;
void dfs(int x,int y){
	vn[++t]=x;	
	vis[x]=xt;
	for(auto i:to[x])if(i!=y){
		vid[t]=i;
		int v=uv[i]^x;
		if(vis[v]!=xt)dfs(v,i);
		break;
	}
	to[x].clear();
}
int del[50005];
void chain(int s){
	++xt;
	t=0;
	dfs(s,0);
	int mx0=0,mx1=0;
	for(int i=1;i<t;i+=2)chkmax(mx0,w[vid[i]]);
	for(int i=2;i<t;i+=2)chkmax(mx1,w[vid[i]]);
	chkmax(mn,min(mx0,mx1));
	for(int i=2;i<t;++i){
		if(del[vn[i]])exit(write("No\n"));
		del[vn[i]]=1;
	}
	if(t&1){
		++m;
		xn[m][0]=mx0;
		xn[m][1]=mx1;
		for(int i=1;i<t;i+=2)xe[m][0].emplace_back(vid[i]);
		for(int i=2;i<t;i+=2)xe[m][1].emplace_back(vid[i]);
		tp[m]=1;
		ux[m]=vn[1];vx[m]=vn[t];
		if(mx0>mx1){swap(xn[m][0],xn[m][1]);xe[m][0].swap(xe[m][1]);swap(ux[m],vx[m]);}
	}
	else{
		if(mx0>=mx1){
			for(int i=2;i<t;i+=2)ans.emplace_back(vid[i]);
		}
		else{
			++m;
			xn[m][0]=mx0;
			xn[m][1]=mx1;
			for(int i=2;i<t;i+=2)xe[m][0].emplace_back(vid[i]);
			for(int i=1;i<t;i+=2)xe[m][1].emplace_back(vid[i]);
			tp[m]=2;
			ux[m]=vn[1];vx[m]=vn[t];
		}
	}
}
void circle(int s){
	++xt;
	t=0;
	dfs(s,0);
	if(t&1)exit(write("No\n"));

	for(int i=1;i<=t;++i){
		if(del[vn[i]])exit(write("No\n"));
		del[vn[i]]=1;
	}
	int mx0=0,mx1=0;
	for(int i=1;i<=t;i+=2)chkmax(mx0,w[vid[i]]);
	for(int i=2;i<=t;i+=2)chkmax(mx1,w[vid[i]]);
	if(mx0>=mx1){
		for(int i=2;i<=t;i+=2)ans.emplace_back(vid[i]);
		chkmax(mn,mx1);
	}
	else{
		for(int i=1;i<=t;i+=2)ans.emplace_back(vid[i]);
		chkmax(mn,mx0);
	}
}
int n;
vector<pii> xto[100005];
int fa[100005],cnt[100005];
int match[100005];
void xdfs(int x,int f){
	for(auto i:xto[x])if(i.x!=f){
		match[i.y]=i.x;
		xdfs(i.x,x);
	}
	xto[x].clear();
}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x!=y){fa[y]=x;cnt[x]+=cnt[y];}
	--cnt[x];
}
bool gg=0;
bool chk(int w){
	for(int i=1;i<=n;++i)fa[i]=i,cnt[i]=1;
	for(int i=1;i<=m;++i){
		if(tp[i]==1){
			if(w<xn[i][1]){
				if(del[ux[i]])return 0;
				merge(ux[i],ux[i]);
			}
			else{
				if(del[ux[i]]&&del[vx[i]])return 0;else
				if(del[ux[i]])merge(vx[i],vx[i]);else
				if(del[vx[i]])merge(ux[i],ux[i]);else
				merge(ux[i],vx[i]);
			}
		}
		else{
			if(xn[i][1]<=w)continue;
			else{
				if(del[ux[i]])return 0;
				if(del[vx[i]])return 0;
				merge(ux[i],ux[i]);
				merge(vx[i],vx[i]);
			}
		}
	}
	for(int i=1;i<=n;++i)if(fa[i]==i && cnt[i]<0)return 0;
	return 1;
}
void solve(int w){
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		if(tp[i]==1){
			if(w<xn[i][1]){
				for(auto i:xe[i][0])ans.emplace_back(i);
				del[ux[i]]=1;
			}
			else{
				if(del[ux[i]]){
					for(auto i:xe[i][1])ans.emplace_back(i);
					del[vx[i]]=1;
				}else
				if(del[vx[i]]){
					for(auto i:xe[i][0])ans.emplace_back(i);
					del[ux[i]]=1;
				}else{
					if(find(ux[i])==find(vx[i])){
						del[ux[i]]=1;
						for(auto i:xe[i][0])ans.emplace_back(i);
					}
					else{
						tp[i]=3;
						fa[find(ux[i])]=find(vx[i]);
						xto[ux[i]].emplace_back(vx[i],i);
						xto[vx[i]].emplace_back(ux[i],i);
					}
				}
			}
		}
		else{
			if(xn[i][1]<=w){
				for(auto i:xe[i][0])ans.emplace_back(i);
				continue;
			}
			else{
				for(auto i:xe[i][1])ans.emplace_back(i);
				del[ux[i]]=del[vx[i]]=1;
			}
		}
	}
	for(int i=1;i<=n;++i)if(del[i]&&!xto[i].empty())xdfs(i,0);
	for(int i=1;i<=n;++i)if(!xto[i].empty())xdfs(i,0);
	for(int i=1;i<=m;++i)if(tp[i]==3){
		if(match[i]==ux[i])
			for(auto i:xe[i][0])ans.emplace_back(i);
		else
			for(auto i:xe[i][1])ans.emplace_back(i);
	}
	write("Yes\n");
	write(w,' ',ans.size(),'\n');
	for(auto i:ans)write(i,' ');
	putc('\n');
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int m,c;
	read(n,m);
	for(int i=1;i<=m;++i){
		read(xu[i],xv[i],c,w[i]);
		uv[i]=xu[i]^xv[i];
		c=getw(c);
		eg[c].emplace_back(i);
	}
	for(int c=1;c<=cntc;++c){
		cntv=0;
		for(auto e:eg[c])add(e);
		for(int i=1;i<=cntv;++i)if(to[nd[i]].size()>2)return write("No\n");
		for(int i=1;i<=cntv;++i)if(to[nd[i]].size()==1)chain(nd[i]);
		for(int i=1;i<=cntv;++i)if(!to[nd[i]].empty())circle(nd[i]);
	}
	int l=mn,r=1000000000;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid))r=mid-1;
		else l=mid+1;
	}
	if(r==1000000000)return write("No\n");
	else solve(r+1);
	return 0;
}