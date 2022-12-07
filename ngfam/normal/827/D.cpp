#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int M = 20;

struct Edge{
	int u;
	int v;
	int w;
	int idx;
	int inTree;

	void Init(int _u, int _v, int _w, int _idx){
		inTree = 0;
		u = _u;
		v = _v;
		w = _w;
		idx = _idx;
	}
}Edges[N];

int n, m;
int lab[N];
int child[N];
int depth[N];
int jump[N][20];
int weight[N][20];
vector < pair < int, int > > adj[N];

bool cmp(Edge u, Edge v){
	return u.w < v.w;
}

int par(int u){
	if(lab[u] < 0){
		return u;
	}
	return lab[u] = par(lab[u]);
}

bool join(int u, int v){
	u = par(u); 
	v = par(v);
	if(u == v){
		return false;
	}
	if(lab[u] > lab[v]){
		swap(u, v);
	}
	lab[u] += lab[v];
	lab[v] = u;
	return true;
}	

void dfs(int u, int p = 0){
	jump[u][0] = p;
	for(int i = 1; i < M; ++i){
		jump[u][i] = jump[jump[u][i - 1]][i - 1];
		weight[u][i] = max(weight[jump[u][i - 1]][i - 1], weight[u][i - 1]);
	}

	child[u] = 1;
	depth[u] = depth[p] + 1;

	for(int i = 0; i < adj[u].size(); ++i){
		int v = adj[u][i].first;
		if(v == p){
			continue;
		}
		weight[v][0] = adj[u][i].second;
		dfs(v, u);
		child[u] += child[v];
	}
}

int num;
int nChain;
int Number[N];
int inChain[N];
int atNumber[N];
int headChain[N];

void hld(int u, int p = 0){
	inChain[u] = nChain;
	if(headChain[inChain[u]] == 0){
		headChain[inChain[u]] = u;
	}
	Number[u] = ++num;
	atNumber[num] = u;

	int nodes = 0;
	for(int i = 0; i < adj[u].size(); ++i){
		int v = adj[u][i].first;
		if(v == p){
			continue;
		}
		if(child[v] > child[nodes]){
			nodes = v;
		}
	}

	if(nodes != 0){
		hld(nodes, u);
	}

	for(int i = 0; i < adj[u].size(); ++i){
		int v = adj[u][i].first;
		if(v == p){
			continue;
		}
		if(v != nodes){
			++nChain;
			hld(v, u);
		}
	}
}

int Lca(int u, int v, bool what){
	if(depth[u] < depth[v]){
		swap(u, v);
	}
	int ans = 0;
	for(int i = M - 1; i >= 0; --i){
		if(depth[jump[u][i]] >= depth[v]){
			ans = max(ans, weight[u][i]);
			u = jump[u][i];
		}
	}
	if(u == v){
		if(what == 1){
			return ans;
		}
		return u;
	}
	for(int i = M - 1; i >= 0; --i){
		if(jump[u][i] != jump[v][i]){
			ans = max(ans, weight[u][i]);
			ans = max(ans, weight[v][i]);
			u = jump[u][i];
			v = jump[v][i];
		}
	}
	ans = max(ans, weight[u][0]);
	ans = max(ans, weight[v][0]);
	if(what == 1){
		return ans;
	}
	else{
		return jump[u][0];
	}
}

struct SegmentTree{
	
	int it[N * 8];
	int lazy[N * 8];

	void Init(){
		memset(it, 60, sizeof it);
		memset(lazy, 60, sizeof lazy);
	}

	#define ii (i << 1)
	#define mid ((l + r) >> 1)

	void Solve(int i){
		if(lazy[i] != lazy[0]){
			lazy[ii] = min(lazy[ii], lazy[i]);
			lazy[ii + 1] = min(lazy[ii + 1], lazy[i]);
			it[i] = min(it[i], lazy[i]);
		}
		lazy[i] = lazy[0];
	}

	void ReCalc(int i){
		it[i] = min(it[ii], it[ii + 1]);
	}

	void upd(int i, int l, int r, int x, int y, int val){
		Solve(i);
		if(l > y || r < x){
			return;
		}
		if(l >= x && r <= y){
			lazy[i] = min(lazy[i], val);
			Solve(i);
			return;
		}
		upd(ii, l, mid, x, y, val);
		upd(ii + 1, mid + 1, r, x, y, val);
		ReCalc(i);
	}

	int query(int i, int l, int r, int x){
		Solve(i);
		if(l > x || r < x){
			return lazy[0];
		}
		if(l == r){
			return it[i];
		}
		int rs = min(query(ii, l, mid, x), query(ii + 1, mid + 1, r, x));
		ReCalc(i);
		return rs;
	}
}Smt;

void upd(int u, int p, int val){
	if(inChain[u] == inChain[p]){
		Smt.upd(1, 1, n, Number[p] + 1, Number[u], val);
	}	
	else{
		int x = headChain[inChain[u]];
		Smt.upd(1, 1, n, Number[x], Number[u], val);
		upd(jump[x][0], p, val);
	}
}

int result[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		Edges[i].Init(u, v, w, i);
	}

	sort(Edges + 1, Edges + m + 1, cmp);

	memset(lab, -1, sizeof lab);
	for(int i = 1; i <= m; ++i){
		if(join(Edges[i].u, Edges[i].v)){
			Edges[i].inTree = 1;
			adj[Edges[i].u].push_back(make_pair(Edges[i].v, Edges[i].w));
			adj[Edges[i].v].push_back(make_pair(Edges[i].u, Edges[i].w));
		}
	}

	dfs(1);
	hld(1);	
	Smt.Init();

	for(int i = 1; i <= m; ++i){
		if(Edges[i].inTree == 0){
			result[Edges[i].idx] = Lca(Edges[i].u, Edges[i].v, 1) - 1;
		
			int p = Lca(Edges[i].u, Edges[i].v, 0);
			upd(Edges[i].u, p, Edges[i].w - 1);
			upd(Edges[i].v, p, Edges[i].w - 1);
		}
	}

	for(int i = 1; i <= m; ++i){
		if(Edges[i].inTree == 1){
			int u = Edges[i].u, v = Edges[i].v;
			if(depth[u] < depth[v]){
				swap(u, v);
			}
			result[Edges[i].idx] = Smt.query(1, 1, n, Number[u]);
		}
	}

	for(int i = 1; i <= m; ++i){
		if(result[i] == Smt.lazy[0]){
			result[i] = -1;
		}
		printf("%d ", result[i]);
	}

	return 0;
}