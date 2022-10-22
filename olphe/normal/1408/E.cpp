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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

struct Edge {
	int l, r, cost;
	Edge(const int ll, const int rr, const int cc) {
		l = ll, r = rr, cost = cc;
	}
	bool operator<(const Edge&e)const {
		return cost > e.cost;
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v(N);
	vector<int>w(M);
	for (auto &i : v)cin >> i;
	for (auto &i : w)cin >> i;
	vector<Edge>edge;
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> K;
		while (K--) {
			cin >> L;
			L--;
			//ans += v[i] + w[L];
			edge.push_back(Edge(i, L+N, v[i] + w[L]));
		}
	}
	sort(edge.begin(), edge.end());
	UnionFind uf(N + M);
	for (auto i : edge) {
		if (uf.Check_Same(i.l, i.r)) {
			ans += i.cost;
			continue;
		}
		uf.Unite(i.l, i.r);
	}
	cout << ans << endl;
}