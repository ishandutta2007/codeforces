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

const int N=102, M=802;
int n, m, flow[N], head[N], next[M], to[M], cap[M], len[M], dis, cost;
bool vis[N];
void add(int u, int v, int c, int w) {
	to[m]=v, cap[m]=c, len[m]=w, next[m]=head[u], head[u]=m++;
	to[m]=u, cap[m]=0, len[m]=-w, next[m]=head[v], head[v]=m++;
}
int dfs(int u, int lim) {
	if(u==n+1) {
		cost+=dis*lim;
		return lim;
	}
	vis[u]=true;
	int save=lim;
	for(int i=head[u]; ~i; i=next[i])
		if(cap[i]&&len[i]==0&&!vis[to[i]]) {
			int cur=dfs(to[i], std::min(lim, cap[i]));
			cap[i]-=cur;
			cap[i^1]+=cur;
			lim-=cur;
			if(lim==0) break;
		}
	return save-lim;
}
bool relabel() {
	int d=1e9;
	for(int i=0; i<m; ++i)
		if(cap[i]&&vis[to[i^1]]&&!vis[to[i]]) cmin(d, len[i]);
	if(d==1e9) return false;
	for(int i=0; i<m; ++i)
		if(vis[to[i^1]]&&!vis[to[i]]) {
			len[i]-=d;
			len[i^1]+=d;
		}
	dis+=d;
	return true;
}
int main() {
	int mm;
	n=rd(), mm=rd();
	memset(head, -1, (n+2)*sizeof(int));
	while(mm--) {
		int u=rd(), v=rd(), c=rd(), f=rd();
		flow[u]+=f;
		flow[v]-=f;
		if(c>=f) {
			add(v, u, f, 1);
			if(c!=f) add(u, v, c-f, 1);
			add(u, v, 1e9, 2);
		} else {
			cost+=f-c;
			add(v, u, c, 1);
			add(v, u, f-c, 0);
			add(u, v, 1e9, 2);
		}
	}
	to[m]=n, cap[m]=1e9, len[m]=0, next[m]=head[1], head[1]=m++;
	to[m]=1, cap[m]=1e9, len[m]=0, next[m]=head[n], head[n]=m++;
	for(int i=1; i<=n; ++i) {
		if(flow[i]<0) add(0, i, -flow[i], 0);
		if(flow[i]>0) add(i, n+1, flow[i], 0);
	}
	do {
		do {
			memset(vis, 0, n+2);
		} while(dfs(0, 1e9));
	} while(relabel());
	printf("%d\n", cost);
	return 0;
}