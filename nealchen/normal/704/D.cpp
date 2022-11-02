#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;
namespace G {
	const int N=2e5+10, M=1e6+10;
	int n, m, s, t, to[M], cap[M], head[N], next[M], deg[N], dis[N], cur[N];
	void init(int v, int src, int dst) {
		n=v, m=0, s=src, t=dst;
		memset(head, -1, n*sizeof(int));
		memset(deg, 0, n*sizeof(int));
	}
	void edge(int u, int v, int w) {
		to[m]=v, cap[m]=w, next[m]=head[u], head[u]=m++;
		to[m]=u, cap[m]=0, next[m]=head[v], head[v]=m++;
	}
	void add_edge(int u, int v, int min, int max) {
		if(max>min) edge(u, v, max-min);
		deg[u]+=min;
		deg[v]-=min;
	}
	bool bfs() {
		static int queue[N];
		int *qhead=queue, *qtail=queue;
		memset(dis, -1, n*sizeof(int));
		dis[*qtail++=t]=0;
		while(qhead!=qtail) {
			int u=*qhead++;
			for(int i=head[u]; ~i; i=next[i])
				if(cap[i^1]&&dis[to[i]]==-1) {
					dis[*qtail++=to[i]]=dis[u]+1;
					if(to[i]==s) return true;
				}
		}
		return false;
	}
	int dfs(int u, int lim) {
		if(u==t) return lim;
		int rem=lim;
		for(int &i=cur[u]; ~i; i=next[i])
			if(cap[i]&&dis[to[i]]+1==dis[u]) {
				int now=dfs(to[i], std::min(cap[i], rem));
				cap[i]-=now;
				cap[i^1]+=now;
				if((rem-=now)==0) break;
			}
		return lim-rem;
	}
	int flow(int ss, int tt) {
		int msave=m, ans=deg[ss];
		edge(tt, ss, 1e9);
		for(int i=0; i<n; ++i) {
			if(deg[i]<0) edge(s, i, -deg[i]);
			if(deg[i]>0) edge(i, t, deg[i]);
		}
		while(bfs()) {
			memcpy(cur, head, n*sizeof(int));
			dfs(s, 1e9);
		}
		for(int i=head[s]; ~i; i=next[i]) if(cap[i]) return -1;
		for(int i=0; i<n; ++i)
			while(~head[i]&&head[i]>=msave) head[i]=next[head[i]];
		s=ss, t=tt;
		while(bfs()) {
			memcpy(cur, head, n*sizeof(int));
			dfs(s, 1e9);
		}
		for(int i=head[s]; ~i; i=next[i]) ans+=cap[i^1];
		return ans;
	}
}
const int N=1e5;
int x[N], y[N], nx, ny, rx[N], ry[N], cnt[2*N], lim[2*N];
char ans[N+1];
int main() {
	int n, m, r, b;
	bool rev=false;
	n=rd(), m=rd(), r=rd(), b=rd();
	if(r>b) rev=true, std::swap(r, b);
	for(int i=0; i<n; ++i) {
		x[i]=rx[i]=rd();
		y[i]=ry[i]=rd();
	}
	std::sort(rx, rx+n);
	nx=std::unique(rx, rx+n)-rx;
	std::sort(ry, ry+n);
	ny=std::unique(ry, ry+n)-ry;
	G::init(nx+ny+4, nx+ny+2, nx+ny+3);
	for(int i=0; i<n; ++i) {
		x[i]=std::lower_bound(rx, rx+nx, x[i])-rx;
		y[i]=std::lower_bound(ry, ry+ny, y[i])-ry;
		++cnt[x[i]], ++cnt[nx+y[i]];
		G::add_edge(x[i], nx+y[i], 0, 1);
	}
	std::fill(lim, lim+nx+ny, n);
	while(m--) {
		int t=rd(), l=rd(), d=rd();
		if(t==1) {
			int i=std::lower_bound(rx, rx+nx, l)-rx;
			if(rx[i]==l) cmin(lim[i], d);
		} else {
			int i=std::lower_bound(ry, ry+ny, l)-ry;
			if(ry[i]==l) cmin(lim[nx+i], d);
		}
	}
	for(int i=0; i<nx+ny; ++i) {
		lim[i]-=(lim[i]+cnt[i])&1;
		if(lim[i]<0) {
			puts("-1");
			return 0;
		}
		int min=std::max(0, (cnt[i]-lim[i])/2), max=(lim[i]+cnt[i])/2;
		if(i<nx) G::add_edge(nx+ny, i, min, max);
		else G::add_edge(i, nx+ny+1, min, max);
	}
	int f=G::flow(nx+ny, nx+ny+1);
	if(f==-1) {
		puts("-1");
		return 0;
	}
	for(int i=0; i<n; ++i) ans[i]="rb"[rev^G::cap[2*i]];
	printf("%lld\n%s\n", (long long)r*f+(long long)b*(n-f), ans);
	return 0;
}