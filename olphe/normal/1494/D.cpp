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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

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

vector<vector<int>>func(vector<vector<int>>& w, vector<int>idx) {
	int mx = 0;
	for (auto i : idx) {
		for (auto j : idx) {
			mx = max(mx, w[i][j]);
		}
	}
	UnionFind uf(N);
	vector<vector<int>>ret;
	for (auto i : idx) {
		for (auto j : idx) {
			if (i == j)continue;
			if (w[i][j] != mx) {
				uf.Unite(i, j);
			}
		}
	}
	for (auto i : idx) {
		vector<int>v;
		if (i != uf.Find(i))continue;
		for (auto j : idx) {
			if (uf.Check_Same(i, j)) {
				v.push_back(j);
			}
		}
		ret.push_back(v);
	}
	return ret;
}

void Solve() {
	cin >> N;
	vector<int>v(N * 2 - 1);
	vector<int>p(N * 2 - 1);
	for (int i = 0; i < N * 2 - 1; i++) {
		p[i] = i;
	}
	vector<vector<int>>w(N, vector<int>(N));
	for (auto& i : w)for (auto& j : i)cin >> j;
	for (int i = 0; i < N; i++) {
		v[i] = w[i][i];
	}
	queue<pair<int, vector<int>>>nx;
	vector<int>idx(N);
	for (int i = 0; i < N; i++) {
		idx[i] = i;
	}
	vector<vector<int>>edge(N * 2 - 1);
	nx.push({ N,idx });
	int nidx = N + 1;
	while (!nx.empty()) {
		int mx = 0;
		auto box = nx.front();
		nx.pop();
		for (auto i : box.second) {
			for (auto j : box.second) {
				mx = max(mx, w[i][j]);
			}
		}
		v[box.first] = mx;
		auto b = func(w, box.second);
		for (auto i : b) {
			if (i.size() == 1) {
				edge[i.front()].push_back(box.first);
			}
			else {
				edge[nidx].push_back(box.first);
				nx.push({ nidx,i });
				nidx++;
			}
		}
	}
	cout << nidx << endl;
	for (int i = 0; i < nidx; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << N + 1 << endl;
	for (int i = 0; i < nidx; i++) {
		for (auto j : edge[i]) {
			cout << i + 1 << " " << j + 1 << endl;
		}
	}
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