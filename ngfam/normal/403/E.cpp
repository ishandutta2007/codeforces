#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int n;
int cnt[2];
int in[2][N];
int out[2][N];
int depth[2][N];
int jump[2][N][20];
vector < int > g[2][N];

void dfs(int id, int v, int p) {
	depth[id][v] = depth[id][p] + 1;
	jump[id][v][0] = p;
	in[id][v] = ++cnt[id];
	for(int i = 1; i < 20; ++i) {
		jump[id][v][i] = jump[id][jump[id][v][i - 1]][i - 1];
	}
	for(int s : g[id][v]) if(s != p){
		dfs(id, s, v);
	}
	out[id][v] = cnt[id];
}

int lca(int id, int u, int v) {
	if(depth[id][u] < depth[id][v]) swap(u, v);
	for(int i = 19; i >= 0; --i) {
		if(depth[id][jump[id][u][i]] >= depth[id][v]) {
			u = jump[id][u][i];
		}
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; --i) {
		if(jump[id][u][i] != jump[id][v][i]) {
			u = jump[id][u][i];
			v = jump[id][v][i];
		}
	}
	return jump[id][u][0];
}

pair < int, int > edges[2][N];
map < pair < int, int >, int > me[2];
multiset < pair < int, int > > items[2][N];

int T[2][N << 2];
#define mid ((l + r) >> 1)

void build(int id, int x, int l, int r) {
	if(l == r) {
		if(items[id][r].size()) T[id][x] = items[id][r].begin() -> first;
		else T[id][x] = n + 1;
		return;
	}
	build(id, x + x, l, mid);
	build(id, x + x + 1, mid + 1, r);
	T[id][x] = min(T[id][x + x], T[id][x + x + 1]);
}

int mark[2][N];
vector < pair < int, int > > temps;

void query(int id, int x, int l, int r, int u, int v, int d) {
	if(T[id][x] > d) return;
	if(l > v || r < u) return;
	if(l == r) {
		while(items[id][r].size() && items[id][r].begin() -> first <= d){
			temps.emplace_back(items[id][r].begin() -> second, 1 - id);
			items[id][r].erase(items[id][r].begin());
		}
		if(items[id][r].size()) T[id][x] = items[id][r].begin() -> first;
		else T[id][x] = n + 1;
		return;
	}
	query(id, x + x, l, mid, u, v, d);
	query(id, x + x + 1, mid + 1, r, u, v, d);
	T[id][x] = min(T[id][x + x], T[id][x + x + 1]);
}
//
int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 2; i <= n; ++i) {
		int x; cin >> x;
		g[0][i].push_back(x);
		g[0][x].push_back(i);
		me[0][make_pair(i, x)] = i - 1;
		me[0][make_pair(x, i)] = i - 1;
		edges[0][i - 1] = make_pair(x, i);
	}

	for(int i = 2; i <= n; ++i) {
		int x; cin >> x;
		g[1][i].push_back(x);
		g[1][x].push_back(i);
		me[1][make_pair(i, x)] = i - 1;
		me[1][make_pair(x, i)] = i - 1;
		edges[1][i - 1] = make_pair(x, i);
	}

	dfs(0, 1, 0);
	dfs(1, 1, 0);

	for(int id = 0; id < 2; ++id) {
		for(int v = 1; v <= n; ++v) {
			for(int s : g[1 - id][v]) {
				int p = lca(id, v, s);
				items[id][in[id][v]].insert(make_pair(depth[id][p] + 1, me[1 - id][make_pair(s, v)]));
			}
		}
	}

	build(0, 1, 1, n);
	build(1, 1, 1, n);

	int idx; cin >> idx;
	vector < pair < int, int > > justAdded;
	justAdded.emplace_back(idx, 0);

	mark[0][idx] = 1;

	while(justAdded.size()) {
		temps.clear();
		if(justAdded.front().second == 0) cout << "Blue\n";
		else cout << "Red\n";
		for(auto &p : justAdded) cout << p.first << " ";
		cout << "\n";

		temps.clear();
		for(auto &p : justAdded) {
			auto e = edges[p.second][p.first];
			int v = e.first;
			if(depth[p.second][e.second] > depth[p.second][e.first]) v = e.second;
			query(p.second, 1, 1, n, in[p.second][v], out[p.second][v], depth[p.second][v]);
		}


		justAdded.clear();
		for(auto &p : temps) {
			if(mark[p.second][p.first]) continue;
			mark[p.second][p.first] = 1;
			justAdded.emplace_back(p.first, p.second);
		}

		sort(justAdded.begin(), justAdded.end());
	}

  return 0;
}