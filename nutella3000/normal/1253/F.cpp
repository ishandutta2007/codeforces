#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
        
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
         
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 1e15 + 7;
const int max_n = 1e5 + 3, log_n = 20;

struct edge {
	int v, to, w;
	edge(int v, int to, int w) : v(v), to(to), w(w) {}
	edge() {}
};

int n, k, q;
vector<edge> ed;
vector<int> gr[max_n];

void djkstra () {
	vector<int> d(n);
	fill(d.begin() + k, d.end(), inf);

	auto comp = [&](int v1, int v2) { return mp(d[v1], v1) < mp(d[v2], v2); };
	set<int, decltype(comp)> so(comp);
	for(int i = 0;i < k;i++) so.emplace(i);

	while(size(so)) {
		int v = *so.begin(); so.erase(so.begin());

		for(int id : gr[v]) {
			int to = ed[id].to, cost = ed[id].w;
			if (d[to] > d[v] + cost) {
				so.erase(to);
				d[to] = d[v] + cost;
				so.emplace(to);
			}
		}
	}

	for(auto& i : ed) 
		i.w += d[i.v] + d[i.to];
}

vector<pii> tree[max_n];
int p[log_n][max_n], mx_edge[log_n][max_n], tin[max_n], tout[max_n], T = 0;

void kruskal() {
	sort(ed.begin(), ed.end(), [](auto& v1, auto& v2) { return v1.w < v2.w; });
	vector<int> par(n); iota(par.begin(), par.end(), 0);

	function<int(int)> get = [&](int v) { return par[v] == v ? v : par[v] = get(par[v]); };

	auto merge = [&](int& v1, int& v2) { par[get(v1)] = get(v2); };
	
	for(auto i : ed) {
		if (get(i.v) != get(i.to)) {
			tree[i.v].emplace_back(i.to, i.w);
			tree[i.to].emplace_back(i.v, i.w);
			merge(i.v, i.to);
		}
	}
}

void dfs(int v, int pr = -1) {
	tin[v] = T++;

	for(auto id : tree[v]) {
		int to = id.first, cost = id.second;
		if (to == pr) continue;

		p[0][to] = v, mx_edge[0][to] = cost;

		for(int i = 1;i < log_n;i++) {
			p[i][to] = p[i - 1][p[i - 1][to]];
			mx_edge[i][to] = max(mx_edge[i - 1][to], mx_edge[i - 1][p[i - 1][to]]);
		}

		dfs(to, v);
	}

	tout[v] = T++;
}

bool ispar(int v, int u) { return tin[v] <= tin[u] && tout[v] >= tout[u]; };

int get_max(int v1, int v2) {
	int res = 0;
	for(int k = log_n - 1;k >= 0;k--) {
		if (!ispar(p[k][v1], v2)) chkmax(res, mx_edge[k][v1]), v1 = p[k][v1];
		if (!ispar(p[k][v2], v1)) chkmax(res, mx_edge[k][v2]), v2 = p[k][v2];
	}
	if (!ispar(v1, v2)) chkmax(res, mx_edge[0][v1]);
	if (!ispar(v2, v1)) chkmax(res, mx_edge[0][v2]);
	return res;
}

void scan() {
	int m;
	cin >> n >> m >> k >> q;
	for(int i = 0;i < m;i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		--v1, --v2;
		
		gr[v1].emplace_back(size(ed));
		ed.emplace_back(edge(v1, v2, w));

		gr[v2].emplace_back(size(ed));
		ed.emplace_back(edge(v2, v1, w));
	}
}

void solve() {
	scan();
	djkstra();
	kruskal();
	dfs(0);

	for(int it = 0;it < q;it++) {
		int v1, v2;
		cin >> v1 >> v2;
		cout << get_max(--v1, --v2) << '\n';
	}
}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}