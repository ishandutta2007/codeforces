#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
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
auto rd=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

const int N=2e5;
int n, m, l[7], ecnt[6][6], prufer[4], to[114], cap[114], head[23], cur[23], next[114], dis[23], e, s, t;
void add_edge(int u, int v, int w) {
	to[e]=v, cap[e]=w, next[e]=head[u], head[u]=e++;
	to[e]=u, cap[e]=0, next[e]=head[v], head[v]=e++;
}
bool bfs() {
	int queue[23], *qhead=queue, *qtail=queue;
	memset(dis, -1, (t+1)*sizeof(int));
	dis[*qtail++=t]=0;
	while(qhead!=qtail) {
		int v=*qhead++;
		if(v==s) return true;
		for(int e=head[v]; e!=-1; e=next[e])
			if(cap[e^1]&&dis[to[e]]==-1)
				dis[*qtail++=to[e]]=dis[v]+1;
	}
	return false;
}
int dfs(int u, int lim) {
	if(u==t) return lim;
	int save=lim;
	for(int &e=cur[u]; e!=-1; e=next[e])
		if(cap[e]&&dis[to[e]]==dis[u]-1) {
			int f=dfs(to[e], std::min(lim, cap[e]));
			cap[e]-=f, cap[e^1]+=f, lim-=f;
			if(lim==0) break;
		}
	return save-lim;
}
void search(int i) {
	if(i<m-2) {
		int &j=prufer[i];
		for(j=0; j<m; ++j) search(i+1);
		return;
	}
	int vis[6]={}, ecur[6][6], handle[6][6], maxflow=0;
	std::vector<std::pair<int, int>> tree;
	for(int i=0; i<m-2; ++i) ++vis[prufer[i]];
	for(int i=0; i<m-2; ++i) {
		int l=std::find(vis, vis+m, 0)-vis;
		tree.emplace_back(l, prufer[i]);
		--vis[l], --vis[prufer[i]];
	}
	int a=std::find(vis, vis+m, 0)-vis, b=std::find(vis+a+1, vis+m, 0)-vis;
	tree.emplace_back(a, b);
	for(int i=0; i<m; ++i) memcpy(ecur[i], ecnt[i], m*sizeof(int));
	for(auto e: tree) {
		int u, v;
		std::tie(u, v)=e;
		--ecur[u][v], --ecur[v][u];
		if(ecur[u][v]<0) return;
	}
	e=0, s=m+m*(m-1)/2, t=s+1;
	memset(head, -1, (t+1)*sizeof(int));
	for(int i=0; i<m; ++i) add_edge(s, i, l[i+1]-l[i]-1);
	for(int i=0, k=m; i<m; ++i) {
		handle[i][i]=e+1;
		add_edge(i, t, ecur[i][i]);
		for(int j=i+1; j<m; ++j, ++k) {
			handle[i][j]=e+1;
			add_edge(i, k, n);
			handle[j][i]=e+1;
			add_edge(j, k, n);
			add_edge(k, t, ecur[i][j]);
		}
	}
	while(bfs()) {
		memcpy(cur, head, (t+1)*sizeof(int));
		maxflow+=dfs(s, n);
	}
	if(maxflow==n-m) {
		for(auto e: tree) printf("%d %d\n", l[e.first], l[e.second]);
		for(int i=0; i<m; ++i) {
			int p=l[i];
			for(int j=0; j<m; ++j)
				for(int rep=cap[handle[i][j]]; rep--; )
					printf("%d %d\n", ++p, l[j]);
		}
		exit(0);
	}
}
int main() {
	assert(scanf("%d", &n)==1);
	for(int p=1; p<=n; p*=10) l[m++]=p;
	l[m]=n+1;
	for(int i=1, j=2; i<n; ++i) {
		int u, v;
		char s[10], t[10];
		assert(scanf("%s%s", s, t)==2);
		u=strlen(s)-1, v=strlen(t)-1;
		++ecnt[u][v];
		if(u!=v) ++ecnt[v][u];
	}
	if(m==1) {
		for(int i=2; i<=n; ++i) printf("1 %d\n", i);
		return 0;
	}
	search(0);
	puts("-1");
	return 0;
}