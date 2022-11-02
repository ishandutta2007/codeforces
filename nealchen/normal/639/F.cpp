#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, c>9&c!=253);
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
auto cmin=[](auto &a, const auto &b) {return b<a?(a=b, true):false;};
auto cmax=[](auto &a, const auto &b) {return a<b?(a=b, true):false;};

const int N=3e5+1;
struct Graph {
	int n, m, head[N], to[4*N], next[4*N];
	void init(int v) {
		n=v, m=0;
		memset(head, -1, n*sizeof(int));
	}
	void add_edges(int u, int v) {
		to[m]=v, next[m]=head[u], head[u]=m++;
		to[m]=u, next[m]=head[v], head[v]=m++;
	}
};
struct Tarjan {
	const int *head, *to, *next;
	int tick, dfn[N], low[N], stack[N], *top, bcc_cnt, bcc[N];
	bool vis[N];
	void dfs(int v, int fa) {
		dfn[v]=low[v]=tick++;
		vis[v]=true;
		*top++=v;
		for(int e=head[v]; ~e; e=next[e]) {
			int u=to[e];
			if(e==fa) continue;
			if(!vis[u]) {
				dfs(u, e^1);
				cmin(low[v], low[u]);
			} else
				cmin(low[v], dfn[u]);
		}
		if(dfn[v]==low[v]) {
			do {
				bcc[*--top]=bcc_cnt;
			} while(*top!=v);
			++bcc_cnt;
		}
	}
	void work(const Graph &g) {
		head=g.head, to=g.to, next=g.next;
		top=stack;
		tick=bcc_cnt=0;
		memset(vis, 0, g.n);
		for(int v=0; v<g.n; ++v) if(!vis[v]) dfs(v, -1);
	}
};
int id[N], x[N], u[N], v[N], dep[N], tick, cho[20][2*N], *eu=cho[0], eul[N], eur[N];
Graph g, tr, g0;
Tarjan tj;
std::vector<int> bcc;
void dfs(int v, int fa) {
	eu[eul[v]=eur[v]=tick++]=v;
	dep[v]=dep[fa]+1;
	for(int e=tr.head[v]; ~e; e=tr.next[e]) {
		int u=tr.to[e];
		if(u==fa) continue;
		dfs(u, v);
		eu[eur[v]=tick++]=v;
	}
}
int lca(int x, int y) {
	x=eul[x], y=eul[y];
	if(x>y) std::swap(x, y);
	int lv=31-__builtin_clz(y-x+1);
	x=cho[lv][x], y=cho[lv][y-(1<<lv)+1];
	return dep[x]<dep[y]?x:y;
}
int main() {
	int n=rd(), m=rd(), q=rd(), n0;
	g.init(n);
	for(int i=0; i<m; ++i) {
		u[i]=rd()-1, v[i]=rd()-1;
		g.add_edges(u[i], v[i]);
	}
	tj.work(g);
	tr.init(n0=tj.bcc_cnt);
	memcpy(id, tj.bcc, n*sizeof(int));
	for(int i=0; i<m; ++i) {
		int a=id[u[i]], b=id[v[i]];
		if(a!=b) tr.add_edges(a, b);
	}
	memset(eul, -1, n0*sizeof(int));
	eu[eul[n0]=eur[n0]=tick++]=n0;
	for(int i=0; i<n0; ++i)
		if(eul[i]==-1) {
			dfs(i, n0);
			eu[eur[n0]=tick++]=n0;
		}
	for(int i=1; (1<<i)<=tick; ++i)
		for(int j=0; (1<<i)+j<=tick; ++j) {
			int x=cho[i-1][j], y=cho[i-1][j+(1<<(i-1))];
			cho[i][j]=dep[x]<dep[y]?x:y;
		}
	for(int r=0, no=1; no<=q; ++no) {
		int nn=rd(), mm=rd(), size;
		std::vector<int> key(1, n0), par(1, 0);
		auto cmp=[](int x, int y) {return eul[x]<eul[y];};

		for(int i=0; i<nn; ++i)
			key.push_back(x[i]=id[(rd()+r-1)%n]);
		for(int i=0; i<mm; ++i) {
			key.push_back(u[i]=id[(rd()+r-1)%n]);
			key.push_back(v[i]=id[(rd()+r-1)%n]);
		}

		std::sort(key.begin(), key.end(), cmp);
		key.resize(size=std::unique(key.begin(), key.end())-key.begin());
		for(int i=1; i<size; ++i) key.push_back(lca(key[i-1], key[i]));
		std::sort(key.begin(), key.end(), cmp);
		key.resize(size=std::unique(key.begin(), key.end())-key.begin());

		g0.init(size);
		for(int j=1; j<size; ++j) {
			while(eul[key[j]]>eur[key[par.back()]]) par.pop_back();
			if(par.back()) g0.add_edges(par.back(), j);
			par.push_back(j);
		}
		for(int i=0; i<nn; ++i)
			x[i]=std::lower_bound(key.begin(), key.end(), x[i], cmp)-key.begin();
		for(int i=0; i<mm; ++i) {
			u[i]=std::lower_bound(key.begin(), key.end(), u[i], cmp)-key.begin();
			v[i]=std::lower_bound(key.begin(), key.end(), v[i], cmp)-key.begin();
			if(u[i]!=v[i]) g0.add_edges(u[i], v[i]);
		}
		tj.work(g0);

		bool ans=true;
		for(int i=1; i<nn; ++i) ans&=(tj.bcc[x[i]]==tj.bcc[x[0]]);
		if(ans) r=(r+no)%n;
		puts(ans?"YES":"NO");
	}
	return 0;
}