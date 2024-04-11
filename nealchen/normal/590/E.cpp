#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

const int N=750, L=1e7+N, V=N*2+2, E=N*(N+3);
int n, tot, tr[L][2], fail[L], id[L], queue[L], e, head[V], to[E], next[E], cap[E], dis[V], cur[V], sid[N], tid[N], eid[N][N], match[N];
bool lvis[N], rvis[N];
char pool[L], *s[N];
std::bitset<N> edge[N];
int init() {
	tr[tot][0]=tr[tot][1]=id[tot]=-1;
	return tot++;
}
void add(int u, int v, int w) {
	to[e]=v, cap[e]=w, next[e]=head[u], head[u]=e++;
	to[e]=u, cap[e]=0, next[e]=head[v], head[v]=e++;
}
bool bfs() {
	int *qhead=queue, *qtail=queue;
	memset(dis, -1, (2*n+2)*sizeof(int));
	dis[*qtail++=2*n+1]=0;
	while(qhead!=qtail) {
		int u=*qhead++;
		if(u==2*n) return true;
		for(int i=head[u]; ~i; i=next[i])
			if(cap[i^1]&&dis[to[i]]==-1)
				dis[*qtail++=to[i]]=dis[u]+1;
	}
	return false;
}
int dfs(int x, int lim) {
	int save=lim;
	if(x==2*n+1) return lim;
	for(int &i=cur[x]; ~i; i=next[i])
		if(cap[i]&&dis[x]==dis[to[i]]+1) {
			int flow=dfs(to[i], std::min(lim, cap[i]));
			cap[i]-=flow, cap[i^1]+=flow;
			lim-=flow;
			if(lim==0) break;
		}
	return save-lim;
}
void construct(int r) {
	rvis[r]=true;
	for(int l=0; l<n; ++l)
		if(!lvis[l]&&edge[l].test(r)&&cap[eid[l][r]]) {
			lvis[l]=true;
			construct(match[l]);
		}
}
int main() {
	char *mem=pool;
	int ans, *qhead=queue, *qtail=queue;
	assert(scanf("%d", &n)==1);
	init();
	for(int i=0; i<n; ++i) {
		int at=0;
		assert(scanf("%s", s[i]=mem)==1);
		for(; *mem; ++mem) {
			int &to=tr[at][*mem-'a'];
			if(to==-1) to=init();
			at=to;
		}
		id[at]=i;
		++mem;
	}
	for(int i=0; i<2; ++i) {
		int &v=tr[0][i];
		if(~v) *qtail++=v; else v=0;
	}
	while(qhead!=qtail) {
		int u=*qhead++;
		for(int i=0; i<2; ++i) {
			int &v=tr[u][i], w=tr[fail[u]][i];
			if(~v) {
				*qtail++=v;
				fail[v]=w;
				if(id[v]==-1) id[v]=id[w]; else if(id[w]!=-1) edge[id[w]].set(id[v]);
			} else v=w;
		}
	}
	for(int i=0; i<n; ++i) {
		int at=0;
		for(auto j=s[i]; *j; ++j) {
			at=tr[at][*j-'a'];
			if(id[at]!=-1&&id[at]!=i) edge[id[at]].set(i);
		}
	}
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(edge[j].test(i)) edge[j]|=edge[i];
	memset(head, -1, (2*n+2)*sizeof(int));
	for(int i=0; i<n; ++i) sid[i]=e, add(2*n, i, 1), tid[i]=e, add(i+n, 2*n+1, 1);
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(edge[i].test(j)) eid[i][j]=e, add(i, j+n, 1);
	ans=n;
	while(bfs()) {
		memcpy(cur, head, (2*n+2)*sizeof(int));
		ans-=dfs(2*n, 1<<30);
	}
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(edge[i].test(j)&&cap[eid[i][j]]==0) match[i]=j;
	for(int i=0; i<n; ++i) if(cap[tid[i]]) construct(i);
	printf("%d\n", ans);
	for(int i=0; i<n; ++i) if(!lvis[i]&&rvis[i]) printf("%d ", i+1);
	puts("");
	return 0;
}