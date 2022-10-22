#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

struct Edge {
	int x, y, cost;
	bool operator<(const Edge& e)const {
		return cost < e.cost;
	}
	Edge() {
		cin >> x >> y >> cost;
		x--, y--;
	}
};

class UnionFind {
	vector<int>parent;
	vector<int>rank;
public:
	UnionFind(int num) {
		num++;
		parent.resize(num);
		rank.resize(num);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int Find(int node) {
		if (parent[node] == node)return node;
		else return parent[node] = Find(parent[node]);
	}
	void Unite(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v)return;
		if (rank[u] < rank[v])parent[u] = v;
		else {
			parent[v] = u;
			if (rank[u] == rank[v])rank[u]++;
		}
	}
	bool Check_Same(int u, int v) {
		return Find(u) == Find(v);
	}
};

void Solve() {
	cin >> N >> M;
	int x = 0;
	vector<map<int, int>>mp(N);
	vector<Edge>edge(M);
	UnionFind uf(N);
	auto bef = uf;
	for (int i = 0; i < M; i++) {
		mp[edge[i].x][edge[i].y] = edge[i].cost;
		mp[edge[i].y][edge[i].x] = edge[i].cost;
		x ^= edge[i].cost;
	}
	if (N == 2) {
		if (M == 1)cout << edge[0].cost << endl;
		else cout << 0 << endl;
		return;
	}
	if (M == 0) {
		cout << 0 << endl;
		return;
	}
	vector<set<int>>st(N);
	for (int i = 1; i < N; i++) {
		if (mp[0].find(i) == mp[0].end()) {
			uf.Unite(0, i);
		}
		else {
			st[0].insert(i);
		}
	}
	for (int i = 1; i < N; i++) {
		int par = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (uf.Check_Same(i, j)) {
				par = uf.Find(i);
				st[i] = st[par];
				break;
			}
			if (j == 0) {
				for (int k = 0; k < N; k++) {
					if (k != i)st[i].insert(k);
				}
			}
		}
		set<int>nx;
		for (auto j : st[i]) {
			if (uf.Check_Same(i, j)) {
				if(par!=-1)st[par].erase(j);
				continue;
			}
			if (mp[i].find(j) == mp[i].end()) {
				uf.Unite(i, j);
			}
			else {
				nx.insert(j);
			}
		}
		st[i] = nx;
	}
	long long int comp_edge = (N - 1) * N / 2 - M;
	long long int comp_con = 0;
	for (int i = 0; i < N; i++) {
	//	cout << i << " " << uf.Find(i) << endl;
		if (i == uf.Find(i))comp_con++;
	}
	sort(edge.begin(), edge.end());
//	cout << N - comp_con << " " << comp_edge << endl;
	if (N - comp_con < comp_edge) {
		long long int ans = 0;
		for (auto i : edge) {
			if (!uf.Check_Same(i.x, i.y)) {
				ans += i.cost;
				uf.Unite(i.x, i.y);
			}
		}
		cout << ans << endl;
		return;
	}
	
	long long int ans = x;
	for (auto i : edge) {
		if (!uf.Check_Same(i.x, i.y)) {
			ans += i.cost;
			uf.Unite(i.x, i.y);
			bef.Unite(i.x, i.y);
		}
		else if (!bef.Check_Same(i.x, i.y)) {
			if (x > i.cost) {
				ans -= x;
				ans += i.cost;
				x = 0;
			}
		}
	}
	cout << ans << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}

}