#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

vector <vector <int>> g, anc;
vector <int> idl, idr, lvl;
int id;

void dfs(int nod, int par) {
	idl[nod] = ++id;
	anc[nod][0] = par, lvl[nod] = lvl[par] + 1;
	for(int bit = 1; bit < 20; bit++) {
		anc[nod][bit] = anc[anc[nod][bit - 1]][bit - 1];
	}
	for(auto it : g[nod]) {
		if(it != par) {
			dfs(it, nod);
		}
	}
	idr[nod] = id;
}

inline int get_lca(int x, int y) {
	if(lvl[x] < lvl[y]) swap(x, y);
	for(int bit = 19; bit >= 0; bit--) {
		if(lvl[anc[x][bit]] >= lvl[y]) {
			x = anc[x][bit];
		}
	}
	if(x == y) return x;
	for(int bit = 19; bit >= 0; bit--) {
		if(anc[x][bit] != anc[y][bit]) {
			x = anc[x][bit], y = anc[y][bit];
		}
	}
	return anc[x][0];
}

inline bool is_anc(int x, int y) {
	return idl[x] <= idl[y] && idr[y] <= idr[x];
}

struct Data {
	int nod, dst, spd, idv;
	bool operator <(const Data &other) const {
		int a = (dst + spd - 1) / spd;
		int b = (other.dst + other.spd - 1) / other.spd;
		if(a == b) return idv > other.idv;
		return a > b;
	}
};

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	int i, n;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	g.resize(n + 1);
	for(i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	anc.resize(n + 1, vector <int>(20));
	idl.resize(n + 1), idr.resize(n + 1), lvl.resize(n + 1);
	dfs(1, 0);

	vector <int> sol(n + 1, -1), dst(n + 1);
	vector <bool> vis(n + 1);
	vector <vector <pair <int, int>>> graph(n + 1);

	int q; cin >> q;
	while(q--) {
		int k, m; cin >> k >> m;
		vector <int> nodes, v(k), s(k);
		for(i = 0; i < k; i++) {
			cin >> v[i] >> s[i];
			nodes.push_back(v[i]);
		}
		vector <int> u(m);
		for(i = 0; i < m; i++) {
			cin >> u[i];
			nodes.push_back(u[i]);
		}
		sort(nodes.begin(), nodes.end(), [&](const int &x, const int &y) {
			return idl[x] < idl[y];
		});
		for(i = (int)nodes.size() - 1; i > 0; i--) {
			nodes.push_back(get_lca(nodes[i], nodes[i - 1]));
		}
		sort(nodes.begin(), nodes.end());
		nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
		sort(nodes.begin(), nodes.end(), [&](const int &x, const int &y) {
			return idl[x] < idl[y];
		});

		stack <int> stk;
		for(auto cur : nodes) {
			while(stk.size() && !is_anc(stk.top(), cur)) {
				stk.pop();
			}
			if(stk.size()) {
				int dst = lvl[cur] - lvl[stk.top()];
				graph[cur].push_back({stk.top(), dst});
				graph[stk.top()].push_back({cur, dst});
				//cerr << cur << " " << stk.top() << " " << lvl[cur] - lvl[stk.top()] << "\n";
			}
			stk.push(cur);
		}
		//cerr << "\n";

		priority_queue <Data> pq;
		for(auto it : nodes) {
			dst[it] = n + 1;
		}
		for(i = 0; i < k; i++) {
			pq.push({v[i], 0, s[i], i});
			dst[v[i]] = 0;
			sol[v[i]] = i;
		}

		while(pq.size()) {
			auto cur = pq.top();
			pq.pop();
			if(vis[cur.nod]) continue;

			if(sol[cur.nod] == -1 || cur.idv == sol[cur.nod]) {
				vis[cur.nod] = 1;
				sol[cur.nod] = cur.idv;
				for(auto &it : graph[cur.nod]) {
					int cst = cur.dst + it.second;
					if((cst + cur.spd - 1) / cur.spd <= dst[it.first]) {
						dst[it.first] = (cst + cur.spd - 1) / cur.spd;
						pq.push({it.first, cst, cur.spd, cur.idv});
					}
				}
			}
		}
		
		for(auto it : u) {
			cout << sol[it] + 1 << " ";
		}
		cout << "\n";

		for(auto cur : nodes) {
			graph[cur].clear();
			vis[cur] = 0;
			sol[cur] = -1;
		}
	}

	return 0;
}