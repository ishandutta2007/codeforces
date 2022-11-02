#include <cstdio>
#include <cstring>
#define meow(args...) fprintf(stderr, args)
inline bool cmin(auto &a, const auto &b) {return b<a?(a=b, true):false;}
inline bool cmax(auto &a, const auto &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

const int N=2001, M=2e5;
int n, p[N], head[N], next[M], to[M], w[M], x[N], y[N], maxx[N], maxy[N];
s64 sum[N][N], fmin[N], gmin[N], f[N][N], g[N][N];
int sp(int src, int *rank) {
	static s64 dis[N];
	static bool vis[N];
	int m=1;
	s64 last=0;
	memset(dis+1, 63, n*sizeof(s64));
	memset(vis+1, 0, n);
	last=dis[src]=0;
	for(int i=1, u; i<=n; ++i) {
		s64 cur=1e18;
		for(int j=1; j<=n; ++j) if(!vis[j]&&cmin(cur, dis[j])) u=j;
		for(int j=head[u]; j!=-1; j=next[j]) cmin(dis[to[j]], cur+w[j]);
		vis[u]=true;
		m+=cur!=last, last=cur;
		rank[u]=m-1;
	}
	return m;
}
int main() {
	int m, s, t, nx, ny;
	n=rd(), m=rd(), s=rd(), t=rd();
	for(int i=1; i<=n; ++i) p[i]=rd();
	memset(head+1, -1, n*sizeof(int));
	for(int i=0; m--; ) {
		int u=rd(), v=rd();
		w[i]=w[i+1]=rd();
		to[i]=v, next[i]=head[u], head[u]=i++;
		to[i]=u, next[i]=head[v], head[v]=i++;
	}
	nx=sp(s, x);
	ny=sp(t, y);
	memset(maxx, -1, ny*sizeof(int));
	memset(maxy, -1, nx*sizeof(int));
	for(int i=1; i<=n; ++i) cmax(maxx[y[i]], x[i]), cmax(maxy[x[i]], y[i]);
	for(int i=1; i<=n; ++i) sum[x[i]][y[i]]+=p[i];
	for(int i=0; i<=nx; ++i) for(int j=ny; j--; ) sum[i][j]+=sum[i][j+1];
	for(int i=nx; i--; ) for(int j=0; j<=ny; ++j) sum[i][j]+=sum[i+1][j];
	for(int i=nx; i--; )
		for(int j=ny; j--; ) {
			f[i][j]=maxy[i]<j?f[i+1][j]:sum[i][j]-gmin[j];
			g[i][j]=maxx[j]<i?g[i][j+1]:sum[i][j]-fmin[i];
			cmin(fmin[i], sum[i][j]+f[i][j]);
			cmin(gmin[j], sum[i][j]+g[i][j]);
		}
	if(f[0][0]>0) puts("Break a heart");
	if(f[0][0]<0) puts("Cry");
	if(f[0][0]==0) puts("Flowers");
	return 0;
}